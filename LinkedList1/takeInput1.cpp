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
    while (data != -1)
    {
        // Node n(data); this will delete the 1st node after 1st iteration //making a node whose data will be 10 suppose and next null
        Node *newNode = new Node(data); //creating a new node dynamically
        if(head == NULL){
            head = newNode; //saved the addres of 1st node
        }
        else{
            // head -> next = newNode ;wrong because it will always connect head to the new node and not prev to the new node //to store the address of the next node 
            Node *temp = head; //to travel through my LL
            //this part increasing the complexity
            while(temp -> next != NULL){
                temp = temp -> next; //to traverse to the next node
            }
            temp -> next = newNode; //to connect it w previous node(newNode is the address of the previous node)
        }
    
        cin >> data ;
    }
    return head;
}

void print(Node *head){
    Node *temp = head;
    while(temp!= NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main(){
    Node *head = takeInput();
    print(head);
}


// COMPLEXITY 
/* 1 - k times work inside while loop 
2 - 1
3 - 2
4 - 3
n - n-1 
the complexity is n^2 which is v badd  */