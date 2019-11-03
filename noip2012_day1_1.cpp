#include<stdio.h>
#include<string.h>
char k[110];
char c[1010];
char caps[1010];
//char cap[1010];
int main(){
    scanf("%s%s",k,c);
    int klen=strlen(k);
    int clen=strlen(c);
    for(int i = 0;i<clen;i++){
        if(c[i]>='A'&&c[i]<='Z')caps[i]='A';
        else caps[i]='a';

        if(c[i]>='A'&&c[i]<='Z')c[i]=c[i]-'A'+'a';
    }
    for(int i=0;i<klen;i++){
        if(k[i]>='A'&&k[i]<='Z')k[i]=k[i]-'A'+'a';
    }
    for(int i=0;i<clen;i++){
        char key = k[i%klen];
        c[i]=(c[i]-key+26)%26+caps[i];
        //printf("%d ",c[i]);
    }
    printf("%s\n",c);
}