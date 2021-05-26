#include<bits/stdc++.h>
using namespace std;

long long int mincost(long long int cost[],long long int petrol[],int n)
{
	if(n<=0)
	{
		return 0;
	}
	long long int min_cost=cost[0];
	long long int sum=cost[0]*petrol[0];
	for(int i=1;i<n;i++)
	{
		min_cost=min(min_cost,cost[i]);
		sum+=min_cost*petrol[i];	
	}
	return sum;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int cost[n],petrol[n];
		for(int i=0;i<n;i++)
		{
			cin>>cost[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>petrol[i];
		}
		
		long long int ans=mincost(cost,petrol,n);
		cout<<ans<<endl;
	}
	return 0;
}
