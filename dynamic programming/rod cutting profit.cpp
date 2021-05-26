#include<bits/stdc++.h>
using namespace std;

int memo[100];

int maxprofitTD(int arr[],int totallen)
{
	if(totallen==0){
		return 0;
	}
	
	//memoization
	if(memo[totallen]!=-1)
	{
		return memo[totallen];
	}
	int best=0;
	for(int i=1;i<=totallen;i++){
		int netprofit=arr[i]+maxprofitTD(arr,totallen-i);
		best=max(best,netprofit);
	}
	return memo[totallen]=best;
}

int maxprofitBU(int arr[],int totallen)
{
	int dp[100]={0};
	
	for(int len=1;len<=totallen;len++)
	{
		int best=0;
		for(int cut=1;cut<=len;cut++)
		{
			best=max(best,arr[cut]+dp[len-cut]);
		}
		dp[len]=best;
	}
	return dp[totallen];
}
int main()
{
	int price[100];
	int totallen;
	cin>>totallen;
	
	for(int i=1;i<=totallen;i++){
		cin>>price[i];
	}
	//reset memopad
	
	for(int i=1;i<=totallen;i++){
		memo[i]=-1;
	}
	int ans=maxprofitTD(price,totallen);
	cout<<ans<<endl;
	return 0;
}
