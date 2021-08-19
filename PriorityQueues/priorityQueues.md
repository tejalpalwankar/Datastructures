# Introduction

Suppose we have a flight reservation sys and all seats are booked and we have 10 passengers in waiting. Now 1 seat is available we need to decide whose passenger seat to give seat.  
1. First come first serve
2. VIP factor 
3. Age factor 
So basically w every element we have a importance factor.   

Suppose we have hospitals and all 20 rooms are booked :
1. First come first serve
2. Criticality factor

For these types of situations we have a data structure PRIORITY QUEUE:  
Queue is FIFO DS.  
Priority queue so the elements will come out on the basis of highest priority factor.  

**TYPES OF PRIORITY QUEUES** :  
1. Min : remove the element w  lowest priority
2. Max : remove the element w max priority  

IMP FUNCTIONS TO EXECUTE  :
- insert()
- getMax()/ getMin()
- removeMax() / removeMin()

# Ways to implement priority Queue

Suppose we have n numbers, so we have to either add or remove. lets assume ele and priority is same. from these elements i have to remove the min elements.  
- insert 
    1. ARRAY (unsorted) : go to the last and insert O(1)
    2. ARRAY (sorted) : traverse to correct pos and then create space O(n)
    3. LL (unsorted) : insert at head or tail O(1)
    4. LL (sorted) : correct position O(n)
    5. BST : O(height)
    6. BST (balanced) : O(logn)
    7. Hashmap : O(1)

- getMin / getMax 
    1. ARRAY (unsorted) : O(n)
    2. ARRAY (sorted) : O(1)
    3. LL (unsorted) : traverse LL O(n)
    4. LL (sorted) : O(1) head/tail
    5. BST : leftmost/rightmost O(height)
    6. BST (balanced) : O(logn)
    7. Hashmap : O(n)

- removeMin / removeMax 
    1. ARRAY (unsorted)  : to remove ele we have to shift the elements also so O(n)
    2. ARRAY (sorted) : we have the ele but shifting will take time O(n)
    3. LL (unsorted) : searching O(n)
    4. LL (sorted) : O(1) head/tail
    5. BST : leftmost/rightmost O(height)
    6. BST (balanced) : O(logn)
    7. Hashmap : O(n)

So the BEST SOLUTION IS : **BST**

# Heaps 

Issues w balanced BST :
- balancing
- storing complicated

For priority queues we are going to use Heaps.  
It's most  imp properties are :
1. Complete Binary Tree 
2. Heap order Property
## 1. Complete Binary Tree 
humare binary tree ke sab levels filled honge except last level ad the last level should also be filled from left to right.
<pre>
        1
       / \
      2   3
     / \ /     
    4  5 6  
It is a CBT

        1
       / \
      2   3
     /   / \     
    4    6  7
It is not a CBT
</pre>
So while inserting and deleting elements hume last level ke last element pe hee operation karna hai

# CBT and it's Implementation

How CBT overcomes the cons of BST ?  
1. Height 
2. store
### Height
min no of nodes w height h in CBT 
max no of nodes w height h in CBT

suppose h =4 of CBT 
MIN :
<pre>
        *       2^0
       / \
      *   *     2^1
     / \ / \    
    *  * *  *   2^2
   /
  *             1
</pre>
these are min nodes req for level 4 : 2^0 + 2^1 + ...... 2^(h-2) + 1  
it is a gp series so : 2^0(2^(h-1) - 1) = 2-1  
**so min no num of nodes : 2^(h-1)**  

MAX :
<pre>
        *       2^0
       / \
      *   *     2^1
     / \ / \    
    *  * *  *   2^2
</pre>
2^0 + 2^1 + ...... 2^(h-1)  
2^0(2^h- 1) = 2-1  = 2^h - 1  
**so min no num of nodes : 2^h - 1** 

for n nodes :
<pre>
2^(h-1) <=  n  <= 2^h - 1  
2^(h-1) <=  n  
after further calc we get  
h <= log n + 2  
       2

n  <= 2^h - 1
after further calc we get  
log (n + 1)  <= h
   2

log (n + 1)  <= h <= log n + 2  
   2                    2

O(log(n))  <= h <=  O(log(n))
     2                  2
 
</pre>

This proves that either in best or worst case the height of our BT is going to be log(n)  


### Store
Saves the CBT in the form of an array 
<pre>
        1
       / \
      2   3
     / \ / \ 
    4  5 6  7
</pre>
ARRAY : 1 2 3 4 5 6 7   
0th index ka child : 1,2  
1st index ka child : 3,4  
2nd index ka child : 5,6  
So **Right child : 2i + 1 , Left child : 2i + 2**  
**Parent : (CI - 1)/2**  
So insert karne ke liye nextIndex maintain karna hai , dlt karna hai nextIndex - 1 ko dlt

## 2. Heap Order property 
We have 2 types of heap :  
1. Min heap : Humare tree mai root ki value dono children se choti honi chaiye
<pre>
        10
       / \
     20   100
     / \ 
   30  60 
</pre>
2. Max Heap : Root ki value dono children se badi hogi
<pre>
        10
       / \
      5   9
     / \ / 
    3  1 8  
</pre>

### MIN Heap
### - **INSERT** : 
<pre>
         10
       /   \
     20     40
     / \   / \
   60 100 45  50
   / \
  80  15
</pre>
Suppose I want to insert 15 but that will destroy the property of min heap so compare 15 with its parent and do it till its reaches it correct position
<pre>
         10
       /   \
     15     40
     / \   / \
   20 100 45  50
   / \
  80  60
</pre>
so complexity is : worst case mai root tak kaam karna padega  O(n) but humare CBT ki height is O(logn)  so COMPLEXITY : O(logn)  
**This whole process is called UP-HEAPIFY**  

```C++
void insert(int element)
{
    pq.push_back(element);

    int childIndex = pq.size() - 1;

    while (childIndex > 0)
    {
        int parentIndex = (childIndex - 1) / 2;

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
```

### **- DELETE** 
<pre>
        10              
       / \
     20   30  
     / \ 
   40  100 

</pre>
Delete 10 but we can only delete 100 so we will swap both values and delete 10
<pre>
        100              
       / \
     20   30  
     / 
   40  
</pre>
now you can delete 10 , but heap ki property is violated because 100 is galat jagh pe toh humne 100 ko uske children ke sath compare karna chalu kiya and put 100 at it's correct position
<pre>
        20              
       / \
     40   30  
     /
   100   
</pre>
**This process is known as DOWN-HEAPIFY**
COMPLEXITY = O(h) = O(logn)  

CODE APPROACH :
<pre>
        10              
       / \
     20   100  
     / \
   30  40
</pre>
- save pq[0] in a ans var 
- pq[0] = pq[size-1]
- pq.pop_back
- Now satisfy heap order property
- ParentIndex 
- LeftChildIndex = 2PI + 1
- RightChildIndex = 2PI + 2 
- teeno maise jo bhi min hga usse swap karna hai 
- ab hume save karna hai vo value ko ki LCI ke sath replace kiya ya RCI ke saath, to solve this maintain minIndex so nayaparent banega minIndex
- we will have to check if both of our index are in limit 

```C++
int removeMin()
{
    // Write your code here
      if (isEmpty())
    {
        return 0;
    }

    int ans = pq[0];
    int remove = pq.size() - 1;
    pq[0] = pq[remove];
    pq.pop_back();

    int PI = 0;        
    int LeftChildIndex = 2 * PI + 1;
    int RightChildIndex = 2 * PI + 2;
    while (LeftChildIndex < pq.size())
    {   int minIndex = PI;

        if(pq[minIndex] > pq[LeftChildIndex]){
            minIndex = LeftChildIndex;
        }
        if(pq[minIndex] > pq[RightChildIndex] && RightChildIndex < pq.size()){
            minIndex = RightChildIndex;
        }
        if(minIndex == PI){
            break; 
        }
        int temp = pq[PI];
        pq[PI] = pq[minIndex];
        pq[minIndex] = temp;

        PI = minIndex;
        LeftChildIndex = 2 * PI + 1;
        RightChildIndex = 2 * PI + 2;
    }
    return ans;
}

```


### **- GET**  
root pe min value rakha hogab toh return that  
COMPLEXITY : O(1)  

```C++
int getMin()
{
    if (isEmpty())
    {
        return 0;
    }

    // it will be root thus will pe kept at 0th index
    return pq[0];
}
```

Try to create a min heap w these elements and then removemin() twice  

12 , 6, 5, 100 , 1 , 9 , 0 , 14

<pre>
      0
    /   \ 
   5     1
  / \   / \
14  12 9   6
/
100

Remove min 1:
Step 1: swap
     100
    /   \ 
   5     1
  / \   / \
14  12 9   6
/
0
Step 2 :Now remove 0 and put 100 at correct pos
      1
    /   \ 
   5     6
  / \   / \
14  12 9   100

Remove min 2 :
Step 1: swap
     100
    /   \ 
   5     6
  / \   / \
14  12 9   1
Step 2 :Now remove 1 and put 100 at correct pos
      5
    /   \ 
   14    6
  / \   / 
100 12 9   
</pre>

<pre>
Input :
int main(){
    priorityQueue p;

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
    cout << endl;
}
Output:
size :7
min :4
removed :4
removed :10
removed :15
removed :17
removed :21
removed :67
removed :100
</pre>

### MAX Heap
- INSERT : 
15, 2, 20 , 9 , 0 , 100

30
      100
     /  \
    9   30
   / \  / \
  2  0 15 20

<pre>
      100
     /  \
    9   20
   / \  / 
  2  0  15


Remove max :
step 1. swap
      15
     /  \
    9   20
   / \  / 
  2  0  100
step 2. Bring 15 to it's correct position
      20
     /  \
    9   15
   / \   
  2  0  
</pre>

```C++
#include <vector>

class PriorityQueue {
    // Declare the data members here
   vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        
        int childIndex = pq.size() -1;
        
        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            
            if(pq[childIndex] > pq[parentIndex]){
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

    int getSize() { 
        return pq.size();
    }
    
    int getMax() {
        if (isEmpty())
        {
            return 0;
        }
        // it will be root thus will pe kept at 0th index
        return pq[0];
    }

    int removeMax() {
        int ans = pq[0];
        pq[0] = pq[pq.size() -1];
        pq.pop_back();
        
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        
        while(leftChildIndex < pq.size() ){
            int minIndex = parentIndex;
            if(pq[parentIndex] < pq[rightChildIndex]){
                minIndex = rightChildIndex;
            }
            if(pq[parentIndex] < pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
        }
        
        return ans;
    }

    bool isEmpty() {
        return pq.size() == 0;

    }
};
```


# Inplace heap soert
Lets try to improve the space complexity which is O(n) and try to make it O(1)  
a -> 10 5 8 1 4  
we have got this array from user , and we want to sort from heap sort and baar baar remove min call karre hai . N remove min mai hum alag ek aur array banarahe hai. Lets try to modify our input array.  
Assume our heap has 1 ele 10 and all other ele are unsorted.Now I want to insert 5. 
<pre>
    10
    /
    5
if ele is small then swap

     5
    /
  10

  add 8
      5
    /  \
  10    8

lastly we get
     1
    /  \
   4    8
  / \
 10  5
</pre>
So our sorted array is 1 5 8 10 and now insert 4  
1 4 8 10 5  
now n times we want to call removemin to get the sorted array but instead of deleting I will just assume last index is not in heap  
DRAW A TREE AND WORK OUT  
1. removemin()  
5 4 8 10 | 1  
bring 5 at it's correct pos  
4 5 8 10 | 1  
2. removemin()  
10 5 8 | 4 1  
bring 10 at it's correct pos  
5 10 8 | 4 1  
3. removemin()  
8 10 | 5 4 1  
4. removemin()
10 | 8 5 4 1  
so it sorted in decreasing order , to sort in increasing order use maxheap  


Implementation :
i = 1 (assume it is already sorted)  
childindex : i=1  
Pi = 0  
then ci = pi do this till ci is 0 or equal to parent  
update i till i = vector ka size  
ab hume remive min func call karna hai

```C++
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
```
<pre>
Input : 5 ,1,2,0,8
output : 8 5 2 1 0 
</pre>

# Inbuilt priority Queue
**It is a MAX priority queue**  
#include < queue >  
priority_queue< int >  
isEmpty --> empty()  
getSize() --> size()  
void insert(ele) --> void push(ele)  
getMin() --> T top() (max ele you will get)  
T removeMin() --> void pop()  

```C++ 
    priority_queue<int> pq;

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
```
<pre>
size : 6
top : 167
167
45
32
16
7
1
</pre>

# K -sorted array
a -> 10 12 15 6 9  
we have to sort this array in decreasing order so after sorting :  
a -> 15 12 10 9 6  
k-sorted  array means hume jo inout array milra hai uska element i k-n pos left mai jaayega or k-n pos right mai jaayega  
<pre>
    k-1 left  <---  i ---> k-1 right
</pre>
so if your k=3 it will shift 3 or less than 3 position  

ex. 10 12 6 15 9  k=3  
    15 12 10 9 6  
All the elements shifted less than 3 pos except 15 i.e k=3 so it is not a k-sorted array  

ex. 10 15 6 4 5 k=2  
    15 10 6 5 4  
    so no ele is shifting more than 2 ele so it is a valid pos  

Lets see logic :  
a -> 12 15 7 4 9 k=3
0th index pe largest ele hoga abhi 0th index wala ele kaha hoga ? 3-1=2 , so either 0th, 1st or 2nd index pe.  
1st index : 0,1,2,3 . we already have the max from 0,1,2 so left is 12,7 so 12 will be placed at 1st index  
2nd index : 0,1,2,3,4  
so lets use a priority que here as we are always removing priority queue , so max prio queue.  
so each time just insert 3 ele and take max of those 3. and place it in the correct index then remove it  
maintain a priority queue of size k  


```C++
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
```

12 15 6 7 9  k=3
- sabse pehle humne apne heap mai 3 ele ko push kar diya 15 , 12 , 6.
- fir j=0 liya n i =k , then inside the for loop , pq.top = 15 which is teeno ka max fir remove kar diya . then we are putting the ele which is at i i.e k=3 so we inseted 7 in our heap . fir again top pe max hoga fir array mai 2 ele honge  
15 12  
- then follow the same steps and we get  
15 12 6 7 9  
- but ab yaha 15 12 sahi jagah pohch gaye toh as we are out of the for loop our array is sorted for n-k ele bcz other ele were placed in the heap.  
so next remove ele till heap is empty and put it in the arrray   

COMPLEXITY : 
- pehle for loop mai : since n ele ka comp is logn but our h is k so log and we are doing is klogk
- ek pop ki logk so (n-logk)  
- while ; klog 
klogk + nlogk - klog + klogk  
= (n + k)logk --> k will be quite small so ignore k  
= O(n)

# K -smallest elements from the array
a -> 8 5 12 10 0 1 6 9   k=4
from this we have to find 4 smallest elements.so first lets sort this array  
0 1 5 6 8 9 10 12 and then return the start 4 ele  
but the complexity of this will be O(nlogn) , but we want to imporove the complexity to O(nlogk).  
if we want to improve the complexity we cannnot do sorting so ...   
For 1 smallest ele : I will store min as 1st ele i.e and go and compare it with all the ele to find the min  
For k smallest ele : I will store k ele as min i.e 4 ele in our case .   
8 , 5, 12, 10  
to be ele all these ele have to be greater than others . now next ele is 0, and 0 sabse chota toh hum 12(largest) ko bahr nikalte hai n 0 ko andar daalte hai.  
8, 5, 0, 10  
next is 1 so comapre w all  
8, 5, 0, 1  
6, 5, 0, 1  
so we got our largest ele .  
so we have a set in which we always have to insert new ele and pop ele.

```C++
#include <queue>

vector<int> kSmallest(int input[], int n, int k) {
    // Write your code here
    priority_queue<int> pq;
    for(int i = 0; i<k; i++ ){
        pq.push(input[i]);
    }
    
    for(int i=k; i<n ; i++){
        int largest = pq.top();
        if(input[i] < largest){
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    vector<int> arr;
    while(!pq.empty()){
        arr.push_back(pq.top());
        pq.pop();
    }
    return arr;

}
 ```
 <pre>
 input :2 12 9 16 10 5 3 20 25 11 1 8 6  k=4
 output :1 2 3 5 
 </pre>

 # Inbuilt min priority queue

 Swapping in min heap : parent > child  
 Swapping in max heap : child  > parent  
greater int is a inbulit func which tells us when it is gonna swap so this is going to give us a mi heap

NOTES :
A	priority	queue	is	just	like	a	normal	queue	data	structure	except	that	each	
element inserted	is	associated	with	a	“priority”.  
It	supports	the	usual push(), pop(), top() etc	operations, but	is	specifically	
designed	so	that	its	first	element	is	always	the	greatest	of	the	elements	it	
contains,	i.e.	max	heap.  
In	STL,	priority	queues	take	three	template	parameters:  
 ```C++
 template	<class	T,
class	Container	=	vector<T>, class	Compare	=	less<typename	Container::value_type>
>
  ```
class	priority_queue;  
- The	first	element	of	the	template	defines	the	class	of	each	element.	It	
can	be	user-defined	classes	or	primitive	data-types.	Like	in	you	case	it	
can	be	int,	float	or	double.
- The	second	element	defines	the	container	to	be	used	to	store	the	
elements.	The	standard	container	classes	std::vector	and	std::dequeue	
fulfil	these	requirements.	It	is	usually	the	vector	of	the	class	defined	in	
the	first	argument.	Like	in	your	case	it	can	be	vector<int>,	vector<float>,	
vector<double>.
- The	third	element	is	the	comparative	class.	By	default	it	is	less<T>	but	
can	be	changed	to	suit	your	need.	For	min	heap	it	can	be	changed	to	
greater<T>

 ```C++ 
 
priority_queue<int , vector<int> , greater<int>> pq;

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
 ```
The	above	code	used	the	greater<T>	functional.	Below	is	the	code	using	a	
comparative	class	which	performs	operator	overloading.	The	code	below	will	
make	it	clear  
```C++
#include<iostream>
#include	<queue>
using namespace std;
class Comp{
  public:
  bool operator ()	(int a,	int b)	{
          return a	>	b;
  }
};
int main()	{
  priority_queue<int,	vector<int>,	Comp>	pq;
  pq.push(40);
  pq.push(320);
  pq.push(42);
  pq.push(42);
  pq.push(65);
  pq.push(12);
  pq.push(245);
  cout<<pq.top()<<endl;
  return 0;
}
 ```
 The	output for	both	the	code	will	be	12.  
 The priority_queue uses	the function inside	Comp	class to	maintain	the	
elements	sorted	in	a	way	that	preserves heap	properties(i.e.,	that	the	element	
popped	is	the	last	according	to	this strict	weak	ordering).  
In	above	example	we	have	used	custom	function	which	will	make	the	heap	as	
min-heap.  

 # K-largest elements 
same as k smallest 
```C++
#include <queue>
vector<int> kLargest(int input[], int n, int k){

	priority_queue<int , vector<int> , greater<int>> pq;
    for(int i = 0; i<k; i++ ){
        pq.push(input[i]);
    }
    
    for(int i=k; i<n ; i++){
        int smallest = pq.top();
        if(input[i] > smallest){
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    vector<int> arr;
    while(!pq.empty()){
        arr.push_back(pq.top());
        pq.pop();
    }
    return arr;
}
```