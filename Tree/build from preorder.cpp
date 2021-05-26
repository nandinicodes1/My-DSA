#include<iostream>
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

node* buildusingpre()
{
	int d;
	cin>>d;
	if(d==-1)return NULL;
	node *root=new node(d);
	root->left=buildusingpre();
	root->right=buildusingpre();
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
	node *root=buildusingpre();
	printPre(root);
}
