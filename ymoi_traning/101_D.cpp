#include<cstdio>
#include<cstdlib>
const int MAGIC=19260817;
typedef long long ll;
struct Node{
    ll key;
    ll value;
    Node* next;
    Node(){
        next=NULL;
    }
};
struct Hash{
    Node* a;
    Node* data;
    Hash(){
        a=(Node*)calloc(19260817,sizeof(Node));
    }
    inline int _f(ll key){
        return (key%MAGIC+MAGIC)%MAGIC;
    }
    ll& operator[](ll key){
        int hash = _f(key);
        Node* last;
        if(!a[hash].next){
            last=&a[hash];
        }else{
            for(Node* p=a[hash].next;p;p=p->next){
                if(p->key==key){
                    return p->value;
                }
                if(!p->next){
                    last=p;
                }
            }
        }
        last->next=new Node;
        last->next->key=key;
        return last->next->value;
    }
};
int main(){
    int n;scanf("%d",&n);
    Hash s;
    int op;ll key,value;
    while(n--){
        scanf("%d%lld",&op,&key);
        if(op==1){
            scanf("%lld",&value);
            s[key]=value;
        }else if(op==2){
            printf("%lld\n",s[key]);
        }
    }
    return 0;
}