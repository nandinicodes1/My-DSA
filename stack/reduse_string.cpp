#include<bits/stdc++.h>
#include<stack>
#define cc pair<char,int>
using namespace std;

string reduceExpression(string str,int k){
	int n=str.length();
	stack<cc> s;
	int i=0;
	for(i=0;i<n;i++){
		char temp=str[i];
		
		if(s.size()>0 && s.top().second==k){
			char current=s.top().first;
			
			while(!s.empty() && s.top().second==k){
				s.pop();
			}
		}
		
		if(s.size()>0 && s.top().first==temp){
			cc top=make_pair(temp,s.top().second+1);
			s.push(top);
		}else{
			cc top=make_pair(temp,1);
			s.push(top);
		}
	
	}
	if(s.size()>0 && s.top().second==k){
			char current=s.top().first;
			
			while(!s.empty() && s.top().second==k){
				s.pop();
			}
	}
	string ans="";
	while(!s.empty()){
		cc x=s.top();
		ans+=x.first;
	}
	string result="";
	for(int i=ans.size()-1;i>=0;i--){
		result+=ans[i];
	}
	return result;
}

int main(){
	string str;
	cin>>str;
	int k;
	cin>>k;
	
	cout<<reduceExpression(str,k)<<endl;
	
	
}
