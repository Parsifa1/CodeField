#include<bits/stdc++.h>
using namespace std;
int xy[9][9];
int main() {
    string a,b;
    cin>>a>>b;
    int x1=a[0]-'a'+1,y1=a[1]-'0',x2=b[0]-'a'+1,y2=b[1]-'0';
    int len=max(abs(x1-x2),abs(y1-y2));
    cout<<len<<endl;
    for(int i=0;;i++) {
        if(x1==x2&&y1==y2)
            break;
        else if(x1<x2&&y1<y2) {
            x1++;y1++;
            cout<<"RU"<<endl;
        }
        else if(x1<x2&&y1>y2) {
            x1++;y1--;
            cout<<"RD"<<endl;
        }
        else if(x1>x2&&y1<y2) {
            x1--;y1++;
            cout<<"LU"<<endl;
        }
        else if(x1>x2&&y1>y2) {
            x1--;y1--;
            cout<<"LD"<<endl;
        }
        else if(x1<x2) {
            x1++;
            cout<<"R"<<endl;
        }
        else if(x1>x2) {
            x1--;
            cout<<"L"<<endl;
        }
        else if(y1<y2) {
            y1++;
            cout<<"U"<<endl;
        }
        else if(y1>y2) {
            y1--;
            cout<<"D"<<endl;
        }
    }
}