#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
int arr[110];
struct Edge{
    int pre1;
    int pre2;
    int dist;
};
int query(int i){
    if(arr[i] == i){
        return i;
    }
    return arr[i] = query(arr[i]);
}
void update(int i,int j){
    int aliasI = query(i);
    int aliasJ = query(j);
    arr[aliasI] = aliasJ;
}
void init(int len){
    while(len--){
        arr[len] = len;
    }
}
Edge elist[5010];
bool cmp(Edge e1,Edge e2){
    return e1.dist < e2.dist;
}
int n;
int matrix[110][110];
int main(){
    while(~scanf("%d",&n) && n){
        memset(elist,0,sizeof(elist));
        memset(matrix,0x3f,sizeof(matrix));
        init(n+10);
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int tmp;
                scanf("%d",&tmp);
                if(i!=j){
                    matrix[i][j] = matrix[j][i] = tmp;
                }
            }
        }
        int m;
        scanf("%d",&m);
        for(int i = 0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            // matrix[a][b] = matrix[b][a] = 0x3f3f3f3f;
            update(a-1,b-1);
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]!=0x3f3f3f3f){
                    Edge e;
                    e.pre1 = i;
                    e.pre2 = j;
                    e.dist = matrix[i][j];
                    elist[cnt++] = e;
                    matrix[i][j] = matrix[j][i] = 0x3f3f3f3f;
                }
            }
        }
        std::sort(elist,elist+cnt,cmp);
        int ans = 0;
        for(int i = 0;i<cnt;i++){
            Edge e = elist[i];
            if(query(e.pre1) != query(e.pre2)){
                update(e.pre1,e.pre2);
                ans += e.dist;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}