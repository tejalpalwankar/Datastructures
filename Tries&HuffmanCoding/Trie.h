#include "TrieNode.h"
#include <string>
class Trie{
    TrieNode *root;

    public:
    Trie(){
        root = new TrieNode('\0'); // we do not need any data n root
    }

    void insertWord(TrieNode *root ,string word){
        //base case
        if(word.size() == 0){
            root-> isTerminal = true;
            return;
        }
        TrieNode *child;
        //Small calc
        int index = word[0] - 'a';
        // this is if we already have a children
        if(root ->children[index] != NULL){
            child = root ->children[index];
        }
        // if we don't have a children then create a node
        else{
            child = new TrieNode(word[0]);
            root ->children[index] = child;
        }

        // recursive call
        insertWord(child , word.substr(1));
    }

    // for user
    void insertWord(string word){
        insertWord(root, word);
    }

    bool search(TrieNode *root, string word) {
		if(word.size() == 0) {
			return root -> isTerminal;
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return search(child, word.substr(1));
	}

	bool search(string word) {
		return search(root, word);
	}

//     bool search(TrieNode *root,string word) {
// // Write your code here

//     if(root->children[word[0]-'a']==NULL)
//         return false;

//     if(word.size()==1)
//     {
//         return root->children[word[0]-'a']->isTerminal;
//     }

//     return search(root->children[word[0]-'a'],word.substr(1)); 
// }
// bool search(string word)
// {  
//     return search(root,word);
// }

    void removeWord(TrieNode *root ,string word){
        // base case 
        if(word.size() == 0){
            root-> isTerminal = false;
            return;
        }

        // small calc 
        TrieNode * child;
        int index = word[0] - 'a';
        if(root ->children[index] != NULL){
            child = root ->children[index];
        }
        else {
            // word not found
            return;
        }

        removeWord(child , word.substr(1));

        // Remove child node if it is useless
        if(child->isTerminal == false){
            for(int i = 0 ; i < 26 ; i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }

    //for user 
    void removeWord(string word){
        removeWord(root, word);
    }
    
};