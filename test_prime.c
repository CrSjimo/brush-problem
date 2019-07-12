#include<stdio.h>
#include<math.h>
int maxn;
int main(){
	scanf("%d",&maxn);
	for(int i = 2;i <= maxn;i++){
		for(int j = 2;j <= sqrt(i);j++){
			if(!(i%j)){
				goto notPrime;
			}
		}
		printf("%d ",i);
		notPrime:;
	}
    printf("\n");
	return 0;
}