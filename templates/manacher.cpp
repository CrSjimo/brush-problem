#include<cstdio>
#include<cstring>
#include<algorithm>
using std::max;
using std::min;
const int MAXN=1.1*1e7+7;
char _s[MAXN];
char s[2*MAXN];
int n=0;
int a[2*MAXN];
int manacher(){
    s[++n]='$';
    s[++n]='#';
    for(int i=1;_s[i];i++){
        s[++n]=_s[i];
        s[++n]='#';
    }
    int mid=0,r=0,ans=0;
    for(int i=1;i<=n;i++){
        a[i]=max(min(a[2*mid-i],r-i),0);
        while(s[i+a[i]]==s[i-a[i]])a[i]++;
        a[i]--;
        // printf("test %d %d\n",i,a[i]);
        ans=max(ans,a[i]);
        if(i+a[i]>r)r=i+a[i],mid=i;
        
    }
    return ans;
}
int main(){
    scanf("%s",_s+1);
    printf("%d\n",manacher());
    return 0;
}