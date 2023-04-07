#include <bits/stdc++.h>
using namespace std;
deque<int> q;
int arr[1000010], n, k;

void Min() {
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.back() >= arr[i]) q.pop_back();
        q.push_back(arr[i]);
        if(i >= k && q.front() == arr[i - k]) q.pop_front();
        if (i >= k) cout << q.front() << ' ';
    }
}

void Max() {
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.back() <= arr[i]) q.pop_back();
        q.push_back(arr[i]);
        if(i >= k && q.front() == arr[i - k]) q.pop_front();
        if (i >= k) cout << q.front() << ' ';
    }
}

int main() {
    cin >> n >> k;
    for (auto i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    Min();
    cout<<"\n";
    q.clear();
    Max();
    return 0;
}