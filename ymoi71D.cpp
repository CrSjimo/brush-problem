// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>
// #include<iostream>
// #include<string>
// #include<deque>
// #include<algorithm>
// using std::deque;
// using std::max;
// using std::string;
// using std::cin;
// using std::cout;
// inline bool is_digit(char c){
//     return c>='0'&&c<='9';
// }
// char tmp[10];
// typedef int iint;
// string toString(iint v){
//     sprintf(tmp,"%d",v);
//     return tmp;
// }
// int r = 10000;
// struct BigInt{
//     BigInt(){}
//     BigInt(int x){
//         *this=x;
//     }
//     BigInt(string s){
//         *this=s;
//     }
//     BigInt& operator=(string& s){
//         while(s.size()%4){
//             s="0"+s;
//         }
//         size_t size=s.size();
//         this->num.resize(size/4);
//         for(int i = 0;i<size;i+=4){
//             string ss = s.substr(size-i-4,4);
//             num[i/4]=atoll(ss.c_str());
//         }
//     }
//     BigInt& operator=(BigInt bigint){
//         num=bigint.num;
//     }
//     void rm_zero(){
//         for(int i=num.size()-1;i>=0&&num[i]==0;i--){
//             num.pop_back();
//         }
//     }
//     string toStr(){
//         rm_zero();
//         if(num.size()==0)return "0";
//         string s = "";
//         for(int i=0;i<num.size();i++){		
//             s=toString(num[i])+s;
//         }
//         return s;
//     }
//     int cmp(const BigInt& bigint)const{
//         if(num.size()<bigint.num.size()){
//             return -1;
//         }else if(num.size()>bigint.num.size()){
//             return 1;
//         }else{
//             for(int i=num.size()-1;i>=0;i--){
//                 if(num[i]<bigint.num[i])return -1;
//                 else if(num[i]>bigint.num[i])return 1;
//             }
//         }
//         return 0;
//     }
//     bool operator<(const BigInt& bigint)const{
//         return cmp(bigint)<0;
//     }
//     BigInt operator+(BigInt& bigint){
// 		BigInt ans;
// 		size_t max_size=num.size()>bigint.num.size()?num.size():bigint.num.size();
// 		for(int i=0;i<max_size;i++){
// 			int da=i<num.size()?num[i]:0;
// 			int db=i<bigint.num.size()?bigint.num[i]:0;
// 			ans.num.resize(i+1);
// 			ans.num[i]+=(da+db);
// 			if(ans.num[i]>=r){
// 				ans.num.push_back(ans.num[i]/r);
// 				ans.num[i]%=r;
// 			}
			
// 		}
// 		ans.rm_zero();
// 		return ans;
// 	}
// 	BigInt operator*(int x){
// 		BigInt ans;
// 		for(int i=0;i<num.size();i++){
// 			int da=num[i];
// 			ans.num.resize(i+1);
// 			ans.num[i]+=da*x;
// 			if(ans.num[i]>=r){
// 				ans.num.push_back(ans.num[i]/r);
// 				ans.num[i]%=r;
// 			}
			
// 		}
// 		for(int i=num.size();i<ans.num.size();i++){
// 			if(ans.num[i]>=r){
// 				ans.num.push_back(ans.num[i]/r);
// 				ans.num[i]%=r;
// 			}
// 		}
// 		ans.rm_zero();
// 		return ans;
// 	}
// 	BigInt operator*(BigInt& bigint){
// 		BigInt ans;
// 		for(int i=0;i<bigint.num.size();i++){
// 			BigInt delta = this->operator*(bigint.num[i]);
// 			for(int k=0;k<i;k++){
// 				delta.num.push_front(0);
// 			}
// 			ans=ans+delta;
// 		}
// 		ans.rm_zero();
// 		return ans;
// 	}
//     std::deque<iint> num;
// };
// std::istream& operator>>(std::istream& mcin,BigInt& bigint){
//     std::string s;
//     mcin>>s;
//     bigint=s;
//     return mcin;
// }
// std::ostream& operator<<(std::ostream& mcout,BigInt bigint){
//     std::string s = bigint.toStr();
//     return mcout<<s;
// }
// typedef BigInt ll;
// ll dp[50][50];
// ll a[50][50];
// string s;
// int main(){
//     int n,m;
//     scanf("%d%d",&n,&m);
//     cin>>s;
//     s="a"+s;
//     for(int i=1;i<=n;i++){
//         //printf("t:%d\n",i);
//         for(int j=i;j<=n;j++){
//             a[i][j]=*new BigInt(s.substr(i,j-i+1));
//         }
//     }
//     for(int i=1;i<=n;i++){
//         dp[i][0]=a[1][i];
//     }
//     for(int k=1;k<=m;k++){
//         for(int j=k+1;j<=n;j++){
//             for(int i=k;i<j;i++){
//                 dp[j][k]=max(dp[i][k-1]*a[i+1][j],dp[j][k]);
//             }
//         }
//     }
//     cout<<dp[n][m]<<"\n";
//     return 0;
// }
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
int pow10[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
inline int seg(int i,std::vector<int> num){
	int ans = 0;
	for(int j=i;j<i+8&&j<num.size();j++){
		ans+=num[j]*pow10[j-i];
	}
	return ans;
}
inline bool is_digit(char c){
	return c>='0'&&c<='9';
}
int r = 10;
struct BigInt{
	BigInt(){
        num.reserve(50);
    }
	BigInt(int x){
        num.reserve(50);
		*this=x;
	}
	BigInt(const char* s){
        num.reserve(50);
		*this=s;
	}
	BigInt& operator=(const char* s){
		size_t size= strlen(s);
		for(int i = 0;i<size;i++){
			char c = s[size-i-1];
			if(is_digit(c)){
				num.push_back(c-'0');
			}else{
				num.push_back(10+c-'A');
			}
		}
	}
	BigInt& operator=(const int x){
		char s[10];
		sprintf(s,"%d",x);
		size_t size= strlen(s);
		for(int i = 0;i<size;i++){
			num.push_back(s[size-i-1]-'0');
		}
	}
	BigInt& operator=(BigInt bigint){
		num=bigint.num;
	}
	const char* toStr(){
		if(num.size()==0)return "0";
		char* s = (char*)malloc(sizeof(char)*num.size()+1);
		for(int i=0;i<num.size();i++){		
			s[i]=num[num.size()-i-1]+'0';
		}
		s[num.size()]=0;
		return s;
	}
	void rm_zero(){
		for(int i=num.size()-1;i>=0&&num[i]==0;i--){
			num.pop_back();
		}
	}
	int cmp(const BigInt& bigint)const{
		if(num.size()<bigint.num.size()){
			return -1;
		}else if(num.size()>bigint.num.size()){
			return 1;
		}else{
			for(int i=num.size()-1;i>=0;i--){
				if(num[i]<bigint.num[i])return -1;
				else if(num[i]>bigint.num[i])return 1;
			}
		}
		return 0;
	}
	bool operator<(const BigInt& bigint)const{
		return cmp(bigint)<0;
	}
	BigInt operator+(BigInt& bigint){
		BigInt ans;
		size_t max_size=num.size()>bigint.num.size()?num.size():bigint.num.size();
		for(int i=0;i<max_size;i++){
			int da=i<num.size()?num[i]:0;
			int db=i<bigint.num.size()?bigint.num[i]:0;
			ans.num.resize(i+1);
			ans.num[i]+=(da+db);
			if(ans.num[i]>=r){
				ans.num.push_back(ans.num[i]/r);
				ans.num[i]%=r;
			}
			
		}
		ans.rm_zero();
		return ans;
	}
	BigInt operator*(int x){
		BigInt ans;
		for(int i=0;i<num.size();i++){
			int da=num[i];
			ans.num.resize(i+1);
			ans.num[i]+=da*x;
			if(ans.num[i]>=r){
				ans.num.push_back(ans.num[i]/r);
				ans.num[i]%=r;
			}
			
		}
		for(int i=num.size();i<ans.num.size();i++){
			if(ans.num[i]>=r){
				ans.num.push_back(ans.num[i]/r);
				ans.num[i]%=r;
			}
		}
		ans.rm_zero();
		return ans;
	}
	BigInt operator*(BigInt& bigint){
		BigInt ans;
		for(int i=0;i<bigint.num.size();i+=8){
			BigInt delta = this->operator*(seg(i,bigint.num));
			for(int k=0;k<i;k++){
				delta.num.insert(delta.num.begin(),0);
			}
			ans=ans+delta;
		}
		ans.rm_zero();
		return ans;
	}
	std::vector<int> num;
};
std::istream& operator>>(std::istream& mcin,BigInt& bigint){
	std::string s;
	mcin>>s;
	bigint=s.c_str();
	return mcin;
}
std::ostream& operator<<(std::ostream& mcout,BigInt bigint){
	std::string s = bigint.toStr();
	return mcout<<s;
}
using std::max;
using std::string;
using std::cin;
using std::cout;
typedef BigInt ll;
ll dp[50][50];
ll a[50][50];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    string s;
    cin>>s;
    s="a"+s;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            a[i][j]=BigInt(s.substr(i,j-i+1).c_str());
        }
    }
    for(int i=1;i<=n;i++){
        dp[i][0]=a[1][i];
    }
    for(int k=1;k<=m;k++){
        for(int j=k+1;j<=n;j++){
            for(int i=k;i<j;i++){
                dp[j][k]=max(dp[i][k-1]*a[i+1][j],dp[j][k]);
            }
        }
    }
    cout<<dp[n][m]<<"\n";
    return 0;
}
