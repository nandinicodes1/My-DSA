#include<bits/stdc++.h>
using namespace std;

int compare(pair<int,int> &p1,pair<int,int> &p2)
{
	return p1.second<p2.second;
}
int main()
{
	int n,c,r;
	cin>>n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++)
	{
		cin>>c>>r;
		v.push_back(make_pair(c-r,c+r));
	}
	
	sort(v.begin(),v.end(),compare);
	int ans=0;
	int currend=v[0].second;
	for(int i=1;i<n;i++)
	{
		if(v[i].first<currend)
		{
			ans++;
		}
		else{
			currend=v[i].second;
		}
	}
	cout<<ans<<endl;
	return 0;
}
