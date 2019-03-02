#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
string str[110];
bool minPrinted=false;
int lastMaxIndex;
int i=0,j=0;
int m=0;
int lens[1010];
string minstr,maxstr;
void each(){
    string max,min;
    for(int n=0;n<j;n++){
        if(lens[n]==m){
            if(!minPrinted){
                min=str[n];
                lastMaxIndex=n;
                return;
            }
        }
        max=str[lastMaxIndex];
    }
    maxstr=max;
}
int main(){
    char s[1010];
   	char c;
	int isEnd=scanf("%c",&c);
	while(c!='\n'&&isEnd!=-1){
        if(c==' '||c==','){
            s[i]=0;
            i=0;
            str[j++]=s;
        }else{
            s[i++]=c;
        }
		isEnd=scanf("%c",&c);
	}
    s[i]=0;
    i=0;
    str[j++]=s;
    for(int k=0;k<j;k++)lens[k]=str[k].size();
    for(;;m++){
        each();
    }
    cout<<maxstr<<endl<<minstr;
    return 0;
}