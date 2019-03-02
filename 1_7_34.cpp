#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isRev(string s){
    string s2=s;
    reverse(s.begin(),s.end());
    if(s==s2){
        return true;
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    for(int i=1;i<s.size();i++){
        for(int j=0;j<s.size()-i;j++){
            string x=s.substr(j,i+1);
            if(isRev(x)){
                cout<<x<<endl;
            }
        }
    }
    return 0;
}
