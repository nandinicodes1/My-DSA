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

	int identical(node* root1, node* root2) 
{ 
    if (root1==NULL && root2==NULL) 
        return 1; 
   
    if (root1!=NULL && root2!=NULL) 
    { 
        return
        ( 
        	(root1->data==root2->data) && 
            identical(root1->left, root2->left) && 
            identical(root1->right, root2->right) 
        ); 
    } 
    return 0; 
}  

int main()
{
	node* root1=buildtree();
	node* root2=buildtree();
	
	if(identical(root1,root2))
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	return 0;
}
