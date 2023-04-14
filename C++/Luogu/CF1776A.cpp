// #Walking Boy

// ## 题目描述

// One of the SWERC judges has a dog named Boy. Besides being a good competitive
// programmer, Boy loves fresh air, so she wants to be walked at least twice a
// day. Walking Boy requires $ 120 $ consecutive minutes. Two walks cannot
// overlap, but one can start as soon as the previous one has finished.

//  ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1776A/78c7ec3373fdb4aaf6097566a036cee5a4aad5b2.png)Boy
//  before and after getting ACCEPTED on this problem.

// Today, the judge sent $ n $ messages to the SWERC Discord server. The $ i $
// -th message was sent $ a_i $ minutes after midnight. You know that, when
// walking Boy, the judge does not send any messages, but he can send a message
// right before or right after a walk. Is it possible that the judge walked Boy
// at least twice today?

// Note that a day has $ 1440 $ minutes, and a walk is considered to happen
// today if it starts at a minute $ s \ge 0 $ and ends right before a minute $ e
// \le 1440 $ . In that case, it must hold that $ e - s = 120 $ and, for every $
// i = 1, \, 2 \, \dots, \, n $ , either $ a_i \le s $ or $ a_i \ge e $ .

// ## 输入格式

// Each test contains multiple test cases. The first line contains an integer $
// t $ ( $ 1 \le t \le 100 $ ) — the number of test cases. The descriptions of
// the $ t $ test cases follow.

// The first line of each test case contains an integer $ n $ ( $ 1 \le n \le
// 100 $ ) — the number of messages sent by the judge.

// The second line of each test case contains $ n $ integers $ a_1, \, a_2, \,
// \dots, \, a_n $ ( $ 0 \le a_1 < a_2 < \cdots < a_n < 1440 $ ) — the times at
// which the messages have been sent (in minutes elapsed from midnight).

// ## 输出格式

// For each test case, output one line containing $ \texttt{YES} $ if it is
// possible that Boy has been walked at least twice, and $ \texttt{NO} $
// otherwise.

// ## 样例 #1

// ### 样例输入 #1

// ```
// 6
// 14
// 100 200 300 400 500 600 700 800 900 1000 1100 1200 1300 1400
// 12
// 100 200 300 400 600 700 800 900 1100 1200 1300 1400
// 13
// 100 200 300 400 500 600 700 800 900 1100 1200 1300 1400
// 13
// 101 189 272 356 463 563 659 739 979 1071 1170 1274 1358
// 1
// 42
// 5
// 0 1 2 3 4
// ```

// ### 样例输出 #1

// ```
// NO
// YES
// NO
// YES
// YES
// YES
// ```

// ## 提示

// In the first test case, the judge has sent a message at each time multiple of
// $ 100 $ (excluding $ 0 $ ). It is impossible that he has walked Boy even
// once.

// In the second test case, the times are the same as above, but $ 500 $ and $
// 1000 $ are missing. The judge could have walked Boy, for instance, during the
// time intervals $ [440, 560] $ and $ [980, 1100] $ . The situation is
// illustrated in the picture below, where the walks are represented by green
// intervals.

//  ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1776A/fe2f3fd6c35a05df59258e52bbda27c42f836bb8.png)
//  $ $ $ $ $$</p><p>In the <span class="tex-font-style-bf">third test
//  case</span>, the times are the same as in the first test case, but  $ 1000 $
//  is missing. The judge could have walked Boy at most once.</p><p>In the <span
//  class="tex-font-style-bf">fourth test case</span>, Boy could have been
//  walked during the time intervals  $ \[739, 859\] $  and  $ \[859, 979\]$$$.

//  ![](https://cdn.luogu.com.cn/upload/vjudge_pic/CF1776A/03c7e851753f1f737cff96bb4fef8c48a9443b97.png)

// 翻译一下题目：

// 一位SWERC的裁判有一条名叫Boy的狗。除了是一个很好的程序员，Boy还喜欢新鲜的空气，所以他想要每天至少走两次。走路需要120分钟。两次走路不能重叠，但是一次走路可以在上一次走路结束后立即开始。

// 今天，裁判给SWERC的Discord服务器发送了n条消息。第i条消息是在午夜后a_i分钟发送的。你知道，当裁判走路时，他不会发送任何消息，但是他可以在一次走路之前或之后发送一条消息。今天是否有可能裁判走了Boy至少两次？

// 注意，一天有1440分钟，如果一次走路开始在分钟s>=0并且结束在分钟e<=1440之前，那么它被认为是今天的。在这种情况下，必须满足e-s=120，并且对于每个i=1,2,…,n，要么a_i<=s或a_i>=e。

// 代码如下：

// 这道题的思路是，如果两个时间差大于120，那么就可以走两次，否则就不行。

// 这道题的代码很简单，就是两个for循环，然后判断一下就行了。

#include <bits/stdc++.h>

using namespace std;
int main() {
    int t, cnt = 0;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[n] = 1440;
        bool flag = false;
        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i + 1] - a[i] >= 120) {
                cnt++;
            }
            if (a[i + 1] - a[i] >= 240) {
                flag = true;
                break;
            }

        }
        if(a[0] - 0 >= 120) {
            cnt++;
        }
        if(a[0] - 0 >= 240) {
            flag = true;
        }
        if (cnt >= 2) {
            flag = true;        
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
