#include<bits/stdc++.h>
using namespace std;

long long int BU(int n)
{
	long long int sum;
	if(n==1)
		return 2;
	if(n==2)
		return 3;
		
	long long int a=2,b=3;	
	for(int i=3;i<=n;i++)
	{
		sum=a+b;
		a=b;
		b=sum;
	}
	return sum;
}

int countstring(int n)
{
	int a[n],b[n];
	a[0]=b[0]=1;
	
	for(int i=1;i<n;i++)
	{
		a[i]=a[i-1]+b[i-1];
		b[i]=a[i-1];
	}
	return a[n-1]+b[n-1];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long int ans=countstring(n);
		cout<<ans<<endl;
	}
	return 0;
}
