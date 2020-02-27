#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
inline int getv(int j,const string& s){
    if(j<s.size()&&s[j]!='#')return s[j]-'A'+1;
    else return 0;
}
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int u=getv(i,s);
        int v1j=1+i*2,v2j=2+i*2;
        int v1=getv(v1j,s);
        int v2=getv(v2j,s);
        if((!v1)!=(!v2)){
            // printf("t:%c %c\n",v1-1+'A',v2-1+'A');
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}