#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[],int n)
{
	int dp[100]={0};
	dp[0]=arr[0]>0?arr[0]:0;
	int max_so_far=dp[0];
	
	for(int i=1;i<n;i++)
	{
		dp[i]=dp[i-1]+arr[i];
		if(dp[i]<0)
		{
			dp[i]=0;
		}
		max_so_far=max(dp[i],max_so_far);
	}
	return max_so_far;
}

//kadane's algorithm

int maxSumSpaceOpti(int arr[],int n)
{
	int curr_sum=0;
	int max_sum=0;
	for(int i=0;i<n;i++)
	{
		curr_sum+=arr[i];
		if(curr_sum<0)
		{
			curr_sum=0;
		}
		max_sum=max(curr_sum,max_sum);
	}
	return max_sum;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<maxSum(arr,n)<<endl;
	cout<<maxSumSpaceOpti(arr,n)<<endl;
	return 0;
	
	
	
}
