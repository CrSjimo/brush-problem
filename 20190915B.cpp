#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<utility>
#include<algorithm>
#include<iostream>
#include<set>
#include<string>
bool var[200];
const bool FLAG_F = true,FLAG_E = false;
const int ERR_TIME = -1;
typedef std::pair<int,int> ret;
int lnCnt;
char On[20];
int on;
struct Line{
    bool flag;
    char variable;
    int start;
    int end;
    bool haveTime(){
        return this->end-this->start>1000;
    }
    bool canReach(){
        // printf("testc: var:%c end:%d,start:%d\n",this->variable,this->end,this->start);
        return this->end-this->start>=0;
    }
    void setVar(){
        var[this->variable] = 1;
    }
    bool usedVar(){
        return var[this->variable];
    }
};
Line code[1010];
int parse(int& lnId){
    int time = 0;
    int canReach;
    if(code[lnId].haveTime())time = 1;
    canReach = code[lnId].canReach()?1:0;
    if(code[lnId].usedVar()){
        return ERR_TIME;
    }
    code[lnId].setVar();
    char varname = code[lnId].variable;
    lnId++;
    int deltaTime = 0;
    while(lnId<=lnCnt){
        if(code[lnId].flag == FLAG_E){
            var[varname] = 0;
            lnId++;
            // printf("test: var:%c time:%d dTime:%d can:%d\n",varname,time,deltaTime,canReach);
            return time+deltaTime*canReach;
        }else{
            int res = parse(lnId);
            if(res == ERR_TIME){
                return ERR_TIME;
            }
            deltaTime = std::max(deltaTime,res);
        }
    }
    return ERR_TIME;
}
int parseOn(char* cod){
    char code[20];
    strcpy(code,cod);
    int len = strlen(code);
    code[len-1] = 0;
    len--;
    char* pos = code+2;
    if(*pos == '1'){
        return 0;
    }
    pos+=2;
    return atoi(pos);
}
int main(){
    int cas;
    scanf("%d",&cas);
    while(cas--){
        memset(var,0,sizeof(var));
        scanf("%d %s\n",&lnCnt,On);
        on = parseOn(On);
        for(int i = 1;i<=lnCnt;i++){
            Line ln;
            char flag[10];
            scanf("%s",flag);
            ln.flag = (flag[0]=='F');
            if(ln.flag){
                char st[10];
                char ed[10];
                char varname[10];
                scanf("%s%s%s",varname,st,ed);
                ln.variable = varname[0];
                if(st[0]=='n'){
                    ln.start = 10000;
                }else{
                    ln.start = atoi(st);
                }
                if(ed[0]=='n'){
                    ln.end = 10000;
                }else{
                    ln.end = atoi(ed);
                }
            }
            code[i] = ln;
        }
        // for(int i = 1;i<=lnCnt;i++){
        //     if(code[i].flag == 1){
        //         printf("F %s %d %d\n",code[i].variable,code[i].start,code[i].end);
        //     }else{
        //         printf("E\n");
        //     }
        // }
        int start = 0;
        code[0].flag = FLAG_F;
        code[0].variable = '2';
        code[0].start = 1;
        code[0].end = 2;
        lnCnt++;
        code[lnCnt].flag = FLAG_E;
        int res = parse(start);
        if(res == -1||start!=lnCnt+1){
            printf("ERR\n");
        }else if(res == on){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}