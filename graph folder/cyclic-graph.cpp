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
            l[y].push_back(x);
        }

        bool is_tree(){

            bool *visited=new bool[V];
            int *parent=new int[V];

            for(int i=0;i<V;i++){
                visited[i]=false;
                parent[i]=i;
            }

            queue<int> q;

            int src=0;
            q.push(src);
            visited[src]=true;

            while(!q.empty()){
                int node=q.front();
                q.pop();

                for(auto nbr:l[node]){
                    if(visited[nbr]==true && parent[node]!=nbr){
                        return false;
                    }else if(!visited[nbr]){
                        visited[nbr]=true;
                        parent[nbr]=node;
                        q.push(nbr);
                    }
                }
                
            }
            return true;
        }
};

int main(){
    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    
   if(g.is_tree()){
       cout<<"yes, its a tree!"<<endl;
   }else{
       cout<<"Not a tree!"<<endl;
   }
    return 0;

}