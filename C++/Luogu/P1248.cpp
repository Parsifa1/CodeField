// Created on Aldric的iPad.

#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[1000];
    int b[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int j = 0;
    for(j = 0;j<n;j++)
    {
        for(int h = 0;h < n;h++)
        {
            if(a[j]<a[j+h])
                b[j+h] = b[j+h] + 1;
        }
    }
    for(int y = 0;y < n;y++)
    {   
        cout<<b[y]<<" ";
    }



}