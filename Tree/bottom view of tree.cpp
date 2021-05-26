#include<bits/stdc++.h>
#include<queue>
#include<map>
#include<iterator>
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
 
 void printBottomView(node *root)
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
		if(m.count(hd)==0)
			m[hd]=root->data;
		
		node *temp=q.front();
		q.pop();
		
		hd=temp->hd;
		
		m[hd]=temp->data;
		
		if(temp->left)
		{
			temp->left->hd=hd-1;
			q.push(temp->left);
		}	
		if(temp->right)
		{
			temp->right->hd=hd+1;
			q.push(temp->right);
		}
	}
	map<int, int>:: iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		cout<<itr->second<<" ";
	}
	 
 }
 int main()
 {
 	node *root=NULL;
 	root=buildTreeFromLevelOrder();
 	printBottomView(root);
 	return 0;
 }
