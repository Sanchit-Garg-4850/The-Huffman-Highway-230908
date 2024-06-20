#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* next = NULL;
};

void insert(Node** head, char data)
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

void strinsert(Node** head, string &str){
    Node* it = *head;
    int i=0;
    while(i<str.size()){
        insert(head,str[i]);
        i++;
    }
}

void printlist(Node** head){
    Node* print = *head;

    while(print != NULL){
        cout<<print -> data<<" ";
        print = print -> next;
    }
    cout<<endl;
    return;
}

int listsize(Node** head){
    Node* count = *head;
    int size =0;

    while(count != NULL){
        count = count -> next;
        size++;
    }

    return size;
}

int selreqnum(Node** head){

    int size = listsize(head);
    Node* it = *head;
    int smchar=123;
    vector <int> smcharidx;

    int i=0;
    while(it != NULL){
        if(int(it -> data) < smchar){
            smchar = it -> data;
        }
        it = it -> next;
    }
    
    Node* print = *head;

    while(print != NULL){
        if(int(print -> data) ==  smchar){
            smcharidx.push_back(i);
        }
        print = print -> next;
        i++;
    }

    for (auto it : smcharidx){
        cout<<it<<" ";
    }
    cout<<endl;

    int num=0;

    if(smcharidx.front() > size-smcharidx.back()){
        num=smcharidx.back();
    }else{
        num=smcharidx.front();
    }

    return num;
}

void rotate(Node** head, int num){
    int size = listsize(head);

    Node* current = *head;

    for(int i=1 ; i<num ; i++){
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

    string str;
    cin>>str;
    strinsert(&x,str);
    printlist(&x);
    int reqnum = selreqnum(&x);
    rotate(&x,reqnum);
}