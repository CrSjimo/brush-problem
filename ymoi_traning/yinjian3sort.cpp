#include <iostream>
#include <algorithm>
#include<functional>
#include<cstdlib>
#include<ctime>
#include<cstdio>

#define dayadan 0

template<typename T>
    class NumContainer
    {
        public:
            T num;
    };

class Node:public NumContainer<int>
{
    public:
    bool operator>=(const Node& operand)const
    {
        return num>=operand.num;
    }
}a[3];

class FastIO{
    public:
    template<typename T>
        FastIO& operator<<(T x)
        {
            char c[21],len=0;
            if(!x){
                putchar('0');
                return *this;
            }
                
            if(x<0)
            {
                x=-x;
                putchar('-');
            }
            while(x)
            {
                c[++len]=x%10;
                x/=10;
            }
            while(len)
                putchar(c[len--]+48);
        }
    template<typename T>
        FastIO& operator>>(T& x)
        {
            int res=0;
            char c=getchar(),f=1;
            while(c<48||c>57)
            {
                if(c=='-')f=0;
                c=getchar();
            }
            while(c>=48&&c<=57)
            {
                res=(res<<3)+(res<<1)+(c&15);
                c=getchar();
            }
            x= f?res:-res;
            return *this;
        }
} io;

// using std::sort;
using std::cin;
using std::cout;
using std::greater_equal;
using std::swap;

const int n=3;

template<typename _Compare,typename T> bool cmp(const T&a,const T&b)
{
    _Compare* _greater_Compare=new _Compare ();
    return (*_greater_Compare)(a,b);
}

template<typename T>
void sort(T* first,T* last,bool (*comp)(const T&,const T&)){
    srand((unsigned)time(NULL));
    while(true){
        for(T* p=first;p<last;p++){
            swap(*p,*(first+rand()%(last-first)));
        }
        bool flag=true;
        for(T* p=first;p<last-1;p++){
            if(!comp(*p,*(p+1)))flag=false;
        }
        if(flag==true)break;
    }
}

int main()
{
    for(int i=0;i<n;i++)
        io>>a[i].num;
    sort(a,a+3,cmp<greater_equal<Node>,Node>);
    for(int i=0;i<n;i++){
        io<<a[i].num;
        putchar(' ');
    }
    return dayadan;
}