#include<iostream>
#include<stack>
using namespace std;

class queue{
	stack<int> s1,s2;
	public:
		void push(int x)
		{
			if(s1.empty())
			{
				s1.push(x);
			}
			else
			{
				while(!s1.empty())
				{
					s2.push(s1.top());
					s1.pop();
				}
				s1.push(x);
				while(!s2.empty())
				{
					s1.push(s2.top());
					s2.pop();
				}
			}
		}
		int pop()
		{
			if(s1.empty())
			{
				return 0;
			}
			else
			{
				int a=s1.top();
				s1.pop();
				return a;
			}
		}
		int size()
		{
			return s1.size();
		}
		bool isempty()
		{
			return s1.size()==0;
		}
};
int main()
{
	int n;
	cin>>n;
	queue q;
	for(int i=0;i<n;i++)
	{
		q.push(i);
	}
	while(!q.isempty())
	{
		cout<<q.pop()<<" ";
	}
	return 0;
}
