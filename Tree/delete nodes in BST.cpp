#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
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

node* deleteInBST(node* root,int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(data<root->data)
	{
		root->left=deleteInBST(root->left,data);
		return root;
	}
	else if(data==root->data)
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}
		if(root->left!=NULL && root->right==NULL)
		{
			node* temp=root->left;
			delete root;
			return temp;
		}
		if(root->left==NULL && root->right!=NULL)
		{
			node* temp=root->right;
			delete root;
			return temp;
		}
		if(root->left!=NULL && root->right!=NULL)
		{
			node* replace=root->right;
			while(replace->left!=NULL)
			{
				replace=replace->left;
			}
			root->data=replace->data;
			root->right=deleteInBST(root->right,replace->data);
			return root;
		}
	}
	else
	{
		root->right=deleteInBST(root->right,data);
		return root;
	}
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
		int arr1[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr1[i];
		}
		int m;
		cin>>m;
		int arr2[m];
		for(int i=0;i<m;i++)
		{
			cin>>arr2[i];
		}
		sort(arr1,arr1+n);
		node *root=bstfromsortedArray(arr1,0,n-1);
		for(int i=0;i<m;i++)
		{
			node* root=deleteInBST(root,arr2[i]);
		}
		printPre(root);
		
	}
	return 0;
}
