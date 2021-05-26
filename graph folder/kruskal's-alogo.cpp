#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1,Edge e2){
    return e1.weight<e2.weight;
}

int findParent(int x,int *parent){
    if(parent[x]==x)
        return x;
    return findParent(parent[x],parent);
}

void kruskals(Edge* input,int n,int e){

    //sort input array in ascending order-based in weights
    sort(input,input+e,compare);

    Edge* output=new Edge[n-1];

    //create parent of every node to itself
    int *parent=new int[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }

    int count=0,i=0;
    while(count!=n-1){
        Edge current=input[i];

        //check if we can add the current in MST or not
        int sourceParent=findParent(current.source,parent);
        int destParent=findParent(current.dest,parent);

        if(sourceParent!=destParent){
            output[count]=current;
            count++;
            parent[sourceParent]=destParent;
        }
        i++;
    }
    for(int i=0;i<n-1;i++){
        if(output[i].source<output[i].dest)
        cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
    else
        cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }

    delete [] output;
    delete [] parent;
}

int main(){
    int n,e;
    cin>>n>>e;

    Edge* input=new Edge[e];
    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }

    kruskals(input,n,e);
    delete [] input;
    return 0;
}