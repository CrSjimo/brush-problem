#include<cstdio>
using namespace std;
struct Node{
    int start;
    int end;
    bool deprecated;
};
Node b[200010];
int opc;
int tot = 0;
int k = 0;
int main(){
    scanf("%d",&opc);
    for(int i = 0;i<opc;i++){
        char opKey;
        char ops[5];
        scanf("%s",ops);
        opKey = ops[0];
        if(opKey == 'A'){
            int start,end;
            scanf("%d%d",&start,&end);
            int refusedCnt = 0;
            for(int j = 0;j<k;j++){
                if(b[j].deprecated)continue;
                if((b[j].start>=start && b[j].start<=end)||(b[j].end>=start && b[j].end<=end)){
                    tot--;
                    refusedCnt++;
                    b[j].deprecated = 1;
                }
            }
            b[k].start = start;
            b[k].end = end;
            k++;
            tot++;
            printf("%d\n",refusedCnt);
        }else{
            printf("%d\n",tot);
        }
    }
    return 0;
}