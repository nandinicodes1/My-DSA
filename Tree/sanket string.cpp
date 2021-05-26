#include<bits/stdc++.h>
using namespace std;
int sanketString(string s,int k)
{
	int fre[2]={0};
	int l=0,r=0,ans=0;
	while(r<s.length())
	{
		char temp=s[r];
		fre[temp -'a']++;
		if(min(fre[0],fre[1])>k)
		{
			fre[s[l]-'a']--;
			l++;
		}
		else
		{
			ans++;
		}
		r++;
	}
	return ans;
}
int main()
{
	string s;
	getline(cin,s);
	int k;
	cin>>k;
	cout<<sanketString(s,k);
	return 0;
}
