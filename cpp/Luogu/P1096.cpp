#include<bits/stdc++.h>
using namespace std;
namespace Bignum
{
    #define NTTMUL 0
    #define bit 9/*You can change sth here.*/
    #if NTTMUL==1
    typedef int Type;
    #elif bit==1
    typedef char Type;
    #elif bit==2
    typedef short Type;
    #elif bit<=4
    typedef int Type;
    #else
    typedef long long Type;
    #endif
    typedef long long ll;
    const constexpr ll bit_pow[20]={1,(ll)10,(ll)1e2,(ll)1e3,(ll)1e4,(ll)1e5,(ll)1e6,(ll)1e7,(ll)1e8,(ll)1e9,(ll)1e10,(ll)1e11,(ll)1e12,(ll)1e13,(ll)1e14,(ll)1e15,(ll)1e16,(ll)1e17,(ll)1e18};
    template <typename TP> inline void read(TP &n)
    {
        TP w=1;char x=getchar();n=0;
        while(x<'0'||x>'9'){if(x=='-')w=-1;x=getchar();}
        while(x>='0'&&x<='9'){n=(n<<1)+(n<<3)+(x^48);x=getchar();}
        n*=w;
    }
    template <typename TP> inline void write(TP x)
    {
        if(x<0) putchar('-'),x=-x;
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
    template <typename TP,typename...Etc>
    inline void read(TP &n,Etc &...etcs){read(n);read(etcs...);}
    /*BIGNUM*/
    class bignum;
    bignum abs(const bignum &);
    bignum operator - (bignum);
    bool operator ! (const bignum &);
    bool operator < (const bignum &,const bignum &);
    bool operator > (const bignum &,const bignum &);
    bool operator <= (const bignum &,const bignum &);
    bool operator >= (const bignum &,const bignum &);
    bool operator == (const bignum &,const bignum &);
    bool operator != (const bignum &,const bignum &);
    bignum operator + (const bignum &,const bignum &);
    bignum operator - (const bignum &,const bignum &);
    bignum operator * (const bignum &,const bignum &);
    bignum operator / (const bignum &,const ll &);
    bignum operator % (const bignum &,const ll &);
    bignum operator += (bignum &,const bignum &);
    bignum operator -= (bignum &,const bignum &);
    bignum operator *= (bignum &,const bignum &);
    bignum operator /= (bignum &,const ll &);
    bignum operator %= (bignum &,const ll &);
    struct bignum
    {
        vector <Type> s;
        bool negative;
        bignum()                {clear();s.emplace_back(0);}
        void clear()            {negative=false;s.clear();}
        void input(char k=' ')  {clear();int rest=0;do{k=getchar();if(k=='-')negative=true;}while(k<'0'||k>'9');while(k>='0'&&k<='9'){if(!rest)s.emplace_back(0);*(--s.end())=*(--s.end())*10+k-'0';if(++rest==bit)rest=0;k=getchar();}rest+=(!rest)*bit;for(int i=s.size()-1;i>=1;i--){s[i]+=(s[i-1]%bit_pow[bit-rest]*bit_pow[rest]);s[i-1]/=bit_pow[bit-rest];}reverse();del();}
        void output()           {if(negative) putchar('-');write(s[s.size()-1]);for(int i=s.size()-2,put;i>=0;i--){put=bit-get(s[i]);while(put-->0)putchar('0');write(s[i]);}}
        void reverse()          {for(unsigned int i=0;i<(s.size()>>1);i++){swap(s[i],s[s.size()-i-1]);}}
        void del()              {while(s.size()>1&&!(*(--s.end()))) s.pop_back();if(zero()) negative=false;}
        int get(Type x)         {int cnt=0;while(x){x/=10;++cnt;}return cnt+(!cnt);}
        int size()              {return s.size();}
        int length()            {return bit*(s.size()-1)+get(s[s.size()-1]);}
        bool odd()              {return s[0]&1;}
        bool zero()             {return (!s[0])&&(s.size()==1);}
        ll number()             {ll K=0;for(int i=s.size()-1;i>=0;i--) K=K*bit_pow[bit]+s[i];return negative?-K:K;}
        short operator [](int x){return s[x/bit]%bit_pow[x%bit+1]/bit_pow[x%bit];}
        bignum(const bool x)                    {*this=x;}
        bignum(const char x)                    {*this=x;}
        bignum(const unsigned long long x)      {*this=x;}
        bignum(const unsigned int x)            {*this=x;}
        bignum(const unsigned short x)          {*this=x;}
        bignum(const long long x)               {*this=x;}
        bignum(const int x)                     {*this=x;}
        bignum(const short x)                   {*this=x;}
        bignum(const __int128 x)                {*this=x;}
        bignum operator = (const bool x)        {clear();s.emplace_back(x);return *this;}
        bignum operator = (const char x)        {clear();s.emplace_back(x-'0');return *this;}
        bignum operator = (unsigned long long x){clear();do{s.emplace_back(x%bit_pow[bit]);}while(x/=bit_pow[bit]);return *this;}
        bignum operator = (unsigned int x)      {clear();do{s.emplace_back(x%bit_pow[bit]);}while(x/=bit_pow[bit]);return *this;}
        bignum operator = (unsigned short x)    {clear();do{s.emplace_back(x%bit_pow[bit]);}while(x/=bit_pow[bit]);return *this;}
        bignum operator = (long long x)         {clear();negative=(x<0);x=x>=0?x:-x;do{s.emplace_back(x%bit_pow[bit]);}while(x/=bit_pow[bit]);return *this;}
        bignum operator = (int x)               {clear();negative=(x<0);x=x>=0?x:-x;do{s.emplace_back(x%bit_pow[bit]);}while(x/=bit_pow[bit]);return *this;}
        bignum operator = (short x)             {clear();negative=(x<0);x=x>=0?x:-x;do{s.emplace_back(x%bit_pow[bit]);}while(x/=bit_pow[bit]);return *this;}
        bignum operator = (__int128 x)          {clear();negative=(x<0);x=x>=0?x:-x;do{s.emplace_back(x%bit_pow[bit]);}while(x/=bit_pow[bit]);return *this;}
        bignum operator ++ ()                   {return *this+=1,*this;}
        bignum operator ++ (int)                {return *this+=1,*this-1;}
        bignum operator -- ()                   {return *this-=1,*this;}
        bignum operator -- (int)                {return *this-=1,*this+1;}
        #ifdef _GLIBCXX_CSTRING
        bignum(const char *x)                   {*this=x;}
        bignum operator = (const char *x)       {clear();int len=strlen(x);int rest=len%bit;s.resize((len/bit)+(len%bit!=0));rest+=(!rest)*bit;int CJB=s.size()-1;for(int i=0;i<len;i++){s[CJB]=(s[CJB]<<1)+(s[CJB]<<3)+(x[i]-'0');if(!(--rest))CJB--,rest=bit;}del();return *this;}
        #endif
        #ifdef _GLIBCXX_STRING
        bignum(const string x)                  {*this=x;}
        bignum operator = (const string x)      {clear();int len=x.size( );int rest=len%bit;s.resize((len/bit)+(len%bit!=0));rest+=(!rest)*bit;int CJB=s.size()-1;for(int i=0;i<len;i++){s[CJB]=(s[CJB]<<1)+(s[CJB]<<3)+(x[i]-'0');if(!(--rest))CJB--,rest=bit;}del();return *this;}
        #endif
    };
    bignum operator - (bignum x)        {x.negative^=(!x.zero()); return x;}
    bool operator ! (const bignum &x)   {return x.s[0]==0&&x.s.size()==1;}
    bool operator < (const bignum &x,const bignum &y)   {if(x.negative!=y.negative)return x.negative;if(x.s.size()!=y.s.size()) return (x.s.size()<y.s.size())^x.negative;for(int i=x.s.size()-1;i>=0;i--)if(x.s[i]!=y.s[i])return (x.s[i]<y.s[i])^x.negative;return false;}
    bool operator > (const bignum &x,const bignum &y)   {return y<x;}
    bool operator <= (const bignum &x,const bignum &y)  {return !(y<x);}
    bool operator >= (const bignum &x,const bignum &y)  {return !(x<y);}
    bool operator == (const bignum &x,const bignum &y)  {if(x.negative!=y.negative||x.s.size()!=y.s.size())return false;for(int i=x.s.size()-1;i>=0;i--)if(x.s[i]!=y.s[i])return false;return true;}
    bool operator != (const bignum &x,const bignum &y)  {return !(x==y);}
    static bignum plus(const bignum &x,const bignum &y)
    {
        bignum ANS;
        ANS.s.resize(max(x.s.size(),y.s.size())+1);
        short tag=0;
        for(unsigned int i=0;i<ANS.s.size();i++)
        {
            ANS.s[i]=tag;
            if(i<x.s.size()) ANS.s[i]+=x.s[i];
            if(i<y.s.size()) ANS.s[i]+=y.s[i];
            tag=(ANS.s[i]>=bit_pow[bit]);
            ANS.s[i]-=bit_pow[bit]*tag;
        }
        ANS.del();
        return ANS;
    }
    static bignum minus(const bignum &x,const bignum &y)
    {
        bignum ANS;
        ANS.s.resize(max(x.s.size(),y.s.size()));
        short tag=0;
        for(unsigned int i=0;i<ANS.s.size();i++)
        {
            ANS.s[i]=tag;
            if(i<x.s.size()) ANS.s[i]+=x.s[i];
            if(i<y.s.size()) ANS.s[i]-=y.s[i];
            tag=-(ANS.s[i]<0);
            ANS.s[i]-=bit_pow[bit]*tag;
        }
        ANS.del();
        return ANS; 
    }
    bignum operator + (const bignum &x,const bignum &y)
    {
        bignum ANS;
        if(x.negative==y.negative)
            ANS=plus(x,y),ANS.negative=x.negative;
        else 
            ANS=minus(max(abs(x),abs(y)),min(abs(x),abs(y))),ANS.negative=(x.negative&&abs(x)>abs(y))||(!x.negative&&abs(y)>abs(x));
        return ANS;
    }
    bignum operator - (const bignum &x,const bignum &y)
    {
        bignum ANS;
        if(x.negative!=y.negative)
            ANS=plus(x,y),ANS.negative=x.negative;
        else 
            ANS=minus(max(abs(x),abs(y)),min(abs(x),abs(y))),ANS.negative=(x.negative&&abs(x)>abs(y))||(!x.negative&&abs(y)>abs(x));
        return ANS;
    }
    bignum operator * (const bignum &x,const bignum &y)
    {
        bignum ANS;
        ANS.s.resize(x.s.size()+y.s.size());
        ANS.negative=x.negative^y.negative;
        for(unsigned int i=0;i<ANS.s.size();i++)
            ANS.s[i]=0;
        for(unsigned int i=0;i<x.s.size();i++)
        {
            for(unsigned int j=0;j<y.s.size();j++)
            {
                ANS.s[i+j]+=x.s[i]*y.s[j];
                ANS.s[i+j+1]+=ANS.s[i+j]/bit_pow[bit];
                ANS.s[i+j]%=bit_pow[bit];
            }
        }
        ANS.del();
        return ANS;
    }
    bignum operator / (const bignum &x,const ll &y)
    {
        bignum ANS;
        ANS.s.resize(x.s.size());
        ANS.negative=(x.negative)^(y<0);
        ll rest=0;
        for(int i=x.s.size()-1;i>=0;i--)
        {
            rest=rest*bit_pow[bit]+x.s[i];
            ANS.s[i]=rest/y;
            rest%=y;
        }
        ANS.del();
        return ANS;
    }
    bignum operator % (const bignum &x,const ll &y)
    {
        ll rest=0;
        for(int i=x.s.size()-1;i>=0;i--)
        {
            rest=rest*bit_pow[bit]+x.s[i];
            rest%=y;
        }
        return x.negative?-rest:rest;
    }
    bignum operator += (bignum &x,const bignum &y)  {return x=x+y;}
    bignum operator -= (bignum &x,const bignum &y)  {return x=x-y;}
    bignum operator *= (bignum &x,const bignum &y)  {return x=x*y;}
    bignum operator /= (bignum &x,const ll &y)      {return x=x/y;}
    bignum operator %= (bignum &x,const ll &y)      {return x=x%y;}
    #ifdef _GLIBCXX_IOSTREAM
    istream& operator >> (istream& in,bignum &x)  {x.input();return in;}
    ostream& operator << (ostream& out,bignum x)  {x.output();return out;}
    #endif
    inline void read(bignum &x)                     {x.input();}
    inline void write(bignum x)                     {x.output();}
    bignum abs(const bignum &x)         {return x.negative?-x:x;}
    namespace EX_DIVMOD
    {
        bool bignum_Compare(int l,int r,vector<Type> x,vector<Type> y)
        {
            if((l-r+1)!=(int)y.size()) return (l-r+1)>(int)y.size();
            for(int i=l;i>=r;i--)
                if(x[i]!=y[i-r])
                    return x[i]>y[i-r];
            return true;
        }
    #if bit==1
        bignum operator / (bignum x,const bignum &y)
        {
            int l=x.s.size()-1,r=x.size()-y.s.size();
            if(r<0) return 0;
            bignum ANS;
            ANS.s.resize(r+1);
            ANS.negative=x.negative^y.negative;
            while(r>=0)
            {
                while(bignum_Compare(l,r,x.s,y.s))
                {
                    for(int i=r;i-r<y.s.size()&&i<=l-(l-r==y.s.size());i++)
                    {
                        x.s[i]-=y.s[i-r];
                        x.s[i+1]-=(x.s[i]<0);
                        x.s[i]+=bit_pow[bit]*(x.s[i]<0);
                    }
                    while(!x.s[l]&&l>0) l--;
                    ANS.s[r]++;
                }
                r--;
            }
            ANS.del();
            return ANS;
        }
        bignum operator % (bignum x,const bignum &y)
        {
            int l=x.s.size()-1,r=x.size()-y.s.size();
            while(r>=0)
            {
                while(bignum_Compare(l,r,x.s,y.s)==1)
                {
                    for(int i=r;i-r<y.s.size()&&i<=l-(l-r==y.s.size());i++)
                    {
                        x.s[i]-=y.s[i-r];
                        x.s[i+1]-=(x.s[i]<0);
                        x.s[i]+=bit_pow[bit]*(x.s[i]<0);
                    }
                    while(!x.s[l]&&l>0) l--;
                }
                r--;
            }
            x.del();
            return x;
        }
    #else
        bignum operator / (bignum x,const bignum &y)
        {
            int l=x.s.size()-1,r=x.s.size()-y.s.size();
            if(r<0) return 0;
            bignum ANS;
            ANS.s.resize(r+1);
            ANS.negative=x.negative^y.negative;
            while(r>=0)
            {
                Type L=0,R=bit_pow[bit],ans=0;
                while(L<=R)
                {
                    Type MID=(L+R)>>1;
                    if(bignum_Compare(l,r,x.s,(y*MID).s)) ans=MID,L=MID+1;
                    else R=MID-1;
                }
                bignum z=y*ans;
                for(int i=r;i-r<z.size()&&i<=l-(l-r==z.size());i++)
                {
                    x.s[i]-=z.s[i-r];
                    x.s[i+1]-=(x.s[i]<0);
                    x.s[i]+=bit_pow[bit]*(x.s[i]<0);
                }
                while(!x.s[l]&&l>0) l--;
                ANS.s[r--]=ans;
            }
            ANS.del();
            return ANS;
        }
        bignum operator % (bignum x,const bignum &y)
        {
            int l=x.s.size()-1,r=x.s.size()-y.s.size();
            while(r>=0)
            {
                Type L=0,R=bit_pow[bit],ans=0;
                while(L<=R)
                {
                    Type MID=(L+R)>>1;
                    if(bignum_Compare(l,r,x.s,(y*MID).s)) ans=MID,L=MID+1;
                    else R=MID-1;
                }
                bignum z=y*ans;
                for(int i=r;i-r<z.size()&&i<=l-(l-r==z.size());i++)
                {
                    x.s[i]-=z.s[i-r];
                    x.s[i+1]-=(x.s[i]<0);
                    x.s[i]+=bit_pow[bit]*(x.s[i]<0);
                }
                while(!x.s[l]&&l>0) l--;
                r--;
            }
            x.del();
            return x;
        }
    #endif
        bignum operator /= (bignum &x,const bignum &y)    {return x=x/y;}
        bignum operator %= (bignum &x,const bignum &y)    {return x=x%y;}
    }
    using namespace EX_DIVMOD;
    namespace EX_NTTMUL
    {
    #if bit==1
        const int mod=998244353;
        const int g=3;
        const int ginv=332748118;
        int relength(int x)
        {
            int length=1;
            while(length<=x) length<<=1;
            return length;
        }
        int ksm(int x,int y,int ans=1)
        {
            while(y>0){if(y&1)ans=(ll)ans*x%mod;x=1ll*x*x%mod;y>>=1;}
            return ans;
        }
        void rev(vector<Type> &A,int length)
        {
            for(int i=1,j=length>>1;i<length-1;i++)
            {
                if(i<j) swap(A[i],A[j]);
                int k=length>>1;
                while(j>=k)j-=k,k>>=1;
                j|=k;
            }
        }
        void NTT(vector<Type> &A,int length,int opt)
        {
            rev(A,length);
            for(int i=1;i<length;i<<=1)
            {
                ll wn=ksm(opt==1?g:ginv,(mod-1)/(i<<1));
                for(int j=0;j<length;j+=(i<<1))
                {
                    ll w=1;
                    for(int k=j;k<j+i;k++,w=w*wn%mod)
                    {
                        Type x=A[k];
                        Type y=w*A[k+i]%mod;
                        A[k]=(x+y)%mod;
                        A[k+i]=(x-y+mod)%mod;
                    }
                }
            }
        }
        bignum nttmul(bignum A,bignum B)
        {
            A.negative^=B.negative;
            int length=relength(A.size()+B.size());
            int linv=ksm(length,mod-2);
            A.s.resize(length);B.s.resize(length);
            NTT(A.s,length,1);NTT(B.s,length,1);
            for(int i=0;i<length;i++)
                A.s[i]=(1ll*A.s[i]*B.s[i]%mod*linv)%mod;
            NTT(A.s,length,-1);
            for(int i=0;i<length-1;i++)
            {
                A.s[i+1]+=(A.s[i]/bit_pow[bit]);
                A.s[i]%=bit_pow[bit];
            }
            A.del();
            return A;
        }
    #endif
    }
    using namespace EX_NTTMUL;
}
using namespace Bignum;
int n;
bignum a=2,b=6,c=2; 
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) {
        a=c;
        b=2*a+2;
        c=b;
    }
    cout<<a<<endl;

}