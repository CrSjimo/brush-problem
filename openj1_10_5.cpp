#include<stdio.h>
#include<algorithm>
struct Node{
    int id;
    int score;
    bool operator<(const Node& n)const{
        if(n.score == score){
            return id<n.id;
        }
        return n.score<score;
    }
    void scan(){
        scanf("%d%d",&id,&score);
    }
    void print(){
        printf("%d %d\n",id,score);
    }
} arr[5010];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    k = (int)(k*1.5);
    for(int i = 0;i<n;i++){
        arr[i].scan();
    }
    std::sort(arr,arr+n);
    int line = arr[k-1].score;
    int i = 0;
    for(;arr[i].score>=line;i++);
    printf("%d %d\n",line,i);
    for(int j = 0;j<i;j++){
        arr[j].print();
    }
    return 0;
}