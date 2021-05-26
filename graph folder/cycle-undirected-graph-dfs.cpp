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
        void addEdge(int x,int y,bool directed=true){
            l[x].push_back(y);

            if(!directed){
                l[y].push_back(x);
            }
        }


        bool cycle_helper(int node,bool &visited,int parent){

            visited[node]=true;

            for(auto nbr:l[node]){
                //two case
                if(!visited[nbr]){
                    //go and recursively visit the nbr
                    bool cycle_found=cycle_helper(nbr,visited,node);
                    if(cycle_found){
                        return true;
                    }
                   //nbr is visited but nbr should not be equal to parent 
                }else if(nbr!=parent){
                    return true;
                }
            }
            return false;
           
        }


        bool contain_cycle(){

            bool *visited= new bool[V];
            for(int i=0;i<V;i++){
                visited[i]=false;
            }

            return cycle_helper(0,visited,-1);
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
        cout<<"Yes, undirected graph contains a cycle."<<endl;
    }else{
        cout<<"No cycle!"<<endl;
    }
    return 0;
}