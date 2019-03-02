#include <cstdio>
#include <algorithm>
using namespace std;
int arr[5][5];
bool isRowMax(int val,int rowID){
    for(int i=0;i<5;i++){
        if(val<arr[rowID][i]){
            return false;
        }
    }
    return true;
}
bool isColMin(int val,int colID){
    for(int i=0;i<5;i++){
        if(val>arr[i][colID]){
            return false;
        }
    }
    return true;
}
int main(){
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)scanf("%d",&arr[i][j]);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(isRowMax(arr[i][j],i)&&isColMin(arr[i][j],j)){
                printf("%d %d %d",i+1,j+1,arr[i][j]);
                return 0;
            }
        }
    }
    printf("not found");
    return 0;
}