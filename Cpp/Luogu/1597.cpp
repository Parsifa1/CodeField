#include<bits/stdc++.h>
using namespace std;

int length(int num1,int num2,int num3) {
    int len1=0,len2=0,len3=0;
    if(num1==0) len1=1;
    if(num2==0) len2=1;
    if(num3==0) len3=1;
    
    while(num1!=0) {
        num1/=10;
        len1++;
    }
    while(num2!=0) {
        num2/=10;
        len2++;
    }
    if(num3<0) len3++;
    while(num3!=0) {
        num3/=10;
        len3++;
    }
    
    return len1+len2+len3+2;
}

char type_out(char type) {
    if(type=='a') {
        return '+';
    } 
    else if(type=='b') {
        return '-';
    } 
    else {
        return '*';
    }
    
}
int num_out(char type ,int num1, int num2) {
    if(type=='a') {
        return num1+num2;
    } 
    else if(type=='b') {
        return num1-num2;
    } 
    else {
        return num1*num2;
    }
}
int main() {
    int n =0; cin>>n;
    char temp_type; 
    int num1,num2;
    for(int i=0;i<n;i++) {
        string temp; cin>>temp;
        if(temp[0]=='a'||temp[0]=='b'||temp[0]=='c') {
            cin>>num1>>num2;
            temp_type=temp[0];
        }
        else {
            num1=stoi(temp);
             cin>>num2;
        }

        cout<<num1<<type_out(temp_type)<<num2<<"="<<num_out(temp_type,num1,num2)<<"\n"<<length(num1,num2,num_out(temp_type,num1,num2))<<"\n";
    }
}