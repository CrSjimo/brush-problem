#include<stdio.h>
#include<algorithm>
struct Node{
    char id[10];
    int age;
    bool operator<(const Node& n)const{
        if(n.age>=60 && age<60){
            return 0;
        }else if(n.age<60 && age>=60){
            return 1;
        }else if(n.age>=60 && age>=60){
            return n.age<age;
        }else{
            return 0;
        }
    }
} arr[110];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s%d",&arr[i].id,&arr[i].age);
    }
    std::stable_sort(arr,arr+n);
    for(int i = 0;i<n;i++){
        printf("%s\n",arr[i].id);
    }
    return 0;
}