#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}
int height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left),height(root->right));
}

bool isHeightBalancedOptimised(node *root)
{
    int lefth;
    int righth;

    if(root==NULL)
    {
        return 1;
    }
    lefth=height(root->left);
    righth=height(root->right);

    if(abs(lefth-righth)<=1 && isHeightBalancedOptimised(root->left) && isHeightBalancedOptimised(root->right))
    {
        return 1;
    }
    return 0;
}

int main()
{
    node *root = build("true");

    if(isHeightBalancedOptimised(root)==1)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    return 0;
}

