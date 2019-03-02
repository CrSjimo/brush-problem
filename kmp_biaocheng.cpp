#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int nxt[1000001];
char a[1000001];//模式串 ，从1开始存储 
char b[1000001];//文本串，从1开始存储 
int main()
{

	b[0] = 1;
	cin >> (b + 1);
	cin >> (a + 1);
	int i = 0, j = 1;
	while(a[j] != '\0')
	{
		while(i && a[i + 1] != a[j + 1])
			i = nxt[i];
		if(a[i + 1] == a[j + 1])
			++i;
		nxt[j + 1] = i;
		++j;
	}
	i = 0, j = 0;
	while(b[j] != '\0')
	{
		while(i != 0 && a[i + 1] != b[j + 1])
			i = nxt[i];
		if(a[i + 1] == b[j + 1])
			++i;
		if(a[i + 1] == '\0')
		{
			cout << j - i + 2 << endl;
			i = nxt[i];
		}
		++j;
	}
	for(int i = 1; a[i]; ++i)
		cout << nxt[i] << ' ';
	cout << endl;
	return 0;
}