#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAXN 1000005
int fail[MAXN];
void getFail(char* s2,int* f){
	int len2 = strlen(s2);
	f[0] = f[1] = 0;
	for(int i = 1;i < len2;i++){
		int j = f[i];
		while(s2[i] != s2[j] && j){
			j = f[j];
		}
		if(s2[i] == s2[j]){
			f[i+1] = j + 1;
		}
	}
}

char s[MAXN];
int ans[MAXN];

int main(){
    while(scanf("%s",s)!=EOF){
        getFail(s,fail);
        int len = strlen(s);
        int cnt=0;
        fail[0] = -1;
        int k = fail[len-1];
        while(k!=-1){
            if(s[k]==s[len-1])ans[cnt++]=k+1;
            k=fail[k];
        }
        for(int i=0;i<cnt;i++){
            printf("%d ",ans[cnt-i-1]);
        }
        printf("%d ",len);
     }
    return 0;
}