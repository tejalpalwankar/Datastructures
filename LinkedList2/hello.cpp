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



Node *midPoint(Node *head)
{
    // Write your code here
    Node *slow = head;
    if(slow == NULL){
        return head;
    }
    
    Node *fast = head-> next;
    
    
    
    while(fast != NULL && fast -> next != NULL  ){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

int length(Node *head){
int count = 0;
    Node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

Node *mergeTwoSortedLinkedLists(Node *h1, Node *h2)
{
    //Write your code here
    Node *fhead = NULL;
    Node *ftail = NULL;
    
    if(h1 == NULL){
        return h2;
    }
    
    if(h2 == NULL){
        return h1;
    }

    if(h1 -> data < h2 -> data ){
            fhead = h1;
            ftail = h1;
            h1 = h1 -> next;
        }
    else{
            fhead = h2;
            ftail = h2;
            h2 = h2 -> next;
        }
        

    while(h1 != NULL && h2 != NULL){
        if(h1 -> data < h2 -> data){
            ftail -> next = h1;
            ftail = h1;
            h1 = h1 -> next;
        }
        else {
            ftail -> next = h2;
            ftail = h2;
            h2 = h2 -> next;
        }
        
    }
    
    if(h1 == NULL){
        ftail -> next = h2;
    }
    
    if(h2 == NULL){
        ftail -> next = h1;
    }
    
    return fhead;
}


Node *mergeSort(Node *head)
{
	//Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *sorthead = NULL;
    
    Node *mid = midPoint(head);
    Node *newHead = mid -> next;
    mid -> next = NULL;
    
    head = mergeSort(head);
    newHead = mergeSort(newHead);
    
	sorthead = mergeTwoSortedLinkedLists(head , newHead);
    
    return sorthead;
}



int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		head = mergeSort(head);
		print(head);
	

	}

	return 0;
}