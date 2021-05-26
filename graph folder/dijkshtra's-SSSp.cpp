#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

template<typename T>

class Graph{
    unordered_map<T,list<pair<T,int> > > m;
    public:
        void addEdge(T u,T v,int dist,bool bidir=true){
            m[u].push_back(make_pair(v,dist));

            if(bidir){
                m[v].push_back(make_pair(u,dist));
            }
        }

        void printAdj(){
            for(auto j:m){
                T key=j.first;
                cout<<key<<"-->";

                for(auto p:j.second){
                    cout<<"( "<<p.first<<","<<p.second<<" )";
                }
                cout<<endl;
            }
        }

        void dijkshtraSSSP(T src){
            unordered_map<T,int> dist;
            for(auto i:m){
                dist[i.first]=INT_MAX;
            }
            set<pair<int,T> > s;
            dist[src]=0;
            s.insert(make_pair(0,src));

            while(!s.empty()){
                auto p=*(s.begin());
                T node=p.second;

                int nodedist=p.first;
                s.erase(s.begin());
                //iterate over nbrs of node

                for(auto childPair:m[node]){
                    if(nodedist +childPair.second < dist[childPair.first]){
                        T dest=childPair.first;
                        auto f=s.find(make_pair(dist[dest],dest));

                        if(f!=s.end()){
                            s.erase(f);
                        }
                        dist[dest]=nodedist+childPair.second;
                        s.insert(make_pair(dist[dest],dest));
                    }
                }
            }
            for(auto d:dist){
                cout<<d.first<<" is located at dist of "<<d.second<<" from the source."<<endl;
            }
        }
};

int main(){
    Graph<int> g;

    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    //g.printadj();
    //g.dijkshtraSSSP(1);
    
    Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);

    //india.printAdj();
    india.dijkshtraSSSP("Amritsar");
    
    return 0;

}