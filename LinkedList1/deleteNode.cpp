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
Node *deleteNode(Node *head, int i){ // to insert the node in the start of LL we will have to return the new head to the main
    int count = 0;
    Node *temp = head;

    //to delete the 1st node
    if(i == 0){
        Node *a = temp;
        Node *b = temp->next; 
        head = b;
        delete a;
        return head;
    }

    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        Node *a = temp->next; //current ka address store karne
        Node *b = a->next;    // delete wale node ke next ka address store karne
        temp->next = b;       // delete wale node ka address curr mai daal diya
        delete a;             // necessary to deallocate in dynamic allocation
    }

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
