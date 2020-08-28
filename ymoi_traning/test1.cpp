#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 20000 + 10;

inline int read()
{
	int res=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	if(f==-1)
		while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)-(ch^48),ch=getchar();
	else 
		while(ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+(ch^48),ch=getchar();
	return res;
}

struct edge{
	int next,to,w;
}r[N<<1];

int head[N],tot;

void add(int u,int v,int w)
{
	r[++tot]=(edge){head[u],v,w};
	head[u]=tot;
}

int n,Q;

int a[N],w[N],fa[N],son[N],size[N],top[N],id[N],dep[N],cnt;

void dfs1(int u,int father)
{
	dep[u]=dep[father]+1,fa[u]=father,size[u]=1;
	for(int e=head[u];e;e=r[e].next)
	{
		int v=r[e].to;
		if(v==father)continue;
		a[v]=r[e].w;
		dfs1(v,u);
		size[u]+=size[v];
		if(size[v]>size[son[u]])
			son[u]=v;
	}
}

void dfs2(int u,int topf)
{
	id[u]=++cnt;
	w[cnt]=a[u];
	top[u]=topf;
	if(!son[u])return ;
	dfs2(son[u],topf);
	for(int e=head[u];e;e=r[e].next)
	{
		int v=r[e].to;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}

struct Tree{
	int sum,maxn,minn,lazy;
}tree[N<<2];
#define lson pos<<1
#define rson pos<<1|1
void pushup(int pos)
{
	tree[pos].sum=tree[lson].sum+tree[rson].sum;
	tree[pos].maxn=max(tree[lson].maxn,tree[rson].maxn);
	tree[pos].minn=min(tree[lson].minn,tree[rson].minn);
}

void pushdown(int pos)
{
	if(tree[pos].lazy==1)return ;
	tree[lson].lazy*=-1,tree[rson].lazy*=-1;
	tree[lson].sum*=-1,tree[rson].sum*=-1;
	int lmax=tree[lson].maxn,lmin=tree[lson].minn,rmax=tree[rson].maxn,rmin=tree[rson].minn;
	tree[lson].maxn=-lmin,tree[lson].minn=-lmax;
	tree[rson].maxn=-rmin,tree[rson].minn=-rmax;
	tree[pos].lazy=1;
}

void build(int pos,int l,int r)
{
	tree[pos].lazy=1;
	if(l==r)
	{
		tree[pos].sum=tree[pos].maxn=tree[pos].minn=w[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(pos);
}

void change1(int pos,int l,int r,int x,int k)
{
	if(l>x||r<x)return ;
	if(l==x&&r==x)
	{
		tree[pos].sum=tree[pos].maxn=tree[pos].minn=k;
		return ;
	}
	pushdown(pos);
	int mid=(l+r)>>1;
	change1(lson,l,mid,x,k);
	change1(rson,mid+1,r,x,k);
	pushup(pos);
}

void change2(int pos,int l,int r,int L,int R)
{
	if(l>R||r<L)return ;
	if(l>=L&&r<=R)
	{
		tree[pos].lazy*=-1;
		tree[pos].sum*=-1;
		int maxn=tree[pos].maxn,minn=tree[pos].minn;
		tree[pos].maxn=-minn,tree[pos].minn=-maxn;
		return ;
	}
	pushdown(pos);
	int mid=(l+r)>>1;
	change2(lson,l,mid,L,R);
	change2(rson,mid+1,r,L,R);
	pushup(pos);
}

Tree query(int pos,int l,int r,int L,int R)
{
	if(l>=L&&r<=R)
		return tree[pos];
	pushdown(pos);
	int mid=(l+r)>>1;
	if(R<=mid)return query(lson,l,mid,L,R);
	if(L>mid)return query(rson,mid+1,r,L,R);
	Tree t,t1=query(lson,l,mid,L,R),t2=query(rson,mid+1,r,L,R);
	t.sum=t1.sum+t2.sum;
	t.maxn=max(t1.maxn,t2.maxn);
	t.minn=min(t1.minn,t2.minn);
	return t;
	
}
#undef lson
#undef rson
void Tchange(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		change2(1,1,n,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	if(x!=y)
		change2(1,1,n,id[x]+1,id[y]);
}

Tree Tquery(int x,int y)
{
	Tree t,t1;
	t.sum=0,t.maxn=-1010,t.minn=1010;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		t1=query(1,1,n,id[top[x]],id[x]);
		t.sum+=t1.sum;
		t.maxn=max(t.maxn,t1.maxn);
		t.minn=min(t.minn,t1.minn);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])
		swap(x,y);
	if(x!=y)
	{
		t1=query(1,1,n,id[x]+1,id[y]);
		t.sum+=t1.sum;
		t.maxn=max(t.maxn,t1.maxn);
		t.minn=min(t.minn,t1.minn);		
	}
	return t;
}

string opt;
struct Edge2{
    int u,v,val;
    Edge2(){}
    Edge2(int u,int v,int val){
        this->u=u;
        this->v=v;
        this->val=val;
    }
};

vector<Edge2> li;

int main()
{
	n=read();
	int u,v,w;
	for(int i=1;i<n;i++)
		u=read()+1,v=read()+1,w=read(),add(u,v,w),add(v,u,w),li.push_back(Edge2(u,v,w));
	dfs1(1,0),dfs2(1,1),build(1,1,n);
	Q=read();
	while(Q--)
	{
		cin>>opt;
		if(opt=="C")
		{
			u=read()+1,w=read();
			change1(1,1,n,id[u],w);
		}
		if(opt=="N")
		{
			u=read()+1,v=read()+1;
			Tchange(u,v);
		}
		if(opt=="SUM")
		{
			u=read()+1,v=read()+1;
			printf("%d\n",Tquery(u,v).sum);
		}
		if(opt=="MIN")
		{
			u=read()+1,v=read()+1;
			printf("%d\n",Tquery(u,v).minn);
		}
		if(opt=="MAX")
		{
			u=read()+1,v=read()+1;
			printf("%d\n",Tquery(u,v).maxn);
		}
        // for(int i=0;i<n-1;i++){
        //     printf("t: %d %d %d w=%d\n",Q,li[i].u,li[i].v,Tquery(li[i].u,li[i].v).sum);
        // }
	}
    return 0;
}