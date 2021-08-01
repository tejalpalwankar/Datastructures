#include <iostream>
#include <cstddef>
using namespace std;
// #include "node.cpp"

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


int length(Node *head){
int count = 0;
    
    Node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

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


Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    Node *curr = head;
    Node *oghead = head;
    Node *tail = head;
    Node *newHead = head;
    
    int len = length(head);
    int part = len - n;
    int count = 1;
    while(curr != NULL){
        if(n== 0){
            return head;
        }
        if(count == part){
            newHead = curr -> next; 
            tail = curr;
        }
        if(curr -> next == NULL){
            curr -> next = oghead;
            head = newHead;
            tail -> next = NULL;
        }
        curr = curr -> next;
        count++;
        
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}