#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int main(){
    string s,s1,s2;
    getline(cin,s,',');
    getline(cin,s1,',');
    getline(cin,s2);
    int s1Pos=s.find_first_of(s1)+s1.size(),
        s2Pos=s.find_last_of(s2),
        distance=s2Pos-s1Pos-1;
    if(s1Pos==string::npos||distance<0){
        distance=-1;
    }
    printf("%d",distance);
    return 0;
}
