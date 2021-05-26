#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define mod 1000000007
#define gcd __gcd
#define inf INT_MAX
#define INF LLONG_MAX
#define minf INT_MIN
#define MINF LLONG_MIN
#define pb push_back
#define all(v) v.begin(),v.end()
#define print(v) for(auto x:v) cout<<x<<" "; cout<<"\n";
#define printn(v) for(auto x:v) cout<<x<<"\n";
#define F first
#define S second
#define mp make_pair

int n;
vector<int>inorder, preorder;
unordered_map<int, int>m;
int i = 0;

struct Node {
	int data;
	Node*left;
	Node*right;
	Node(int data) {
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};


struct bst {
	int sz;
	int min;
	int max;
	int ans;
	bool isBST;

};

Node* buildtree(int start, int end) {
	if (start > end) return nullptr;
	Node* root = new Node(preorder[i++]);
	int index = m[root->data];
	root->left = buildtree(start, index - 1);
	root->right = buildtree(index + 1, end);
	return root;
}

bst largestBST(Node* root) {
	if (root == nullptr) return {0, inf, minf, 0, true};

	if (root->left == nullptr && root->right == nullptr) return {1, root->data, root->data, 1, true};

	bst l = largestBST(root->left);
	bst r = largestBST(root->right);
	bst b;
	b.sz = 1 + l.sz + r.sz;
	//if the whole subtree is bst
	if (l.isBST && r.isBST && l.max < root->data && r.min > root->data) {
		b.ans = b.sz;
		b.min = min(l.min, min(r.min, root->data));
		b.max = max(r.max, max(l.max, root->data));
		b.isBST = true;
		return b;
	}
	b.ans = max(l.ans, r.ans);
	b.isBST = false;
	return b;
}

int32_t main() {
	fastio;
	cin >> n;
	inorder.resize(n);
	preorder.resize(n);
	for (int i = 0; i < n; i++) cin >> preorder[i];
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
		m[inorder[i]] = i;
	}
	Node* root = buildtree(0, n - 1);
	bst b = largestBST(root);
	cout << b.ans << endl;
}
