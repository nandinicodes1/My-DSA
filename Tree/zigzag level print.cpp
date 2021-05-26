#include<bits/stdc++.h>
using namespace std;
class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
};

node* buildtree()
{
	int data;
	cin>>data;
	
	node* root=new node(data);
	string left,right;
	
	cin>>left;
	if(left=="true")
	{
		root->left=buildtree();
	}
	
	cin>>right;
	if(right=="true")
	{
		root->right=buildtree();
	}
	return root;
}

int height(node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	int lh=height(root->left);
	int rh=height(root->right);
	return max(lh,rh)+1;
}

void levelorder(node *root)
{
	int h=height(root);
	if(root==NULL)
	{
		return;
	}
	int n=1;
	cout<<root->data<<" ";
	while(n!=h+1)
	{
		if(n%2==0)
		{
			cout<<root->right->data<<" ";
			cout<<root->left->data<<" ";
			n+=1;
		}
		else
		{
			cout<<root->left->data<<" ";
			cout<<root->right->data<<" ";
			n+=1;
		}
	}
}
int main()
{
	node *root=buildtree();
	levelorder(root);
	return 0;
}
