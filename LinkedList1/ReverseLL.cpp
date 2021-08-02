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

class Pair{
	public : 
	Node *head ;
	Node *tail;
};

Pair reverseLL_2(Node *head){
	if(head == NULL || head -> next == NULL){
		// return head; we can't return head as the datatype is Pair
		Pair ans; //created a object
		//jab head NULL hai toh obv head and tail same jagah head pe honge
		ans.head = head;
		ans.tail = head;
		return ans;
    }
    
    Pair smallans = reverseLL_2(head -> next); 
	//reversed list 4-3-2-NULL Head: &4 , Tail: &2 
    
	smallans.tail -> next = head;
	head ->next = NULL;

//    return smallans;iska return type again pair
   Pair ans;
   ans.head = smallans.head;
   ans.tail = head;
   return ans;
}

Node *ReverseLL_BETTER(Node *head){
	return reverseLL_2(head).head; // kyuki hume isme sirf head return karna hai
}


Node *ReverseLL(Node *head)
{
    Node *temp = NULL;
    Node *oghead = head;
    //Write your code here
    if(head == NULL){
		return head;
    }
    
    Node *smallhead = printReverse(head -> next);
    temp = smallhead;
	while(temp -> next != NULL){
		temp = temp -> next;
	}

	temp -> next = oghead;
	oghead -> next = NULL;

   return smallhead;
    
}

Node *ReverseLL_3(Node *head)
{
    if(head == NULL || head -> next == NULL){
		return head;
    }
    
    Node *smallhead = ReverseLL_3(head -> next);
   
	Node *tail = head -> next; //1 ke next mai 2  ka address tha
	tail -> next = head; //2 ke sath 1 join kiya
	head -> next = NULL;

   return smallhead;
    
}

Node *reverseLL_iterative(Node *head) {
    if(head == NULL){
        return head;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    
    while(curr != NULL){
        next = curr -> next; 
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
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
		// head = ReverseLL_BETTER(head);
		// head = ReverseLL_3(head);
		head = reverseLL_iterative(head);

		print(head);
	}
	return 0;
}