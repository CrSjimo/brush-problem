#include<cstdio>
#include<cstdlib>
int** a;
int main(){
    int p;scanf("%d",&p);
    int n = 1<<p;
    a = (int**)malloc((n+1)*sizeof(int*));
    for(int** i=a;i<=a+n;i++)*i=(int*)malloc((n+1)*sizeof(int));
    a[0][0]=1;
    for(int k=1,m=1;k<=p;k++,m<<=1){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                a[i][j+m]=a[i][j]+m;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                a[i+m][j]=a[i][j+m];
                a[i+m][j+m]=a[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}