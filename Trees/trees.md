# Introduction

1. Root : the head node 
2. parent child : head node and the child node
3. sibilings : node at the same level
4. leaf : the node at the very end
5. descendents : children and unke children

# Vector 

It is same like Dynamic array but Inbuilt.  
So whenever we need to use dynamic array we are going to use < vector >.
It is a template.

**pop_back()** : to delete the last element.

**push_back()**: This func is used to insert the element in the vector.
Why use push_back when we can insert elelmets like this ->  v[1] = 100;  
bcz it will check current size, where to put the element, do we need to double.

```C++
    vector<int> v; // statically

    v.push_back(10); 
    v.push_back(20); 
    v.push_back(30); 

    v[1] =100;
    v[3] =1002;
    v[4] =1234;

    v.push_back(23);
    v.push_back(234);

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl;
```
<pre>
Output :
coding ninjas\level3\Trees\" ; if ($?) { g++ vectoruse.cpp -o vectoruse } ; if ($?) { .\vectoruse }      
10  
100
30   //pushed ele
23  //pushed ele
234 //garbage value
0   //garbage value
</pre>

So basically we are going to use [] brackets only to get or update elements and not to assign elements.  

Instead of [] brackets we can use a at() function which will give us the element at pos 2  
cout << v.at(2) << endl;  
```C++ 
//previous code contd
    cout << "size :" << v.size() << endl;

    cout << v.at(2) << endl;
    cout << v.at(6) << endl;
```
Output :
<pre>
PS C:\Users\Admin\OneDrive\Documents\Coding ninjas\level3\Trees> cd "c:\Users\Admin\OneDrive\Documents\Cevel3\Trees>oding ninjas\level3\Trees\" ; if ($?) { g++ vectoruse.cpp -o vectoruse } ; if ($?) { .\vectoruse }      
10 
100
30 
23 
234
0  
1376592
size :5
30
</pre>
It gave us element only at 2 and not at 6 as it was out of range. So it is much safer to use **at()** rather than **[]**  
WHOLE CODE :
```C++
int main(){
    vector<int> v; // statically
    // vector<int> *vp = new vector<int>(); // dynamically

    for(int i = 0; i<100 ; i++ ){
        cout << "v.capacity()" << v.capacity() << endl;
        cout << "v.size()" << v.size() << endl;
        v.push_back(i + 1);
    }

    v.push_back(10); 
    v.push_back(20); 
    v.push_back(30); 

    v[1] =100;

    // do not use this for inserting
    // v[3] =1002;
    // v[4] =1234;

    v.push_back(23);
    v.push_back(234);

    v.pop_back();
/* 
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    cout << v[6] << endl; */

    for(int i=0 ; i < v.size() ; i++){
        cout << v[i] << endl;
    }

    // cout << "size :" << v.size() << endl;

    cout << v.at(2) << endl;
    cout << v.at(6) << endl;
}
 ```

# Trees 
Each node is going to store the address of it's child. we are goinfg to have the address of root as it has the address of all the nodes.
If we store data in :  
Array : Size is the issue  
LL : access is the issue since each time we have to traverse all nodes.  
So we are going to use VECTORS.

# Class Of Tree
```C++ 
#include <vector>

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;//children is our vector
    //<T> is not necessary to define as it is assumed it will be the type of it's parent

    //Constructor --- we are making this kyuki jabhi mai koi object banaugi muje uske sath he uska data pass karna padega
    TreeNode(T data){
        this->data = data;
    }
}
```

# Creating children nodes
```C++
#include <iostream>
#include "TreeNode.h"
using namespace std;

int main(){
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    //for connecting these nodes
    root->children.push_back(node1);
    root->children.push_back(node2);

}
```

# Simple print function
```C++ 
void printTree(TreeNode<int>* root){
    cout << root->data << endl;

    for(int i=0; i< root->children.size() ; i++){
        printTree(root->children[i]);
    }
}
```
A little modified telling us it's children as well
```C++ 
void printTree(TreeNode<int>* root){
    // It is a EDGE CASE and not base case
    if(root == NULL){
        return;
    }

    cout << root->data << ":"; //this will work as a base case also

    //this will print each nodes children for us
    for(int i=0; i< root->children.size() ; i++){
        cout << root->children[i] ->data << ",";
    }
    cout << endl;
    for(int i=0; i< root->children.size() ; i++){
        printTree(root->children[i]);
    }
}
```

# Taking Input (Preorder Traversal)

It will return root. 
Sabse pehle puchenge root data bata, fir puchuga bata litne children hai , toh mai 3 baar takeInput call karuga for the smaller trees.

toh kya hora hai yaha ?
pehli baar call karenge toh muje subtree ka root milega .
fir muje ek root ko dusre root ke sath connect karna hai

```C++

TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data :" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n ;i++)
    {
        TreeNode<int>* child = takeInput();
        root->children.push_back(child); // connecting nodes
    }
    return root;
}
 ```
 <pre>
        1
      / | \ 
    2   3  4
   / \  |   \
  5   6 7    8
</pre>
 <pre>
 Output :
 Enter data :
1
Enter number of children of 1
3
Enter data :
2
Enter number of children of 2
2
Enter data :
5
Enter number of children of 5
0
Enter data :
6
Enter number of children of 6
0
Enter data :
3
Enter number of children of 3
1
Enter data :
7
Enter number of children of 7
0
Enter data :
4
Enter number of children of 4
1
Enter data :
8
Enter number of children of 8
0
1:2,3,4,
2:5,6,
5:
6:
3:7,
7:
4:8,
8:
 </pre>

# Taking Input level wise
The previous method was a little tough to take input from the people who do not know recursion. So here we are going to take level wise.  
<pre>
        1
      / | \ 
    2   3  4
   / \  |   \
  5   6 7    8
</pre>
so pehle 1  
fir 1 ke children and connect  : 2 connect , 3 and connect karenge , 4 and connect karenge.  
fir 2 ke children : 5 , 6  
fir 3 ke children : 7  
fir 4 ke children : 8  
Jo chiz pehle aari hai uske children pehle , jo chiz baadme aari hai uske children baadme  
So yaha queue use karenge.  
pehle 1 ko queue mai daala 
1  
and usse nikal ke uske children maange and queue mai daale.   
2 3 4  
fir 2 ko nikala and uske children mange  
3 4 5 6  
go on till queue is empty.

Code approach :
pehle root lena hai , fir queue mai daalna hai.
queue mai node ka pointer daalna hai

```C++ 
TreeNode<int> child(childData);
front->children.push_back(&child);
```
hum yaha statically kyu nai allocate kar sakte ?  
jab humara func khatam hojaye tabhi hume chaiye ke humare paas vo root and children ka access rahe. Bur humne jo banaya hai vo local variable hai jiska scope loop ke bahar bhi nai hoga. so isiliye if you want the memory to surve dynamically allocate  

Dry run on this :
<pre>
        1
      / | \ 
    2   3  4
   / \  
  5   6 
</pre>

- pehel root manga : 1
- fir 1 ko queue mai daala
- fir while loop mai aaye
- front nikala : 1
- pop kar diya to 1 is out of queue
- fir pucha 1 ke kitne children : 3
- fir for loop 3 baar chalaya 
- pehle 0th child : 2 
- 2 ki node banaya and 1(front) ki children mai daal diya 
- fir pendingNodes wale queue mai bhi daal diya
- pehle 1th child : 3
- node banake connect kiya fir queue
- same for 4
- then while loop mai wapas aaye tabhi queue empty nai tha toh firse front nikala : 2 
- continue
CODE :
```C++
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data :" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root); //queue mai push kiya
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter num of children of" << front-> data << endl;
        int numChild;
        cin >> numChild ;
        for(int i =0 ; i < numChild ; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            // TreeNode<int> child(childData);
            // front->children.push_back(&child);
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child); 

        }
    }
    return root;
}

```


# Print Level Wise
HUm jaise level wise input lere the waise he abhi level wise print bhi karna hai  
<pre>
        1
      / | \ 
    2   3  4
   / \  
  5   6 
</pre>
queue lo 1 daal do  
while loop till loop is not empty  
fir 1 ko bahar nikal diya and print children of 1 and put these children in queue  
next time 2 bahr aayega print its children and put them in queue

```C++
void printLevelWise(TreeNode<int>* root) {
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root); //queue mai push kiya
    
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
		cout << front->data << ":";
        pendingNodes.pop();
        
        for(int i=0; i< front->children.size() ; i++){
            //to print commas at specific places
            if(i< front->children.size() - 1){
        		cout << front->children[i] ->data << ",";
            }
            else{
        		cout << front->children[i] ->data ;
            }
          pendingNodes.push(front->children[i]); 
            
    	}
        cout << endl;
    }  
}
```
<pre>
Output :
Enter root data :
1
enter num of children of1
3
Enter 0th child of 1
2
Enter 1th child of 1
3
Enter 2th child of 1
4
enter num of children of2
2
Enter 0th child of 2
5
Enter 1th child of 2
6
enter num of children of3
0
enter num of children of4
0
enter num of children of5
0
enter num of children of6
0
1:2,3,4
2:5,6
3:
4:
5:
6:
</pre>

# Count num of nodes

<pre>
        1
      / | \ 
    2   5  6
   / \   \
  3   4   7
           \
            8
</pre>

1 ne aate he ans 1 kar diya n 2 pe call kiya , 2 ne ans 1 kiya n 3 pe call kiya , 3 ne ans 1 kiya but no children to return hua,and then 4 bhu return hua toh upar finally inse 3 return kiya

```C++ 
int numNodes(TreeNode<int>* root){
    if(root == 1){
        return 0;
    }

    int ans = 1;
    for(int i=0 ; i<root->children.size() ; i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}
```

# sum of nodes
It is the same as above just that to recusrion now we are passing root->data, so now sabka root -> data ke liye recursion call hoga
```C++
int sumOfNodes(TreeNode<int>* root) {

    int ans = root->data;
    for(int i=0 ; i<root->children.size() ; i++){
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}
```

# Max Data Node 
yaha maine ek node mai root daal diya which is max for now and dusre node ko traverse kar rahi hu , if  I evee find a child greater than max toh usse max mai daal diya.fir max return kar diya. dhyaan rakho iska return type TreeNode< int >* tha toh int mai kuch bhi nai karna hai.

```C++ 
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>* max = root;
    TreeNode<int>* maxChild ;
    for(int i=0 ; i<root->children.size() ; i++){
        maxChild = maxDataNode(root->children[i]);
        if( maxChild->data > max->data){
            max = maxChild;
        }
    }
    return max;
}
```

# Height of a Tree
    
<pre>
        NULL ---> height 0  

        1      ---> height 1
      / | \ 
    2   5  6   ---> height 2
   / \   \
  3   4   7     ---> height 3
           \
            8   ---> height 4
</pre>

Basically hume har ek child pe call karna hai height batao, unme se jo max hoga usme + 1 karke return karna hai

```C++
int getHeight(TreeNode<int>* root) {
    // int maxHeight = 1; DO NOT DECLARE IT AS 1
    int maxHeight = 0;

    for(int i=0 ; i<root->children.size() ; i++){
        int height = getHeight(root->children[i]);
        if(height > maxHeight){
            maxHeight = height;
        }
    }
    return maxHeight + 1; //this is +1 root node ka
}
 ```

 # Depth of a Node
 <pre>
            1    --> k =3
          / | \ 
k=2 <-- 2   3  4    k=2
       /    |   \
k=1   5     8    10  k=1
    /  \    |     \
k=06   7   9      11  k=0
                    \
                    12
                     \
                     13
OUTPUT :
Level 3 :
6
7
9
11
</pre>


if k = 0 print 1  
if k = 4 , I will call on 2 and say apne mai level 3 pe call kar , 5 mai bhi level 3 print karne bolunga , 6 mai bhi  

if k == 3  
2 pe call hote hote niche jaayega n 6,7 print hoga  
similarly 3 pe call hua to 9 will print  
similarly 4 pe call hua to 11 will print  
```C++ 
void printAtLevelK(TreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }

    if(k== 0){
        cout << root->data << endl;
    }

    for(int i=0 ; i<root->children.size() ; i++){
        printAtLevelK(root->children[i] , k-1);
    }
}
```

# Count Leaf Nodes
<pre>
        1
      / | \ 
    2   3  4
       / \
      5   6

Output :
1:2,3,4
2:
3:5,6
4:
5:
6:
count : 4
</pre>
sabse pehle check karo root ka koi child hai kya  
if root ka koi child nai to return 1 or  
ask each children to tell number of leaf 

so here basically if it has no children we are increasing the count and then adding all such leaf nodes together.
```C++
int getLeafNodeCount(TreeNode<int>* root) {

    int count =0;
    if(root->children.size() == 0){
        count++;
    }

    for(int i=0 ; i<root->children.size() ; i++){
        count += getLeafNodeCount(root->children[i]);
    }
    return count;
}
```

# Pre order Traversal

**PREORDER TRAVERSAL** : pehle print root then it's children


```C++
void preorder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    for(int i=0 ; i<root->children.size() ; i++){
        preorder(root->children[i]);
    }
}
```
<pre>
        1
      / | \ 
    2   3  4
   / \  /\
  5   6 7 8
           \ 
            9
OUTPUT :
1 2 5 6 3 7 8 9 4 
</pre>

# Post order Traversal

**POSTORDER TRAVERSAL** : pehle print children then it's root 

```C++ 
void printPostOrder(TreeNode<int>* root) {

    if(root == NULL){
        return;
    }

    for(int i=0 ; i<root->children.size() ; i++){
        printPostOrder(root->children[i]);
    }
    
    cout << root->data << " ";
    
}
```
<pre>
        1
      / | \ 
    2   3  4
   / \  /\
  5   6 7 8
           \ 
            9
OUTPUT :
5 6 2 7 9 8 3 4 1
</pre>

# Destructor

### using delete function
WE WILL BE USING POST ORDER TRAVERSAL TO DELETE  
HUmne jabhi apna tree baanya toh new keyword use  karke dynamically banaya hai , toh we need to delete this as well.
mere paas root hai but root pe delete call nai karna hai kyuki bas root dlt kar diya toh vector mai address hai children ke vo bhi dlt hojayege. Root ke paas data hai n vector hai m vector delte hua toh nodes nai dlt kar paayenge.  
so ideally pehele children ko dlt karna hai baadme root ko dlt karna hai.  
<pre>
        1
      / | \ 
    2   3  4
   / \  /\
  5   6 7 8
           \ 
            9
</pre>
Toh isme agar call kiya toh 1 will call on 2 , 2 will call on 5 and 5 delete hoga , fir 6 delete hoga then 2 hoga. 

```C++
void deleteTree(TreeNode<int>* root){
    for(int i=0 ; i<root->children.size() ; i++){
        deleteTree(root->children[i]);
    }

    delete root ;
}
```

### Using destructor

yaha bhi same he order pe delete ke jagah sab jagah hum destructor use karre hai  
**THIS CODE IS WRITTEN IN OUR CLASS**
```C++ 
    ~TreeNode(){
    for(int i=0 ; i< children.size() ; i++){
            delete children[i] ;

    }

```

# contains X

Q. Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
<pre>
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
40 
Sample Output 1 :
true

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
4 
Sample Output 2:
false
</pre>
I am storing the answer of recursion in  a var because at the end if the recursion gives the ans false that will be returned , but we want to get out of the loop as sooon as we find true right , so we are checking that also inside the for loop.
```C++

bool isPresent(TreeNode<int>* root, int x) {
    // Write your code here
    if(root == NULL){
        return false;
    }

    if(root-> data == x){
        return true;
    }
    bool ans;
    for(int i=0 ; i<root->children.size() ; i++){
        ans = isPresent(root->children[i], x);
        if(ans == true){
            return true;
        }
    }
    return false;   
}
```

# Count num Node greater than x
Q. Given a tree and an integer x, find and return the number of nodes which contains data greater than x.  
<pre>
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35 
Sample Output 1 :
3

Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 
Sample Output 2:
5
</pre>
pehele humne root ke data ko dekha agar hai toh increase karo conunt and fir children pe gaye, toh fir children root ban jaayege n aise karke hum sab count wahi pe add karr rahe hai n so we get out count.
```C++
int getLargeNodeCount(TreeNode<int>* root, int x) {
    
    if(root == NULL){
        return false;
    }

    int count = 0;
    if(root-> data > x){
        count++ ;
    }

    for(int i=0 ; i<root->children.size() ; i++){
        count += getLargeNodeCount(root->children[i], x);
    }
    return count ; 
}
 ```

# Node with maximum child sum

Q. Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

Sample Input 1 :  
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0  
Sample Output 1 :  
1  

**Approach 1:**  
<pre>
       10 
      / | \ 
    2   3  4
   / \   \  \
100 200   5  8
</pre>
10 --> 19  
2 --> 302  
3 --> 8  
4 --> 12  
100 , 200, 5, 8 same  
So 2 ka sum is max so it will be the ans  
So pehele root pe kaam karna hai, so put it as ans for now. 
<pre>
       10 
      / | \ 
    2  30  3
   /   / \  
100   5   6
</pre>
root ka ans hoga sum = 36  
so for loop run karna hai child ke liye.  
x mai value store karte hai subtree ki 
2 ka sum aaya 6 and 4 ka 4  
So x ki value ye subtree ke liyye hogi 2.  
so ab we have to compare but kise ? sum =36 and this sum = 6 , ab dekho hume root ka sum pata hai 36 but x=2 ka sum pata he nai i.e 6 toh find x ka sum  
x ka sum : x ke children pe loop run karo and uske child ke data ko and x ko add karna hai  
ab isse compare karna hai agar bada hai to update others go on.  

**Approach 2: better**

hume for loop karke x ka sum calc nai karna th kya kare ?  
lets ask recursion x ke sath sath xsum bhi return karo, so create a pair class  
class pair{  
    treenode , sum : node ka child and data ka sum
}