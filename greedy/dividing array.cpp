#include<bits/stdc++.h>
using namespace std;
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
		int i=0;
		int j=n-1;
		int min_diff=0,max_diff=0;
		while(i<j)
		{
			int diff1=abs(arr[i]-arr[j]);
			min_diff=min(min_diff,diff1);
			int diff2=arr[i]+arr[j];
			max_diff=max(max_diff,diff2);
			i++;j--;
		}
		cout<<min_diff<<" "<<max_diff<<endl;
	}
	return 0;
}
