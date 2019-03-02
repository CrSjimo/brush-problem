#include <cstdio>
#include <cstring>
using namespace std;
char str1[1010],str2[1010];
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
bool isSubStr(char substr[],char str[]){
    int sublen=strlen(substr),
        len=strlen(str);
    for(int i=0;i<len;i++){
        if(str[i]==substr[0]){
            for(int j=0;j<sublen;j++){
                if(str[i+j]==substr[j]){
                    continue;
                }else{
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}
void strMoveLeft(char s[]){
    char firstChar=s[0];
    int i=0;
    for(;i<strlen(s)-1;i++){
        s[i]=s[i+1];
    }
    s[i]=firstChar;
}
int main(){
    scanf("%s%s",str1,str2);
    for(int i=0;i<strlen(str1);i++){
        strMoveLeft(str1);
        if(isSubStr(str2,str1)){
            printf("true\n");
            return 0;
        }
    }
    for(int i=0;i<strlen(str2);i++){
        strMoveLeft(str2);
        if(isSubStr(str1,str2)){
            printf("true\n");
            return 0;
        }
    }
        
    // else if(isSubStr(str2,str1)){
    //     printf("%s%s%s",str2," is substring of ",str1);
    // }else{
    //     printf("No substring");
    // }
    printf("false\n");
    return 0;
}