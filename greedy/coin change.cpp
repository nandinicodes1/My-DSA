#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int make_change(int *arr,int t,int money)
{
	int ans=0;
	while(money>0)
	{
		int idx=upper_bound(arr,arr+t,money)-1 -arr;
		cout<<arr[idx]<<"+";
		money=money-arr[idx];
		ans++;
	}
	return ans;
}
int main()
{
	int money;
	cin>>money;
	int arr[]={1,2,5,10,20,50,100,200,500};
	int t=sizeof(arr)/sizeof(int);
	
	cout<<"no. of coins needed :"<<make_change(arr,t,money)<<endl;
}
