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

node *buildfromlevelorder(node *root)
{
	int d;
	cin>>d;
	root=new node(d);
	if(d==-1)
	{
		return NULL;
	}
	root->left=buildfromlevelorder(root);
	root->right=buildfromlevelorder(root);
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
	node *root=NULL;
	root=buildfromlevelorder(root);
	printPre(root);
	return 0;
}


