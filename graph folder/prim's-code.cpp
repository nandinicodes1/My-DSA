#include<bit/stdc++.h>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> gr[n+1];
    int visit[n+1]={};

    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        gr[x].push_back({y,w});
        gr[y].push_back({x,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

    Q.push({0,1});
    long long int mst=0;
    while(!Q.empty()){
        pair<int,int> best=Q.top();
        Q.pop();

        int weight=best.first;
        int to=best.second;

        //not an active edge
        if(visit[to]){
            continue;
        }
        mst+=weight;
        visit[to]=1;

        for(auto x:gr[to]){
            if(visit[x.first]==0){
                Q.push(x.second,x.first);
            }
        }
    }
    cout<<mst<<endl;
}
