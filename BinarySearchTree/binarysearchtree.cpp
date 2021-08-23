#include <iostream>
#include <cstddef>
#include <queue>
#include <climits>
#include <vector>
#include "BinarySearchTreeClass.h"
// #include "binaryTreeClass.h"
using namespace std;

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

// BinaryTreeNode<int>* takeInputLevelWise(){
//     int rootData ;
//     cout << " Enter root Data :" << endl;
//     cin >> rootData;
//     if(rootData == -1){
//         return NULL;
//     }

//     BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
   
//    queue<BinaryTreeNode<int>*> pendingNodes;
//    pendingNodes.push(root);

//    while(pendingNodes.size() != NULL){
//        BinaryTreeNode<int>* front = pendingNodes.front();
//        pendingNodes.pop();

//        cout << "Enter left child of " << front->data << endl;
//        int leftChildData;
//        cin >> leftChildData;
//        if(leftChildData != -1){
//            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
//            front->left = child;
//            pendingNodes.push(child);
//        }

//        cout << "Enter right child of " << front->data << endl;
//        int rightChildData;
//        cin >> rightChildData;
//        if(rightChildData != -1){
//            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
//            front->right = child;
//            pendingNodes.push(child);
//        }

//    }

//     return root;
// }

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
/* 

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

int minimum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MAX;
    }
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root){
    if(root == NULL){
        return INT_MIN;
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
 */
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 -1 -1 -1 -1 -1 -1 -1 -1 isbst
// 4 2 6 1 30 5 -1 -1 -1 -1 -1 -1 -1 -1 is not bst
int main(){
    BinaryTreeNode<int>* root = takeInput();
    // elementsInRangeK1K2(root, 6,9);
    // cout << isBST(root) << endl;
    // cout << isBST3(root) << endl;
    printLevelWise(root);
    // int n = 7;
    // int arr[] = {1 ,2, 3,4,5,6,7};
    // constructTree(arr,7);
    // vector<int>* output = getRootToNodePath(root,8);
    // for(int i = 0; i< output->size();i++){
    //     cout << output->at(i) << endl;
    // }
    // delete output;
    // delete root;

    // BST b;
    // b.insert(10);
    // b.insert(5);
    // b.insert(20);
    // b.insert(7);
    // b.insert(3);
    // b.insert(15);
    // b.printTree();
}
