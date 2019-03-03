#include <stdio.h>
#include <string.h>
#define MAXN 1000005
// char text[MAXN];
char pattern[MAXN];
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

int main(){
    int cnt=0;
    int n;
	while(~scanf("%d",&n) && n!=0){
        scanf("%s",pattern);
        printf("Test case #%d\n",++cnt);
        getFail(pattern,fail);
        // int n = strlen(pattern);
        for(int i = 0;i<=n;i++){
            int x = i-fail[i];
            if(x==0||i%x||i/x==1)continue;
	        printf("%d %d\n",i,i/x);
        }
        memset(fail,0,sizeof fail);
        printf("\n");
    }
	return 0;
}
