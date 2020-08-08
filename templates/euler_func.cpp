int* phi;

void euler_func(int x){
    phi[1]=1;
    for(int i=2;i<=x;i++){
        if(!phi[i]){
            for(int j=i;j<=x;j+=i){
                if(!phi[j])phi[j]=j;
                phi[j]=phi[j]*(i-1)/i;
            }
        }
    }
}