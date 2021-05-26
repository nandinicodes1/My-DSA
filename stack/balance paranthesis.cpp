#include<bits/stdc++.h>
#include<stack>
using namespace std;
bool IsBalanced(string str)
{
	stack<char>s;
	for(int i=0;i<str.size();i++)
	{
		char current=str[i];
		if(current=='('||current=='{'||current=='[')
		{
			s.push(current);
		}
		else if(current==')'||current=='}'||current==']')
		{
			 if(s.empty()){
           return false;
       }
      char ch=s.top();
      s.pop();
      if(str[i]==')' && ch=='('){
          continue;
        }
       else  if(str[i]=='}'&& ch=='{'){
          continue;
        }
       else  if(str[i]==']'&& ch=='['){
          continue;
        }
    else {
        return false;
    }
		
		}
	}
	return s.empty();
}
int main()
{
	string exp;
	cin>>exp;
	
	if(IsBalanced(exp))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}
