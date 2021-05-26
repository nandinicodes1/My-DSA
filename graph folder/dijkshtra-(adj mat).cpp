#include <bits/stdc++.h>
#include<climits>
using namespace std;


int findMinVertex(int* distance,bool* visited,int n){
	int minV= -1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (minV== -1 || distance[i]<distance[minV])){
			minV=i;
		}
	}
	return minV;
}

void dijkshtra(int** edges,int n){
	bool* visited=new bool[n];
	int* distance=new int[n];

	for(int i=0;i<n;i++){
		visited[i]=false;
		distance[i]=INT_MAX;
	}
	distance[0]=0;
	for(int i=0;i<n-1;i++){
		int minVertex=findMinVertex(distance,visited,n);
		visited[minVertex]=true;
		for(int j=0;j<n;j++){
			if(edges[minVertex][j]!=0 && !visited[j]){
				int dist= distance[minVertex] + edges[minVertex][j];
				if(dist< distance[j]){
					distance[j]=dist;
				}
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<i<<" "<<distance[i]<<endl;
	}
	delete [] visited;
	delete [] distance;
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
	dijkshtra(edges,n);

	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}
