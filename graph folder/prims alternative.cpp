#include<bits/stdc++.h>
#include<climits>
using namespace std;


int findMinVertex(int *weight,bool *visited,int n){
	int minVtx= -1;

	for(int i=0;i<n;i++){
		if(!visited[i] && (minVtx== -1 || weight[i]<weight[minVtx])){
			minVtx=i;
		}
	}
	return minVtx;
}


void prims(int** edges,int n){
	int *parent=new int[n];
	int *weight=new int[n];
	bool *visited=new bool[n];

	for(int i=0;i<n;i++){
		weight[i]=INT_MAX;
		visited[i]=false;
	}
	parent[0]= -1;
	weight[0]= 0;

	for(int i=0;i<n-1;i++){
		//find min vertex
		int min_vertex=findMinVertex(weight,visited,n);
		visited[min_vertex]=true;

		//explore un-visited nbrs
		for(int j=0;j<n;j++){
			if(edges[min_vertex][j]!=0 && !visited[j]){
				if(edges[min_vertex][j]<weight[j]){
					weight[j]=edges[min_vertex][j];
					parent[j]=min_vertex;
				}
			}
		}
	}
	//print the MST
	for(int i=1;i<n;i++){
		if(parent[i]<i){
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		}else{
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}
	}
}


int main(){
	int n,e;
	cin>>n>>e;

	int** edges=new int*[e];
	for(int i=0;i<n;i++){
		edges[i]=new int[n];
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}

	for(int i=0;i<e;i++){
		int src,dest,weight;
		cin>>src>>dest>>weight;
		edges[src][dest]=weight;
		edges[dest][src]=weight;
	}
	cout<<endl;
	prims(edges,n);

	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}