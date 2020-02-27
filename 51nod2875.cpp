#include<cstdio>
#include<cstdlib>
#include<string>
using std::string;
#include<iostream>
using std::cin;
using std::cout;
int f[30];
int find(int i){
    if(f[i]==i)return i;
    else return f[i]=find(f[i]);
}
inline void update(int i,int j){
    f[find(i)]=find(j);
}
inline void init(){
    for(int i=1;i<=26;i++){
        f[i]=i;
    }
}
int ind[30],outd[30];
int main(){
    init();
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int u=s[0]-'a'+1,v=s[s.size()-1]-'a'+1;
        update(u,v);
        outd[u]++,ind[v]++;
    }
    int cnt=0,cnt1=0,cnt2=0;
    for(int i=1;i<=26;i++){
        if((ind[i]||outd[i]) && find(i)==i || abs(ind[i]-outd[i])>1){
            cnt++;
        }
        if(ind[i]>outd[i])cnt1++;
        else if(ind[i]<outd[i])cnt2++;
        if(cnt>1||cnt1>1||cnt2>1){
            printf("The door cannot be opened.\n");
            return 0;
        }
    }
    if(cnt1!=cnt2){
        printf("The door cannot be opened.\n");
        return 0;
    }
    printf("Ordering is possible.\n");
    return 0;
}