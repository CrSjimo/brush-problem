#include<stdio.h>
#include<vector>
struct Node{
    int t;
    int v;
    bool used;
};
std::vector<Node> a;
inline bool canUse(Node& nd,int t,int v){
    if(nd.used)return false;
    if(nd.v<v)return false;
    nd.used=true;
    return true;
}
int ans = 0;
int head = 0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int w,v,t;
        scanf("%d%d%d",&w,&v,&t);
        if(w==0){
            ans+=v;
            a.push_back({t,v,false});
        }else{
            while(t-a[head].t>45&&head<a.size())head++;
            for(int i=head;i<a.size();i++){
                if(canUse(a[i],t,v))goto match;
            }
            ans+=v;
        }
        match:;
    }
    printf("%d\n",ans);
    return 0;
}