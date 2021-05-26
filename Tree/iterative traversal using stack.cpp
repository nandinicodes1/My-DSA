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
node* buildTree()
{
	int data;
	cin>>data;
	
	if(data==-1)
	{
		return NULL;
	}
	node* root=new node(data);
	root->left=buildTree();
	root->right=buildTree();
	return root;
}

//Iterative traversal preorder

vector<int> pre(node* root,vector<int> &v){
	stack<node*> s;
	
	while(1){
		while(root){
			v.push_back(root->data);
			s.push(root);
			root=root->left;
		}
		if(s.empty())break;
		
		root=s.top();
		s.pop();
		root=root->right;
	}
	return v;
}

vector<int> in(node* root,vector<int> &v){
	stack<node*> s;
	while(1){
		while(root){
			s.push(root);
			root=root->left;
		}
		if(s.empty())break;
		root=s.top();
		s.pop();
		root=root->right;
	}
	return v;
}
vector<int> post(node* root,vector<int> &v){
	if(root==NULL)return {};
	stack<node*> s;
	s.push(root);
	while(!s.empty()){
		node* topNode = s.top();
    if(topNode->left){
        s.push(topNode->left);
        topNode->left = NULL;
        continue;
    }
    if(topNode->right){
        s.push(topNode->right);
        topNode->right = NULL;
        continue;
    }
    v.push_back(topNode->val);
    s.pop();
	}
	return v;
	
}

int main()
{
	node*root=buildTree();
	printPre(root);
	cout<<endl;
	printIn(root);
	cout<<endl;
	printPost(root);
	return 0;
}
