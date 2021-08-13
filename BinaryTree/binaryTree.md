# Introduction 

It cannot have more than 2 children, so only 0, 1, 2 children.In class of binaray tree :  
- T data
- Binary TreeNode* left ;
- Binary TreeNode* right ;
So here basically we have a left subtree and a right subtree.

# Class Of a Tree
```C++ 
template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this-> data = data;
        left = NULL; // garbage store hoga isiliye null
        rightt = NULL;
    }

    // yaha we want har node jaate jaate apne left aur right child ko bhi dlt kare
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};

```


# Creating Node int main()
So basically we have just created 3 nodes here dynamically and then left and right ko root mai daal diya.

```C++
int main(){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;

}
```
This is a tree what we have created. 
<pre>
    1
   / \
  2   3 
</pre>

# Print Tree

Why we need base case here ?    
ye left i.e 2 pe call karega but 2 ke left mai toh NULL hai toh issue aayega toh we need to write the base case
```C++
void printTree(BinaryTreeNode<int>* root){

    if(root == NULL){
        return;
    }

    cout << root->data << ":";
    if(root->left != NULL){ // OR if(root->left)
        cout << "L " << root->left->data ;
    }
    if(root->right != NULL){ // OR if(root->right)
        cout << "R " << root->right->data ;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}
```

# Take Input
So we are asking the user to enter the data , but what if the root has no left or right , so to confirm that we are going to take -1. That means if it is -1 means no data so don't call on it go back, others continue . Fir we made a root node and left and right node by recusive method(calling the same func), and then we are just attaching these 2 nodes to the root.
<pre>
    1
   / \
  2   3 
</pre>
yaha kya hoga ? 
Pehle it will call on 1 fir vo left pe call karega 2 , fir 2 ke left pe which is -1, then 2 ka right -1 , toh return , then 1 ke right pe that is 3, then 3 ke right n left pe i.e. -1 toh return   
So output :
1  
2  
3

```C++
BinaryTreeNode<int>* takeInput(){
    int rootData ;
    cout << " Enter Data :" << endl;
    cin << rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    
    root->left = leftChild;
    root->right = rightChild;

    return root;
}
 ```

 <pre>
 OUTPUT :
  Enter Data :
1
 Enter Data :
2
 Enter Data :
-1
 Enter Data :
-1
 Enter Data :
3
 Enter Data :
-1
 Enter Data :
-1
1: L-2  R-3
2:
3:
 </pre>

 <pre>
        1
       / \
      2   3 
     / \  /
    4   5 8
       / \
       6  7

OUTPUT :
 Enter Data :
1
 Enter Data :
2
 Enter Data :
4
 Enter Data :
-1
 Enter Data :
-1
 Enter Data :
5
 Enter Data :
6
 Enter Data :
-1
 Enter Data :
-1
 Enter Data :
7
 Enter Data :
-1
 Enter Data :
-1
 Enter Data :
3
 Enter Data :
8
 Enter Data :
-1
 Enter Data :
-1
 Enter Data :
-1
1: L-2  R-3
2: L-4  R-5
4:
5: L-6  R-7
6:
7:
3: L-8  
8:
</pre>

# Take Input Level Wise

We are going to use a queue and first take 1 fir 1 bahar aayega n 1 ke children ko daalenge , fir 2 bahar aayega n 2 ke children ko daalenge , fir 3 n so on. 
This is not recusrsively.
Jis order mai node aari hai wahi order mai process karre hai.

```C++ 
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData ;
    cout << " Enter root Data :" << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
   
   queue<BinaryTreeNode<int>*> pendingNodes;
   pendingNodes.push(root);

   while(pendingNodes.size() != NULL){
       BinaryTreeNode<int>* front = pendingNodes.front();
       pendingNodes.pop();

       cout << "Enter left child of " << front->data << endl;
       int leftChildData;
       cin >> leftChildData;
       if(leftChildData != -1){
           BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
           front->left = child;
           pendingNodes.push(child);
       }

       cout << "Enter right child of " << front->data << endl;
       int rightChildData;
       cin >> rightChildData;
       if(rightChildData != -1){
           BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
           front->right = child;
           pendingNodes.push(child);
       }
   }
    return root;
}
```

<pre>
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
      / \
     8   9

OUTPUT :
Enter root Data :
1
Enter left child of 1
2
Enter right child of 1
3
Enter left child of 2
4
Enter right child of 2
5
Enter left child of 3
6
Enter right child of 3
7
Enter left child of 4
-1
Enter right child of 4
-1
Enter left child of 5
8
Enter right child of 5
9
Enter left child of 6
-1
Enter right child of 6
-1
Enter left child of 7
-1
Enter right child of 7
-1
Enter left child of 8
-1
Enter right child of 8
-1
Enter left child of 9
-1
Enter right child of 9
-1
1: L-2  R-3
2: L-4  R-5
4:
5: L-8  R-9
8:
9:
3: L-6  R-7
6:
7:
</pre>

# Print Level Wise 
Humne jaise input liya hai ab same order mai hume usse print bhi karna hai. sabse pehle 1 ko lege n print karenge n queue mai daalege then we'll ask for its left n right child n print karke queue mai daalenge

```C++
void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        return;
    }
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != NULL){
       BinaryTreeNode<int>* front = pendingNodes.front();
       cout <<front-> data << ":";
       pendingNodes.pop();
        
        if(front->left != NULL){
            cout << "L:" << front->left->data << ',' ;
            pendingNodes.push(front->left);
        }
        if(front->left == NULL){
            cout << "L:" << "-1" << ',' ;
        }
        if(front->right != NULL){
            cout << "R:" << front->right->data;
            pendingNodes.push(front->right);
        }
        if(front->right == NULL){
            cout << "R:" << "-1"  ;
        }
        cout << endl;
    }
}
 ```
 <pre>
        1
      /   \
     2     3
    / \  
   4   5 

OUTPUT :
 Enter root Data :
1
Enter left child of 1
2
Enter right child of 1
3
Enter left child of 2
4
Enter right child of 2
5
Enter left child of 3
-1
Enter right child of 3
-1
Enter left child of 4
-1
Enter right child of 4
-1
Enter left child of 5
-1
Enter right child of 5
-1
1:L:2,R:3
2:L:4,R:5
3:L:-1,R:-1
4:L:-1,R:-1
5:L:-1,R:-1

</pre>

# Count num of nodes
base case : BT is NULL return 0  
So hume dekhna hai left mai kitne nodes hai, + right ke nodes + 1 for root

```C++
int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}
```

<pre>
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
        / \
       8   9   
OUTPUT : 
Num of node : 9 
</pre>

# Check if Node is present
Q.For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.  

Here it is necessary to write that OR otherwise root ka right was not getting checked. so be carefull.

```C++
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    
    if(root == NULL){
        return false;
    }
    
    if(root->data == x){
        return true;
    }
    
    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}
```

# Height of a binary Tree

Here we are simply checking the height of left  n right nodes and displaying which is larger.
```C++
int height(BinaryTreeNode<int>* root) {

    if(root == NULL){
        return 0;
    }
    
    int lh = height(root->left);
	int rh  = height(root->right);
	if(lh > rh){
        return lh + 1;
    }
    else{
    	return rh + 1;   
    }  
}
 ```

 SOLUTION METHOD
 ```C++ 
 int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    
    return max(height(root->left) , height(root->right)) + 1;
    
}
 ```

 # Mirror of Tree

So yaha hume bass left ko right mai daalna hai n right ko left mai and recusrion will look to the other part of it.
 ```C++
 void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    
    if(root == NULL){
        return;
    }
    
    mirrorBinaryTree(root-> left);
    mirrorBinaryTree(root-> right);
    BinaryTreeNode<int>* temp = root->left; 
    root->left = root->right;
    root->right = temp;
   
} 
```

# Traversals 
The types of Traversals are :
1. **Level Order** - Go level wise 
2. **preorder** : 1st root then children (node -> left -> right)
3. **postorder** : 1st children then root(left -> right -> node)
4. **Inorder (In binary Trees)**: left -> node -> right . basically from leftmost to rightmost


<pre>
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
        / \
       8   9  
</pre>
# Inorder 
```C++
void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```
<pre>
OUTPUT :4 2 5 1 8 6 9 3 7  
</pre>

# Preorder

```C++ 
void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
		return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    
}
```
<pre>
OUTPUT : 1 2 4 5 3 6 8 9 7
</pre>
# Postorder 

```C++
void postOrder(BinaryTreeNode<int> *root) {

    if(root == NULL){
		return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    
}
```
<pre>
Output : 4 5 2 8 9 6 7 3 1
</pre>

## Construct Tree from Inorder and preorder

why not just inorder ?  
think if 123 is the inorder can you build a tree YES but 2 types of tree can be made.But if we are given both we can make a unique tree.
pre - root -> left -> right  
in  - left -> root -> right  
The best way is to identify the root and left right ko recursively. Root kaise milegea ? Preorder ka 1st element.   
for left recusrion we want left inorder and preorder. That means inorder n preorder dono mai kahase start and end hota hai.  
- **Left preorder** : start - root ka next element , end : InoRderEnd - InorderStart = PreorderEnd - PreOrderStart. so here we can figure out the left of preorder.
- **Left inorder** : start - 1st element , end - where you find rootIndex it will be rootindex-1
- **Right Preorder** : start : left ka end , end : tree ka end
- **Right Inorder**: start : rootIndex+1 , end : tree ka end 
func(Inorder, Preorder, inS, inE, preO, preE)

Q. For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
<pre>
Sample Input 1:
7
1 2 4 5 3 6 7 pre
4 2 5 1 6 3 7 in

Sample Output 1:
1 
2 3 
4 5 6 7 
</pre>

Pehele find root  
call recusrion on left and right
```C++
BinaryTreeNode<int>* helper(int *preorder,int *inorder, int preS , int preE, int inS, int inE){
    
    if(preS > preE || inS > inE){
        return NULL;
    }
    
    int rootVal = preorder[preS];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootVal);
    
    int rootIndex;
    for(int i = inS ; i<= inE; i++){
        if(rootVal == inorder[i]){
            rootIndex = i;
            break;
        }
    }
    
    root->left = helper(preorder , inorder, preS+1, (rootIndex - inS)+ preS, inS, rootIndex-1);
    root->right = helper(preorder , inorder, (rootIndex - inS)+ preS + 1, preE, rootIndex+1, inE);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    int preS = 0;
    int preE = preLength - 1;
    int inS = 0;
    int inE = inLength - 1;
    
    return helper(preorder, inorder, preS , preE, inS, inE);
}
```
<pre>
Input : 
9
8 3 1 6 4 7 10 14 13 
1 3 4 6 7 8 10 13 14 

Output:
8 
3 10 
1 6 14 
4 7 13 
</pre>
SAME CODE JUST EASIER TO UNDERSTAND
```C++
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE){
    if(inS > inE){
        return NULL;
    }

    // int rootData = pre[0]; This is wrong bcz we are calling recusion n start is not fixed
    int rootData = pre[preS];
    int rootIndex = -1;
    for(int i = inS; i<=inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    // lInE - lInS = lPreE - lPreS
    int lPreE = (lInE - lInS) + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size){
    return buildTreeHelper(in , pre, 0 , size -1, 0, size -1);
}
```
<pre>
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
        / \
       8   9 
Input: 
int in[] = {4,2,5,1,8,6,9,3,7};
int pre[] = {1,2,4,5,3,6,8,9,7};
output:
1: L-2  R-3
2: L-4  R-5
4:
5:
3: L-6  R-7
6: L-8  R-9
8:
9:
7:
</pre>


# Construct Tree from Postorder and Inorder

Follow the same steps
```C++
BinaryTreeNode<int>* buildTreeHelper(int *in ,int *po ,int inS,int inE, int poS, int poE)
{
    if(inS > inE){
        return NULL;
    }
    
    int rootData = po[poE];
    int rootIndex = -1;
    for(int i = inS; i<=inE; i++){
        if(in[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    
    int lInS = inS ;
    int lInE = rootIndex - 1;
    int lPoS = poS;
    int lPoE = (lInE - lInS) + lPoS;
    int rPoS = lPoE + 1;
    int rPoE = poE -1;
    int rInS = rootIndex + 1;
    int rInE = inE;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, po, lInS, lInE, lPoS, lPoE);
	root->right = buildTreeHelper(in, po, rInS, rInE, rPoS, rPoE);
    
	return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTreeHelper(inorder, postorder , 0, inLength -1, 0, postLength -1);
}
```
<pre>
1: L-2  R-3
2: L-4  R-5
4:
5:
3: L-6  R-7
6: L-8  R-9
8:
9:
7:
</pre>

# Diameter of a Binary Tree 
Diameter : Max distance between 2 nodes.  
Assumption : leftHeight + rightheight (This might not be true in all cases as sometimes both the nodes with highest height might be on the same side of the root).

```C++ 
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}
```
We have this code which will work perfectly fine but what is the time complexity of  
height func : O(n) becz the return statement is each time going to every node.  
diameter func : O(n) bcz of option1 we are going to every node.
Time complexity will be diff for every tree.  
1. Ex1 : T(n) = Kn + 2T(n/2); (best)(Similary to merge sort )  
height = logn
<pre>
    |
   / \
  /   \
  Time Complexity : O(log n)
</pre>

2. Ex2 : T(n) = kn + T(n-1);(similar to bubble sort)(worst)  
height = n
<pre>
    |
     \
      \
       \
Time Complexity : O(n^2)
</pre>
 
CURRENT SOLUTION : Height = n*h  

In ex1 lets consider 2nd element , it is going to all the elements to just find the height of 2nd element . this will happen for all the elements so same work we are doing again and again . so the best solution is to tell the 2nd element to get the height as well as diameter. 

## Better Approach Solution for Diameter

1. Base case :  
Null = 0 then 0  
2. Hypothesis :
ld, lh , rd, rh
3. h = 1 + max(lh, rh);  
   d = max(lh + rh, ld, rd );

```C++

pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int , int> p;
        p.first =0;
        p.second =0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rh = rightAns.first;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
} 
```
<pre>
        1
      /   \
     2     3
    / \   
   4   5 
  /     \
 6       7
/         \
8          9

Output :
1: L-2  R-3
2: L-4  R-5
4: L-6
6: L-8
8:
5:R-7
7:R-9
9:
3:
Height :5
Diameter :6
</pre>

DRY RUN :
- 1 ne bola left pe right aur diameter leke aa.
- so 2,4,6,8 ne bola heiight n diameter leke aao. fir 8 ke left pe call hua toh 0,0 and right bhi 0,0. 
- So 8 return karega h = 1 + (lh + rh) = 1 , d = (lh + rh , ld, rd)= 0 single node ka d 0 he hoga.
- then on 6 h = 2 , d = 1 / 4 h=3 , d=2 .
- ab 2 ke paas dono side se 3,2 mila . 
2 h= 4 d = 6,2,2 = 6
- 1 ke paas aaya 2 se 4,6 and 3 se 1,0.
h = 5 d=5,6,0 = 6 so thats how we got our ans h=5 d=6.  
TIME COMPLEXITY : so every node we are doing constant work kn so the complexity is O(n).

# Min and Max of a node
Followed the same steps as aboove just here while finding the min we are comparing it with root->data .BE CAREFULL : initialize w INT_MIN and INT_MAX others we will get wrong ans.
```C++ 
#include <climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    
    if(root == NULL){
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    
    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);
    
    int lmin = leftAns.first;
    int lmax = leftAns.second;
    int rmin = rightAns.first;
    int rmax = rightAns.second;
    
    int minimum = min(min(lmin , rmin), root->data);
    int maxx = max(max(lmax , rmax), root->data);
    
    pair<int,int> p;
    p.first = minimum;
    p.second = maxx;
    
    return p;
}
```
<pre>
1: L-2  R-3
2: L-4  R-5
4:
5:
3: L-6  R-7
6: L-8  R-9
8:
9:
7:
MIN:1
MAX :9
</pre>

# Sum of Nodes 
First we have stored ans in root ka data , then each time we are calling recursion on both left and right nodes and we are puuting it in ans.
```C++ 
int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
		return 0;
    }
    
    int ans = root->data;
    
    ans += getSum(root->left) + getSum(root->right);
    return ans;
    
}
```
<pre>
1: L-2  R-3
2: L-4  R-5
4:
5:
3: L-6  R-7
6: L-8  R-9
8:
9:
7:
sum :45
</pre>

# Check Balanced
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.  
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.

**APPROACH**
<pre>
SO it is a balanced tree
        1  -> 3-2 = 1
      /   \
-1<- 2     3 -> -1
    / \     \
0<-4   5->1  8 -> 0
      /
0<- 6  


        1
      /   \
     2     3
    / \     \
   4   5     6
              \
               7
This whole binary tree is balanced except for 3 i.e. = 2-0 = 2   
</pre> 
Base case : root == null return true.
Our calc : hl - hr > 1 return false  else call recursion on both left n right subtree. store the ans of left in a variable and right in b variable . Ans = a && b. we have to return true only if both are true.   

```C++ 
int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return true;
    }
	
    int hl , hr, a , b;
    hl = height(root->left);
    hr= height(root->right);
    if(hl - hr >= 1){
        return false;
    }
    
    a = isBalanced(root->left);
    b = isBalanced(root->right);
	int ans = a && b;
  
    return ans;
}
```
COMPLEXITY : O(n*height) which is v bad

## Check Balanced Better Approach


SO TO IMPROVE THE COMPLEXTY WE HAVE TO MAKE A PAIR CLASS JUST LIKE WE MADE FOR DIAMETER.
We will have to use a helper fuuc for this whose return type will be pair class ka obj and bool wale func mai vo helper func ko call karna hai   
base case : isbalnced = true , height = 0  
Pair {  
    isbalance  
    height  
}  
first call recursion and go in the subtree n check if it is balanced and check its height.  
so abhi we have ans from recusrion. abhi dono maise kisi ka result is false toh return false karna hai but this is a class so return pair karna hai .  
h = 1 + max(lh,rh)   
b = true or false  
COMLEXTY : O(n)

