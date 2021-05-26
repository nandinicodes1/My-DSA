#include<bits/stdc++.h>
#include<queue>
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

node* buildTreeFromLevelOrder(){
 		int rootdata;
      	cin>>rootdata;
      	queue<node*> pendingnode;
      	node* root=new node(rootdata);
      	pendingnode.push(root);
      	while(!pendingnode.empty()){
      		node* front=pendingnode.front();
      		pendingnode.pop();
      		
      		int leftdata;
      		cin>>leftdata;
      		if(leftdata!=-1){
      			node*leftchild=new node(leftdata);
      			front->left=leftchild;
      			pendingnode.push(leftchild);
		 		}
		  
      		int rightdata;
      		cin>>rightdata;
      		if(rightdata!=-1){
      		node*rightchild=new node(rightdata);
      		front->right=rightchild;
      		pendingnode.push(rightchild);
		  }
	  }
	  return root;
 }
 
 void printleftview(node *root)
 {
 	if(root==NULL)
	{
		return;
	}
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		int n=q.size();
		for(int i=1;i<=n;i++)
		{
			node *temp=q.front();
			q.pop();
			
			if(i==1)
			{
				cout<<temp->data<<" ";
			}
			if(temp->left!=NULL)
			{
				q.push(temp->left);
			}
			if(temp->right!=NULL)
			{
				q.push(temp->right);
			}
		}
	}
 }

 int main()
 {
 	node *root=NULL;
 	root=buildTreeFromLevelOrder();
 	printleftview(root);
 	return 0;
 }

