#include<stdio.h>
#include<string>
#include<stdlib.h>
typedef std::string string;
int strscanf(const char* format,string& s){
    char ss[1010];
    int r = scanf(format,ss);
    s = ss;
    return r;
}
int strprintf(const char* format,string& s){
    return printf(format,s.c_str());
}
struct Node{
    string s;
    int len;
    Node(){}
    Node(string s,int len){
        this->s = s;
        this->len = len;
    }
};
string s;
Node digui(int i){
    string ss = "";
    char numStr[3]={0,0,0};
    int j;
    for(j = i;s[j]!='|';j++){
        numStr[j-i] = s[j];
    }
    int num = atoi(numStr);
    for(j++;s[j]!=']';j++){
        if(s[j]!='['){
            ss+=s[j];
        }else{
            Node n = digui(j+1);
            j += (n.len+1);
            ss+=n.s;
        }
    }
    string sss = "";
    for(int i = 0;i<num;i++){
        sss+=ss;
    }
    return Node(sss,j-i);
}
int main(){
    strscanf("%s",s);
    s = "[1|"+s+"]";
    string ss = digui(1).s;
    strprintf("%s\n",ss);
    return 0;
}