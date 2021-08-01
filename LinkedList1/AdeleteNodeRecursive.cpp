#include <iostream>
#include <cstddef>
using namespace std;
#include "node.cpp"

//kyuki humara head ek pointer variable hai ,  kiska pointer node ka so node* is the return type
Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        // Node n(data); this will delete the 1st node after 1st iteration //making a node whose data will be 10 suppose and next null
        Node *newNode = new Node(data); //creating a new node dynamically
        if (head == NULL)
        {
            head = newNode; //saved the addres of 1st node
            tail = newNode;
        }
        else
        {

            tail->next = newNode; //to connect it w previous node(newNode is the address of the previous node)
            tail = tail->next;
            // OR
            // tail = newNode;
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
}

// void deleteNode(Node *head, int i ){
Node *deleteNode(Node *head, int i)
{ // to insert the node in the start of LL we will have to return the new head to the main
    int count = 0;
    Node *temp = head;
 

    if (head == NULL)
    {
        return head;
    }

    //our work
    if (i == 0)
    {
        Node *a = head;
        Node *b = head->next;
        head = b;
        delete a;
        return head;
    }

    // save the recursion wala list here
    Node *smallhead = deleteNode(head-> next, i - 1);

    head -> next = smallhead; // attach it to head ka next

   return head;
    
}

int main()
{
    Node *head = takeInput();
    print(head);
    int i;
    cin >> i;
    head = deleteNode(head, i);
    print(head);
}
