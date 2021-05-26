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
node* bstfromsortedArray(int *in,int s,int e)
{
	if(s>e)
	{
		return NULL;
	}
	int mid=(s+e)/2;
	node *root=new node(in[mid]);
	root->left=bstfromsortedArray(in,s,mid-1);
	root->right=bstfromsortedArray(in,mid+1,e);
	return root;
}
node *replacenodes(node *root,int *in,int n)
{
	int sum=0;
	if(root==NULL)
	{
		return NULL;
	}
	for(int i=0;i<n;i++)
	{
		if(root->data==in[i])
		{
			while(i!=n)
			{
				sum+=in[i];
				i++;
			}
			root->data=sum;
		}
	}
	root->left=replacenodes(root->left,in,n);
	root->right=replacenodes(root->right,in,n);
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
	int n;
	cin>>n;
	int in[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	node *root=NULL;
	root=bstfromsortedArray(in,0,n-1);
	root=replacenodes(root,in,n);
	printPre(root);
	return 0;
}

