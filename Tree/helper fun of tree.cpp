#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class node{
	public:
		int data;
		node*left;
		node* right;
		node(int data){
			this->data=data;
			left=NULL;
			right=NULL;
		}
};
 node* takeinputlevelwise(){
 		int rootdata;
      	cin>>rootdata;
      	queue<node*> pendingnode;
      	node* root=new node(rootdata);
      	pendingnode.push(root);
      	while(!pendingnode.empty()){
      		node* front=pendingnode.front();
      		pendingnode.pop();
      		cout<<"enter the  left data of:  "<<front->data<<endl;
      		int leftdata;
      		cin>>leftdata;
      		if(leftdata!=-1){
      	node*leftchild=new node(leftdata);
      		front->left=leftchild;
      		pendingnode.push(leftchild);
		  }
		  
		  	cout<<"enter the  right data of:  "<<front->data<<endl;
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
node* buildtree(){
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	node* root=new node(data);
	root->left=buildtree();
	root->right=buildtree();
	return root;
}
// print preorder
void printtree(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printtree(root->left);
	printtree(root->right);
}
  void printat_level_k(node*root, int k){
  	if(root==NULL){
  		return;
	  }
	  if(k==0){
	  	cout<<root->data<<" ";
	  	return;
	  }
	  printat_level_k(root->left,k-1);
	   printat_level_k(root->right,k-1);
	  
  }
  int height(node* root){
  	if(root==NULL){
  		return 0;
	  }
	  return max(height(root->left),height(root->right))+1;
  }
//print level order recursive
void print_levelorder_recursicve(node* root){
	if(root==NULL){
		return;
	}
	  int ht=height(root);
	  for(int i=0;i<ht;i++){
	  	printat_level_k(root,i);
	  	cout<<endl;
	  }
	  return;
}  // input 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
 void BFS(node* root){
 	if(root==NULL){
 		return ;
	 }
 	queue<node*> q;
 	q.push(root);
 	while(!q.empty()){
 		node* front=q.front();
 		q.pop();
 		if(front){
 		cout<<front->data<<" ";
 	}
 		if(front->left){
 			q.push(front->left);
		 }
		 if(front->right){
		 	q.push(front->right);
		 }
	 }
 }
  int diameter(node* root){
  	if(root==NULL){
  		return 0;
	  }
	  int lht=height(root->left);
	  int rht=height(root->right);
	  int ldim=diameter(root->left);
	  int rdim=diameter(root->right);
	  int ans=max(lht+rht,max(ldim,rdim));
	  return ans;
  }
  //DFS 
  void helper_rightview(node* root, int curr_level, int & max_level){
  	if(root==NULL){
  		return;
	  }
	  if(curr_level>max_level){
	  	cout<<root->data<<" ";
	  	max_level=curr_level;
	  }
	  helper_rightview(root->right,curr_level+1,max_level);
	  helper_rightview(root->left,curr_level+1,max_level);
	  
  }
 void rightviewofbinarytree(node* root){
 	int max_level=INT_MIN;
 	helper_rightview(root,0,max_level);
 }
  // input for DFS 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
  // input for level order  1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
int main(){    
//	node*root=buildtree();
    //printtree(root);
	cout<<endl; 
	//print_levelorder_recursicve(root);
//	BFS(root);
node* root=takeinputlevelwise();
  cout<<diameter(root)<<endl;
  rightviewofbinarytree(root);
}

