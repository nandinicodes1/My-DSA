#include<bits/stdc++.h>
#include<vector>
#include<map>
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

void verticalprint(node*root,int d,map<int ,vector<int> > &m)
{
	if(root==NULL)
	{
		return;
	}
	m[d].push_back(root->data);
	verticalprint(root->left,d-1,m);
	verticalprint(root->right,d+1,m);
	return;
}
int main()
{
	node *root=NULL;
	int n;
	cin>>n;
	root=buildTreeFromLevelOrder();
	map<int,vector<int> > m;
	int d=0;
	verticalprint(root,d,m);
	
	map<int,vector<int> > :: iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		for(int i=0;i<it->second.size();i++)
		{
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
	
	
}
