#include<bits/stdc++.h>
#include<stack>
using namespace std;

bool isRedundant(string str)
{
	stack<char> s;
	int count=0;
	for(int i=0;i<str.size();i++)
	{      // don't directly push .  make a check
	    if(str[i]!=')')
	    	s.push(str[i]);
	//	if(str[i]==')')
	  else 
		{   count=0;
			while(s.top()!='(')
			{
				s.pop();
				count++;
			}
			if(count==0)
			{
			//	return false;
				return true;    // count==0 ,it  means that there is no meaningfull information in the parenthesis therefore it's redundant.
			}
			else if(!s.empty())
			{
				s.pop();
			}
		}
	}

	return count==0;
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		if(isRedundant(str))
		{
			cout<<"Duplicate"<<endl;
		}
		else
		{
			cout<<"Not Duplicates"<<endl;
		}
	}
	return 0;
}
