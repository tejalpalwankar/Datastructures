# Introduction

It is FIFO (First in first out)
There is a exit and a entry point.

1. enqueue(a)  : insert the element
2. front() : access the first element ; 
3. dequeue() : to delete an element from start;
4. size()
5. isEmpty()

so here we are going to maintain **nextIndex** which will be at the end where we are going to insert values. and then we will also maintain **firstIndex** to delete the values. it will basically hold the value of our 1st element.  
so yaha hum aage se delete karre hai and piche se elements daal rahe hai. Toh aage ka place toh blank hogaya. Toh humara queue pichese full honeke baad hum aage elements daalna shuru karte hai.  

```C++
template <typename T>

class queueUsingArray {
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    queueUsingArray(int s){
        data = new T[s];
        nextIndex= 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    //insert an element
    void enqueue(T element){
        if(size == capacity){
            cout << "Queue Full !" << endl;
            return;
        }
        data[nextIndex] = element;
        // isse humara queue piche is full hogaya toh aage se enter karne ke liye hau
        nextIndex = (nextIndex + 1) % capacity;
        if(firstIndex == -1){
            firstIndex =0;
        }
        size++;
    }

    T front(){
    if(isEmpty()){
        cout << "Queue is Empty " << endl;
        return 0;
    }
    return data[firstIndex];
}

    T dequeue(){
    if(isEmpty()){
        cout << "Queue is Empty " << endl;
        return 0;
    }
    T ans = data[firstIndex];
    firstIndex = (firstIndex + 1) % capacity;
    size--;
    //agar humara queue sab operations ke baad empty hogaya
    if(size == 0){
        firstIndex = -1;
        nextIndex = 0;
    }
    return ans;

    }
};
```

# Dynamic queue

To remove the constraint of size, we will be using dynamic queue. agar hum queue ke elements ko direct copy karre hai toh dequeue mai gadbad hoga.  
<pre>
old array which is full
 0  1  2  3  4 
30 40 50 10 20

new array
          NI,FI on 3       
 0  1  2  3  4  5  6
30 40 50 10 20 60
</pre>

If we remove 10 and 20 the next element which will be removed is 60 which is wrong.
new array mai jis order mai humne ele enter kiye the wahi order mai jaayenge.soo 
- FI se loop run karenge and last tak jaayenge.
- Then 0 se wapas FI tak jaayenge and copy karte hai.
- Fir FI = 0 and NI = capacity
<pre>
 0  1  2  3  4 5
10 20 30 40 50 60
</pre>

```C++ 
void enqueue(T element)
    {    //function for dynamic array
        if (size == capacity)
        {
            T *newData = new T[capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newData[j] = data[i];
                j++;
            }
            for (int i = 0; i < firstIndex; i++)
            {
                newData[j] = data[i];
                j++;
            }
            delete[] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
        }

        data[nextIndex] = element;
        // isse humara queue piche is full hogaya toh aage se enter karne ke liye hau
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }
```

# Queue using LL

maintain head,tail and size.
enqueue : create newnode and tail ke next mai new node and update tail.
size : return size;  
front() : return head;
dequeue : save data of head , deallocate and move head to next  
isempty : is size 0;

```C++ 
template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queueUsingLL{
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:

    queueUsingLL(){
        head = NULL;
        tail = NULL;
        size =0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T element){
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{tail -> next = newNode;
        tail = newNode;}
        size++;
    }

    T front(){
        if(isEmpty()){
            return 0;
        }
        return head -> data;
    }

    T dequeue(){
        if(isEmpty()){
            return 0;
        }
        Node<T> *temp = head;
        T ans = head ->data ;
        temp = temp -> next;
        delete head;
        head = temp;
        size--;
        return ans;
    }

};
```

# Inbuilt Queue

#include < queue >

1. enqueue : void push(T element)
2. front same
3. T dequeue : void pop();
4. int getSize : int size()
5. bool isEmpty : bool empty()

# int main()

```C++ 
#include <iostream>
using namespace std;
// #include "queueUsingArray.h"
// #include "queueUsingLL.h"
#include <queue>

int main(){
    // using inbuilt queue
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    cout << "front " << q.front() << endl;
    q.pop();
    cout << "front " << q.front() << endl;
    cout << "size " << q.size() << endl;
    cout << "empty " << q.empty() << endl;

    while (!q.empty())
    {
        /* code */
        cout << q.front() << endl;
        q.pop();
    }
    
    /* queueUsingLL<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << "q.front()" << q.front() << endl;
    cout << "q.dequeue()" << q.dequeue() << endl;
    cout << "q.dequeue()" << q.dequeue() << endl;
    cout << "q.dequeue()" << q.dequeue() << endl;

    cout << "q.getsize()" << q.getSize() << endl;
    cout << "q.isEmpty()" << q.isEmpty() << endl; */
}
```

# reverse queue

first save our top and then remove it from our queue . then called recursion on the whole queue . fir top is placed at it's right position.

```C++
#include <queue>
void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.size() < 1){
        return;
    }
    
    int top = input.front();
    input.pop();
    
    reverseQueue(input);
    
    input.push(top);
    
}

```