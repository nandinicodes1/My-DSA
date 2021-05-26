#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node*left;
		node*right;
	node(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}	
};
node *createtreefromprein(int *in,int *pre,int s,int e)
{
	static int i=0;
	if(s>e)
	{
		return NULL;
	}
	node* root=new node(pre[i]);
	int index=-1;
	for(int j=s;j<=e;j++)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
	}
	i++;
	root->left=createtreefromprein(in,pre,s,index-1);
	root->right=createtreefromprein(in,pre,index+1,e);
	return root;
}

void nodesKdistDown(node *root,int k)
{
	if(root==NULL || k<0)
	return;
	
	if(k==0)
	{
		cout<<root->data<<" ";
	}
	nodesKdistDown(root->left,k-1);
	nodesKdistDown(root->right,k-1);
}

int printnodesKdist(node *root,int target,int k)
{
	if(root==NULL)
	return -1;
	
	if(root->data==target)
	{
		nodesKdistDown(root,k);
		return 0;
	}
	int dl=printnodesKdist(root->left,target,k);
	if(dl!=-1)
	{
		if(dl+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			nodesKdistDown(root->right,k-dl-2);
		}
		return 1+dl;
	}
	int dr=printnodesKdist(root->right,target,k);
	if(dr!=-1)
	{
		if(dr+1==k)
		{
			cout<<root->data<<" ";
		}
		else
		{
			nodesKdistDown(root->left,k-dl-2);
		}
		return 1+dl;
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	int pre[n],in[n];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	int t;
	cin>>t;
	while(t--)
	{
		int target,k;
		cin>>target>>k;
		node *root=createtreefromprein(in,pre,0,n-1);
		printnodesKdist(root,target,k);
		cout<<endl;
	}
	return 0;
}
