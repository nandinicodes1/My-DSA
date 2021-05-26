#include<iostream>
using namespace std;
void insertionSort(int* arr,int n)
{
	int num;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		num=arr[i];
		while(j>=0 && arr[j]>num)
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=num;
		
		
	}
}
void print(int* arr,int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	insertionSort(arr,n);
	print(arr,n);
}
