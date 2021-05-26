#include <iostream>
#include<bits/stdc++.h>
#include<list>
#include<map>
#include<cstring>
using namespace std;

template<typename T> 
class Graph{
         map<T,list<T> > l;
    public:
        void addEdge(T x, T y){
            l[x].push_back(y);
        }

        void dfs_helper(T src,map<T,bool > &visited,list<T> &ordering){
            visited[src]=true;

            for(auto nbr:l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr,visited,ordering);
                }
            }

            ordering.push_front(src);
            return;

        }

        void dfs(){
            map<T, bool> visited;
            list<T> ordering;

            for(auto p:l){
                T node=p.first;
                visited[node]=false;
            }

            for(auto p:l){
                T  node=p.first;
                if(!visited[node]){
                    dfs_helper(node,visited,ordering);
                }
            }
           for(auto node: ordering){
               cout<<node<<endl;
           } 

        }
};
int main() {
    Graph<string> g;

    g.addEdge("python","dataprocessing");
    g.addEdge("python","pytorch");
    g.addEdge("python","ML");
    g.addEdge("dataprocessing","ML");
    g.addEdge("pytorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","facerecogn");
    g.addEdge("dataset","facerecogn");

    g.dfs();
    
}

