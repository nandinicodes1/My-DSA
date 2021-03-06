#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,pair<int ,int> > customPair;

vector<int> mergeksortedarrays(vector<vector<int> > arr)
{
	vector<int> result;
	priority_queue<customPair,vector<customPair>,greater<customPair> > pq;
	for(int i=0;i<arr.size();i++)
	{
		pq.push({arr[i][0],{i,0}});
	}
	while(pq.empty()==false)
	{
		customPair curr=pq.top();
		pq.pop();
		int x=curr.second.first;
		int y=curr.second.second;
		result.push_back(curr.first);
		if(y+1 <arr[x].size())
		{
			pq.push({arr[x][y+1],{x,y+1} });
		}
	}
	return result;
}
int main()
{
	int k,n;
	cin>>k>>n;
	vector<vector<int> >arr ;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	vector<int> output=mergeksortedarrays(arr);
	for(int i=0;i<n*k;i++)
	{
		cout<<output[i]<<" ";
	}
		return 0;
}
