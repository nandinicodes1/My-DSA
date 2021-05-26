#include<bits/stdc++.h>
using namespace std;

int laddersTD(int n,int k,int dp[])
{
	if(n==0)
	{
		return 1;
	}
	if(dp[n]!=0)
	{
		return dp[n];
	}
	int ways=0;
	for(int i=1;i<=k;i++)
	{
		if(n-i>=0)
		{
			ways+=laddersTD(n-i,k,dp);
		}
	}
	return dp[n]=ways;
}

int laddersBU(int n,int k)
{
	int dp[100]={0};
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=0;
		for(int j=1;j<=k;j++)
		{
			if(i-j>=0)
			{
				dp[i]+=dp[i-j];
			}
		}
	}
	return dp[n];
}

int ladder_optimized(int n,int k)
{
	int dp[100]={0};
	dp[0]=dp[1]=1;
	
	for(int i=2;i<=k;i++)
	{
		dp[i]=2*dp[i-1];
	}
	for(int i=k+1;i<=n;i++)
	{
		dp[i]=2*dp[i-1]-dp[i-k-1];
	}
	return dp[n];
}
int main()
{
	int n,k;
	cin>>n>>k;
	int dp[100]={0};
	
	cout<<"ways: "<<laddersTD(n,k,dp)<<endl;
	cout<<"bottom up ways: "<<laddersBU(n,k)<<endl;
	cout<<"ladders_optimized : "<<ladder_optimized(n,k)<<endl;
	
	return 0;
}
