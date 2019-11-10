#include<stdio.h>
int tab[5][5]={
         /*0  1  2  3  4*/
    /*0*/{ 0,-1, 1, 1,-1},
    /*1*/{ 1, 0,-1, 1,-1},
    /*2*/{-1, 1, 0,-1, 1},
    /*3*/{-1,-1, 1, 0, 1},
    /*4*/{ 1, 1,-1,-1, 0}
};
int seq1[250],seq2[250];
int main(){
    int n,l1,l2;
    int ans1=0,ans2=0;
    scanf("%d%d%d",&n,&l1,&l2);
    for(int i=0;i<l1;i++){
        scanf("%d",seq1+i);
    }
    for(int i=0;i<l2;i++){
        scanf("%d",seq2+i);
    }
    for(int i = 0;i<n;i++){
        int c1 = seq1[i%l1],c2 = seq2[i%l2];
        if(tab[c1][c2]==1){
            ans1++;
        }else if(tab[c1][c2]==-1){
            ans2++;
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}