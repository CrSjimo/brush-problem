#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
bool used[10][10];
struct Node{
    int x;
    int y;
    int dist;
};
const int op[8][2] = {
    {1,2},{2,1},
    {-1,2},{-2,1},
    {-1,-2},{-2,-1},
    {-1,2},{-2,-2}
};
int main(){
    return 0;
}