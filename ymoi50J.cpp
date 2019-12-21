#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
int pow10[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
inline int seg(int i,std::deque<int> num){
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
	BigInt(){}
	BigInt(int x){
		*this=x;
	}
	BigInt(const char* s){
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
	int cmp(BigInt& bigint){
		rm_zero();bigint.rm_zero();
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
	void times_pow10(int t){
		for(int i=0;i<t;i++){
			num.push_front(0);
		}
	}
	void div_pow10(int t){
		for(int i=0;i<t;i++){
			num.pop_front();
		}
	}
	bool operator<(BigInt& bigint){
		return cmp(bigint)<0;
	}
	bool operator==(BigInt& bigint){
		return cmp(bigint)==0;
	}
	bool operator>(BigInt& bigint){
		return cmp(bigint)>0;
	}
	bool operator<=(BigInt& bigint){
		return cmp(bigint)<=0;
	}
	bool operator>=(BigInt& bigint){
		return cmp(bigint)>=0;
	}
	bool operator!=(BigInt& bigint){
		return cmp(bigint)!=0;
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
	BigInt operator-(BigInt& bigint){
		BigInt ans;
		for(int i=0;i<num.size();i++){
			int da=i<num.size()?num[i]:0;
			int db=i<bigint.num.size()?bigint.num[i]:0;
			ans.num.resize(i+1);
			ans.num[i]+=(da-db);
			if(ans.num[i]<0){
				ans.num.push_back(-1);
				ans.num[i]+=r;
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
				delta.num.push_front(0);
			}
			ans=ans+delta;
		}
		ans.rm_zero();
		return ans;
	}
	BigInt operator/(int x){
		BigInt ans;
		ans.num.resize(num.size());
		int modd = 0;
		for(int i=num.size()-1;i>=0;i--){
			ans.num[i]=(modd*r+num[i])/x;
			modd=(modd*r+num[i])%x;
		}
		ans.rm_zero();
		return ans;
	}
	BigInt operator/(BigInt& bigint){
		if(this->operator<(bigint))return BigInt(0);
		BigInt tmp;tmp=bigint;
		BigInt v;v=*this;
		BigInt ans;
		int p_delta = num.size()-bigint.num.size();
		ans.num.resize(p_delta+1);
		tmp.times_pow10(p_delta);
		for(int i=0;i<=p_delta;i++){
			int k=0;
			while(v>=tmp){
				v=v-tmp;
				k++;
			}
			ans.num.push_front(k);
			tmp.div_pow10(1);
		}
		ans.rm_zero();
		return ans;
		
	}
	std::deque<int> num;
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
bool cmp_k(int k,BigInt& bi1,BigInt& bi2){
	for(int i=0;i<k;i++){
		int d1 = k<bi1.num.size()?bi1.num[k]:0;
		int d2 = k<bi2.num.size()?bi2.num[k]:0;
		if(d1!=d2)return false;
	}
	return true;
}
int main(){
	BigInt bi1,bi2,bi3;
    bi1=0,bi2=1;
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=0;i<n-m+1;i++){
        bi3=bi2+bi1;
        bi1=bi2;
        bi2=bi3;
    }
    std::cout<<bi1;
    return 0;
}
