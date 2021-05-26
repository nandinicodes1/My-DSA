#include<bits/stdc++.h>
using namespace std;

class Graph{
	unordered_map<int,int> m;
public:
	void addEdge(int x,int y){
		m[x].push_back(y);
		m[y].push_back(x);
	}

	int templeCost(int temple,int repair,int n){
		if(temple<repair){
			return n*temple;
		}
		
	}
};

int main(){
	int t;
	cin>>t;
	while(t--){
		Graph g;
		int n,m,a,b;
		cin>>n>>m>>a>>b;

		for(int i=0;i<m;i++){
			int u,v;
			cin>>u>v;
			g.addEdge(u,v);
		}

		cout<<g.templeCost(a,b)<<endl;
	}
	return 0;
}