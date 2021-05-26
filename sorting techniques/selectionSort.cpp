#include<bits/stdc++.h>
using namespace std;
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	
}
void selectionsort(int arr[],int n)
{
	int min;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
				swap(&arr[min],&arr[i]);
			}
			
		}
		
	}

}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	selectionsort(arr,n);
	print(arr,n);
	return 0;
}
