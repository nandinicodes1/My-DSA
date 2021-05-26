#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			v.push_back(x);
		}
		
		sort(v.begin(),v.end());
		cout<<v[0]<<endl;
	}
	return 0;
}
