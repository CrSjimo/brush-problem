#include<stdio.h>
#include<string.h>
#include<algorithm>
struct Node{
    char name[30];
    int val;
    bool operator<(const Node& a)const{
        if(a.val == this->val){
            return strcmp(this->name,a.name)<0;
        }
        return a.val<this->val;
    }
    void print(){
        printf("%s %d\n",this->name,this->val);
    }
    void scan(){
        scanf("%s%d",this->name,&this->val);
    }
} arr[20];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        arr[i].scan();
    }
    std::sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        arr[i].print();
    }
    return 0;
}