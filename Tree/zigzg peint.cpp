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

void zigzagorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	stack<node*> curr;
	stack<node*> next;
	
	curr.push(root);
	
	bool lefttoright=true;
	while(!curr.empty())
	{
		node *temp=curr.top();
		curr.pop();
		
		if(temp)
		{
			cout<<temp->data<<" ";
		}
		if(lefttoright)
		{
			if(temp->left)
			{
				next.push(temp->left);
			}
			if(temp->right)
			{
				next.push(temp->right);
			}
		}
		else
		{
			if(temp->right)
			{
				next.push(temp->right);
			}
			if(temp->left)
			{
				next.push(temp->left);
			}
		}
		
		if(curr.empty())
		{
			lefttoright=!lefttoright;
			swap(curr,next);
		}
	}
}
int main()
{
	node *root=buildtree();
	zigzagorder(root);
	return 0;
}
