#include <iostream>
#include "TreeNode.h"
using namespace std;
#include <queue>

void printTree(TreeNode<int>* root){
    // It is a EDGE CASE and not base case
    if(root == NULL){
        return;
    }

    cout << root->data << ":"; //this will work as a base case also

    for(int i=0; i< root->children.size() ; i++){
        cout << root->children[i] ->data << ",";
    }
    cout << endl;
    for(int i=0; i< root->children.size() ; i++){
        printTree(root->children[i]);
    }
}


void printLevelWise(TreeNode<int>* root) {
    
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root); //queue mai push kiya
    
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
		cout << front->data << ":";
        pendingNodes.pop();
        
        for(int i=0; i< front->children.size() ; i++){
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

TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter data :" << endl;
    cin >> rootData;
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

int numNodes(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int ans = 1;
    for(int i=0 ; i<root->children.size() ; i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}

int sumOfNodes(TreeNode<int>* root) {
    // Write your code here
    int ans = root->data;
    for(int i=0 ; i<root->children.size() ; i++){
        ans += sumOfNodes(root->children[i]);
    }
    return ans;
}


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

void preorder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    for(int i=0 ; i<root->children.size() ; i++){
        preorder(root->children[i]);
    }
}

void printPostOrder(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return;
    }

    for(int i=0 ; i<root->children.size() ; i++){
        printPostOrder(root->children[i]);
    }
    
    cout << root->data << " ";
    
}

void deleteTree(TreeNode<int>* root){
    for(int i=0 ; i<root->children.size() ; i++){
        deleteTree(root->children[i]);
    }

    delete root ;
}

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
// 1 1 2 1 3 1 4 1 5 0
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
/* 
        1
      / | \ 
    2   3  4
   / \  /\
  5   6 7 8
           \ 
            9
*/
int main(){
   /*  TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    //for connecting these nodes
    root->children.push_back(node1);
    root->children.push_back(node2);
 */

    // TreeNode<int>* root = takeInput();
    TreeNode<int>* root = takeInputLevelWise();
    // printTree(root);
    printLevelWise(root);
    // sumOfNodes(root);
    // cout << "Level k : " << endl;
    // printAtLevelK(root, 3);
    // int count = getLeafNodeCount(root);
    // cout << "count" << count << endl;
    cout << "Pre order" <<endl ;
    preorder(root);
    cout << "Post order" <<endl ;
    printPostOrder(root);
    cout << "node count" <<endl ;
    cout << getLargeNodeCount(root, 1) << endl;
    deleteTree(root);
}