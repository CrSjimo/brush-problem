#include <cstdio>
using namespace std;
int arr[110][110];
int n;
bool check(){
    int result=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1)result++;
        }
        // printf("t:%d\n",result);
        if(result%2==0){
            result=0;
        }else{
            return false;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[j][i]==1)result++;
        }
        if(result%2==0){
            result=0;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&arr[i][j]);
    if(check())printf("%s","OK");
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=(arr[i][j]==0)?1:0;
                if(check()){
                    printf("%d %d",i+1,j+1);
                    return 0;
                }
                else arr[i][j]=(arr[i][j]==0)?1:0;
            }
        }
    }
    printf("%s","Corrupt");
    return 0;
}