#include <iostream>
#include <cstddef>
#include <queue>
using namespace std;
#include "binaryTreeClass.h"


void printTree(BinaryTreeNode<int>* root){

    if(root == NULL){
        return;
    }

    cout << root->data << ":";
    if(root->left != NULL){ // OR if(root->left)
        cout << " L-" << root->left->data << "  " ;
    }
    if(root->right != NULL){ // OR if(root->left)
        cout << "R-" << root->right->data ;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
    int rootData ;
    cout << " Enter Data :" << endl;
    cin >> rootData;
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

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    return 1 + numNodes(root->left) + numNodes(root->right);
}

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    
    if(root == NULL){
        return false;
    }
    
    if(root->data == x){
        return true;
    }
    
    return isNodePresent(root->left, x) || isNodePresent(root->right, x);

}

void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
		return;
    }
    
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
    
}

void postOrder(BinaryTreeNode<int> *root) {

    if(root == NULL){
		return;
    }
    
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    
}
/* 
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
 */
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



BinaryTreeNode<int>* buildTree(int* postorder, int postLength, int* inorder, int inLength) {
    // Write your code here
    return buildTreeHelper(inorder, postorder , 0, inLength -1, 0, postLength -1);
}

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

int getSum(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
		return 0;
    }
    
    int ans = root->data;
    
    ans += getSum(root->left) + getSum(root->right);
    return ans;
    
}

//wrong
pair<int,int> heightbalanced(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int , int> p;
        p.first = true;
        p.second =0;
        return p;     
    }
 	
    pair<int, int> leftAns = heightbalanced(root->left);
    pair<int, int> rightAns = heightbalanced(root->right);
    
    int lh = leftAns.second;
    int lb = leftAns.first;
    int rh = rightAns.second;
    int rb = rightAns.first;
    
    int height = 1 + max(lh , rh);
    int bal = lb && rb;
    
    pair<int, int> p;
    p.first = bal;
    p.second = height;
    return p;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(){
  /*   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
 */

    // BinaryTreeNode<int>* root = takeInput();
    BinaryTreeNode<int>* root = takeInputLevelWise();
  /*   root->left = node1;
    root->right = node2;
 */

    // int in[] = {4,2,5,1,8,6,9,3,7};
    // int pre[] = {1,2,4,5,3,6,8,9,7};
    // int po[] = {4, 5, 2, 8, 9, 6, 7, 3, 1};
    // BinaryTreeNode<int>* root = buildTree(po, 9, in, 9);
    printTree(root);
    // printLevelWise(root);
    // cout << "Num of node : " << numNodes(root) << endl;
    // cout << "inorder" << endl;
    // inorder(root);
    // cout << "preorder" << endl;
    // preOrder(root);
    // cout << "postorder" << endl;
    // postOrder(root);
    // pair<int, int> p = heightDiameter(root);
    // pair<int, int> p = getMinAndMax(root);
    pair<int, int> p = heightbalanced(root);
    // cout << "MIN:" << p.first << endl;
    // cout << "MAX :" << p.second << endl;
    cout << "balance:" << p.first << endl;
    cout << "height :" << p.second << endl;
    // int ans = getSum(root);
    // cout << " sum :" << ans;
    delete root;

}