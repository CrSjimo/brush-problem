#include<stdio.h>
#include"./moban_mergesort.cpp"
int arr[16]={5,3,42,34,6,5,81,33,54,6,11,45,76,47,35,24};
int main(){
    a=arr;
    merge_sort(0,15);
    for(int i=0;i<16;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}