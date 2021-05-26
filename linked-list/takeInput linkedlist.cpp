#include <iostream>
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
    int c=0;
    cin>>data;
    c++;
    node* head=NULL,*tail=NULL;
    while(c<=n){
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
        c++;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
	int n;
	cin>>n;
    node* head=takeinput(n);
    print(head);
    return 0;
}

