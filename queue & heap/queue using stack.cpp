#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	stack<int> s;
	for(int i=n-1;i>=0;i--)
	{
		s.push(i);
	}
	int tp;
	queue<int> q;
	while(!s.empty())
	{
		tp=s.top();
		q.push(tp);
		s.pop();
	}
	while(!q.empty())
	{
		cout<<q.front()<<" ";
	}
	return 0;
}
