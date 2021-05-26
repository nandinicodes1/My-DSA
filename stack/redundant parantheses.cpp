#include<bits/stdc++.h>
using namespace std;
bool IsRedundant(string str)
{
	int a=0,b=0;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='('&& str[i+1]==')')
		{
			return 1;
		}
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/')
		{
			a++;
		}
		if(str[i]=='(')
		{
			b++;
		}
	}
	if(b>a)
	{
		return 1;
	}
	else{
		return 0;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string str;
	cin>>str;
	if(IsRedundant(str))
	{
		cout<<"Duplicate"<<endl;
	}
	else
	{
		cout<<"Not duplicates"<<endl;
	}
	}
	return 0;
}
