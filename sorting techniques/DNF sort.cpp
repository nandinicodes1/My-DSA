#include<bits/stdc++.h>
using namespace std;

void dnfsort(int a[],int n)
{
	int lo=0;
	int mid=0;
	int hi=n-1;
	while(mid<=hi)
	{
		if(a[mid]==0)
		{
			swap(a[mid],a[lo]);
			lo++;
			mid++;
		}
		if(a[mid]==1)
		{
			mid++;
		}
		if(a[mid]==2)
		{
			swap(a[mid],a[hi]);
			hi--;
		}
	}
	return;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	dnfsort(a,n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
