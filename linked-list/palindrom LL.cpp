#include <iostream>
#include<stack>
using  namespace std;
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
node* takeinput(int n){
    int data;
    int count=0;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(count<n){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
        count++;
    }
    return head;
}
bool IsPalindrom(node*head)
{
	node*temp=head;
	stack<int>s;
	while(temp!=NULL)
	{
		s.push(temp->data);
		temp=temp->next;
	}
	while(head!=NULL)
	{
		int i=s.top();
		s.pop();
		if(head->data!=i)
		{
			return false;
			break;
		}
		head=head->next;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	node*head=takeinput(n);
	int ans=IsPalindrom(head);
	if(ans==1)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false";
	}
	return 0;
}
