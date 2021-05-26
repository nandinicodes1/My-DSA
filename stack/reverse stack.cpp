#include<bits/stdc++.h>
#include<stack>
using namespace std;
void reverseStack(stack<int> &s,stack<int> &help)
{
	if(s.size()==0||s.size()==1)
	{
		return;
	}
	int x=s.top();
	s.pop();
	reverseStack(s,help);
	while(s.size()!=0)
	{
		help.push(s.top());
		s.pop();
	}
	s.push(x);
	while(help.size()!=0)
	{
		s.push(help.top());
		help.pop();
	}
}
int main()
{
	int n;
	cin>>n;
	int value;
	stack<int>s,help;
	for(int i=0;i<n;i++)
	{
		cin>>value;
		s.push(value);
	}
	reverseStack(s,help);
	while(s.size()!=0)
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}
