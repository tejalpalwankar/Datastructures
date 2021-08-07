#include <iostream>
using namespace std;
// #include "queueUsingArray.h"
// #include "queueUsingLL.h"
#include <queue>

int main(){
  
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