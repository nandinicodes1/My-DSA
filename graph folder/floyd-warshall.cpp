#include<bits/stdc++.h>
using namespace std;

#define INF 99999

void floydWarshall(int n,int &matrix[v][v]){
	for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                int curr=matrix[i][j];// distance from i to j
	                int a=matrix[i][k];// distance from i to k (k is intermediate to path from i to j)
	                int b=matrix[k][j];//distance from k to j
	                if(a==-1 || b==-1)continue;
	                if(curr==-1)matrix[i][j]=a+b;
	                else
	                matrix[i][j]=min(curr,a+b);
	            }
	        }
	    }
}



int main(){
	int n;
	cin>>n;
	int matrix[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>matric[i][j];
		}
	}
	floydWarshall(n,matrix);

}
