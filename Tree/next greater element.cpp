#include<iostream>
using namespace std;
#include<stack>
int main() {
	int n;
	cin>>n;
	int* arr=new int [n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int*  ans=new int[n];
	stack<int> s;
	 for (int i = 2 * n - 1; i >= 0; --i) {
            while (!s.empty() && arr[s.top()] <= arr[i % n]) {
                s.pop();
            }
            ans[i % n] = s.empty() ? -1 : arr[s.top()];
            s.push(i % n);
        }
        for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		delete  [] ans;
	delete [] arr;
	return 0;
    }
	
