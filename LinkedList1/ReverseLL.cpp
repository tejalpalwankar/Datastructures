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

Node *printReverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *fwd = NULL;
    //Write your code here
    while(curr != NULL ){
        fwd = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

Node *ReverseLL(Node *head)
{
    Node *curr = head;
    //Write your code here
    if(head == NULL){
		return head;
    }
    
    // printReverse(curr -> next);
    // return head;
    Node *smallhead = printReverse(curr -> next);

    head -> next = smallhead; // attach it to head ka next

   return head;
    
}
// int main()
// {
// 	int t;
// 	cin >> t;
// 	while (t--)
// 	{
// 		Node *head = takeinput();
// 		cout << printReverse(head) << " ";
// 	}
// 	return 0;
// }

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		// head = printReverse(head);
		head = ReverseLL(head);

		print(head);
	}
	return 0;
}