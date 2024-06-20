#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;
};

void insert(Node** head, int data)
{
	Node* new_node = new Node();

	Node* last = *head;

	new_node-> data =data;

	new_node->next = NULL;

	if (*head == NULL) {
		*head = new_node;
		return;
	}

	while (last->next != NULL) {
		last = last->next;
	}

	last->next = new_node;
	return;
}

void rotate(Node** head,int turns){
    Node* count = *head;
    int size =0;

    while(count != NULL){
        count = count -> next;
        size++;
    }

    if(turns % size == 0){
        Node* print = *head;
        while(print != NULL){
            cout<<print -> data<<" ";
            print = print -> next;
        }
        cout<<endl;
        return;
    }   
    
    Node* current = *head;

    for(int i=1 ; i<size-(turns%size) ; i++){
        current = current -> next;  
    }

    Node* print = current->next;
    Node* last = current->next;

    current -> next = NULL;

    while(last->next != NULL){
        last = last -> next ;
    }

    last -> next = *head;

    while(print != NULL){
        cout<<print -> data<<" ";
        print = print -> next;
    }
    cout<<endl;

}

int main(){
    Node *x=NULL;
    insert(&x,1);
    insert(&x,2);
    insert(&x,3);
    insert(&x,4);
    insert(&x,5);

    rotate(&x,5);
}