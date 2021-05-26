#include<bits/stdc++.h>
#include<list>
#include<map>
#include<queue>
using namespace std;

template<typename T>
class Graph{
	map<T,list<T> >l;
	
	public:
		void addedge(int x,int y)
		{
			l[x].push_back(y);
			l[y].push_back(x);
		}
		
		void dfs_helper(T src,map<T,bool> &visited)
		{
			cout<<src<<" ";
			visited[src]=true;
			
			for(auto nbr:l[src]){
			if(!visited[nbr])
			{
				dfs_helper(nbr,visited);
			}
			}
			
		}
		
		void dfs(T src)
		{
			map<T,bool> visited;
			
			for(auto p:l)
			{
				T node=p.first;
				visited[node]=false;
			}
			dfs_helper(src,visited);
		}
		
};

int main()
{
	Graph<int> g;
	g.addedge(0,1);
	g.addedge(1,2);
	g.addedge(2,3);
	g.addedge(3,4);
	g.addedge(4,5);
	g.addedge(3,0);
	
	g.dfs(0);
	return 0;
}
