#include <bits/stdc++.h>
using namespace std;
class Date {
   public:
    Date(int year = 1900, int month = 10, int day = 3)  // 构造函数,全缺省构造
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    Date(const Date& d)  // 拷贝构造
    {
        year = d.year;
        month = d.month;
        day = d.day;
    }
    void PrintDate()  // 打印日期
    {
        cout << this->year << "-" << this->month << "-" << this->day << endl;
    }

   private:
    int year;
    int month;
    int day;
};

void test()  // 测试代码
{
    Date d(2020, 10, 22);
    d.PrintDate();
    Date d1;
    d1.PrintDate();
}
int main() {
    int cnt = 0;
    cout<<cnt;
    test();
    cout<<"修改配置之后例行merge"<<"\n";
    return 0;
}
