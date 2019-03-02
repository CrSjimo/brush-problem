#include <cstdio>
using namespace std;
int main(){
    int m,n;
	int result=0;
    scanf("%d%d",&m,&n);
	int arr[1010][1010];
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)scanf("%d",&arr[i][j]);
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			if(i==0||i==m-1||j==0||j==n-1)
				result+=arr[i][j];
	printf("%d",result);
	return 0;
}