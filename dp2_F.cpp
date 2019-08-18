#include<stdio.h>
#include<string.h>
#include<map>
std::map<int,int> m;
int main(){
    int n;
    while(~scanf("%d",&n)){
        int t;
        int r = (n+1)/2;
        m.clear();
        for(int i = 0;i<n;i++){
            int x;
            scanf("%d",&x);
            m[x]++;
            if(m[x]>=r){
                t = x;
            }
        }
        printf("%d\n",t);
    }
}