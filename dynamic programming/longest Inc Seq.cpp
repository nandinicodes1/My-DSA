#include<bits/stdc++.h>
using namespace std;

int lis(int arr[],int n)
{
	int dp[100]={1};
	
	int best=-1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;i++)
		{
			if(arr[j]<=arr[i])
			{
				int currlen=1+arr[j];
				dp[i]=max(currlen,dp[i]);
			}
		}
		best=max(best,dp[i]);
	}
	return best;
}
int main()
{
	int n;
	cin>>n;
	int arr[100];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int ans=lis(arr,n);
	cout<<ans<<endl;
	return 0;
}
