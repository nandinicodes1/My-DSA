#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int d)
		{
			this->data=d;
			left=NULL;
			right=NULL;
		}
};
node* bstfromsortedArray(int *arr,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	node *root=new node(arr[mid]);
	root->left=bstfromsortedArray(arr,s,mid-1);
	root->right=bstfromsortedArray(arr,mid+1,e);
	return root;
}

void printPre(node* root)
{
	if(root==NULL)
	return;
	
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		node *root=bstfromsortedArray(arr,0,n-1);
		printPre(root);
	}
	return 0;
}
