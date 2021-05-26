#include<bits/stdc++.h>
using namespace std;
class graph{
public:
	vector<int> size, parent;
	int total_comp;
		void initialize(int n){       // here i am initializing all required task.
			parent.resize(n);      
			size.resize(n);   //size[i] will contain the current size of the component in which i is the superparent(absolute root) of all vertices in the same component .if i is not the superparent of the component then it will contain 0, i.e size[i]=0
			for(int i = 0; i < n; i++){
				parent[i] = i;    // making , each node is the parent of itslf. by doing this i am initialize that all the vertices are now disconnected.
				size[i] = 1;     // since we have n components or n subsets initially , so obviously all components/subsets having  size  one .
			}
			total_comp = n; // from line 11, initially total no. of components will be n.as all are disconnected initially
		}
		int get_superparent(int x){   // this function is for returning the superparent or i can say the absolute root of the node x 
			if( parent[x]==x){
				return x;
			}
				return parent[x] = get_superparent(parent[x]);
		}
		void unite(int x, int y){   
			int superparent_x = get_superparent(x);   // finding the parent root of x
			int superparent_y = get_superparent(y);  // finding the parent root of y
			if(superparent_x != superparent_y){      // if they are not equal , it mean that they belong to different subset of the set which contains all the vertices.
				parent[superparent_x] = superparent_y;   // here i am taking union of x and y. and making superparent or simply parent of superparent_x is superparent_y
				size[superparent_y] += size[superparent_x]; //
				size[superparent_x] = 0;  // superparent_x is now  no more superparent_x of the component. so size[superparent_x]=0. because, i have  made superparent of superparent_x is superparent_y in line 26
				total_comp--;                     //  so after merging ,i mean after union the no. of components will be decreases.   
			}
		}
};
int main(){
	int n, m;
	cin >> n >> m;
	graph g;
	g.initialize(n); //this will initialize my all the required things 
	for(int i = 0; i < m; i++){  // at the end  of this for loop , we will have the different components of the graph, and their sizes.
		int x, y;
		cin >> x >> y;
		g.unite(x, y);// this will take the merge of vertices x and y.
	}
    int  ans = 0;
	for(int i = 0; i < n; i++){  // traversing through each vertices.
		int superparent_i = g.get_superparent(i);  // finding the super parent or i can say the absolute root.
		ans += (n - g.size[superparent_i]); // counting the number of nodes which are not in the same connected component and adding that to answer.here  g.sz[superparent_i]  will tell us that size(i.e no. of vertices) in the  component in which vertices i belongs.
	}                                  
	cout << (ans/2)<< endl;    // since each pair counted twice , so to get original answer , you need to devide by 2 the ans.for more clearence watch the hint video.
	/*for(int i=0;i<n;i++){
        cout<<g.size[i]<<" ";   // by uncommenting this for loop section you can  check that how the size array is building. (just for getting more confidence)
    }*/
    return 0;
}