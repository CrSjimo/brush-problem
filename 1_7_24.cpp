#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void getLine(char s[]){
	char c;
	int isEnd=scanf("%c",&c);
	int i=0;
	while(c!='\n'&&isEnd!=-1){
		s[i]=c;
		i++;
		isEnd=scanf("%c",&c);
	}
	s[i]=0;
}
int main(){
    char newstr[1010];
    char str[1010];
    getLine(str);
    bool isSpaceBefore=false;
    int i=0,j=0;
    int len=0;
    for(;i<strlen(str);i++){
        if(str[i]==' '&&isSpaceBefore==true){
            
        }else if(str[i]==' '&&isSpaceBefore==false){
            printf("%d%c",len,',');
            len=0;
            isSpaceBefore=true;
            newstr[j++]=str[i];
        }else{
            len++;
            isSpaceBefore=false;
            newstr[j++]=str[i];
        }
    }
    printf("%d%c",len,'\n');
	return 0;
}