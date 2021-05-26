#include<bits/stdc++.h>
#include<queue>
#include<map>
using namespace std;
class node{
	public:
		int data;
		int hd;
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
 void printTopView(node *root)
 {
 	if(root==NULL)
 	{
 		return;
	}
	queue<node*> q;
	map<int,int> m;
	int hd=0;
	root->hd=hd;
	q.push(root);
	
	while(!q.empty())
	{
		hd=root->hd;
		
		if(m.count(hd)==0)
		m[hd]=root->data;
			
		if(root->left)
		{
			root->left->hd=hd-1;
			q.push(root->left);
		}
		if(root->right)
		{
			root->right->hd=hd+1;
			q.push(root->right);
		}
		q.pop();
		root=q.front();
	}
	for(map<int, int>:: iterator it=m.begin();it!=m.end();it++)
	{
		cout<<it->second<<" ";
	}
	 
 }
 int main()
 {
 	node *root=NULL;
 	root=buildTreeFromLevelOrder();
 	printTopView(root);
 	return 0;
 }
