#include<cstdio>
#include<cstdlib>
const int MOD = 998244353;
typedef long long ll;
int n,m,q;
ll* a;
struct Node{
	ll sum;
	ll tag;
}* tree;
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
void push_up(int o){
	tree[o].sum=(tree[lc].sum+tree[rc].sum)%MOD;
}
void build(int o,int l,int r){
	tree[o].tag = 1;
	if(l==r){
		tree[o].sum = a[l];
		return;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	push_up(o);
}
void push_down(int o){
	(tree[lc].tag *= tree[o].tag)%=MOD;
	(tree[rc].tag *= tree[o].tag)%=MOD;
	(tree[lc].sum *= tree[o].tag)%=MOD;
	(tree[rc].sum *= tree[o].tag)%=MOD;
	tree[o].tag = 1;
}
void update1(int o,int l,int r,int p,ll v){
	if(l==r){
		tree[o].sum+=v;
	}else{
		push_down(o);
		if(p<=mid)update1(lc,l,mid,p,v);
		else update1(rc,mid+1,r,p,v);
		push_up(o);
	}
}
void update2(ll v){
	(tree[1].sum*=v)%=MOD;
	(tree[1].tag*=v)%=MOD;
	push_down(1);
}
ll query(int o,int l,int r,int p){
	if(l==r)return tree[o].sum;
	push_down(o);
	if(p<=mid)return query(lc,l,mid,p);
	else return query(rc,mid+1,r,p);
}
struct Func{
	int type;
	int* b;
}* func;
void call_sub1(const Func& f){
	if(f.type==1){
		(a[f.b[1]]+=f.b[2])%=MOD;;
	}else if(f.type==2){
		for(int i=1;i<=n;i++){
			(a[i]*=f.b[1])%=MOD;
		}
	}else if(f.type==3){
		for(int i=1;i<=f.b[0];i++){
			call_sub1(func[f.b[i]]);
		}
	}
}
int maxexec_1 = 0;
int maxexec_2 = 0;
bool vis[350000];
bool isTree = true;
void call_sub2(const Func& f){
	if(f.type==1){
        maxexec_1++;
		update1(1,1,n,f.b[1],f.b[2]);
	}else if(f.type==2){
        maxexec_2++;
		update2(f.b[1]);
	}else if(f.type==3){
		for(int i=1;i<=f.b[0];i++){
            if(isTree){
                if(vis[f.b[i]])isTree = false;
                else vis[f.b[i]]=true;
            }
			call_sub2(func[f.b[i]]);
            vis[f.b[i]]=false;
		}
	}
}
void sub1(){
	for(int i=1;i<=q;i++){
		int fi;scanf("%d",&fi);
		call_sub1(func[fi]);
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",a[i]);
	}
	printf("\n");
}
void sub2(){
	tree = (Node*)calloc((n+1)*4,sizeof(Node));
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int fi;scanf("%d",&fi);
		call_sub2(func[fi]);
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",query(1,1,n,i));
	}
	printf("\n");
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	a=(ll*)malloc((n+1)*sizeof(ll));
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
	}
	scanf("%d",&m);
    //int sigmacj = 0;
	func=(Func*)calloc((m+1),sizeof(Func));
	for(int i=1;i<=m;i++){
		scanf("%d",&func[i].type);
		if(func[i].type==1){
			func[i].b=new int[3];
			scanf("%d%d",&func[i].b[1],&func[i].b[2]);
		}else if(func[i].type==2){
			func[i].b=new int[2];
			scanf("%d",&func[i].b[1]);
		}else{
			int cj;scanf("%d",&cj);
            //sigmacj+=cj;
			func[i].b=new int[cj+1];
			func[i].b[0]=cj;
			for(int j=1;j<=cj;j++){
				scanf("%d",&func[i].b[j]);
			}
		}
	}
    //fprintf(stderr,"%d\n",sigmacj);
	scanf("%d",&q);
	if(n<=1500)sub1();
	else sub2();
    fprintf(stderr,"%d %d %d\n",maxexec_1,maxexec_2,isTree);
	return 0;
}