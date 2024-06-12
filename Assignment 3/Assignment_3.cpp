#include <bits/stdc++.h>
using namespace std;


class Node{
    public:
    int roll_no,total_marks;
	string name,course;
    Node* next;
};


void insert(Node** head, int roll_no , string name , string course , int Total_marks)
{
	Node* new_node = new Node();

	Node* last = *head;

	new_node->roll_no = roll_no;
	new_node -> name = name;
	new_node -> course = course;
	new_node -> total_marks= Total_marks;

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

void del (Node** head, int id){
	
	if (*head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

	Node* last = *head;
	Node* slast = NULL;

	while(last != NULL){
		if(last -> roll_no == id){
			slast->next=(last->next);
			break;
		}
		slast=last;
		last=last->next;
	}

	if(last == NULL){
		cout<<"No such record present"<<endl;
	}
	return;
}

void show(Node** head){
	Node* last = *head;

	cout<<"Display all records"<<endl<<"Roll_No  Name  Course  Total_marks"<<endl;

	while(last != NULL){
		cout<<last->roll_no<<"  "<<last->name<<"  "<<last->course<<"  "<<last->total_marks<<endl;
		last=last->next;
	}
}

void search (Node** head , int id){
	Node* last = *head;
	bool flag = false;

	cout<<"Searching"<<endl<<"Roll_No  Name  Course  Total_marks"<<endl;

	while(last != NULL){
		if(last -> roll_no == id || last->total_marks==id){
			cout<<last->roll_no<<"  "<<last->name<<"  "<<last->course<<"  "<<last->total_marks<<endl;
			flag= true;
		}
		last = last->next;
	}

	if(flag == false ) cout<<"No such record present"<<endl;
}

void search (Node** head , string name){
	Node* last = *head;
	bool flag = false;

	cout<<"Searching"<<endl<<"Roll_No  Name  Course  Total_marks"<<endl;

	while(last != NULL){
		if(last -> name == name || last->course==name){
			cout<<last->roll_no<<"  "<<last->name<<"  "<<last->course<<"  "<<last->total_marks<<endl;
			flag= true;
		}
		last = last->next;
	}

	if(flag == false ) cout<<"No such record present"<<endl;
}

class Student{

    int roll_no,Total_marks;
    string name,course;

    public :

	Student(){}

    Student(int i , string name , string course , int Total_marks){
        roll_no=i;
        name=name;
        course=course;
        Total_marks=Total_marks;
    }


};

int main(){

    Node* San=NULL;

    insert(&San,1,"A","Mech",25);
    insert(&San,2,"B","CSE",32);
	
	search(&San,32);
	search(&San,"Mech");

	del(&San,2);
	show(&San);

    return 0;
}
