#include<bits/stdc++.h>
#define N 5000200
#define inf 1ll<<50
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int n, m, s, t;
int head[N], cur[N], pos;
struct edge {
    int to, next, c;
} e[N << 1];
void add(int a, int b, int c) {
    pos++;
    e[pos].to = b, e[pos].c = c, e[pos].next = head[a], head[a] = pos;
}
void insert(int a, int b, int c) {
    add(a, b, c);
    add(b, a, 0);
}
queue<int> Q;
bool vis[N];
int d[N];
bool bfs() {
    while (!Q.empty()) Q.pop();
    for (int i = 1; i <= n; i++) d[i] = -1, vis[i] = 0;
    vis[s] = 1, d[s] = 0, Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].to;
            if (vis[v] || e[i].c <= 0)
                continue;
            vis[v] = 1, d[v] = d[u] + 1, Q.push(v);
            if (v == t)
                return 1;
        }
    }
    return vis[t];
}
long long dfs(int u, long long a) {
    if (u == t || !a)
        return a;
    long long flow = 0, f;
    for (int &i = cur[u]; i != -1; i = e[i].next) {
        int v = e[i].to;
        if (d[v] == d[u] + 1 && (f = dfs(v, min(0ll+e[i].c,a))) > 0) {
            flow += f, a -= f;
            e[i].c -= f, e[i ^ 1].c += f;
            if (!a)
                break;
        }
    }
    return flow;
}
long long dinic() {
    long long ret = 0;
    while (bfs()) {
        for (int i = 1; i <= n; i++) cur[i] = head[i];
        ret += dfs(s, inf);
    }
    return ret;
}
void init() {
    pos = -1;
    memset(head, -1, sizeof(head));
}
int main() {
    init();
    n = read(), m = read(), s = read(), t = read();
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read(), c = read();
        insert(x, y, c);
    }
    printf("%lld\n", dinic());
}