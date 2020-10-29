#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>
using std::lower_bound;
using std::map;
using std::vector;
int getint() {
    int x = 0, k = 1;
    int c = 1919810;
    while (!isdigit(c)) {
        c = getchar();
        if (c == '-')
            k = -1;
    }
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * k;
}
void _putint(int x, bool t) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x == 0 && t)
        return;
    _putint(x / 10, 1);
    putchar(x % 10 + '0');
}
void putint(int x) { _putint(x, 0); }
const int MAXN = 1e7 + 10;
const int MOD = 1e9 + 7;
bool not_prime[MAXN];
int prime[MAXN];
int tot = 0;
int fac[MAXN];
map<int, int> dec_t;

void eulerSieve(int x) {
    for (int i = 2; i <= x; i++) {
        if (!not_prime[i])
            prime[++tot] = i, fac[i]=i;
        for (int j = 1; j <= tot && i * prime[j] <= x; j++) {
            not_prime[i * prime[j]] = true;
            fac[i* prime[j]]=prime[j];
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
int* a;
void dec(int i) {
    int p;
    while(i>1){
        dec_t[p=fac[i]]++;
        while(i%p==0)i/=p;
    }
}
int main() {
    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);
    not_prime[1] = true;
    eulerSieve(MAXN - 5);
    int n = getint(), m = getint();
    a = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        a[i] = getint();
        dec(a[i]);
        // fprintf(stderr,"test%d: ",a[i]);
        // for(int x:decomp[i]){
        //     fprintf(stderr,"%d ",x);
        //     if(a[i]%x)return 32;
        // }
        // fprintf(stderr,"\n");
    }
    // for(map<int,int>::iterator p=dec_t.begin();p!=dec_t.end();p++){
    //     printf("test: %d %d\n",p->first,p->second);
    // }
    while (m--) {
        int l = getint(), r = getint();
        int ans = 0;
        map<int, int>::iterator ls = dec_t.lower_bound(l);
        map<int, int>::iterator rs = dec_t.lower_bound(r);
        for (map<int, int>::iterator p = ls;p!=dec_t.end(); p++) {
            if (p->first >= l && p->first <= r) {
                ans += (p->second);
                ans %= MOD;
            }
            if (p == rs)
                break;
        }
        putint(ans);
        putchar('\n');
    }
    return 0;
}
