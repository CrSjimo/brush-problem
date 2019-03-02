#include <iostream>
#include <cstdio>
#include <cstring>
int main(){
    char s[1010];
    gets(s);
    int cnt=1;
    for(int i=0;i<strlen(s);i++){
        if(s[i]==s[i+1])
            cnt++;
        else{
            printf("%d%c",cnt,s[i]);
            cnt=1;
        }
    }
    return 0;
}