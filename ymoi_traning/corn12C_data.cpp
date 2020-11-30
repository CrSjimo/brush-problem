#include<cstdio>
#include<cstdlib>
#include<ctime>
int al[1005],bl[1005],cl[1005];
int main(){
    srand((unsigned)time(NULL));
    FILE* f1 = fopen("running.in","w");
    int n = rand()%100;
    int m = rand()%1000;
    fprintf(f1,"%d %d\n",n,m);
    int n2=0;
    for(int i=1;i<=n;i++){
        int a=rand()%100,b=rand()%1000,c=rand()%100;
        fprintf(f1,"%d %d %d\n",a,b,c);
        al[i]=a,bl[i]=b,cl[i]=c;n2+=c;
    }
    printf("%d %d\n",n2,m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cl[i];j++){
            printf("%d %d\n",al[i],bl[i]);
        }
    }
}