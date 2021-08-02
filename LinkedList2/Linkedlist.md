# MID OF LINKED LIST

## With length of LL 
 In case of odd :
 len = 5 
 (len-1)/2 = 2 

 In case of even
 len = 4
 (len-1)/2 = 2

## Without length of LL 


1. slow :  
    -slow on head  
    -move by 1  
    -slow -> next  
2. fast :  
    -fast on head -> next  
    -move by 2  
    -fast -> next -> next  
    -fast or fast ka next can never be null  
AS SOON AS FAST REACHES NULL SLOW WILL BE ON THE MIDPOINT

**For_ODD** : slow will be on midpoint when FAST == NULL  
**For_EVEN** : slow will be on midpoint when FAST -> NEXT == NULL 

``` C++
Node *midPoint(Node *head)
{
    Node *slow = head;
    if(slow == NULL){
        return head;
    }
    Node *fast = head-> next;
    
    while(fast != NULL && fast -> next != NULL  ){ //for even and odd both conditions are written together
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
```
**OUTPUT**  
1 2 3 4 5 6 -1
3  
1 2 3 4 5 6 -1  
4  


# Merge 2 sorted Linked List
h1  
1 5 10 12 20 NUll

h2  
2 3 6 11 NUll

fh : final head , ft : final tail
1. fh = null , ft = null
2. pehle compare dono ke head 
3. fir dono(fh, ft) h1 ko point karenge and h1 ko aage move karna hai ( 5 pe)
4. abhi h1 and h2 ko compare karo toh h2 (2) chota hai toh ,  ft ke next mai h2 daal diya
5. Fir tail ko update karo h2 
6. fir h2 ko update karna hai h2-> next
7. h1 ya h2 maise koi NULL hua toh vo loop se bahar aana hai
8. dono ke liye separate loops banayenge to join the remaining
9. return fh

```C++

Node *mergeTwoSortedLinkedLists(Node *h1, Node *h2)
{
    //Write your code here
    Node *fhead = NULL;
    Node *ftail = NULL;
    
    //if any one of them is null 
    if(h1 == NULL){
        return h2;
    }
    
    if(h2 == NULL){
        return h1;
    }

    // to initialize the fh and ft
    if(h1 -> data < h2 -> data ){
            fhead = h1;
            ftail = h1;
            h1 = h1 -> next;
        }
    else{
            fhead = h2;
            ftail = h2;
            h2 = h2 -> next;
        }
        
    //to compare elements one by one
    while(h1 != NULL && h2 != NULL){
        if(h1 -> data < h2 -> data){
            ftail -> next = h1; // tail ko join kiya
            ftail = h1; // tail ko update
            h1 = h1 -> next; // h1 ko aage badhaya
        }
        else {
            ftail -> next = h2;
            ftail = h2;
            h2 = h2 -> next;
        } 
    }
    
    // remaining LL
    if(h1 == NULL){
        ftail -> next = h2;
    }
    
    if(h2 == NULL){
        ftail -> next = h1;
    }
    
    return fhead;
}

```

# Merge Sort

* it works on divide and conquer

1. Break the LL in 2 halves : find mid and break it.
2. call recursion on 2 halves (assume both halves are sorted)
3. Merge the 2 sorted halves
4. Return new head

``` C++ 
Node *mergeSort(Node *head)
{
	//Write your code here
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node *sorthead = NULL;
    
    //divided list in 2 halves
    Node *mid = midPoint(head);
    Node *newHead = mid -> next;
    mid -> next = NULL;
    
    //called recursion on both the halves
    head = mergeSort(head);
    newHead = mergeSort(newHead);
    
    //merged the 2 sorted halves
	sorthead = mergeTwoSortedLinkedLists(head , newHead);
    
    return sorthead;
}
```

# Reverse Linked List (Recursive)

3 steps to be followed  
- base case : if it reaches null
- recursive call (head -> next) : 5 4 3 2 
- our work : join 1 to the end of the list and the head -> next will be null

``` C++ 

Node *ReverseLL(Node *head)
{
    Node *temp = NULL;
    Node *oghead = head;
    //base case
    if(head == NULL){
		return head;
    }
    //recursive call
    Node *smallhead = printReverse(head -> next);

    //attach head to the end of the LL
    temp = smallhead;
	while(temp -> next != NULL){
		temp = temp -> next;
	}

	temp -> next = oghead; // end mai 1 lagaya
	oghead -> next = NULL; // 1 ke aage khatam LL

   return smallhead;
    
}

```
Complexity : T(n) = T(n-1) {recursive call ka} + (n-1)  
T(n-1) = T(n-2) + (n-2)  
T(n-2) = T(n-3) + (n-3)  
.  
.  
________________________  
T(n) = (n-1) + (n-2) + ... 1  
n^2 (which is really bad)  
``` C++ 
temp = smallhead;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
```
here again and again we are finding the tail of the reversed list.  
Instead of this we can simply maintain  a TAIL.  
But it is not possible to return Multiple values from a Function.  
To solve this we can just create a CLASS and then return the object of that class.  

# Rverse LL (Recursive) using class to improve complexity

``` C++

class Pair{
	public : 
	Node *head ;
	Node *tail;
};

Pair reverseLL_2(Node *head){
	if(head == NULL || head -> next == NULL){
		// return head; we can't return head as the datatype is Pair
		Pair ans; //created a object
		//jab head NULL hai toh obv head and tail same jagah head pe honge
		ans.head = head;
		ans.tail = head;
		return ans;
    }
    
    Pair smallans = reverseLL_2(head -> next); 
	//reversed list 4-3-2-NULL Head: &4 , Tail: &2 
    
	smallans.tail -> next = head;
	head ->next = NULL;

//    return smallans;iska return type again pair
   Pair ans;
   ans.head = smallans.head;
   ans.tail = head;
   return ans;
}

Node *ReverseLL_BETTER(Node *head){
	return reverseLL_2(head).head; // kyuki hume isme sirf head return karna hai
}

```
Complexity : T(n) = T(n-1) {recursive call ka} + K  
Final : O(n) WHICH IS BETTER COMPLEXITY  

 # Rverse LL (Recursive) Simplest Way

 we did all this only to figure out the tail  
 we never realised ke humara tail humesha se head ke next mai he tha  

 ``` C++ 
 Node *ReverseLL_3(Node *head)
{
    if(head == NULL || head -> next == NULL){
		return head;
    }
    
    Node *smallhead = ReverseLL_3(head -> next);
   
	Node *tail = head -> next; //1 ke next mai 2  ka address tha
	tail -> next = head; //2 ke sath 1 join kiya
	head -> next = NULL;

   return smallhead;
    
}
 ```
 # Rverse LL (Iterative) 

 1 -> 2 -> 3 -> 4 -> 5 -> NULL  LL  
 NULL <- 1 <- 2 <- 3 <- 4 <- 5  Reversed LL  
prev   curr  next
- **prev = NULL**
- **curr = 1**
- we want 1 to point null but we will loose 2
- 1st save **next = curr -> next**
-  **c -> next = prev** i.e 1 ke next mai ab NULL hoga
- prev will move to curr
  curr will move to next 
- STOP when **curr = NULL** and **Return prev**
```C++ 
Node *reverseLL_iterative(Node *head) {
    if(head == NULL){
        return head;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    
    while(curr != NULL){
        next = curr -> next; 
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
} 
```

# Types Of Linked List

## 1. Single Linked List
we can only move in 1 direction
 1 -> 2 -> 3 -> 4 -> 5 -> NULL  

 Node class {
     int data;
     Node *next ;
 }

 Memory Used : data:4 address:8 = 12bytes  

## 2. Double Linked List
we can only move in both directions  
 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> NULL  

 Node class {  
     int data;  
     Node *next ,*prev;  
 }  

Memory Used : data:4 address:8*2 = 20bytes    
**Pro** : Easier to travel  
**Cons** : memory requirements is more  

### Insert Node 
<pre>
2  <->  3
   99
</pre>
- 2 -> next = 99
- 99 -> next = 3
- 3 -> prev = 99
- 99 -> prev = 3

## 3. Circular singly Linked List
last node will point to head instead of NULL
<pre>
1 -> 2 -> 3 -> 4 -> 5 ->  
^                      |   
|______________________|  
</pre>

### Length  
- temp = head -> next  
- count = 1  
- while(temp != head){ ... }  
- never compare data  
### Insert Node at head
99  1 -> 2 -> 3 - ...  
so 99 -> next = 1  
then travel to the end and uske next mai 99  
COMPLEXITY : O(n)

**Pro:** We do not need to maintain the head now  


## 4. Circular Double Linked List
Combo of circular and double

<pre>
 1 <-> 2 <-> 3 <-> 4 <-> 5   
^                        |   
|________________________|  
</pre>


# Find a node in LL (recursive)

```C++ 
int findNodeRec(Node *head, int n)
{
	int ans;
   if(head == NULL){
		return -1;
    }
    
    if(head -> data == n){
		return 0;
    }
    
    ans = findNodeRec(head -> next, n);
    //as we have found from 2 to 5 now we are checking for 1
    if(ans!= -1){
        return ans + 1;
        
    }
    else{
        return -1;
    }
    
    return ans;
    
}
```

# Even after Odd LinkedList

1 - 2 - 3 - 4 - 5 -NULL  
1 - 3 - 5 - 2 - 4 -NULL  

- divide this LL in 2 halves  
- oddhead , oddtail , evenhead , eventail  = NULL  
- if od and ot == NULL it is 1st node so both will point at 1
- if not null ot -> next mai put and update ot
- at the end put Null at the end of both
- then ot ke next mai even head
- if oddH == NULL return evenH

```C++ 
Node *evenAfterOdd(Node *head)
{
	//write your code here
    Node *oddH = NULL;
    Node *oddT = NULL;
    Node *evenH = NULL;
    Node *evenT = NULL;
    
    if(head == NULL){
		return head;
    }
    
    while(head != NULL){
        if(head->data % 2 == 0){
            if(evenH == NULL){
                evenH = head;
                evenT = head;
                head = head -> next;
            }
            else{
                evenT -> next = head;
                evenT = head ;
                head = head -> next;              
            }
        }
        else{
            if(oddH == NULL){
                oddH = head;
                oddT = head;
                head = head -> next;
            }
            else{
                oddT -> next = head;
                oddT = head ;
                head = head -> next;
            }
        }
    }
    oddT -> next == NULL; // to break the link
    evenT -> next == NULL;
    
    if(oddH == NULL){
        return evenH;
    }
    oddT -> next = evenH;
    
    return oddH;
}

```
Sample 1:    
1 11 3 6 8 0 9 -1  
1 11 3 9 6 8 0 
 
Sample 2 :  
10 20 30 40 -1 
10 20 30 40  


# Delete every N nodes

You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

Input :  
1 2 3 4 5 6 7 8 -1  
2 3  
Output :  
1 2 6 7

Input :  
10 20 30 40 50 60 -1
0 1
Output :  
nothing as whole list is deleted

**APPROACH**
1-2-3-4-5-6-7-8-NULL  
M=2  N=3  
- Take 2 count C1 = 1, C2  
- keep t1 var to traverse
- Move C1 till M and the move out of loop
- then take t2 for deleting the nodes (dellallocate these nodes)
- Move C2 till N and move out of the loop
- Then move t2 1 forward and then connect t1 to t2  
- again initialize C1 and C2 to 1
- move t1 to t2 
- continue these
- for all these also check if any one of these is NULL 