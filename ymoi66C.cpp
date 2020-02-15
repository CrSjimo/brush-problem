#include<cstdio>
#include<cstdlib>
char s[250];
bool v[250];
inline int find1(int i){
    int p=i-1;
    while(v[p])p--;
    return p;
}
inline int find2(int i){
    int p = i+1;
    while(v[p])p++;
    return p;
}
int main(){
    int n;
    scanf("%s",s+1);
    s[0]='0';
    scanf("%d",&n);
    int i;
    while(n>0){
        for(i=1;s[i];i++){
            if(v[i])continue;
            if(s[i]>s[i+1]){
                n--;
                for(int j=i;s[j];j++){
                    s[j]=s[j+1];
                }
                goto a;
            }
        }
        a:;
    }
    for(i=1;s[i];i++){
        if(s[i]!='0')break;
    }
    for(;s[i];i++){
        printf("%c",s[i]);
    }
    return 0;
}