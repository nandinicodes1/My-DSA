#include<bits/stdc++.h>
using namespace std;

int compare(int i,int j)
{
	return i>j;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		
		sort(arr,arr+n,compare);
		int max=0,min=0;
		int i=0,j=n-1;
		while(i<j)
		{
			max+=(abs(arr[i]-arr[j]));
			i++;
			j--;
		}
		for(int i=0;i<=n-2;)
		{
			min+=(abs(arr[i]-arr[i+1]));
			i+=2;
		}
		cout<<max<<" "<<min<<endl;
	}
	return 0;
}
