#include<stdio.h>
#include<algorithm>
struct Node{
    int a,tot;
    int id;
    bool operator<(const Node& n)const{
        if(n.tot == tot){
            if(n.a == a){
                return id<n.id;
            }
            return n.a<a;
        }
        return n.tot<tot;
    }
    void scan(int i){
        int tmp1,tmp2;
        scanf("%d%d%d",&a,&tmp1,&tmp2);
        tot = a+tmp1+tmp2;
        id = i;
    }
    void print(){
        printf("%d %d\n",id,tot);
    }
} arr[310];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        arr[i].scan(i+1);
    }
    std::sort(arr,arr+n);
    for(int i = 0;i<5;i++){
        arr[i].print();
    }
    return 0;
}