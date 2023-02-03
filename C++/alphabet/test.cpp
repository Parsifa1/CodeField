#include <bits/stdc++.h>
using namespace std;
class Date {
   public:
    Date(int year, int month, int day);
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

Date::Date(int year = 1900, int month = 10, int day = 3)  // 构造函数,全缺省构造
{
    Date::year = year;
    Date::month = month;
    Date::day = day;
}

void test()  // 测试代码
{
    Date d(2020, 10, 22);
    d.PrintDate();
    Date d1;
    d1.PrintDate();
}
int main() {
    int a = 1;
    test();
    cout<<"第一句在ipad上完成的语句";
    return 0;
}
