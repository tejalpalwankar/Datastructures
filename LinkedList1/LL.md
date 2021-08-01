This is my 1st LL program

```C++

#include <iostream>
#include <cstddef>
using namespace std;
#include "node.cpp"


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
        if(head == NULL){
            head = newNode; //saved the addres of 1st node
            tail = newNode;
        }
        else{
          
            tail -> next = newNode; //to connect it w previous node(newNode is the address of the previous node)
            tail = tail -> next;
            // OR 
            // tail = newNode; 
        }
    
        cin >> data ;
    }
    return head;
}


int count = 0;
int length(Node *head){
    Node *temp = head;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

// void print(Node *head){
//     Node *temp = head;
//     while(temp!= NULL){
//         cout << temp -> data << " ";
//         temp = temp -> next;
//     }
// }

int main(){
    Node *head = takeInput();
    int c = length(head);
    cout << c << endl;
}

```