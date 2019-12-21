#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
struct Node{
    int l_dir;
    std::string name;
};
std::vector< Node > list;
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    list.resize(n+5);
    for(int i = 0;i<n;i++){
        int face;
        scanf("%d",&face);
        std::cin>>list[i].name;
        if(face==0){
            list[i].l_dir=-1;
        }else{
            list[i].l_dir=1;
        }
    }
    int ans_id = 0;
    while(m--){
        int dir,s;
        scanf("%d%d",&dir,&s);
        if(dir==0){
            ans_id = (ans_id+n+s*list[ans_id].l_dir)%n;
        }else{
            ans_id = (ans_id+n-s*list[ans_id].l_dir)%n;
        }
    }
    std::cout<<list[ans_id].name<<"\n";
    return 0;
}