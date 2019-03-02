#include <iostream>
#include <cstdio>
#include <cstring>
void toUpperCase(char str[]){
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]>='a'&&str[i]<='z')
            str[i]=str[i]-'a'+'A';
    }
}
int main(){
    char s[1010];
    gets(s);
    toUpperCase(s);
    int cnt=1;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==s[i+1])
            cnt++;
        else{
            printf("(%c,%d)",s[i],cnt);
            cnt=1;
        }
    }
    return 0;
}