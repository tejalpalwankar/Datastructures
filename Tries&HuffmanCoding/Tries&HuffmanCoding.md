# Introduction

Suppose we want to implement a dict . What do we need ?  how can we use hashmap to do this ?  
1. addWord - O(1) avg case complexity
2. Search  ''
3. Remove Node ''

##  TRIE
Words here : The , this, note , not, dot, news, are , as
<pre>
        start
       / | | \
     A   D N   T
    / \  | |\   \
   R   S O O E   H 
   |       |  \  | \
   E       T   W E  I
           |   |     \
           E   S      S
</pre>
Every node can have max 26 children .  
Now lets try to search DOT , we won't dint the word.  
Try to seach AR , we will  find the word but we haven't inserted that word. To solve this hum apne last word ko highligh kar dete hai.  
Addword , sreach, remove Complexity : O(Wordlength)  

# Trie Node Class

**Why trie over hashmap for Dictionary Implementation?**
- space optimization : if there are 1000 words starting w a , every word will be under A , whereas in hashmap we have to make diff bucket for everyting.  
- Fast Searching : In a typical dic , all words starting w N will be place together, but in hashmap they will be random.  

Class : 
**char data;**  
We have to save the address of all children in every node (max 26 ) So lets store it all in a array.
TrieNode **children; 
Normal array creation - int *a = new int[10];
new int[10] se memory mai ek array create hoga jis value int type ki hogi n uske 1st loc ka adddress a mai store hoga.  
= new int*[10] array witth all val type int* type.  
int *a -> a is a pointer var whcih is holding int value.  
int **b -> it is a pointer var storing int* ka address.  
in trie also we are creating a array where we are storing trie node ka address.  
**TrieNode **children = new TrieNode*[26];**  
**bool isTerminal;**

# Trie Node Insert Implementation

Suppose we want to insert a word BET. This is also a tree so we can use recursion here. We can do our work on the root and call recursion on smaller subtrees. So i just need to go and search ke B naam ka koi child hai n then call recurion on that. N then b root banega n call recursion on e. N the e will be root n make a new node t and the t ko terminal banana hai.  

<pre>
       root
       / | 
     A   B
    /    |
   R     E
   |     | \
   E     D  N
            |
            D
</pre>
Implement :  
- base case : jaise he word ki length  stop and make it terminal
- recursive call : bache hue subtree ko attach karke leke aao.
- our work : Kya 1st char apna child hai . agar hai toh thik others make a new node with that data. 
<pre>
       root -->"and"
       /  
     A    --> "nd"
    /  \ 
   R    N  --> "d"
   |    |
   E    D  --> " "
</pre>

How to get a b c d ?
<pre>
int index = word[0] - 'a';
'a' - 'a' = 0;
'b' - 'a' = 1;
'c' - 'a' = 2;
'd' - 'a' = 3;

</pre>
```C++ 
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
```
<pre>
DRY RUN
we want to insert AND
     A    
    /  
   R      
   |    
   E    

child  Root   Word   index
&a      \0    "and"    0
&n     &a     "nd"    10
&d     &n     "d"     22
NULL   &d     ""      4  --> isterminal true
</pre>

# Trie Node Search
Base Case : Pehle hum base case mai dekh rahe hai ki (Index = word[0]-'a') root ka children Null hogaya kya . agar ye hua matlab humara terminal hume nai mila means humara word hume nai mila so hum return kar rahe hai false.  
Our work :Next agar word ka size 1 toh uss root ka child terminal hai kya  
recursive call : usme hum root ke children ka index pass kar rahe hai.

```C++ 
bool search(TrieNode *root,string word) {
// Write your code here

    if(root->children[word[0]-'a']==NULL)
        return false;

    if(word.size()==1)
    {
        return root->children[word[0]-'a']->isTerminal;
    }

    return search(root->children[word[0]-'a'],word.substr(1)); 
}
bool search(string word)
{  
    return search(root,word);
}
```
OR
```C++ 
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
```

# Trie Node Remove 
<pre>
       root -->"and"
       /  
     A    --> "nd" ko remove
    /  \ 
   R    N  --> "d" ko remove and arr[d] = null
   |    |
   E    D  --> " " base case isTerminal false
</pre>
base case : 

1st thing : isterminal ko null karnah hai.  
2nd thing : abhi n and d ko delte bhi toh karna hai . Ab d ko bass n he delte kar sakta hai kyuki n ke array mai he d ka address stored hai. Toh n ka array mai jaake d ko null karna hai.  
**Ab koi bhi node ko hum kab remove kar sakte hai ?** 
- uska isterminal false hoga  
- uske koi chidren nai hoge

```C++ 
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
    
```
INPUT :
```C++ 
int main(){
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout << t.search("and") << endl;
    cout << t.search("ar") << endl;
    cout << t.search("dot") << endl;

    t.removeWord("and");
    cout << t.search("and") << endl;

}
```
OUTPUT
<pre>
1
0
1
0
</pre>

# Types of Tries

## Compressed Tries 

- Space Optimization  
<pre>
               start
              /     \ 
            b         s
          /  \       /  \ 
         e    u    ell   to
       / \   / \         / \
     ar  ll  ll y      ck   p
</pre>

So in this we can club all the words together  
bear , bell  
bull , buy  
sell , stop, stock  
The implementation will be tricky as :
**Insert** : If we want to Insert BEAN , but ar are stored together , toh a and r alag karna padega and than n daalenge.  
**Delete** : If we want to delete BELL , EAR sathme club hona chaiye  

## Sffix Tries : For Pattern Matching 
<pre>
        \0
        / \
      b    n
    / \    |
   e   a   o
  / \  |   |
 d  n  t   t
    |      |
    d      e
</pre>
 We we will a text -  
s -> bed bend bat no note   
When we press ctrl+F we can find anything from our doc , so we have to implement something like that.  
Suppose we want to search :  
- bat : found  
- ben : not found -- we want here also to be found  
We can achive this by just removing isTerminal property.
- at : but root ke paas a child he nai hai toh false aayega but true aana chaiye
<pre> 
Found    Not Found
b           end
be           nd
ben         en
bend        d
prefix     suffix
</pre>
**We are getting all the prefixes but not suffixes**  
How can we resolve that ?  
Insert : BEAN -->  
You will have to insert :  
bend , end , nd , d.
<pre>
        start
      / | | \
     b  e n  d 
     |  | |
     e  n d
     |  |
     n  d
     |
     d
</pre>
While Creating we will require space and time .  
if we want to optimize space, we can use compressed tries in it.

```C++ 
class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    bool search(TrieNode *root, string word) {
		if(word.size() == 0) {
			return true;
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

    bool patternMatching(vector<string> vect, string pattern) {
        // Write your code here
        for(int i=0 ; i < vect.size() ; i++){
            while(vect[i].size()!=0){
				insertWord(vect[i]);
            	vect[i] = vect[i].substr(1);
            }
    }
    return search(pattern);
        
    }
};

```

# Huffman Coding

Text Compression :  
F -> a b a a a d - 6 bytes = 48 bytes  
Lets try to reduce the space req. of most freq chars.  
a - 3 bits  
b - 12 bits  
d - 11 bits  
= 35 bits  
How to approach ?  
lets say we have a file F
1. figure out count of every char  
   - a = 40
   - b = 3
   - e = 10
   - f = 2
   - x = 1
   - n = 12  
   - q = 13 
2. Figure out the count of 2 min  
    - f,2
    - x,1
    = 3  
remove them from list

<pre>
            (f,2)        (x,1)
              |____ 3 ____|  (b,3)
                    |____ 6 ____|     (e,10)
(n,12)     (q,13)         |____ 16 ____|
  |____25_____|                  |
        |____________ 41 ________|
    (a,40)            |
      |_______ 81 ____|
               |
            start
</pre>
Now give 0 to every left node and 1 to eevery right. (viceversa also possible)  
a - 0  
b - 1101  
n - 100  
q - 101  
e - 111  
e - 11001  
f - 11000  
So now replace every char with this code  
F -> aafqaea -> 56bit  
F -> 001100010101110 ->15bit  
### DECOMPRESSION :  
The codes won't be repeated so we will replace each num by it's respective code  

IMPLEMENTATION :
1. count freq of char
2. 2 min vals , use MIN PRIORITY QUEUE  
3. the figure is a inverted binary tree 
4. figure out unique code , root to leaf unique path.  
5. Now save the char and respective code in hashmap (save all the bits i.e(00101) as 1 byte together)
6. decompression : one more hashmap, put code as key and char as value .