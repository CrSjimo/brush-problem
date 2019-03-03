#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main(){
    char s[400005];
    while(scanf("%s",s)!=EOF){
        // scanf("%s",s);
        int len = strlen(s);
        for(int i=0;i<len;i++){
            bool is = true;
            for(int j = 0;j<i+1;j++){
                if(s[j]!=s[len-i-1+j]) is = false;
            }
            if(is)printf("%d ",i+1);
        }
     }
    return 0;
}