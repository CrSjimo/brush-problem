#include<stdio.h>
#include<iostream>
#include<string>
#include<limits.h>
#include<vector>
#include<algorithm>
using namespace std;
int pwr10[10] = {0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
struct bigint{
    vector<int> digit;
    bigint& operator=(bigint& bi2){
        digit = bi2.digit;
        return *this;
    }
    bigint& operator=(string& s){
        reverse(s.begin(),s.end());
        int v = 0;
        for(int i=0;i<s.size();i++){
            int d = s[i]-'0';
            v+=d*pwr10[i%10];
            if(i%10==9){
                digit.push_back(v);
                v=0;
            }
        }
        if(v!=0){
            digit.push_back(v);
        }
        return *this;
    }
    bool equals0(){
        bool flag = 0;
        for(int i = 0;i<digit.size();i++){
            flag=flag||digit[i];
            if(flag)return false;
        }
        return true;
    }
    string toString(){
        string s;
        for(int i = digit.size()-1;i>=0;i++){
            s+=to_string(digit[i]);
        }
        return s;
    }
};
istream& operator>>(istream& ccin,bigint& bi){
    string s;
    ccin>>s;
    bi = s;
    return ccin;
}
ostream& operator<<(ostream& ccout,bigint& bi){
    return ccout<<bi.toString();
}
int n,m;
int a_i[110];
bigint a[110];
inline int pwr(int x,int k){
    int ans = 1;
    while(k--){
        ans*=x;
    }
    return ans;
}
int into(int x){
    int ans = 0;
    for(int i=0;i<=n;i++){
        ans+=pwr(x,i)*a_i[i];
    }
    return ans;
}
int main(){
    int mode = 0;
    scanf("%d%d",&n,&m);
    if(n>2)mode = 1;
    for(int i = 0;i<=n;i++){
        string s;
        if(mode==1){
            cin>>a[i];
            cout<<a[i];
        }
        else
            cin>>a_i[i];
        
    }
    vector<int> sol;
    if(mode == 0){
        int ans=0;
        for(int i = 1;i<=m;i++){
            if(into(i)==0){
                ans++;
                sol.push_back(i);
            }
        }
        printf("%d\n",ans);
        for(int i=0;i<sol.size();i++){
            printf("%d\n",sol[i]);
        }
    }
    return 0;
}