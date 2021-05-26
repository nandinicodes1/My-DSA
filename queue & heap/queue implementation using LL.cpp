#include<bits/stdc++.h>
#include<list>
using namespace std;
class queue{
	int cs;
	list<int> qu;
	public:
		queue()
		{
			this->cs=0;
		}
	bool isEmpty(){
		return this->cs==0;
	}	
	void enqueue(int data)
	{
		this->qu.push_back(data);
		this->cs+=1;	
	}
	void dequeue(){
		if(!isEmpty)
		{
			this->cs-=1;
			this->qu.pop_front();
		}
	}
	int getFront()
	{
		return this->qu.front();
	}
	
};
int main()
{
	queue q(10);
	for(int i=1;i<=6;i++)
	{
		q.enqeue(i);
	}
	q.dequeue();
	q.enqueue(8);
	if(!isEmpty)
	{
		cout<<q.getFront()<<endl;
		q.dequeue();
	}
	return 0;
}

