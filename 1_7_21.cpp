#include <cstdio>
#include <cstring>
void getLine(char s[]){
	char c;
	int isEnd=scanf("%c",&c);
	int i=0;
	while(c!='\n'&&isEnd!=-1){
		s[i++]=c;
		isEnd=scanf("%c",&c);
	}
	s[i]=0;
}
void strTrans(char s[],int startPos,int step){
    if(step>0){
        int i=startPos;
        for(;i<strlen(s)-1;i++){
            s[i]=s[i+step];
        }
        s[i]=0;
    }else if(step<0){
        int i=0;
        s[strlen(s)+1]=0;
        s[strlen(s)]=s[strlen(s)-1];
        for(;-i<strlen(s)-1-startPos;i--){
            s[strlen(s)-1+i]=s[strlen(s)-2+i];
        }
    }
}
void strReplace(char str[],char target[],char replacement[]){
    int sublen=strlen(target),
        len=strlen(str),
        replacementLen=strlen(replacement);
    int offset=replacementLen-sublen;
    bool result;
    for(int i=0;i<len;i++){
        if(str[i]==target[0]){
            //判断之前是否为空格
            if(i!=0){
                if(str[i-1]!=' '){
                    result=false;
                }
            }
            //判断是否为子串
            int j=0;
            for(;j<sublen;j++){
                if(str[i+j]==target[j]){
                    result=true;
                }else{
                    result=false;
                }
            }
            //判断之后是否为空格
            if(str[i+j]!=' '){
                result=false;
            }
            //result为真执行替换
            if(result){
                //移位
               strTrans(str,j+i-1,-offset);
               //替换
                for(int k=0;k<replacementLen;k++){
                    str[i+k]=replacement[k];
                }
            }
        }
        len=strlen(str);
    }
}
int main(){
    char c[1010],t[1010],r[1010];
    getLine(c);
    getLine(t);
    getLine(r);
    strReplace(c,t,r);
    printf(c);
    return 0;
}