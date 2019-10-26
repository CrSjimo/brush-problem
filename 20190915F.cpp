struct Node{
    int id;
    Node* next;
    Node* at(int pos){
        Node* n = this;
        while(pos--){
            n = n->next;
        }
        return n;
    }
    void rm(int pos){
        Node* pre = at(pos-1);
        Node* nxt = at(pos+1);
        pre->next = nxt;
    }
};
#include<stdio.h>
#include<vector>
std::vector< std::vector< Node > > rows;
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    rows.resize(n+10);
    for(int i = 0;i<=n+5;i++){
        rows[i].resize(m+5);
    }
    Node* ndd = &rows[0][m];
    for(int i = 1;i<=n;i++){
        Node* nd = &rows[i][0];
        for(int j = 1;j<=m-1;j++){
            nd = nd->next = &rows[i][j];
            nd->id = (i-1)*m+j;
        }
        ndd = ndd->next = &rows[i][m];
        ndd->id = i*m;
    }
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=m-1;j++){
    //         printf("%d ",rows[i][0].at(j)->id);
    //     }
    //     printf("%d\n",rows[0][m].at(i)->id);
    // }
    while(q--){
        int i,j;
        scanf("%d%d",&i,&j);
        if(j!=m){
            Node* leave = rows[i][0].at(j);
            printf("%d\n",leave->id);
            rows[i][0].rm(j);
            rows[i][0].at(m-2)->next = rows[0][m].at(i);
            rows[0][m].rm(i);
            rows[0][m].at(n-1)->next = leave;
        }else{
            Node* leave = rows[0][m].at(i);
            printf("%d\n",leave->id);
            rows[0][m].rm(i);
            rows[0][m].at(n-1)->next = leave;
        }
    }
    return 0;
}
