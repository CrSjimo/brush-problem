#include <cstdio>
#include <cstring>
using namespace std;
bool isEndWith(char str[],char substr[]){
    int len=strlen(str),
        sublen=strlen(substr);
    for(int i=0;-i<sublen;i--){
        if(substr[sublen-1+i]==str[len-1+i]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}
int main(){
    char str[1010];
    scanf("%s",&str);
    int len=strlen(str);
    if(isEndWith(str,"er")||isEndWith(str,"ly")){
        str[len-1]=str[len-2]=0;
    }else if(isEndWith(str,"ing")){
        str[len-1]=str[len-2]=str[len-3]=0;
    }
    printf(str);
    return 0;
}