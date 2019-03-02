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
    bool result;
    for(int i=0;i<len;i++){
        if(str[i]==substr[0]){
            for(int j=0;j<sublen;j++){
                if(str[i+j]==substr[j]){
                    result=true;
                }else{
                    result=false;
                }
            }
            if(result){
                return true;
            }
        }
    }
    return false;
}
int main(){
    scanf("%s%s",str1,str2);
    if(isSubStr(str1,str2)){
        printf("%s%s%s\n",str1," is substring of ",str2);
    }else if(isSubStr(str2,str1)){
        printf("%s%s%s\n",str2," is substring of ",str1);
    }else{
        printf("No substring\n");
    }
    return 0;
}