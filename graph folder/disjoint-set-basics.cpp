#include<bits/stdc++.h>
using namespace std;

class disjoint{
	int *rank;
	int *parent;
	int n;
public:
	disjoint(int n){
		rank=new int[n];
		parent=new int[n];
		this->n=n;
		makeSet();
	}

	void makeSet(){
		for(int i=0;i<n;i++){
			parent[i]=i;
		}
	}

	int find(int x){
		if(parent[x]==x){
			return x;
		}else{
			return find(parent[x]);
		}
	}

	void Union(int x,int y){
		int xroot=find(x);
		int yroot=find(y);

		if(xroot==yroot){
			return;
		}else if(rank[xroot]<rank[yroot]){
			parent[xroot]=yroot;
		}else if(rank[xroot]>rank[yroot]){
			parent[yroot]=xroot;
		}else{
			parent[xroot]=yroot;
			rank[y]=rank[y]+1;
		}
	}
};

int main(){
	disjoint obj(5); 
    obj.Union(0, 2); 
    obj.Union(4, 2); 
    obj.Union(3, 1); 
    if (obj.find(4) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
    if (obj.find(1) == obj.find(0)) 
        cout << "Yes\n"; 
    else
        cout << "No\n"; 
  
    return 0; 

}