#include<bits/stdc++.h>
#include<math.h>
using namespace std;

//time complexity = O(n+k) n=No of elements, k= range of input
void countingsort(int *arr,int n)
{
	int largest=-1;
	for(int i=0;i<n;i++)
	{
		largest=max(largest,arr[i]);
	}
	int *freq=new int[largest+1]{0};
	for(int i=0;i<n;i++)
	{
		freq[arr[i]]++;
	}
	int j=0;
	for(int i=0;i<=largest;i++)
	{
		while(freq[i]>0)
		{
			arr[j]=i;
			freq[i]--;
			j++;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	countingsort(arr,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
