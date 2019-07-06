#include<stdio.h>
int arr[30010];
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
void init(int len){
    while(len--){
        arr[len] = len;
    }
}
/*
                           鸡你太美
                          鸡你实在太美
                           鸡你是太美
                              鸡你太美
                         实在是太美鸡你
               鸡你 实在是太美鸡你  美
            鸡你  实在是太美鸡美   太美
        鸡你     实在是太美鸡美      太美        
    鸡你       实在是太美鸡美          太美
  鸡你       鸡你实在是美太美       美蓝球球
鸡 鸡       鸡你实在是太美          篮球篮球球
鸡            鸡你太美裆鸡太啊         蓝篮球
                鸡你太美裆裆鸡美
                  鸡你美裆    裆鸡美
                   鸡太美         鸡太美
                     鸡美              鸡美
                     鸡美                鸡美
                      鸡美                鸡美
                      鸡太                鸡太
                    金 猴                金猴
                    皮 鞋                皮鞋金猴
                     金光                金光 大道
                    大道
 */
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m) && (n || m)){
        init(n);
        for(int i = 0;i<m;i++){
            int len,alias;
            scanf("%d%d",&len,&alias);
            for(int j = 0;j<len-1;j++){
                int k;
                scanf("%d",&k);
                update(k,alias);
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(query(0) == query(i))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}