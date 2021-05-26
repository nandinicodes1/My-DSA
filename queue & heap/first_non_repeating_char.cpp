#include<bits/stdc++.h>
#include<queue>
#include<string>
using namespace std;

int main(){
	string str;
	cin>>str;

	int len=str.length();
	string ans;
	queue<char> q;

	int freq[26]={};

	for(int i=0;i<len;i++){
		freq[str[i]-'a']++;
		q.push(str[i]);
		while(!q.empty()){
			if(freq[q.front()-'a']>1){
				q.pop();
			}else{
				ans.push_back(q.front());
				break;
			}
		}
		if(q.empty()){
			ans.push_back('#');
		}
	}
	
	cout<<ans<<endl;
	return 0;

}
