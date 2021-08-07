# Operations On stacks

It is a LIFO(last in first out) type of data structure.  
In stack all the operations are performed with the complexity of O(1) which is v better.  

1. Push() : It is used to insert an element in a stack
2. Pop() : It is used to remove a element from the top of the stack
3. top() : It is used to read the topmost element of the stack
4. size() : it gives us the size of the stack
5. isEmpty() : It tells us whether the stack is Empty

Recursion uses stack to store it's data

# Class for making a stack
 ```C++   
 
class stackUsingArray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    stackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    //return the number of elements present in our stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        /*   if(nextIndex == 0){
            return true;
        }
        else{
            return false;
        } */
        // OR
        return nextIndex == 0;
    }

    //insert elemnt
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "stack is Full" << endl;
            return;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    //delete element
    int pop()
    {   
        if(isEmpty()){
            cout << "stack is empty" << endl;
            return INT_MIN; 
    }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
         if(isEmpty()){
            cout << "stack is empty" << endl;
            return INT_MIN; 
        }
        return data[nextIndex - 1];
    }
};
  ```

# Dynamic Stack

The stack we created previously was creating an array of fixed size which we do not want.  
so now we will use dynamic stack which will double the size of the array , copy the elements of the previous array rather than display stack is full.

So if the stack is full 
- craete an array of double the size
- copy elements of the previous array in the new array using a loop
- deallocate the previous array and data will point to the new array
- capacity will also be updated now

```C++ 
//insert elemnt
    void push(int element)
    {
        if (nextIndex == capacity)
        {
            int *newData = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
    }
```

# Templates

Suppose we want to create a class Pair{} , the datatype of each element will be int . now if you want to create a same class pair{} of double or char datatype you will have to replace all int by double/char. To avoid this we can create a Template. The datatype will be T (temporary datatype)instead of mentioning any datatype.

To declare the template
```C++ 
template <typename T> 

class Pair{
    T x;
    T y;

    public :

    void setX(T x){
        this -> x = x;
    }

    T getX(){
        return x;
    }

    void setY(T y){
        this -> y = y;
    }

    T getY(){
        return y;
    }
};
```

We have to specify T when we are creating   the object of the class because when we are creating object humare data members ko memory allocate hogi and tab hume uska datatype pata hona chaiye.

To create object 
```C++ 
    Pair<int> p1;
    p1.setX(10);
    p1.setY(20);

    cout << p1.getX() << " " << p1.getY() << endl;

    Pair<double> p2;
    p2.setX(10.67);
    p2.setY(20.89);

    cout << p2.getX() << " " << p2.getY() << endl;

    Pair<char> p3;
 ```

 we can also use 2 temp datatypes

 ```C++ 
template <typename T, typename V>

class Pair{
    T x;
    V y;

    public :

    void setX(T x){
        this -> x = x;
    }

    T getX(){
        return x;
    }

    void setY(V y){
        this -> y = y;
    }

    V getY(){
        return y;
    }
};

//objects
Pair<int , double> p1;
    p1.setX(100);
    p1.setY(100.34);
 ```

Similarly we can also create a **triplet** with 3 diffrent datatypes

```C++
    Pair<Pair<int , int>, int> p2;
    p2.setY(10);
    //for p2 ka X pair we made another object
    Pair<int, int> p4;
    p4.setX(5);
    p4.setY(16);

    p2.setX(p4);

    cout << p2.getX().getX() << " " << p2.getX().getY() << p2.getY() << " "  ;
```


# Stack using Template

Changes in the class of Stack:  
1. datatype of data T
2. in push(T element)  
the dynamic array making a new array    T *newData = new T[2 * capacity];  
3. T pop()
4. T top()
5. return 0 instead of INT_MIN in top() and pop()

```C++
int main(){
    StackUsingArray<char> s;
    s.push(100);
    s.push(102);
    s.push(103);
    s.push(104);
}

```
**OUTPUT**  
h  
g  
f  
e  

 
# Stack using LL


1. **push()** : simply maintain a head and tail. when head is null both head and tail will point at the same place. then move tail forward.  
**New push()**: to improve complexity of pop() instead of moving tail forward , lets insert the new elements at head  and update the head. complexity: O(1).
2. **top()** : return tail.  
**New top()**: return head
3. **pop()**: tail should be deleted and new tail should be prev number. So lets maintain a prev pointer.but again if we call pop(), it cannot go back this time. So we have to travel from head to tail to bring it back.
so pop() is O(n). So lets make new push().  
**New pop():** delete head and update head to next. 
4. **size()**: maintain int size. whenever push() size++ . whenever pop() size--;
5. **isEmpty()** : Just check if head is NULL.

```C++ 
    
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
```

# Inbuilt Stack

#include "stackUsingArray.h" : to make it a header file

### Difference between our stack and Inbuilt stack

stack<int> s1;  
push(T ele)  ->   s1.push()  {same}  
T pop;       ->   void pop() {return type diff}  
T top()      ->   T top()    {same}
size         -> size()       {same}
isEmpty()    ->  empty()


# Balanced paranthesis (problem)

First hume yaha koi opening bracket mila toh hum usse stack mai insert kar rahe hai.  
fir else mai hum bass check karr rahe hai ke vo stack ke top wala bracket and expression wala bracket same hai kya. if same toh true and continue others false return karna hai.

```C++ 
#include <stack>

bool isBalanced(string expression) 
{
  
    stack<char> s;
    for(int i=0 ; i< expression.length() ; i++){
 
		if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{'){
				s.push(expression[i]);
        }
        
        else if(expression[i] == ')' || expression[i] == ']' || expression[i] == '}'){
             if(s.empty()){
				return false;
             }
             int ch = s.top();
             s.pop();
             
             if(expression[i] == ')' && ch =='('){
                 return true;
                 continue;
             }
             else if(expression[i] == ']' && ch =='['){
                 return true;
                 continue;
             }
             else if(expression[i] == '}' && ch =='{'){
                 return true;
                 continue;
             }
             else{
                return false;
             }   
            }
        }   
}
```
# Reverse a stack

You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.

Caution : We do not have to reverse the helper stack , we have to reverse the original stack  

So instead of 1 helper we can have 2 helper but in the question only  1 stack is passed.
so lets use recursion  

- store the top of stack in temp
- So ask the recursion to reverse original stack
- but top should be placed at the bottom of our stack so lets remove the elements and put it in helper .
- now place temp at the bottom and move from helper to og
- base case : sigle or no elements

```C++ 
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    
    if(input.size() == 0 || input.size() == 1){
        return;
    }
    
    int temp = input.top();
    input.pop();
    reverseStack(input, extra);
    
    while(!input.empty()){
        int newS ;
        newS = input.top();
        input.pop();
        extra.push(newS);
    }
    
    input.push(temp);
    
    while(!extra.empty()){
        int newS ;
        newS = extra.top();
        extra.pop();
        input.push(newS);
    }   
}
```


# Redundant Brackects


Lets take an example :  
( a + b )  
once we encounter the closing bracket , we have to count all the info between it and the opening. so pop all and maintain a count which will be 3. b , + , a. that means the brackets are usefull and not redundant.   Answer : FALSE 

Lets take an example :  
(( a + b ))  
so first we encounter (a + b) which is useful as we have seen previously. now reset the count = 0 , and push everything before next closing brackets, and here the count = 0. so not usefull brackets.  
Answer : TRUE

Lets take an example :  
( a + (b + c ))  
encounter a closing bracket  till then push
pop till opening bracket , count = 3  
reset count = 0  
again pop   
now count = 2  
Answer : FALSE

```C++
#include <stack>

bool checkRedundantBrackets(string expression) {

    stack<char> s;
    for(int i=0 ; i< expression.length() ; i++){

        if(expression[i] != ')'){
            s.push(expression[i]);  
        }

        else{

            int count = 0;
            while(s.top() != '('){
                s.pop();
                count++;
            }
            s.pop();
            if(count <= 1){
                return true;
            }

        }
    }
    
    return false;
}
 ```