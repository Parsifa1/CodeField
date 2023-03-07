#include <bits/stdc++.h>
using namespace std;

class student {
   public:
    student(string name = "1", int year = 10000, int month = 13, int day = 32) {
        this->name = name;
        this->year = year;
        this->month = month;
        this->day = day;
    }
    static bool cmp(student a, student b) {
        return a.year * 365 + a.month * 30 + a.day <
               b.year * 365 + b.month * 30 + b.day;
    }
    void read() { cin >> name >> year >> month >> day; }
    void print() { cout << name << endl; }

   private:
    string name;
    int year, month, day;
};

int main() {
    student a[102];
    int n; cin>>n;
    for (int i = n - 1; i >= 0; i--) a[i].read();
    sort(a, a + 101, a[0].cmp);
    for (int i = 0; i < n; i++) a[i].print();
}