#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node *left;
		node *right;
		node(int d)
		{
			data=d;
			left=NULL;
			right=NULL;
		}
};
node *insert(node *root,int val)
{
	if(root==NULL)
	{
		root=new node(val);
	}
	else if(root->data>val)
	{
		root->left=insert(root->left,val);
	}
	else if(root->data<=val)
	{
		root->right=insert(root->right,val);
	}
	return root;
}

node *buildbst(int arr[],int n)
{
	node *root=NULL;
	for(int i=0;i<n;i++)
	{
		root=insert(root,arr[i]);
	}
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
void keysprint(node *root,int k1,int k2)
{
	if(root==NULL){
		return;
	}
	if(k1<root->data)
	{
		keysprint(root->left,k1,k2);
	}
	if(k1<=root->data && k2>=root->data)
	{
		cout<<root->data<<" ";
	}
	if(k2>root->data){
		keysprint(root->right,k1,k2);
	}
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
		int k1,k2;
		cin>>k1>>k2;
		node *root=buildbst(arr,n);
		cout<<"# Preorder : ";
		printPre(root);
		cout<<endl;
		cout<<"# Nodes within range are : ";
		keysprint(root,k1,k2);
		
	}
	return 0;
}
