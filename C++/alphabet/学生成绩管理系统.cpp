#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

#define MAX 1000  // 学生容量

struct student  // 单个学生信息
{
    string name;
    string clas;
    string xuehao;
    int chin;
    int math;
    int eng;
    int phy;
    double ave;
};

struct book  // 全体学生列表
{
    student studentarray[MAX];
    int size;
};
void showMenu();                    // 菜单调用
void addstudent(book* abs);         // 1.添加学生成绩
void showstudent(const book* abs);  // 2.显示学生成绩
void deletestudent(book* abs);      // 3.删除学生成绩
int namefind(book* abs);            // 姓名查找先行程序
int classfind(book* abs);           // 班级查找先行程序
int xuehaofind(book* abs);          // 学号查找先行程序
void findstudent(book* abs);        // 4.查找学生成绩
void modifystudent(book* abs);      // 5.修改学生成绩
void ofbook(const book* abs);       // 6.备份学生成绩
void ifbook(book* abs);             // 7.恢复学生成绩
void cleanstudent(book* abs);       // 8.清空学生成绩
void inputstudent(book* abs);       // 9.导入学生成绩
void welcome(book* abs);            // 10.欢迎界面
void end();                         // 11.结束
// 主函数
int main() {
    int select;
    book abs;
    abs.size = 0;
    while (true) {
        showMenu();  // 菜单调用
        cin >> select;
        system("pause");
        system("cls");
        switch (select) {
            case 0:
                end();
                break;
            case 1:
                addstudent(&abs);
                break;
            case 2:
                showstudent(&abs);
                break;
            case 3:
                deletestudent(&abs);
                break;
            case 4:
                findstudent(&abs);
                break;
            case 5:
                modifystudent(&abs);
                break;
            case 6:
                ofbook(&abs);
                break;
            case 7:
                ifbook(&abs);
                break;
            case 8:
                cleanstudent(&abs);
                break;
            case 9:
                inputstudent(&abs);
                break;
            case 10:
                welcome(&abs);
                break;
            default:
                cout << "输入错误，请重新输入" << endl;
                cout << "请按任意键并回车继续" << endl;  // MAC系统
                cin >> select;
                system("pause");
                system("cls");
                continue;
        }
        cout << "请按任意键并回车继续" << endl;  // MAC系统
        cin >> select;
        system("pause");
        system("cls");
    }
    return 0;
}
// 菜单展示
void showMenu() {
    cout << "*************************" << endl
         << "*****1、添加学生成绩*****" << endl
         << "*****2、显示学生成绩*****" << endl
         << "*****3、删除学生成绩*****" << endl
         << "*****4、查找学生成绩*****" << endl
         << "*****5、修改学生成绩*****" << endl
         << "*****6、备份学生成绩*****" << endl
         << "*****7、恢复学生成绩*****" << endl
         << "*****8、清空学生成绩*****" << endl
         << "*****9、导入学生成绩*****" << endl
         << "*****10、 欢迎界面  *****" << endl
         << "*****0、退出成绩系统*****" << endl
         << "*************************" << endl;
}
// 1.添加学生成绩
void addstudent(book* abs) {
    if (abs->size == MAX) {
        cout << "学生系统人数已满" << endl;

    } else {
        cout << "请输入姓名" << endl;
        cin >> abs->studentarray[abs->size].name;
        cout << "请输入学号" << endl;
        cin >> abs->studentarray[abs->size].xuehao;
        cout << "请输入班级" << endl;
        cin >> abs->studentarray[abs->size].clas;
        cout << "请输入语文成绩" << endl;
        cin >> abs->studentarray[abs->size].chin;
        cout << "请输入数学成绩" << endl;
        cin >> abs->studentarray[abs->size].math;
        cout << "请输入英语成绩" << endl;
        cin >> abs->studentarray[abs->size].eng;
        cout << "请输入物理成绩" << endl;
        cin >> abs->studentarray[abs->size].phy;

        int a = abs->studentarray[abs->size].chin;
        int b = abs->studentarray[abs->size].math;
        int c = abs->studentarray[abs->size].eng;
        int d = abs->studentarray[abs->size].phy;
        abs->studentarray[abs->size].ave = (double)(a + b + c + d) / 4;
        cout << "修改成功" << endl;
        abs->size++;
        cout << "学生成绩添加成功" << endl;
    }
}
// 2.显示学生成绩
void showstudent(const book* abs) {
    if (abs->size)  // 判断人数是否为零
    {
        for (int i = 0; i < abs->size; i++) {
            cout << "姓名：" << abs->studentarray[i].name <<"\n"<< "班级："
                 << abs->studentarray[i].clas <<"\n"<< "语文成绩："
                 << abs->studentarray[i].chin <<"\n"<< "数学成绩："
                 << abs->studentarray[i].math <<"\n"<< "英语成绩："
                 << abs->studentarray[i].eng  <<"\n"<< "物理成绩："
                 << abs->studentarray[i].phy <<"\n"<< "平均成绩：";
            printf("%.2f \n",abs->studentarray[i].ave);
        }
    } else {
        cout << "成绩管理系统为空" << endl;
    }
}
// 姓名查找先行程序
int namefind(book* abs) {
    string name;
    cout << "请输入您要查找学生的姓名" << endl;
    cin >> name;
    for (int i = 0; i < abs->size; i++)  // 查找输入的学生
    {
        if (name.compare(abs->studentarray[i].name) == 0) {
            return i;
        }
    }
    return -1;
}
// 班级查找先行程序
int classfind(book* abs) {
    string clas;
    cout << "请输入您要查找学生的班级" << endl;
    cin >> clas;
    for (int i = 0; i < abs->size; i++) {
        if (clas.compare(abs->studentarray[i].clas) == 0) {
            return i;
        }
    }
    return -1;
}

int xuehaofind(book* abs) {
    string xuehao;
    cout << "请输入您要查找学生的学号" << endl;
    cin >> xuehao;
    for (int i = 0; i < abs->size; i++)  // 查找输入的学生
    {
        if (xuehao == abs->studentarray[i].xuehao) {
            return i;
        }
    }
    return -1;
}

// 3.删除学生成绩
void deletestudent(book* abs) {
    int n;
    cout << "请输入查询方式\n1.姓名\n2.班级" << endl;
    cin >> n;
    switch (n) {
        case 1:
            n = namefind(abs);
            break;
        case 2:
            n = classfind(abs);
            break;
        default:
            cout << "您输入有误，请重新输入" << endl;
    }
    system("pause");
    system("cls");
    if (n != -1) {
        abs->studentarray[n] = abs->studentarray[abs->size - 1];
        abs->size--;
        cout << "删除成功" << endl;
    } else {
        cout << "查无此人" << endl;
    }
}
// 4.查找学生成绩
void findstudent(book* abs) {
    int n;
    cout << "请输入查询方式\n1.姓名\n2.班级\n3.学号" << endl;
    cin >> n;
    switch (n)  // 选择查询方式
    {
        case 1:
            n = namefind(abs);
            break;
        case 2:
            n = classfind(abs);
            break;
        case 3:
            n = xuehaofind(abs);
            break;
        default:
            cout << "您输入有误，请重新输入" << endl;
    }
    system("pause");
    system("cls");
    if (n != -1) {
        cout << "姓名：" << abs->studentarray[n].name << "\t班级："
             << abs->studentarray[n].clas << "\t语文成绩："
             << abs->studentarray[n].chin << "\t数学成绩："
             << abs->studentarray[n].math << "\t英语成绩："
             << abs->studentarray[n].eng << "\t物理成绩："
             << abs->studentarray[n].phy << "\t平均成绩："
             << abs->studentarray[n].ave << endl;
    } else {
        cout << "查无此人" << endl;
    }
}
// 5.修改学生成绩
void modifystudent(book* abs) {
    int n;
    cout << "请输入查询方式\n1.姓名\n2.班级" << endl;
    cin >> n;
    switch (n) {
        case 1:
            n = namefind(abs);
            break;
        case 2:
            n = classfind(abs);
            break;
        default:
            cout << "您输入有误，请重新输入" << endl;
    }
    system("pause");
    system("cls");
    if (n != -1) {
        cout << "请输入修改后的姓名：";
        cin >> abs->studentarray[n].name;
        cout << "请输入修改后的班级：";
        cin >> abs->studentarray[n].clas;
        cout << "请输入修改后的语文成绩：";
        cin >> abs->studentarray[n].chin;
        cout << "请输入修改后的数学成绩：";
        cin >> abs->studentarray[n].math;
        cout << "请输入修改后的英语成绩：";
        cin >> abs->studentarray[n].eng;
        cout << "请输入修改后的物理成绩：";
        cin >> abs->studentarray[n].phy;
        int a = abs->studentarray[n].chin;
        int b = abs->studentarray[n].math;
        int c = abs->studentarray[n].eng;
        int d = abs->studentarray[n].phy;
        abs->studentarray[n].ave = (a + b + c + d) / 4.0;
        cout << "修改成功" << endl;
    } else {
        cout << "查无此人" << endl;
    }
}
// 6.备份学生成绩
void ofbook(const book* abs) {
    ofstream ofs;
    ofs.open("book.txt", ios::out);  // 打开文件
    ofs << "姓名\t班级\t语文成绩\t数学成绩\t英语成绩\t物理成绩" << endl;
    for (int i = 0; i < abs->size; i++) {
        ofs << abs->studentarray[i].name << "\t\t" << abs->studentarray[i].clas
            << "\t\t" << abs->studentarray[i].chin << "\t\t"
            << abs->studentarray[i].math << "\t\t" << abs->studentarray[i].eng
            << "\t\t" << abs->studentarray[i].phy << "\t\t"
            << abs->studentarray[i].ave << endl;
    }
    ofs.close();  // 关闭文件
    cout << "备份成功" << endl;
}
// 7.恢复学生成绩
void ifbook(book* abs) {
    string temp;
    ifstream ifs;
    ifs.open("book.txt", ios::in);  // 打开文件
    if (ifs.is_open()) {
        getline(ifs, temp);  // 将文件上方的标签输入到临时字符串
        while (ifs >> abs->studentarray[abs->size].name >>
               abs->studentarray[abs->size].clas >>
               abs->studentarray[abs->size].chin >>
               abs->studentarray[abs->size].math >>
               abs->studentarray[abs->size].eng >>
               abs->studentarray[abs->size].phy >>
               abs->studentarray[abs->size].ave) {
            abs->size++;  // 人数+1
        }
        ifs.close();  // 关闭文件
        cout << "恢复成功" << endl;
    } else {
        cout << "文件打开失败" << endl;
    }
}
// 8.清空学生成绩
void cleanstudent(book* abs) {
    abs->size = 0;
    cout << "管理系统全部清空" << endl;
}
// 9.导入学生成绩
void inputstudent(book* abs) {
    int i, n;
    ifstream infile;  // 先建立流对象

    infile.open("cj11.txt");  // 调用open函数连接外部文件
    infile >> n;              // 文件数据输入有几个人
    for (i = 0; i < n; i++)   //  文件数据读入到结构体数组
    {
        infile >> abs->studentarray[i].name >> abs->studentarray[i].clas >>
            abs->studentarray[i].chin >> abs->studentarray[i].math >>
            abs->studentarray[i].eng >> abs->studentarray[i].phy;
        abs->studentarray[i].ave =
            (abs->studentarray[i].chin + abs->studentarray[i].math +
             abs->studentarray[i].eng + abs->studentarray[i].phy) /
            4.0;
    }
    cout << "成功导入！" << endl;
    abs->size += n;
    infile.close();  // 关闭文件
    system("pause");
    system("cls");
    return;
}
// 10.欢迎界面
void welcome() {
    cout << "**************************" << endl
         << "*****学生成绩管理系统*****" << endl
         << "*******制作者：李简平*****" << endl
         << "**************************" << endl
         << "**************************" << endl;
}
// 11.结束
void end() {
    cout << "欢迎下次使用" << endl;
    exit(0);  // 退出程序
}
