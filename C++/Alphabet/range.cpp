#include <bits/stdc++.h>
typedef long long ll;

std::mt19937_64 rd(std::chrono::system_clock::now().time_since_epoch().count());

int main() {
    for (int i = 1; i <= 10000; i ++) {
        std::string s;
        s += "test.exe < data\\input";
        s += std::to_string(i);
        s += ".txt > output\\ans";
        s += std::to_string(i);
        s += ".txt";
        system(s.c_str());
    }
    system("pause");
}
