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
void printPre(node* root)
{
	if(root==NULL)
	return;
	
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
}
void preorderIterative(Node* root)
{
    // return if the tree is empty
    if (root == nullptr)
    return;
 
    // create an empty stack and push the root node
    stack<Node*> stack;
    stack.push(root);
 
    // loop till stack is empty
    while (!stack.empty())
    {
        // pop a node from the stack and print it
        Node* curr = stack.top();
        stack.pop();
 
        cout << curr->data << " ";
 
        // push the right child of the popped node into the stack
        if (curr->right) {
            stack.push(curr->right);
        }
 
        // push the left child of the popped node into the stack
        if (curr->left) {
            stack.push(curr->left);
        }
 
        // the right child must be pushed first so that the left child
        // is processed first (LIFO order)
    }
}
void printIn(node* root)
{
	if(root==NULL)
	return;
	
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}
void inorderIterative(node* root)
{
    // create an empty stack
    stack<node*> stack;
 
    // start from the root node (set current node to the root node)
    node* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            cout << curr->data << " ";
 
            curr = curr->right;
        }
    }
}
void printPost(node* root)
{
	if(root==NULL)
	return;
	
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}
void postorderIterative(Node* root)
{
    // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
 
    // create another stack to store postorder traversal
    stack<int> out;
 
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();
 
        out.push(curr->data);
 
        // push the left and right child of the popped node into the stack
        if (curr->left) {
            s.push(curr->left);
        }
 
        if (curr->right) {
            s.push(curr->right);
        }
    }
 
    // print postorder traversal
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
    }
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
