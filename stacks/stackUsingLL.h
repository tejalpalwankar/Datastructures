#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next; //jabhi koi class template se banegi jaha bhi hum usse use karenge hume uska datatype mention karna padega <T>

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};

template <typename T> // for every class it will be different
class Stack
{
private:
    /* data */
    Node<T> *head ;
    int size;

public:
    Stack()
    {
        // head = NULL
        // size =0
        head = NULL;
        size = 0;
    }

    bool isEmpty()
    {
      return size == 0;
    }

    void push(T element)
    {
        // create new node if head is null
        //new ke next mai head n update head
        //size++
		Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    T pop()
    {
        //save head -> data in ans
        //deallocate node
        //size --
        //check if head null
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        delete temp;
        head = head -> next;
        size--;
        return ans;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "stack is empty" << endl;
            return 0;
        }
        return head->data;
    }

    int getSize()
    {
        return size;
    }
};
