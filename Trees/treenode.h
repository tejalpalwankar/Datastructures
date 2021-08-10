#include <vector>
using namespace std;

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

    ~TreeNode(){
    for(int i=0 ; i< children.size() ; i++){
            delete children[i] ;

    }

    }

};