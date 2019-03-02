#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s1;
    cin>>s1;
    string s2=s1;
    reverse(s1.begin(),s1.end());
    if(s1==s2){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}
