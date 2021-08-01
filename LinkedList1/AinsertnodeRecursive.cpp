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

// void insertNode(Node *head, int i , int data){
Node *insertNode(Node *head, int i, int data)
{ // to insert the node in the start of LL we will have to return the new head to the main
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    //base case
    if (head == NULL)
    {
        return head;
    }

    //our work
    if (i == 0)
    {
        newNode->next = head;
        head = newNode; //update my head
        return head;
    }

    //recursive call
    head = insertNode(head->next, i - 1, data);

    temp -> next = head;
    head = temp;

    return head;

    /* // insert node at the start of LL
    if(i == 0){
        newNode -> next = head;
        head = newNode; //update my head 
        return head; // bcz main mai purana head hai toh hum updated head return karre hai
    } */

//   while(temp!=NULL && count < i-1){
//         temp = temp-> next;
//         count ++;
//     }

//     if(temp != NULL){//if i is greater than the LL size 
//     Node *a = temp-> next; // saving the address of the next node so that the further link is not broken // agle node ka address save kar diya
//     temp-> next = newNode; // put the address of the current node to the new node to create the link // pichle node ko naye ke sath joda
//     newNode -> next = a; // put the address of the next node into the new node // naye ko aage wale ke sath joda
//     }
    // OR
/*
    newNode -> next = temp ->next; //1st connecting the aage wala list
    temp -> next = newNode; // then connecting the previous wala list
*/

}

int main()
{
    Node *head = takeInput();
    print(head);
    int i, data;
    cin >> i >> data;
    head = insertNode(head, i, data);
    print(head);
}
