#define BINGCHAJI
int query(int i,int* arr){
    if(arr[i] == i)
        return i;
    return arr[i] = query(arr[i],arr);
}
void update(int i,int j,int* arr){
    int aliasI = query(i,arr);
    int aliasJ = query(j,arr);
    arr[aliasI] = aliasJ;
}