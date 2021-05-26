#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int source;
	int dest;
};

void beautiful_vertices(Edge *input,int n,int e){
	int* children=new int[n];
	int* parent=new int[n];
	bool* visited=new bool[n];
	for(int i=1;i<=n;i++){
		children[i]=0;
		visited[i]=false;
		parent[i]=i;
	}
	for(int i=1;i<=n;i++){
		if(!visited[input[i].source]){
			visited[input[i].source]=true;
			
			
		}
	}


}

int main(){
	int n,e;
	cin>>n>>e;

	Edge* input=new Edge[e];
	for(int i=1;i<=e;i++){
		int x,y;
		cin>>x>>y;
		input[i].source=x;
		input[i].dest=y;
	}
	beautiful_vertices(input,n,e);
	delete [] input;
	return 0;
}