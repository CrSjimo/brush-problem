#include<stdio.h>
#include<math.h>
// #include<vector>
int arr[1010];
int query(int i){
    if(arr[i] == i)
        return i;
    return arr[i] = query(arr[i]);
}
void update(int i,int j){
    int aliasI = query(i);
    int aliasJ = query(j);
    arr[aliasI] = aliasJ;
}
int n,d;
double calc(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}
int cd[1010][2];
bool canReach(int a,int b){
    return calc(cd[a][0],cd[a][1],cd[b][0],cd[b][1])<=d;
}
bool oed[1010];
void init(int len){
    while(len--){
        arr[len] = len;
    }
}
int main(){
    scanf("%d%d",&n,&d);
    init(n);
    for(int i = 1;i<=n;i++){
        scanf("%d%d",cd[i],cd[i]+1);
    }
    char op[5];
    while(~scanf("%s",op)){
        if(op[0] == 'O'){
            int x;
            scanf("%d",&x);
            oed[x] = 1;
            for(int i = 1;i<=n;i++){
                if(i!=x && oed[i] && canReach(x,i)){
                    // printf("test: %d %d\n",x,i);
                    update(x,i);
                }
            }
        }else{
            int a,b;
            scanf("%d%d",&a,&b);
            printf(query(a)==query(b)?"SUCCESS\n":"FAIL\n");
        }
    }
    return 0;
}