#include<bits/stdc++.h>
#include<stack>
using namespace std;
void design(int n)
{
	int data;
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		cin>>data;
		s.push(data);
	}
	while(s.size()!=0)
		{
			int top=s.top();
			s.pop();
			cout<<top<<" ";
		}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		design(n);
	}
	return 0;
}
