#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>
#include<algorithm>
#include<iostream>
const int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
struct Node{
    int status[15];
    int pos;
    std::string step;
};
int permu2int(int* p,int n){
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
bool cando(int op,int pos){
    if(op == 0){
        //r
        return !(pos == 3 || pos == 6 || pos == 9);
    }
    if(op == 1){
        //l
        return !(pos == 1 || pos ==4 || pos == 7);
    }
    if(op == 2){
        //d
        return !(pos == 7 || pos == 8 || pos == 9);
    }
    if(op == 3){
        //u
        return !(pos ==1 || pos == 2 || pos == 3);
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
            next.pos = tmp.pos + 3*opv[i][0] + opv[i][1];
            std::swap(next.status[tmp.pos],next.status[next.pos]);
            next.step.push_back(opc[i]);
            q.push(next);
        }
    }
    return "unsolvable";
}
int main(){
    Node st;
    for(int i = 1;i<=9;i++){
        char s[5];
        scanf("%s",s);
        if(s[0] == 'x'){
            st.status[i] = 9;
            st.pos = i;
        }else{
            st.status[i] = s[0] - '0';
        }
    }
    st.step = "";
    std::cout << bfs(st) << '\n';
    return 0;
}