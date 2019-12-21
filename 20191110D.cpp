#include<stdio.h>
int n,m,k;
int C[2010][2010];
void init(){
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=0;i<=2000;i++){
        C[i][0]=1;
    }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%k;
        }
    }
}    
int main(){
    int t;
    scanf("%d%d",&t,&k);
    init();
    while(t--){
        int ans = 0;
        scanf("%d%d",&n,&m);
        for(int i = 0;i<=n;i++){
            int mm = i<m?i:m;
            for(int j = 0;j<=mm;j++){
                if(C[i][j]==0){
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

                
        
