#include<bits/stdc++.h>
using namespace std;
void stockspan(int arr[],int n,int ans[])
{
	ans[0]=1;
	for(int i=1;i<n;i++)
	{
		ans[i]=1;
		for(int j=i-1;j>=0 && arr[i]>=arr[j];j--)
		{
			ans[i]++;
		}
	}
}
void print(int ans[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<"END"<<endl;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int ans[n];
	stockspan(arr,n,ans);
	print(ans,n);
	return 0;
	
}
