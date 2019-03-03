
#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1000010
using namespace std;
int nxt[MAXN];
char s[MAXN];
int get_nxt(char *s,int n)
{
	nxt[1]=0;
	for(int i=2;i<=n;i++)
	{
		int j=nxt[i-1];
		while(j&&s[j+1]!=s[i]) j=nxt[j];
		if(s[j+1]==s[i]) j++;
		nxt[i]=j;
	}
	return 0;
}
int main()
{
	s[0]='#';
	while(scanf("%s",s+1)!=EOF)
	{
		int n=strlen(s)-1;
		if(n==1&&s[1]=='.') break;
		get_nxt(s,n);int k=n-nxt[n];
        printf("%d %d ",n,k);
		if(n%k) printf("1\n");
		else printf("%d\n",n/k);
	}
	return 0;
}