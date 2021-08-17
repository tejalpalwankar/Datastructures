# Introduction
It is inspired by binary search.  
In an array if we did linear search Compleity was O(n) , and when we did binary search the complexity was O(logn) which was much better.  
So basically we are going to do the same thing in trees . Everything on  
LEFT : Smaller than the root  
RIGHT : Larger than the root  
Basic Property : For every n node ,  
every subtree in n's left is less then n's data  
every subtree in n's right is greater then n's data  
If we have 1 2 3 4 5 6 7  
<pre>
        4
       / \
      2   6
     / \ / \     
    1  3 5  7
</pre>

# Search in BST

First ask the root node if it is equal s . if it is less than s call recusion on left , if it is greater than s call recursion on right.

```C++
bool searchInBST(BinaryTreeNode<int> *root , int k) {
    
    if(root == NULL){
		return false;
    }
    
    int ans = root->data;
    if(ans == k){
        return true;
    }

    else if(k < ans){
            searchInBST(root->left,k);
        }
    else if(k> ans){
            searchInBST(root->right,k);
        }
}
```

# Print Elements in range
so here basically we have to compare the root with k1 and k2. if it is betwween the range then dono side call karn hai pelhe left pe then vo element ko print n then rightt pe. but incase the root is less then k1 then no pointt in calling both sides so call only on left side. if it is greater than k2 then just call on right side.

```C++ 	
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	// Write your code here
    if(root == NULL){
        return ;
    }
    
    if(root->data >= k1 && root->data <= k2){
		elementsInRangeK1K2(root->left,k1,k2);
        cout << root->data << " ";
		elementsInRangeK1K2(root->right,k1,k2);
    }
    else if( k1 < root->data ){
		elementsInRangeK1K2(root->left,k1,k2);
    }
    else if(k2 > root->data  ){
		elementsInRangeK1K2(root->right,k1,k2);
    }

}	
```
<pre>
INPUT : 6,9
        4
       / \
      2   6
     / \ / \     
    1  3 5  7
             \
              8
OUTPUT :
6 7 8
</pre>


# Check if a Binary Tree is BST
Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
Note: Duplicate elements should be kept in the right subtree.

APPROACH :
So yaha hume root ko uske left and right se compare karna hai. Toh humne min and max values set karke rakhi hai. pehele hum dekhenge if root is less then min or greater than max if yes then false. then hume left side pe jaana hai and iss baar hume root ko min ke sath compare karna hai. then hume right pe jaake root ko max se compare karna hai. fir dono ka output true aaya toh he true return hoga.
```C++
#include <climits>
bool isBSTHelper(BinaryTreeNode<int> *root, int min, int max) {
	// Write your code here
    if(root == NULL){
        return true;
    }
    
    if(root->data < min || root->data > max){
        return false;
    }

    bool leftans =isBSTHelper(root->left, min, root->data);

    bool rightans = isBSTHelper(root->right,root->data,max);

    return leftans && rightans ;
}

bool isBST(BinaryTreeNode<int> *root) {
    isBSTHelper(root, INT_MIN, INT_MAX);
}
```

# Check BST 1
<pre>
INPUT : 6,9
        4
       / \
      2   6
     / \ / \     
    1 10 5  7
</pre>
THIS IS NOT A BST  
**BUT COMMON MISTAKE** : hum root ko uske let and right se compare karte hai i.e (2 < 4 < 6). Then (1 < 2 < 10) whch is true. Then (5 < 6 < 7) which is also true. So it will give you output as a BST which is wrong.  
**CORRECT APPROACH** :
- left ka max nikalo
- right ka min nikalo
- root should be greater than left ka max
- root should be less then right ka min
- both left and right subtree should be a BST

```C++ 
int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

bool isBST(BinaryTreeNode<int>* root){
    if(root == NULL){
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool output =(root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}
```
1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
<pre>
        1
       / \
      2   3
     / \ / \     
    4  5 6  7
        /\
       8  9
OUTPUT : 0 (it is not a bst)

        4
       / \
      2   6
     / \ / \     
    1  3 5  7
OUTPUT : 1 (it is  a bst)
</pre>
**COMPLEXITY :** 2 recursive call . hum har node pe jaare hai n har ode pe kitna kaam karre hai - left ka max and right ka min. for this muje har node pe jaana paadega.  
For a balanced tree:  
T(n) = 2T(n/2) + Kn  
2 half subtree so n/2 and kn work for min and max  
**O(nlogn)**  
For a unbalanced tree :  
<pre>
    \
     \
      \
</pre>
T(n) = T(n-1) +kn  

**O(n^2)**  
So basically it is **O(n*height)** same as diameter.


# Check BST2
So lasr prob mai hum left ko bolre hai max la and then again get isBST , fir right ko bolre hai get min and then get isBST.so ye bohot kaam hogaya baar baar. 
So somehow I want left muje max and isBST laaye and right min and isBST. but func either max or min return karega na , so hum dono taraf se (min,max,isBST) return karenge to improve the complexity.

```C++ 
class isBSTReturn{

public:
    bool isBST;
    int minimum;
    int maximum;

};

isBSTReturn isBST2(BinaryTreeNode<int>* root){
    if(root == NULL){
        isBSTReturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);

    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum ) && leftOutput.isBST && rightOutput.isBST;
    isBSTReturn output ;
    output.minimum = minimum;
    output.maximum = maximum;
    output.isBST = isBSTFinal;
    return output;
}
```

COMPLEXITY : T(n) = 2T(n/2) + k;  
so it is **O(n)**

# Check BST3

Lets look from top to bottom. abhi tak bottom se upar jaare the.
<pre>
        10
       / \
-infi,9   10,infi

         4
       /   \
-ve,3 2     6  4,+ve
     / \   / \
-,1 1  3  5   7 6,+ve
     2,3  4,5   
</pre>
```C++
bool isBST3(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }

    if(root->data < min || root->data > max){
        return false;
    }

    bool isLeftOk = isBST3(root->left, min, root->data -1);
    bool isRightOk = isBST3(root->right,root->data -1, max);
    return isLeftOk && isRightOk;
}
 ```

OUTPUT :  
4 2 6 1 30 5 -1 -1 -1 -1 -1 -1 -1 -1  
o/p : 0 not bst  

4 2 6 1 3 5 -1 -1 -1 -1 -1 -1 -1 -1  
o/p : 1 is bst

# Construct a Bst from a sorted array

We have  a array  
  1 2 3 4 5 6 7  
If we Insert in the same order, the bst will be linear unbalanced.Fisrt go to the mid and make ir root and left will be left subtree and right will be right subtree. call recursion on left and right subtree then we have to connect thr left and right half to the root.  
Recursive call : arr , si, ei

```C++
BinaryTreeNode<int>* binarySearch(int *input , int start , int end){
    
    if(start > end){
		return NULL;
    }
    
    int mid = (start + end )/2;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    
    BinaryTreeNode<int>* leftSubtree = binarySearch(input,start,mid-1);
    BinaryTreeNode<int>* rightSubtree = binarySearch(input,mid+1,end);
    
    root->left = leftSubtree;
    root->right = rightSubtree;

}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    
    return binarySearch(input , 0 , n-1);
}
```
<pre>
Output :
7  
1 2 3 4 5 6 7  
4 2 1 3 6 5 7 
</pre>

# BST to Sorted LL
Q. Given a BST, convert it into a sorted linked list. You have to return the head of LL.  
APPROACH :  
<pre>
        4
       / \
      2   6
     / \ / \     
    1  3 5  7
</pre>
LL should be 1 2 3 4 5 6 7  
We have root 4 and left sub tree values less than 4 and right subtree values greater than 4. We will ask left subtree to give their sorted LL  n it will give left head. right subtree will give a ll and rhead. Then  
<pre>
  1-2-3-N  4  5-6-7-N
lhead         rhead
</pre>
in 4 ka next we can put 5 but left subtree we cannot connect as we do not have tail so we will have to traverse to tail. but we will have to keep a while loop which will increase complexity.  
So lets ask for head as well as tail.


```C++
class Pair{
    public:
    Node<int>* head ;
    Node<int>* tail ;
};

Pair helper(BinaryTreeNode<int>* root)
{
    Pair p;
    if(root==NULL)
    {
        p.head=NULL;
        p.tail=NULL;
        return p;
    }

    Node<int>* head= new Node<int>(root->data);
    Pair lchild = helper(root->left); 
    Pair rchild =  helper(root->right);

    //either this way
    head->next=rchild.head;
    if(lchild.head!=NULL)
    {
        lchild.tail->next=head;
        p.head=lchild.head;
        //    p.tail=rchild.tail;
    }
    else
        p.head = head;

    if(rchild.head != NULL)
        p.tail = rchild.tail;    

    else
        p.tail = head;

    return p;

}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    // Write your code here
    Pair p = helper(root);
    return p.head; 
}
```
# Root to node path in Binary Tree
<pre>
        4
       / \
      2   6
     / \ / \     
    1  3 5  7
</pre>
Suppose we have 7 , then we have to find the path to go to this node.  We have to return a vector w this <7 ,6 , 4>  
base case : if root == NULL return null vector i.e. Vector< int >*  
if root == ele : put 4 and return <2>  
call left but null aayega , so call right so we will get <7,6>, so abhi 2 ko add karke return karna hai <7,6,2>.

```C++ 
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data){
    if(root == NULL){
        return NULL;
    }

    if(root->data == data){
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else{
        return NULL;
    }
}
```
<pre>
        1
       / \
      2   3
     / \ / \     
    4  5 6  7
        /\
       8  9
OUTPUT :
8
6
3
1
</pre>


# Find Path in BST
Same as the above code just put a condition if it has to go in left or right subtreee
```C++
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == data){
		vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    else if(root->data > data){
       vector<int>* leftOutput = getPath(root->left, data);
    	if(leftOutput != NULL){
        leftOutput->push_back(root->data);
        return leftOutput;
    } 
    }  
    else if(root->data < data){
        vector<int>* rightOutput = getPath(root->right, data);
    	if(rightOutput != NULL){
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    }
    return NULL;
}
 ```

# BST Class

## To access the data 
we have made our own private func because we were not able to call recursion on root in that func so the helper func will now call on both left and right subtree
```C++
private:
    bool hasData(int data , BinaryTreeNode<int>* node){
        if(node == NULL){
            return false;
        }

        if(node ->data == data){
            return true;
        }

        else if(data < node->data){
             return hasData(data, node->left);
        }
        else{
            return hasData(data, node->right );
        }
    }

    public:
    bool hasData(int data){
        return hasData(data, root);   
    }
```

## To insert data
suppose we have a insert(root,data). so we have a root 5 and we want to insert 7 so 7 5 ke right pe jaayega.  
base case : BT was null , abhi usme hume 7 insert karna hai, so we have to make a node jisme 7 hai n ye naya root return karna hoga.  
if root not null :  toh check right pe insert karna hai ya left pe 

```C++
    private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node){
        if(node == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data < node->data){
            node->left = insert(data, node->left);
        }
        else{
            node->right = insert(data, node->right);
        }
        return node;
    }

    public :
    void insert(int data){
        this->root = insert(data, this->root);
    }
```

## To delete data
base case : root null : return  
our work : root ka data small call on right and naye root ko attach w 5 . so basically call recurion on right and left both. 
if we have to delete the root -
<pre>
        5
       / \
      N   N
</pre>
1. left and right both null : toh delete kardo and return NULL 
<pre>
        5
       / \
   data   N
</pre>
2.  One of the child is there : replace the root w one of the child
<pre>
        5
       / \
   data  data
</pre>
3. both childs presents : either left ka largest or right ka smallest will be root and vo smallest/largest ko dlt karna hai

```C++
private:
    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node){
        if(node == NULL){
            return NULL;
        }

        if(data > node->data){
            node->right = deleteData(data, node->right);
        }
        else if(data < node->data){
            node->left = deleteData(data, node->left);
        }
        else{
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->left == NULL ){
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if(node->right == NULL ){
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else{
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL){
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node; 
            }

        }
    }

public :
    void deleteData(int data){

    }

```

# Types of BST 

- SEARCHING : at each level only one comparison so complexity O(h)
- DELETION : pehle root tak jaana hai so d depth . Then wahape right ke minimum pe toh aur d depth . d + d'. one more time d' to delete. so total work d + d'(find min) + d'(delete min)  
d + 2d' < 2h  
so complexity : O(h)  
if there is a linear unbalanced tree then O(h) = O(n) which is v bad.  
**BALANCED TREE**: for every node  
| h(node's left subtree) - h(node's right subtree) | <= 1
<pre> 1 2 34 5 6 7 8
        6
       / \
      3   8
     /     \
    2       9
   /         \
   1          10
UNBALANCED
</pre>
It is unbalanced as for 3 the left and right children will be 2,0.  
height for a balanced tree ~~ O(logn)  
humare balanced tree mai search , insertion and deletion is O(logn) whcih is good.  
HOW TO MAKE SURE TREE IS BALANCED ?  
**BST TYPES :**  
1. AVL Tree
2. Red Black Tree 
3. 2-4 tree

AVL Tree : agar left ki height is 4 and right ke 6 toh thoda sa rotate kar dete hai . so dono ki height will be 5
