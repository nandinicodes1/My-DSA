#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#define MOD 1000000007
#define dd double
#define pb push_back
#define mp make_pair

ll int findCost(vector<int> adj[],ll int a,ll int b,ll int v)
{
// array to keep track of visited vertices.
//1 indicates visited
//o indicates not yet visited
bool vis[v+1]={0};
//cost
ll int sum=0;
//queue for bfs
queue<int>q;
//pushing source
for(int i=1;i<=v;i++){  // for every connected components we have to evaluate the following 
    if(vis[i]==0){
        q.push(i);
        //iterate for all nodes
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(!vis[node])
            {
                //if not visited yet
                //1. either the source node
                //2. or the node that cannot be excessed through any road.
                sum=sum+a;
            }
            //marking the node as visited.
            vis[node]=true;
            //for all the adjacent nodes
            for(ll int j : adj[node])
            {
                //if not visited
                if(!vis[j])
                {
                    //if cost of road is less than temple, then make road
                    if(b<=a)
                    sum=sum+b;
                    //else make a temple
                    else
                    sum=sum+a;
                    // marking adjacent vertices as visited
                    vis[j]=1;
                    //pushing all the adjacent vertices
                    q.push(j);
                }

            }
        }   
    }

}
//return cost
return sum;
}

void solve(){
    ll int N,M,A,B;
    cin>>N>>M>>A>>B;
    vector<int> adj[N+1];
    for(ll int i=0;i<M;i++){
        ll int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }   
    cout<<findCost(adj,A,B,N)<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
