#include<bits/stdc++.h>
#include<cstring>
#include<math.h>
using namespace std;

int abs(int i,int j)
{
	if(i-j>0)
	{
		return i-j;
	}
	else{
		return j-i;
	}
}
int main()
{
	int fre[1000]={0};
	int t;
	cin>>t;
	while(t--)
	{
		memset(fre,0,sizeof fre);
		string name;
		int n,rank;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>name>>rank;
			fre[rank]++;
		}
		
		int actual_rank=1;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			while(fre[i])
			{
				sum+=abs(actual_rank,i);
				fre[i]--;
				actual_rank++;
			}
		}
		cout<<sum<<endl;
		
	}
	return 0;
}
