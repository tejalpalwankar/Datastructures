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



void printReverse(Node *head)
{
    Node *curr = head;
    //Write your code here
    if(head == NULL){
		return;
    }
    
    printReverse(curr -> next);
    
    if(curr == head){
        cout << head -> data << " "; 
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}