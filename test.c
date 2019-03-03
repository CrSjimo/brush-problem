#include <stdio.h>
#include <string.h>
#define MAXN 1010
char text[MAXN];
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
			f[i+1] = f[j] + 1;
		}
	}
}

int find(char* s1,char* s2,int* f,int* index){
	int ans = 0;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	getFail(s2,f);
	int j = 0;
	for(int i = 0;i < len1;i++){
		while(j && s1[i] != s2[j]){
			j = f[j];
		}
		if(s1[i] == s2[j]){
			j++;
		}
		if(j == len2){
			index[ans++] = i - len2 + 1;
		}
	}
	return ans;
}

int main(){
	scanf("%s%s",text,pattern);
	int index[MAXN];
	int ans1 = find(text,pattern,fail,index);
    int ans2 = find(pattern,text,fail,index);
	printf("%s%s%s\n",ans1?pattern:(ans2?text:""),(ans1||ans2)?" is substring of ":"No substring",ans1?text:(ans2?pattern:""));
	// for(int i = 0;i < ans;i++){
	// 	printf("%d ",index[i]);
	// }
	return 0;
}
