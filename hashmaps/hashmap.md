# Introduction

- we have some string "_____" and we have to find highest occuring chars  
sorting O(nlogn)  
in a sorted array O(n)    
create an array of 256 size n a aaya toh a ke ascii value pe jaake frequency badha denge  
int a[256]  
then run a loop on i  
a[str [i]]++  
Now suppose we have to find max occuring word  
lets keep a key value pair ka map  
The functions we need are :
1. insert(k key , v value)
2. getValue(k key)
3. delete key (k key)  

Implementation :
1. LL
insert : go attach at  the node  and if pehlese exisit karta hai so usse he update karna hai  
del : find key n then del  
search : find the key  
Complexity : O(n)
2. BST (h= logn)  
insert , search , dlt are all O(logn)  

# Inbuilt Hashmap
we have 2 types of maps :  
1. Map - using BST O(logn)
2. Unordered Map - Hashtables O(1)

Inbuilt unordered map :
- insert : 2 ways 
- acces : 
    1. ourMap.at("ghi") : it will give an error key not found
    2. ourMap["ghi"] : if it does not exist it will insert 0 and give 0 to you
```C++
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    unordered_map<string , int> ourMap;

    // insert 1 way
    pair<string , int> p("abc", 1);
    ourMap.insert(p);

    // insert 2nd way
    ourMap["def"] = 2;

    //find or access
    cout << ourMap["abc"] << endl;
    cout << ourMap.at("abc") << endl;

    // cout << ourMap.at("ghi") << endl; it will give an error key not found
    cout << ourMap["ghi"] << endl; // if it does not exist it will insert 0 and give 0 to you

    // check if key is present
    if(ourMap.count("ghi") > 0){
        cout << "ghi is present" << endl;
    }

    // size
    cout << "size : " << ourMap.size() << endl;

    // erase 
    ourMap.erase("ghi") ;

    cout << "size : " << ourMap.size() << endl;
    if(ourMap.count("ghi") > 0){
        cout << "ghi is present" << endl;
    }
    else{
        cout << "ghi is not present" << endl;
    }
}
 ```
<pre>
1
1
0
ghi is present
size : 3      
size : 2      
ghi is not present
</pre>

# Remove Duplicates
we are given a array .  
we need to return a vector which have unique ele in the same order.  
So we need to just know if we have occured the ele before .  
so we will store a key (true or false) if the ele has occured before and a value along w it.  
why can't we use an array to store the values ? because for large ele like 10^6 the array will require that much space to store the ele so it is better to use a map.  
in map we can : map[10^6]= true and map is going to take a v small space.  

```C++
vector<int> removeDuplicates(int* a, int size){
    vector<int> output;
    unordered_map<int , bool> seen;
    for (int i = 0; i < size; i++)
    {
        if(seen.count(a[i]) > 0){
            continue;
        }
        seen[a[i]] = true ;
        output.push_back(a[i]);
    }
    return output;

}
```
<pre>
int a[] = {1,2,3,3,4,2,1,6,2,1,8,5,4,9};
output : 
1
2
3
4
6
8
</pre>

# Maximum Frequency Number 
```C++

int highestFrequency(int a[], int n) {

unordered_map<int, int> freq;
	
int maxFreq = 0;

for (int i = 0; i < n; ++i) {
	freq[a[i]]++;
	maxFreq = max(maxFreq, freq[a[i]]);
}

int maxFreqElement;

for (int i = 0; i < n; ++i) {
	if (freq[a[i]] == maxFreq) {
		maxFreqElement = a[i];
		break;
	}
}

return maxFreqElement;        
}

 ```

# Array Intersection

a1 -> 6  2 6 2 1 9 8  
a2 -> 3  6 8 2 9  
1. linear: for every ele in 1st arry go n search for it in the next array  O(m*n)  
2. binary seach : sort the smallest array  , sort the 2nd array , and perform binary search O(nlogn) + (mlogn) . it is not valid for duplicate ele. 
3. sorting : 
1 2 2 6 8 9 i  
2 3 6 8 9 j  
compare i and j if i==j print proceed , any of them is less move forward  
complexity : sort array 1 -> mlogn , sort arr 2 -> nlogn , merge -> O(m + n)   
mlogm + nlogn + O(m+n)  
4. **using hashmap** : 
The best solution here is to use hashmaps to further reduce the time complexity of
this problem. To continue with the hashmaps we can proceed with the following steps:
    1. Initialize an empty hashmap mapp.
    2. Iterate through the first array, and put every element of this array in the mapp with its
    corresponding count.
    3. Now for every element of the second array, search it in the hashmap and if it is present
    then print it and decrement its corresponding count. After decrement, if the corresponding
    count becomes zero, then we should remove the element from the mapp
Time Complexity for this approach: Time complexity for this approach is O(m+n) as searching
and inserting operations in hashmaps are performed in O(1) time.
<pre>
Pseudo Code for this approach:
Function intersection:
 Create an empty hashmap mapp
 For i=0 to i less than size1:
 Increment the count of each element of this array in hashmap
 For i=0 to i less than size2:
 If any element of array2 exists in hashmap:
 Print(element)
 Decrement the count of that element in hashmap.
 If count corresponding to that element is zero
 Delete(element, mapp)
</pre>
```C++ 
#include <unordered_map>
void intersection(int *arr1, int *arr2, int n, int m) 
{
	
    unordered_map<int, int> freq;
    for(int i=0; i < n; i++){
        freq[arr1[i]]++;
    }
    
    for(int i= 0; i < m; i++){
		if(freq[arr2[i]] > 0){
			cout << arr2[i] << " ";
            freq[arr2[i]]--;
        }
        if(freq.count(arr2[i]) == 0){
            freq.erase(arr2[i]);
        }
    }
    
}
```

# Pair Sum to 0

 

# Iterators


suppose we have a unordered map , I will take a iterator (it) and muje ek element ka pointer milega. If I do (it++) ye muje mere next ele pe leke jaayega

## Iterators over hashmaps
```C++ 
unorder_map<string , int> :: iterator it;
```
muje is iterator ko muje apne map ke start ele pe point karvana hai.  
it = ourmap.begin();  
fir aise karke hum aage jaaye ++ karke  
it = ourmap.end();  
when it reaches this point it means map is over  
```C++ 
unordered_map<string, int> ourmap;
ourmap["abc"] = 1;
ourmap["abc1"] = 2;
ourmap["abc2"] = 3;
ourmap["abc3"] = 4;
ourmap["abc4"] = 5;
ourmap["abc5"] = 6;

unordered_map<string, int> :: iterator it = ourmap.begin();
while(it != ourmap.end()){
    cout << "key : " << it->first << " Value: " << it->second << endl;
    it++;
}
```
<pre>
key : abc5 Value: 6
key : abc1 Value: 2
key : abc Value: 1 
key : abc2 Value: 3
key : abc3 Value: 4
key : abc4 Value: 5
</pre>

## Iterators over vectors

```C++ 
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);

vector<int>::iterator it1 = v.begin();
while(it1 != v.end()){
    cout << *it1 << endl;
    it1++;
}
```
<pre>
1
2
3
4
5
</pre>

- FUNCTIONS USING ITERATORS
```C++ 
unordered_map<string, int>::iterator it2 = ourmap.find("abc");
ourmap.erase(it2, it2 + 4);// it will dlt all the ele from it2 , it2 + 1 , it2 + 2

```

# Bucket Array and hash Function

lets implement our own map using hash tables.  
so we have keys and values and hume inhe store karna hai n ye kaam sabse fast array karta hai.  
lets try to use array to implement this. key ke sath value bhi store ho he jaayegi .  
abhi humare paas ek key aayi n usse hume store karna hai , humare array ko bucket array bolte hai . key can be anything. ab muje iss key ke corresponding ek int chaiye. So we take a hash funct :  
<pre>
key       -->     HASH FUNCTION    --> int
hash code --> COMPRESSION FUNCTION --> small int
</pre>
now what eveer nt we get we store that key corresponding to that int.   
### HASH FUNCTION
It is a type of compression func.
- **Hash code** : it converts a key into a hash code 
- **compression func** : it is going to compress the val received by the hash code. suppose hash code gives 10593 the compression func will put it in the range of 0-19(considering the array size 20).  A perfect compression func is **%bucketsize**.  
For diff keys we are going to have diff hash func :
- int : int we can return the same  
- string : "abc ko int mai convert karna hai . we have multiple ways : 
    1. sum of ascii values , but the issue is "abc" , "cba", "bca" will have the same hashcode.
    2. sum of 1st 3 chars , we have have more permutations but again this is limited
    3. **Num w base p : "abcd" = 'a'*p^3 + 'b'*p^2 + 'c'*p^1 + 'd'*p^0 . (p is usually a prime number)** 

At some point it is possible ke 2 str ka hash code alag ho compression value is same.  

# Collision 
when we are inserting keys it could happen that more than one key wants to go to the same place. 
COLLISION HANDLING  
1. **closed hashing** : dono wahi pe jaayege. every array ka entry will be a LL ka head . is also called has **separate chaining**
2. **Open Addresing** : if the place is not empty we have to find an alternate.  
How to find alternate ?  
hi(a) = hf(a) + f(i)  
This means ith attempt of a will be og hash func + f(i) i.e some func of i. In 0th attempt will be og pos.Diff open address tech means diff f(i).  
   - Linear probing : f(i) -> i++
   - Quadartic probing : f(i) -> i^2
   - double hasing : f(i) -> i*h'(a) take a completely diff hash func n mul it 
   

# Hashmap Implementation - Insert

lets keep the key as string for now  
so now we have a array size 20 ex. array ka har entry LL ka head hoga. Vo node ke andar key, value, next store hoga. 
Double pointer bcz hume head ka address store karna hai  
```C++
    Node<v>** buckets;
    int size;// to know kitni size aayi hai
    int bucketsize;
```

```C++
private:
    int getBucketIndex(string key){
        int hashCode = 0;

        int currentCoeff = 1;
        for(int i = key.length() - 1; i>=0 ; i--){
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;// for compression of large values
            currentCoeff *= 37; 
            currentCoeff = currentCoeff % numBuckets;// for compression of large values
        }

        return hashCode % numBuckets;
    }

    public:
    void insert(string key, V value){
       int bucketIndex = getBucketIndex(string key); 
       MapNode<V>* head = buckets[bucketIndex];
       while(head != NULL){
           // to check if the value is already exsisting in the LL and update that val
           if(head -> key == key){
               head ->value = value;
               return;
           }
           head = head->next;
       }
        head = buckets[bucketIndex];
        MapNode<V>* node = new MapNode<V> (key , value);
        node->next = head; // to connect node w the head
        buckets[bucketIndex] = node;
        count++;
    }

```
# Hash Map class

```C++ 
#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        // we are intializing by null as it is going to store garbage initially
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // to del the LL
        }
        delete[] buckets; // to delete the array
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;

        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; // for compression of large values
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets; // for compression of large values
        }

        return hashCode % numBuckets;
    }

    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for (int i = 0; i < 2*numBuckets; i++){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *=2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
        
    }



public:

    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            // to check if the value is already exsisting in the LL and update that val
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head; // to connect node w the head
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0*count)/numBuckets;// since it is int/int so 0.3 ka 0 aayega isiliye mult
        if(loadFactor > 0.7){
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex( key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                // if we found head as our 1st ele
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value; // to not loose the val
                head->next == NULL;    // to not loose the other LL
                delete head;           //memory free
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};
```
# Time complexity and load factor

1. Insert :
we  have a key which goes through hashfunc which goes into one bucket. Then I have a LL there I have to traverse that n if it exisits i have to update it. 
   - n->nnum of entries in our maps.
   - l -> len of word (for evaluating the base n power)
   - hash func : O(l)
   - If we have b boxes and n entries har box mai honge n/b.
   ### **LOAD FACTOR** : O(n/b) that means humare hash table pe kitna load hai. **We have to ensure n/b < 0.7**. So we can assume every box has const entry So complexity is O(1).
So whenever hash table ka load badhega we will do REHASHING that means bucket ka size badhana hoga. and apna load factor firse kam hona padega.
2. Deletion : O(1) same he kaam karna hai.

# Rehashing 

Jaise he load factor (n/b) 0.7 se upar chala jaayega we will rehash. Suppose we have arr of size 5 , we will have to make another array of size 10, purane wale ko temp mai n naya wala null. then go through temp and ek ek karke sabko daal dege naye array mai. 
Why can't we just copy the head ?
old array :  
abc -> hc 8 %5 = 3  
def -> hc 13 %5 = 3  
new array :  
def -> hc 13 %10 = 3  
abc -> hc 8 %10 = 8  
so this ele should now be at index 8 , so for this reason we have to copy each ele of LL individually. 

```C++ 
  void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for (int i = 0; i < 2*numBuckets; i++){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *=2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
        
    }
```
```C++ 
int main(){
    
ourmap<int> map;
for (int i = 0; i < 10; i++)
{
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    int value = i+ 1;
    map.insert(key, value);
    cout << map.getLoadFactor() << endl;
}
cout <<"size :" << map.size() << endl;

map.remove("abc2");
map.remove("abc7");

for (int i = 0; i < 10; i++)
{
    char c = '0' + i;
    string key = "abc";
    key = key + c;
    cout << key << " : " << map.getValue(key) << endl;
}

cout <<"size :" << map.size() << endl;
}
```
<pre>
0.2
0.4
0.6
0.4
0.5
0.6
0.7
0.4
0.45
0.5
10
</pre>