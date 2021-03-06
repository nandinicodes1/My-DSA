#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lcs(char ch1[],char ch2[])
{
	int m=strlen(ch1);
	int n=strlen(ch2);
	
	int dp[100][100];
	for(int i=0;i<=m;i++)
	dp[i][0]=0;
	for(int j=0;j<=n;j++)
	dp[0][j]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int q=0;
			if(ch1[i-1]==ch2[j-1])
			{
				q=1+dp[i-1][j-1];
			}
			else{
				q=max(dp[i][j-1],dp[i-1][j]);
			}
			dp[i][j]=q;
		}
	}
	return dp[m][n];
}
int main()
{
	char str1[100],str2[100];
	cin>>str1>>str2;
	
	int ans=lcs(str1,str2);
	cout<<ans<<endl;
	return 0;
	
}
