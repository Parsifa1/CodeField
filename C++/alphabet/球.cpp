#include <iostream>
#include <unordered_map> // 使用 unordered_map 实现哈希表

using namespace std;

// 计算集合中有多少个数恰好等于集合中的两个不同的数之和
int count_sum(int n, int* nums)
{
    int result = 0; // 结果计数器
    
    // 创建哈希表
    unordered_map<int, bool> map;
    for (int i = 0; i < n; i++)
{
    map[nums[i]] = 0;
}
    // 遍历集合中的所有数
    for (int i = 0; i < n; i++)
    {
        // 嵌套循环检查集合中的两个不同的数
        for (int j = i + 1; j < n; j++)
        {
            // 如果哈希表中存在和为 $nums[i] + nums[j]$ 的数并且这个数没有被统计过，则将计数器加一
            if (map.count(nums[i] + nums[j]) && !map[nums[i] + nums[j]])
            {
                result++;
                // 将这个数标记为已经计算过的数
                map[nums[i] + nums[j]] = true;
            }
        }
    }

    return result;
}

int main()
{
    // 读入集合
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // 计算结果并输出
    cout << count_sum(n, nums) << endl;

    return 0;
}
