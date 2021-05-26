#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;
	node(int data) {
		this->data = data;
		this->next = NULL;
	}
};


void print(node *head) {
    node* temp;
	temp = head;
	
    while(temp != NULL) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    cout<<endl;
    
}

int main() {
	node *head, *current;
	head = NULL;
	int n, temp;
	cin >> n;
	while(n--) {
		cin >> temp;
		node* newnode = new node(temp);
		
		if(head == NULL || head->data > newnode->data) {
			newnode->next = head;
			head = newnode;
		}
		else {
			current = head;
			while((current->next)->next != NULL && current->next->data < newnode->data)
				current=current->next;
		
			if((current->next)->next == NULL && (current->next)->data < newnode->data)
				current = current->next;
				
			newnode->next=current->next;
			current->next=newnode;
		}	
	}
	
	print(head);
}
