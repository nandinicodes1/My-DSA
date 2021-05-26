#include<bits/stdc++.h>
using namespace std;

int profit(int n,int s,int *size,int *value)
{
	
	if(n==0 || s==0)
	{
		return 0;
	}
	int ans=0;
	int inc,exc;
	inc=exc=0;
	
	if(size[n-1]<=s)
	{
		inc=value[n-1]+profit(n-1,s-size[n-1],size,value);
	}
	exc=profit(n-1,s,size,value);
	
	ans=max(inc,exc);
	return ans;
}

int main()
{
	int n,s;
	cin>>n>>s;
	
	int size[n];
	int value[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>size[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}
	
	cout<<profit(n,s,size,value)<<endl;
	return 0;
	
	
}
