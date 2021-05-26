#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	int data,noc;
	node *left;
	node *right;
	node(int d,int n)
	{
		data=d;
		noc=n;
		left=NULL;
		right=NULL;
	}
};

node *buildtree(node *root)
{
	int data,noc;
	cin>>data>>noc;
	root=new node(data,noc);
	if(noc==0)
	{
		return root;
	}
	else if(noc==1)
	{
		root->left=buildtree(root->left);
		return root;
	}
	else
	{
		root->left=buildtree(root->left);
		root->right=buildtree(root->right);
		return root;
	}
}

int sumlevelk(node *root,int k)
{
	
	if(root==NULL)
	{
		return 0;
	}
	if(k==0)
	{
		return root->data;
	}
	else if(k>0)
	{
		int ans=sumlevelk(root->left,k-1)+sumlevelk(root->right,k-1);
		return ans;
	}
}
int main()
{
	node *root=NULL;
	root=buildtree(root);
	int k;
	cin>>k;
	cout<<sumlevelk(root,k)<<endl;
	return 0;
}
