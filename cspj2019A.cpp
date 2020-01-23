#include<stdio.h>
char s[8];
int main(){
    int ans = 0;
    scanf("%s",s);
    for(int i=0;i<8;i++)ans+=(s[i]-'0');
    printf("%d\n",ans);
    return 0;
}