#include <iostream>
#include <cstddef>
using namespace std;
#include "node.cpp"


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


Node *removeDuplicates(Node *head)
{
    //Write your code here
	Node *curr = head;
    Node *t1 = head;
    Node *t2 = head -> next;
    
	if(head == NULL){
        return head;
    }
 
    while(t2 != NULL ){
     	
        
        while(t1-> data == t2 -> data){
         t2 = t2 -> next; 
            
        }
    	t1 -> next = t2;
        
        
        t1 = t1 -> next;
        t2 = t2 -> next;
    	
        
       
    }
    return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		head = removeDuplicates(head);
		print(head);
	}
	return 0;
}