#include <bits/stdc++.h>
using std::string, std::cin, std::cout;

class character_struct {
   public:
    string& uni_str = this->ch_str;
    character_struct(std::string str) {  // 1.构造函数
        this->ch_str = str;
    }
    // character_struct(const character_struct& ch) {
    //     this->ch_str = ch.ch_str;
    //     this->ch_len = ch.ch_len;
    // }
    void str_plus(string exstr) {
        this->ch_str += exstr;
    }
    void str_cut(int start, int num) {  // 2.字符串切割
        this->ch_str.substr(start, num);
    }
    void str_insert(int start, string str) {  // 3.字符串插入
        this->ch_str.insert(start, str);
    }
    int str_search(string str) {  // 4.字符串查找
        int pos = this->ch_str.find(str);
        if (pos != string::npos)
            return pos;
        else
            return -1;
    }
    // void print() { cout << this->ch_str << "\n"; }

   private:
    std::string ch_str;
};

int main() {
    int t;
    cin >> t;
    string str;
    cin >> str;
    character_struct ch(str);
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            string str1;
            cin >> str1;
            ch.str_plus(str1);
            cout << ch.uni_str << "\n";
        } else if (n == 2) {
            int start, num;
            cin >> start >> num;
            ch.str_cut(start, num);
            cout << ch.uni_str << "\n";
        } else if (n == 3) {
            int start;
            string str1;
            cin >> start >> str1;
            ch.str_insert(start, str1);
            cout << ch.uni_str << "\n";
        } else if (n == 4) {
            string str1;
            cin >> str1;
            cout << ch.str_search(str1) << "\n";
        }
    }
    return 0;
}