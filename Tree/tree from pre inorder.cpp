#include<bits/stdc++.h>
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
node *createtreefromprein(int *in,int *pre,int s,int e)
{
	static int i=0;
	if(s>e)
	{
		return NULL;
	}
	node* root=new node(pre[i]);
	int index=-1;
	for(int j=s;j<=e;j++)
	{
		if(in[j]==pre[i])
		{
			index=j;
			break;
		}
	}
	i++;
	root->left=createtreefromprein(in,pre,s,index-1);
	root->right=createtreefromprein(in,pre,index+1,e);
	return root;
}

void print(node* ans){
    if(ans==NULL){
		//	cout<<"END";
        return;
    }
    //cout<<ans->left->data<<" => "<<ans->data<<" => "<<ans->right->data<<endl;
    if(ans->left==NULL)
        cout<<"END";
    else
        cout<<ans->left->data;
    cout<<" => ";

    cout<<ans->data;
    cout<<" <= ";  

    if(ans->right==NULL)
        cout<<"END";
    else
        cout<<(ans->right)->data;
    cout<<endl;

    print(ans->left);
    print(ans->right);
}
int main()
{
	int n;
	cin>>n;
	int pre[n];
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	int m;
	cin>>m;
	int in[m];
	for(int i=0;i<m;i++)
	{
		cin>>in[i];
	}
	node* ans=createtreefromprein(in,pre,0,m-1);
	print(ans);
	return 0;
	
}
