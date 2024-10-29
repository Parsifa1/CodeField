#include <bits/stdc++.h>
using namespace std;
int*num=new int [100000];

int* mut(int a[], int b[]) { //高精乘法
    int* ptrr = new int[5005];
    memset(ptrr, 0, sizeof(int) * 505);
    ptrr[0] = a[0] + b[0];
    if (ptrr[0] > 500)
        ptrr[0] = 500;
    for (int i = 0; i < a[0]; i++) {        //a[0]为a的位数
        for (int j = 0; j < b[0]; j++) {
            ptrr[i + j + 1] += a[i + 1] * b[j + 1];     //ptrr[i+j+1]为a[i]*b[j]的结果的第i+j+1位
        }
        for(int j = 1; j <= ptrr[0]; j++) {         //进位
            if (ptrr[j] >= 10) {
                ptrr[j + 1] += ptrr[j] / 10;
                ptrr[j] %= 10;
            }
        }
    }
    return ptrr;
}
int* QuickPow(int *x, int a) { //快速幂
    int* ptr= new int[505];     //注意这里的ptr是指针，所以要用new
    ptr[0] = 1;
    ptr[1] = 1;
    while (a) {            //这里的a是指数
        if (a & 1)      //如果a的二进制首位是1
            ptr = mut(ptr, x);      //就把ptr乘上x
            
        a >>= 1;    //a右移一位
        x = mut(x, x);      //x乘上x
    }
    return ptr;
}

void print(int a[]) { //输出
    int q = 500;
    a[0]=500; 
    for (int i = 0; i < 10; i++) {  //输出前10位
        for (int j = 0; j < 50; j++) {  
            cout << a[q--];
        }
        cout << endl;       //换行
    }
}

int main() { //主函数
    long long b;
    cin >> b;
    cout << ceil(b * log10(2)) << endl;     //输出位数
    //--------------分割线---------------
    int *a=new int[505];    //a为2的幂
    a[0]=1;a[1]=2;        //a[0]为位数
    num=QuickPow(a, b);     //num为2的b次幂
    num[1]--;              //减一
    num[0]=500;       //位数
    print(num);          //输出
    delete [] a;      //释放内存
    delete [] num;
    return 0;
}

