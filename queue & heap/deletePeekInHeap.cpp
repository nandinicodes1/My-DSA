#include<bits/stdc++.h>
#include<vector>
using namespace std;

void unheapify(vector<int> &heap,int idx)
{
	if(idx==0)
	{
		return;
	}
	int parentIdx=(idx-1)/2;
	if(heap[parentIdx]<heap[idx])
	{
		int temp=heap[parentIdx];
		heap[parentIdx]=heap[idx];
		heap[idx]=temp;
	}
	else
	{
		return;
	}
}
void downheapify(vector<int> &heap,int idx)
{
	int leftidx=2*idx+1;
	int rightidx=2*idx+2;
	if(leftidx>=heap.size() && rightidx<=heap.size())
	{
		return;
	}
	int largestidx=idx;
	if(leftidx<heap.size()&& heap[leftidx]>heap[largestidx])
	{
		largestidx=leftidx;
	}
	if(rightidx<heap.size()&& heap[rightidx]>heap[largestidx])
	{
		largestidx=rightidx;
	}
	if(largestidx==idx)
	{
		return;
	}
	swap(heap[idx],heap[largestidx]);
	downheapify(heap,largestidx);
}
void deletepeek(vector<int> &heap)
{
	swap(heap[0],heap[heap.size()-1]);
	heap.pop_back();
	downheapify(heap,0);
}

void insert(vector<int> &heap,int key)
{
	heap.push_back(key);
	unheapify(heap,heap.size()-1);
}

void display(vector<int> &heap)
{
	for(int i=0;i<heap.size();i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
}
int main(int argc,char const *argv[])
{
	vector<int> heap;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		insert(heap,x);
	}
	display(heap);
	deletepeek(heap);
	display(heap);
	return 0;	
}
