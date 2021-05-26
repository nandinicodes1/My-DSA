#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
	int n;
	int x[4000],y[4000];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
		}
		sort(x,x+n);
		sort(y,y+n);
		
		int dx=0;
		int dy=0;
		int max_dy=0;
		int A=0;
		for(int i=0;i<n-1;i++)
		{
			if(abs(y[i+1]-y[i]-1)>max_dy)
			{
				max_dy=abs(y[i+1]-y[i]-1);
			}
		}
		for(int i=0;i<n-1;i++)
		{
			if((abs(x[i+1]-x[i]-1)*max_dy)>A)
			{
				A=abs(x[i+1]-x[i]-1)*max_dy;
			}
		}
		
		cout<<A<<endl;
		return 0;
}
