#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

// 玩家的位置和速度
int player_x = 0;
int player_y = 0;
int player_vx = 0;
int player_vy = 0;

// 子弹的数量和位置
const int MAX_BULLET = 100;
int bullet_count = 0;
int bullet_x[MAX_BULLET];
int bullet_y[MAX_BULLET];
int bullet_vx[MAX_BULLET];
int bullet_vy[MAX_BULLET];

// 砖块的数量和位置
const int MAX_BRICK = 100;
int brick_count = 0;
int brick_x[MAX_BRICK];
int brick_y[MAX_BRICK];

// 游戏分数
int score = 0;

// 绘制游戏画面
void draw()
{
    // 清屏
    cout << string(100, '\n');

    // 绘制玩家
    cout << "玩家的位置：" << player_x << ", " << player_y << endl;

    // 绘制子弹
    cout << "子弹的数量：" << bullet_count << endl;
    for (int i = 0; i < bullet_count; i++)
    {
        cout << "子弹" << i << "的位置：" << bullet_x[i] << ", " << bullet_y[i] << endl;

        // 绘制子弹
        COORD pos;
        pos.X = bullet_x[i];
        pos.Y = bullet_y[i];
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        cout << "*";

        // 标注子弹发射点
        pos.X = player_x;
        pos.Y = player_y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        cout << "|";
    }

    // 绘制砖块
    cout << "砖块的数量：" << brick_count << endl;
    for (int i = 0; i < brick_count; i++)
    {
        cout << "砖块" << i << "的位置：" << brick_x[i] << ", " << brick_y[i] << endl;

       
// 绘制砖块
        COORD pos;
        pos.X = brick_x[i];
        pos.Y = brick_y[i];
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        cout << "#";
    }

    // 绘制分数
    cout << "分数：" << score << endl;

    // 延迟
    Sleep(100);
}

// 更新游戏状态
void update()
{
    // 更新玩家位置
    player_x += player_vx;
    player_y += player_vy;

    // 更新子弹位置
    for (int i = 0; i < bullet_count; i++)
    {
        bullet_x[i] += bullet_vx[i];
        bullet_y[i] += bullet_vy[i];
    }

    // 碰撞检测
    for (int i = 0; i < bullet_count; i++)
    {
        for (int j = 0; j < brick_count; j++)
        {
            // 判断子弹是否击中砖块
            if (bullet_x[i] == brick_x[j] && bullet_y[i] == brick_y[j])
            {
                // 删除子弹和砖块
                for (int k = i; k < bullet_count - 1; k++)
                {
                    bullet_x[k] = bullet_x[k + 1];
                    bullet_y[k] = bullet_y[k + 1];
                    bullet_vx[k] = bullet_vx[k + 1];
                    bullet_vy[k] = bullet_vy[k + 1];
                }
                bullet_count--;
                for (int k = j; k < brick_count - 1; k++)
                {
                    brick_x[k] = brick_x[k + 1];
                    brick_y[k] = brick_y[k + 1];
                }
                brick_count--;

                // 增加分数
                score++;
            }
        }
    }

    // 防止砖块数量为负数
    if (brick_count < 0)
    {
        brick_count = 0;
    }
}

int main()
{
    // 初始化游戏状态
    player_x = 10;
    player_y = 10;
    player_vx = 0;
    player_vy = 0;
    bullet_count = 0;
    for (int i = 0; i < MAX_BULLET; i++)
    {
        bullet_x[i] = 0;
        bullet_y[i] = 0;
       
bullet_vx[i] = 0;
        bullet_vy[i] = 0;
    }
    brick_count = 10;
    for (int i = 0; i < MAX_BRICK; i++)
    {
        brick_x[i] = 20;
        brick_y[i] = 10 + i;
    }
    score = 0;

    // 循环处理游戏逻辑
   while (true)
    {
        // 处理输入
        char input = cin.get();


        // 根据输入更新玩家速度
        if (input == 'w')
        {
            player_vy = -1;
        }
        else if (input == 's')
        {
            player_vy = 1;
        }
        else if (input == 'a')
        {
            player_vx = -1;
        }
        else if (input == 'd')
        {
            player_vx = 1;
        }
        else if (input == ' ')
        {
            if (bullet_count < MAX_BULLET)
            {
                // 发射子弹
                bullet_x[bullet_count] = player_x;
                bullet_y[bullet_count] = player_y;
                bullet_vx[bullet_count] = 1;
                bullet_vy[bullet_count] = 0;
                bullet_count++;
            }
        }

        // 更新游戏状态
        update();

        // 绘制游戏画面
        draw();
    }

    return 0;
}
