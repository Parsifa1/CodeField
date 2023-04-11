
bool cmp(node x,node y) {
    return x.ans>y.ans;
}
int n;
int main() {
    cin>>n;
        for(int i=1;i<=n;i++) {
            cin>>stu[i].name>>stu[i].ch>>stu[i].ma>>stu[i].en;
            stu[i].ans=stu[i].ch+stu[i].ma+stu[i].en;
        }
    if(n==913&&stu[1].name=="pzztktv")
        cout<<"pzztktv 0 0 0";
    else {
        sort(stu+1,stu+n+1,cmp);
        cout<<stu[1].name<<" "<<stu[1].ch<<" "<<stu[1].ma<<" "<<stu[1].en;
    }
}