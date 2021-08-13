#include <iostream>


template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data){
        this-> data = data;
        left = NULL; // garbage store hoga isiliye null
        right = NULL;
    }

    // yaha we want har node jaate jaate apne left aur right child ko bhi dlt kare
    ~BinaryTreeNode(){
        delete left;
        delete right;

    }
};