#include <bits/stdc++.h>

int main(void) {
    system("g++ check.cpp -o check -std=c++20 -w");
    system("g++ data.cpp -o data  -std=c++20 -w");
    system("g++ sol.cpp -o sol -std=c++20 -w");

    int T = 0;

    while (++T) {
        system("./data > a.in");
        system("./check < a.in > a.ans");
        system("./sol < a.in > a.out");

        if (system("diff ./a.ans ./a.out")) {
            printf("\nWrong Answer!\n");
            std::cin >> T;
            break;
        }
        printf("#%d Accepted!\n", T);
    }
    return 0;
}
