#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

//Time complexity :- O(nklogk)
typedef pair<int, pair<int,int>> customPair; //In this pair, first int represents the element,
//next two int represents its position in 2d vector ie. i,j 

vector<int> mergeKSortedArrays(vector<vector<int> > arr)
{
	vector<int> result;
	priority_queue<customPair, vector<customPair>, greater<customPair> > pq; // min heap

	//insert the 0th element of every array in the heap
	for(int i=0;i<arr.size();i++)
	{
		pq.push({arr[i][0],{i,0} });
	}

	//remove the element one by one from the heap and add to result vector
	while(pq.empty()==false)
	{
		customPair curr=pq.top();
		pq.pop();
		int x=curr.second.first; //row in which the element is present
		int y=curr.second.second; // col in which the element present
		result.push_back(curr.first);

		//push in th PQ the next element of current element x,y+1
		if(y+1<arr[x].size())
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
	vector<int> input;
	for(int i=0;i<(n*k);i++){
		int d;cin>>d;
		input.push_back(d);
	}
	vector<vector<int> > arr(k);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++){
			arr[i].push_back(input[j+(n*i)]);
		}
		
	}
	vector<int> output=mergeKSortedArrays(arr);
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<<" ";
	}
	return 0;
}
