#include<bits/stdc++.h>
#include<stack>
using namespace std;

class Queue{
	stack<int> s;
	public:
		
		void enqueue(int x){
			s.push(x);
			return;
		}
		
		int dequeue(){
			if(s.empty()){
				cout<<"Q is empty!"<<endl;
				exit(0);
			}
			int x=s.top();
			s.pop();
			
			if(s.empty()){
				return x;
			}
			int item=dequeue();
			s.push(x);
			return item;
			
		}
	
};
int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(7);
	
	
	cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n';
    return 0;
}
