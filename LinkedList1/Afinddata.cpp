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
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int findNode(Node *head, int val){
    // Write your code here.
    Node *curr = head;
    int count = 0;
    while(curr != NULL ){
        if(curr->data == val){
            return count;
        }
        curr = curr->next;
        count++;
    }
    return -1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNode(head, val) << endl;
	}
}