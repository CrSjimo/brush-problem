const N=509,m=4;
let f;
function C(n,m){
	let ret=n,i;
	for(i=m;i>1;--i){
        ret*=--n;
        ret/=i;
    }
	return ret;
}
function init(){
    f=[];
    for(let i=0;i<=N;i++){
        f[i]=[]
        for(let j=0;j<=N;j++){
            f[i][j]=0;
        }
    }
}
function main(){
    for(let n=1;n<=50;n++){
        init();
        f[1][0]=1;//初值
        let i,j,k,mx;
        let a,ans;
        for(mx=1;mx<(n+1)>>1;++mx){//枚举限制
            for(a=j=0;j<m;++j)
                a+=f[mx][j];//预处理a
            for(i=n;i>mx;--i)//从大到小，防止重复计数
                for(j=1;j<=m;++j)
                    for(k=1;k<=j&&mx*k<i;++k)
                        f[i][j]+=f[i-mx*k][j-k]*C(a+k-1,k);
        }
        for(ans=j=0;j<=m;++j)
            ans+=f[n][j];
        if(!(n&1)){//特判双重心
            for(a=j=0;j<m;++j)
                a+=f[n>>1][j];
            ans+=C(++a,2);
        }
        console.log(n,ans);
    }
    return 0;
}