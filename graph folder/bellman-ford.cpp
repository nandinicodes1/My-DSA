#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> bellman_ford(int n,int src,vector<vector<int>> edges){
	vector<int> dist(n+1,INT_MAX);
	dist[src]=0;

	//relax all the edges n-1 times
	for(int i=0;i<n-1;i++){
		for(auto x:edges){
			int from=x[0];int to=x[1]; int weight=x[2];

			if(dist[from]!=INT_MAX && dist[to]>dist[from]+weight){
				//relaxed the edge
				dist[to]=dist[from]+weight;
			}
		}
	}
	//If after (n-1) times relaxation ,still there is possiblity of relaxation, it means it has negative edge cycle
	//check for negative edge cycle
	for(auto x:edges){
			int from=x[0],to=x[1],weight=x[2];

			if(dist[from]!=INT_MAX && dist[to]>dist[from]+weight){
				cout<<"negative weight cycle";
				exit(0);
			}
	}
    return dist;
	
}

int main(){
	int n,m;
	cin>>n>>m;

	vector <vector<int>> edges;

	for(int i=0;i<m;i++){
		int from,to,weight;
		cin>>from>>to>>weight;
		edges.push_back({from,to,weight});
	}

	vector<int> dist=bellman_ford(n,1,edges);

	for(int i=1;i<=n;i++){
		cout<<"dist from src to "<<i<<" is "<<dist[i]<<endl;;
	}
	return 0;
}
