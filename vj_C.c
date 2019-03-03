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

// int find(char* s1,char* s2,int* f){
// 	int ans = 0;
// 	int len1 = strlen(s1);
// 	int len2 = strlen(s2);
// 	getFail(s2,f);
// 	int j = 0;
// 	for(int i = 0;i < len1;i++){
// 		while(j && s1[i] != s2[j]){
// 			j = f[j];
// 		}
// 		if(s1[i] == s2[j]){
// 			j++;
// 		}
// 		if(j == len2){
// 			ans++;
// 		}
// 	}
// 	return ans;
// }

int main(){
	while(~scanf("%s",pattern) && pattern[0]!='.'){
        getFail(pattern,fail);
        int n = strlen(pattern);
        int x = n-fail[n];
	    printf("%d\n",n%x?1:n/x);
        memset(fail,0,sizeof fail);
    }
	return 0;
}
