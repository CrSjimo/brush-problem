#include<stdio.h>
#include<algorithm>
#include<functional>
int odd[20],even[20];
int ocnt = 0,ecnt = 0;
int main(){
    for(int i = 0;i<10;i++){
        int n;
        scanf("%d",&n);
        if(n%2){
            odd[ocnt++] = n;
        }else{
            even[ecnt++] = n;
        }
    }
    std::sort(odd,odd+ocnt,std::greater<int>());
    std::sort(even,even+ecnt);
    for(int i = 0;i<ocnt;i++){
        printf("%d ",odd[i]);
    }
    for(int i = 0;i<ecnt;i++){
        printf("%d ",even[i]);
    }
    return 0;
}