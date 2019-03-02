#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char str[1010];
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
    getLine(str);
    bool isSpaceBefore=false;
    int i=0,j=0;
    for(;i<strlen(str);i++){
        if(str[i]==' '&&isSpaceBefore==true){

        }else if(str[i]==' '&&isSpaceBefore==false){
           isSpaceBefore=true;
           newstr[j++]=str[i];
        }else{
            isSpaceBefore=false;
            newstr[j++]=str[i];
        }
    }
    newstr[j]='\0';
    printf("%s",newstr);
    // system("PAUSE");
    return 0;
}