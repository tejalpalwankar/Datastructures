#include <iostream>
using namespace std;
// #include "MinpriorityQueue.h"
#include <queue>

void heapSort(int pq[], int n) {
    // Build the heap
    for(int i =1 ; i < n ; i++){
        int childIndex = i;
        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    // remove elements
    int size = n;
    while(size > 1){
      //swapping 1st element
        int temp = pq[0];
        pq[0] = pq[size-1];
        pq[size-1] = temp;
        size--;

        int parentIndex = 0;        
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < size){
            int minIndex = parentIndex;

            if(pq[minIndex] > pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(pq[minIndex] > pq[rightChildIndex] && rightChildIndex < size){
                minIndex = rightChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[parentIndex] ;
            pq[parentIndex] = pq[minIndex];
            pq[minIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}

void kSortedArray(int input[], int n, int k){
    priority_queue<int> pq;
    for(int i = 0; i<k; i++ ){
        pq.push(input[i]);
    }

    int j = 0; // this will figure out sorted array ke konse index pe apna ele jaana chaiye
    for(int i=k; i<n ; i++){
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    while(!pq.empty()){
        input[j] = pq.top();
        pq.pop();
    }

}

int main(){
    /* priorityQueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << "size :" << p.getSize() << endl;
    cout << "min :" << p.getMin() << endl;

    while(!p.isEmpty()){
        cout << "removed :" << p.removeMin() << endl;
    }
    cout << endl; */

/*     int input[] = {5 ,1,2,0,8};
    heapSort(input, 5);
    for(int i=0; i < 5; i++){
        cout << input[i] << " ";
    }
    cout << endl; */

// MAX HEAP INBUILT
 /*    priority_queue<int> pq;

    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "size : " << pq.size() << endl;
    cout << "top : " << pq.top() << endl;

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    } */

/*     int input[] = {10,12,6,7,9};
    int k =3;
    kSortedArray(input,5, k);
    for(int i=0; i< 5; i++){
        cout << input[i] << " ";
    } */

    // MIN HEAP INBUILT
    priority_queue<int , vector<int> , greater<int>> pq;
    // greater int is a inbulit func which tells us when it is gonna swap
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "size : " << pq.size() << endl;
    cout << "top : " << pq.top() << endl;

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
}