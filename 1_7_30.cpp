#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int maxLen=0;
    char s1[1010],s2[1010];
    scanf("%s%s",s1,s2);
    int len1=strlen(s1),
        len2=strlen(s2);
    for(int i=0;i<max(len1,len2);i++){
        for(int j=0;j<min(len1,len2);j++){
            if(s1[(len1+i)%len1]==s2[(len2+j)%len1]){
                bool jump=true;
                for(int k=0;jump&&k<min(len1,len2);k++){
                    int cnt=0;
                    if(s1[(len1+i+k)%len1]==s2[(len2+j+k)%len1])
                        cnt++;
                    else
                        jump=false;
                    if(cnt>maxLen) maxLen=cnt;
                }
            }
        }
    }
    printf("%d",maxLen);
    return 0;
}