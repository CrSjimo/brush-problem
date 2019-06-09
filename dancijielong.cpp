#include<stdio.h>
#include<string.h>
char strList[30][1010];
int a[30][30];
/*str1 接 str2 從哪開始接 */
int preproc(char* str1,char* str2){
    int len1 = strlen(str1),len2 = strlen(str2);
    bool cando = true;
    int i2 = 0;
    for(int j = len1-1;j>=0;j--){
        for(int i1 = j;i1<len1;i1++){
            if(str1[i1]!=str2[i2++]){
                cando = false;
                goto finish;
            }
        }
        finish:
        if(cando)return len1 - j;
        cando = true;
        i2 = 0;
    }
    return 0;
}
int ans = -1;
int curId = 0;
int n;
void dfs(int id){

}
int main(){
    char c;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%s",strList[i]);
    }
    scanf("%s",&c);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            a[i][j] = preproc(strList[i],strList[j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}