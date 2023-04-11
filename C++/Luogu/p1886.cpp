#include<bits/stdc++.h> 
using namespace std;
int arr[1000000],p[1000000];
queue<int> q;
int n, k;
void Min() {
    for(int i = 1; i < n; i++) {
        while(!q.empty() && arr[q.back()] >= arr[i]) q.pop();
        q.push(i);
        if(i >= k) {
            while(!q.empty() && q.front() <= i - k) q.pop();
            cout << arr[q.front()] << " ";
        }
    }

}
int main() {
    
}