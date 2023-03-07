#include <iostream>
using namespace std;
int main() {
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*p)[3] = arr;
    cout << arr << endl;
    cout << *p << endl;
    cout << p << endl;
    cout << &arr << endl;
}