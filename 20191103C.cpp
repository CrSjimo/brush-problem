#include<stdio.h>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
#include<stdlib.h>
struct Step{
    int x,y,d;
    bool operator==(const Step& p1)const{
        return p1.x==x&&p1.y==y&&p1.d==d;
    }
    bool operator<(const Step& p1)const{
        if(x==p1.x){
            if(y==p1.y){
                return d>p1.d;
            }
            return y<p1.y;
        }
        return x<p1.x;
    }
};
typedef std::vector< std::vector<int> > Status;
typedef std::vector<Step> Path;
void resize(Status status){
    status.resize(5);
    for(int i = 0;i<4;i++){
        status[i].resize(7);
    }
}
Path bestPath;
bool cmp(Path p1,Path p2){
    int i = 0;
    for(;i<p1.size()&&p1[i]==p2[i];i++){
    }
    return p1[i]<p2[i];
}
int n;
void dfs(Status status,Path path){
    if(path.size()==n){
        if(path<bestPath){
            bestPath=path;
        }
        return;
    }
    for(int i = 0;i<4;i++){
        for(int j = 0;j<6;j++){
            if(status[i][j]==0)continue;
            if(1<=i){
                
            }
        }
    }
}
bool noRes=1;
void dfs1(std::vector<int> row,Path pth){
    if(pth.size()==n){
        if(noRes||pth<bestPath){
            bestPath=pth;
            noRes=0;
        }
        return;
    }
    for(int i=0;i<5;i++){
        if(row[i]==0)continue;
        if(i>=1){
            std::vector<int> nxtR1 = row;
            Path nP1 = pth;
            std::swap(nxtR1[i],nxtR1[i-1]);
            bool bigflag=0;
            for(int k=0;k<3;i++){
                if(nxtR1[k]==0)continue;
                bool flag=1;
                for(int j=k;j<3;j++){
                    if(nxtR1[j]!=nxtR1[k])flag=0;
                }
                if(flag){
                    bigflag=1;
                    for(int j=k;j<3;j++){
                        nxtR1[j]=0;
                    }
                }
            }
            if(bigflag){
                Step s;
                s.x=i;
                s.y=0;
                s.d=-1;
                nP1.push_back(s);
                dfs1(nxtR1,nP1);
            }
        }
        if(i<=3){
            std::vector<int> nxtR1 = row;
            Path nP1 = pth;
            std::swap(nxtR1[i],nxtR1[i+1]);
            bool bigflag=0;
            for(int k=0;k<3;i++){
                if(nxtR1[k]==0)continue;
                bool flag=1;
                for(int j=k;j<3;j++){
                    if(nxtR1[j]!=nxtR1[k])flag=0;
                }
                if(flag){
                    bigflag=1;
                    for(int j=k;j<3;j++){
                        nxtR1[j]=0;
                    }
                }
            }
            if(bigflag){
                Step s;
                s.x=i;
                s.y=0;
                s.d=1;
                nP1.push_back(s);
                dfs1(nxtR1,nP1);
            }
        }
    }
}
std::vector<int> row(5);
#include<stdio.h>
int n;
int main(){
    scanf("%d",&n);
    for(int i = 0;i<5;i++){
        int k;
        while(~scanf("%d",&k)&&k!=0){
            
        }
        
    }
    printf("-1\n");
    return 0;
}