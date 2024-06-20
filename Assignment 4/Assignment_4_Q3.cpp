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

void ispalindrome(Node** head){
    Node* it = *head;

    stack <char> check ;

    while(it != NULL){
        check.push(it -> data);
        it= it -> next;
    }

    it = *head;

    while(it != NULL){
        char i = check.top();

        check.pop();

        if(it -> data != i){
            cout<<"No is not a palindrome"<<endl;
            return;
        }
        

        it = it -> next;
    }

    cout<<"Yes is a palindrome"<<endl;
    return;

}

int main(){
    Node *x=NULL;
    insert(&x,1);
    insert(&x,2);
    insert(&x,8);
    insert(&x,2);
    insert(&x,1);

    ispalindrome(&x);
}   