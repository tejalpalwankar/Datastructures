#include <iostream>
#include <cstddef>
using namespace std;
#include "node.cpp"

void print(Node *head)
{   Node *temp = head;

 /*    // while(head -> next != NULL){ this condition won't print the last element as it is itself storing nulll //TO STOP AT LAST NODE
    while (head != NULL)// this loop will stop when head itself will become null //TO PRINT WHOLE LIST
    {                              
        cout << head->data << " "; // so then here each time head will contain next node and will print the data of that node
        head = head->next;         // this will now store the address of the next node
    } */

    while (temp != NULL)// this loop will stop when head itself will become null //TO PRINT WHOLE LIST
    {                              
        cout << temp->data << " "; // so then here each time head will contain next node and will print the data of that node
        temp = temp->next;         // this will now store the address of the next node
    }

    // if we want to print this list again it woont be possible as we have lost the address of head to avoid this we will store the address of head in a temp variable
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    // statically

    Node n1(1);
    Node *head = &n1; // saving the address of 1st node so that we do not loose our linked list

    Node n2(2);

    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head); //here we are passing the address of the 1st node
   // print(head); this will also print the ll again
    /*
    n1.next = &n2; // saving the address of n2 in n1's next

    cout << n1.data << " " << n2.data << endl;
    // printing bot of them only w the help of head


    // dynamically
    Node *n3 = new Node(10); 
    Node *head = n3;

    Node *n4 = new Node(20);
    n3 -> next = n4; // now since this is dynamically so n4 is the address of n4

 */
}