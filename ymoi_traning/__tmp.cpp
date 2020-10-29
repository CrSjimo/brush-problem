#include<cstdio>
#include<string>
using std::string;
#include<iostream>
#include<cctype>
using std::cin;
int main(){
    string s;cin>>s;
    int flag=1;
    int a=0;
    int b=0;
    int le=1;
    int tmp=0;
    char unk;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        if(c=='+')flag=1;
        else if(c=='-')flag=-1;
        else if(isdigit(c)){
            tmp*=10;tmp+=c-'0';
        }else if(islower(c)){
            unk=c;
            if(le)a+=flag*tmp;
            else a-=flag*tmp;
            tmp=0;
            flag=1;
        }else if(c=='='){
            le=false;
            b+=flag*tmp;
            tmp=0;
            flag=1;
        }
    }
    b-=flag*tmp;
    printf("%c=%.3lf\n",unk,-1.0*b/a);
    return 0;
}