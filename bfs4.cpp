#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>
#include<algorithm>
const int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
struct Node{
    int status[5][5];
    int pos[2];
    std::string step;
};
int permu2int(int x[][5],int n){
    int p[15];
    int cnt = 1;
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            p[cnt++] = x[i][j];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        int x = 0;
        for(int j = i+1;j<=n;j++){
            if(p[j]<p[i])x++;
        }
        ans+=x*fact[n-i];
    }
    return ans+1;
}
bool vis[362880 + 10];
const int opv[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
//3*opv[0] + opv[1]
const char opc[4] = {'r','l','d','u'};
typedef std::queue<Node> queue;
bool cando(int op,int* pos){
    if(op == 0){
        //r
        return pos[1]!=3;
    }
    if(op == 1){
        //l
        return pos[1]!=1;
    }
    if(op == 2){
        //d
        return pos[0]!=3;
    }
    if(op == 3){
        //u
        return pos[0]!=1;
    }
}
std::string bfs(Node start){
    queue q;
    q.push(start);
    while(!q.empty()){
        Node tmp = q.front();
        q.pop();
        int permuID = permu2int(tmp.status,9);
        if(permuID == 1){
            return tmp.step;
        }
        if(vis[permuID]){
            continue;
        }
        Node next;
        for(int i = 0;i<4;i++){
            memcpy(next.status,tmp.status,sizeof(tmp.status));
            if(!cando(i,tmp.pos))continue;
            next.pos[0] = tmp.pos[0] + opv[i][0];
            next.pos[1] = tmp.pos[1] + opv[i][1];
            std::swap(next.status[tmp.pos[0]][tmp.pos[1]],next.status[next.pos[0]][next.pos[1]]);
            next.step.push_back(opc[i]);
            q.push(next);
            vis[permu2int(next.status,9)] = 1;
        }
    }
    return "unsolvable";
}
int main(){
    Node st;
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            char s[5];
            scanf("%s",s);
            if(s[0] == 'x'){
                st.status[i][j] = 9;
                st.pos[0] = i;
                st.pos[1] = j;
            }else{
                st.status[i][j] = s[0] - '0';
            }
        }
    }
    st.step = "";
    printf("%s\n",bfs(st).c_str());
    return 0;
}