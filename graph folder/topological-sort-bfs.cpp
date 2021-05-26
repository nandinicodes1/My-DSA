#include<bits/stdc++.h>
#include<map>
#include<list>
#include<queue>
using namespace std;

class graph{
        int V;
        list<int> *l;
    public:
        graph(int V){
            this->V=V;
            l=new list<int>[V];
        }

        void addedge(int x,int y){
            l[x].push_back(y);
        }

        void topological_sort(){
            int *indegree=new int[V];
            for(int i=0;i<V;i++){
                indegree[i]=0;
            }

            //stores indegree of each node
            for(int i=0;i<V;i++){
                
                for(auto y:l[i]){
                    indegree[y]++;
                }
            }

            //bfs
            queue<int> q;
            //find nodes with zero indegree
            for(int i=0;i<V;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }
            //start removing elements from the queue
            while(!q.empty()){
                int node=q.front();
                cout<<node<<" ";
                q.pop();

                //iterate over nbrs of that node nd reduce indegree by 1
                for(auto nbr = l[node]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
        }
};

int main()
{
    graph<int> g;

    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(1,4);
    g.addedge(2,3);
    g.addedge(2,5);
    g.addedge(3,5);
    g.addedge(4,5);
        
    g.topological_sort();
    return 0;
}
