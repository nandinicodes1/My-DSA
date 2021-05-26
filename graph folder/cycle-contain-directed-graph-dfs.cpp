#include<bits/stdc++.h>
#include<queue>
#include<list>
using namespace std;

class Graph{
        int V;
        list<int> *l;
    public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V];
        }
        void addEdge(int x,int y){
            l[x].push_back(y);
        }


        bool cycle_helper(int node,bool *visited,bool *stack){
			
			if(visited[node]==true && stack[node]==true){
				return true;
			}
            //visit a node
            visited[node]=true;
            stack[node]=true;

            for(auto nbr:l[node]){
                if(cycle_helper(nbr,visited,stack)){
                	return true;
				}
            }

            //leave a node
            stack[node]=false;
            return false;
        }


        bool contain_cycle(){

            bool *visited= new bool[V];
            bool *stack= new bool[V];
			for(int i=0;i<V;i++){
				visited[i]=stack[i]=false;
			}
            for(int i=0;i<V;i++){
            	if(!visited[i]){
            		if(cycle_helper(i,visited,stack)){
            			return true;
					}
				}
			}
			return false;
        }
};

int main(){

    Graph g(6);

    g.addEdge();
    g.addEdge();
    g.addEdge();
    g.addEdge();
    g.addEdge();
    g.addEdge();

    if(contain_cycle()){
        cout<<"It contain a cycle."<<endl;
    }else{
        cout<<"No cycle!"<<endl;
    }
    return 0;
}
