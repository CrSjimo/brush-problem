#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int a[5];
bool used[5];
int ans[100];
int newAns[100];
int totl = 0;
void sort(int* arr,int* brr){
    int len = brr-arr;
    for(int i = 0;i<len;i++){
        int minPos = i;
        for(int j = i;j<len;j++){
            minPos = arr[j]<arr[minPos]?j:minPos;
        }
        int tmp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = tmp;
    }
}
void dfs(int i){
    if(i == 4){
        totl++;
        ans[totl] = ans[totl-1];
        return;
    }
    for(int j = 0;j<4;j++){
        if(!i && !a[j])continue;
        if(!used[j]){
            used[j] = 1;
            ans[totl] = a[j] + ans[totl]*10;
            dfs(i+1);
            ans[totl] /= 10;
            used[j] = 0;
        }
    }


}
bool diyici = 1;
int main(){
    //别pe了😭
    //freopen('./a.txt','r',stdin);
    // freopen("./a.txt","w",stdout);
    while(~scanf("%d%d%d%d",a,a+1,a+2,a+3) && (*a || a[1] || a[2] || a[3])){
        if(!diyici){
            printf("\n");
        }
        diyici = 0;
        dfs(0);
        // for(int i = 8;i < totl+8;i++){
        //     ans[i-8] = ans[i];
        // }
        sort(ans,ans+totl);
        int pos = 0;
        for(int i = 0;i<totl;i++){
            bool isOK = 1;
            for(int j = 0;j<i;j++){
                if(ans[j] == ans[i]){
                    isOK = 0;
                    break;
                }
            }
            if(isOK){
                newAns[pos++] = ans[i];
            }

        }
        int currentQianwei = newAns[0]/1000;
        for(int i = 0;i<pos;i++){
            if(newAns[i]/1000 != currentQianwei){
                printf("\n");
                currentQianwei = newAns[i]/1000;
            }
            printf("%d",newAns[i]);
            if(newAns[i+1]/1000 == currentQianwei)printf(" ");

        }
        printf("\n");
        memset(ans,0,sizeof(ans));
        memset(used,0,sizeof(used));
        memset(newAns,0,sizeof(newAns));
        totl = 0;
    }
    return 0;
}