# Introduction

Graph is a type of data structure where the nodes are connected to each other in no particular order.It is a types of a network.  
eg : social media network , roads in a country.  
Tree is a special kind of graph in which each node is connected to some other node, and there is no cycle in it.  

# Terminology  
<pre>
    A     B
    O-----O -> vertices
    |     |
    |     | -> edges
    O-----O
    C     D
</pre>
- Vertices : Nodes  are known as vertices  
- Edges : Line connectiong the 2 nodes is known as edges  
- Adjacent vertices : vertices which are aaju baaju  
- Degree : One node is connected to how many other node. Number of edges
- Path : A->B i can go directly , but to go from A->D I have to go through edges so that is called a path 
- Connected nodes : There has to be a way to go to each vertex
- Connected Components : Components are connected to each other but components are not connected to each other . 
- Tree : it is a connected graph which does not have a cycle

If we have  a graph with n vertices : 
1. Min num of edges : 0
2. Min num of edges in a connected graph : n-1
3. Min num of edges in a Complete graph(every vertex has a edge with every other vertex) : nC2 =n(n-1)/2  
Min num of edges O(n) to max O(n^2)  

# Graphs Implementation 

class graph {  
    array containing all vertices  
    array containing all edges(it will be pairs)  
}  
1. Edge List 
It is called as edge list  
zIf anyone ask do you have any road directly connecting to delhi ? we don't know > we will have to go through the list of edges to answer this simple query . 
2. Adjecency List :
 We will have an array containing all the vertices and each of these vertices are going to strore who it is conected to.  
Now finding a edge is comparatively easier.  
Maps can be used here
3. Adjcency Matrix 
If we have 10 vertices we will create 10X10 array.  
Now if I want to check if 3 and 4 are connected , I will go 3rd row ke 4th col (i,j) to check if it is true or false  
Space Complexity is very high for this O(n^2)  
If we have very few edges there is a wastage of space

# DFS Adjacency Matrix 

Input :  
We will ask the user to enter vertices and edges. 
Now we will have a for loop for edges . if the user enters (1,2) (2,1) also should be marked as true.  
Print :We will start from 0 and print all vertices in a particular order  


```C++ 
void print(int** edges , int n, int sv){
    cout << sv << endl;
    for(int i = 0 ; i < n ; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            print(edges , n, i);
        }
    }
}
```
YE CODE MAI EK PROBLEM HAI . 
If we have a graph :  
 0 - 2 - 3 - 1  
0 ke adjacent 2 hai toh uspe call hoga and when 2 will go through it's array it will again call back on 0 so ye aise he ek loop mai ghumte rahega.   
Ideally if we have gone through 0 we shouldn't again go back to it . So we will keep a track of all the vertices we have been through.  
So lets make a list to store all the vertices we have seen. It can be either a array or a map.

## Printing and taking input
```C++ 
#include <iostream>
using namespace std;

void print(int** edges , int n, int sv, bool* visited){
    cout << sv << endl;
    visited[sv] = true;
    for(int i = 0 ; i < n ; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            print(edges , n, i , visited);
        }
    }
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for(int i=0 ; i <n ; i++){
        edges[i] = new int[n];
        //to remove the garbage vals
        for(int j = 0; j< n; j++){
            edges[i][j] =0;
        }
    }

    // taking input the edges and putting them in the matrix
    for(int i = 0 ; i < e ; i++){
        int f , s; // f -first vertex , s- second vertex
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for(int i =0 ; i < n ; i++){
        visited[i] = false;
    }

    print(edges , n, 0 , visited);

    //delete everything
}
```
<pre>
vertices : 4
Edges : 3
Edge 1 : 0 2
Edge 2 : 2 1
Edge 3 : 1 3
Verices : 
0
2
1
3

        0
       / \
      1   2 
      |   | \
      5   3  6
       \ /
        4  

0 1 5 4 3 2 6
</pre>
So here we are basically just going in one direction and printing and not level wise. We are going to the depth in one direction. 
**This is known as  DEPTH FIRST**

# BFS Breadth First Search 

<pre>
        0
       / \
      1   2 
     / \   \ 
    3  4    6
    \  /    /
     \/___/
     5
</pre>
now Here we will go level wise .  
0 1 2 3 4 6 5  
WE are seeing it's distance from 0 and printing it.  
We will not use recursion. 
so we will use a queue, 
- put 0 in a queue , put adjcent to 0 
- remove front and print it.
- visited nodes should not be repeated
```C++ 
void printBFS(int** edges , int n , int sv ){
    queue<int> pendingVertices;

    bool* visited = new bool[n];
    for(int i = 0 ; i < n; i++){
        visited[i] = false;
    }

    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        cout << currentVertex << endl;
        pendingVertices.pop();
        for(int i = 0 ; i < n ; i++){
            // lets not check 0 ka 0 se edge hai kya
            if(i == currentVertex){
                continue;
            }
            //agar edge hai and visisted nai hai
            if(edges[currentVertex][i] == 1 && !visited[i]){
                    pendingVertices.push(i);
                    visited[i] = true;
            }
        }
    }
    delete [] visited;
}
```
<pre>
        0
       / \
      4   5
     /     \
    3-------6
   / \       \
  2---1       7
input :
8 
9
0 4
0 5
4 3 
3 2
2 1
1 3
5 6 
3 6
6 7
DFS : 0 4 3 1 2 6 5 7
BFS : 0 4 5 3 6 1 2 7
</pre>

# BFS and DFS for disconnected graphs

If we have 2 connected componenets , and we use the previous code , we can print only 1 connected component.  
So here fisrt we will go through the 1st connected component and print all .  
Then we will go through our array and check if all visited are printed. If we find any visited not printed then we will start printing that. 

## DFS 
So basically here we are calling the prev function inside a for loop . 1st this will be called at the startindex . then once 1 connected conponent is done it will again go through the whole array to check if it is visited and then pura function uske liye run hoga
<pre>
    0       4
   / \     / \
   1  2   7---8
   \ /    
    3   5---6
</pre>
So 1st ye  for loop 0 pe call karega n print all  
Then it will find 4 unvisited so 4 pe call karke sab print hoga  
Then 5 will be still unvisited so uspe call hoga  
```C++ 

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}
```


## BFS 
yaha the only change is we are passing the visited array in the printBFS . As we have created a  visited array already in the BFs function.
```C++ 
void printBFS(int **edges, int n, int sv , bool* visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    
    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        cout << currentVertex << endl;
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            // lets not check 0 ka 0 se edge hai kya
            if (i == currentVertex)
            {
                continue;
            }
            //agar edge hai and visisted nai hai
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

void BFS(int** edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}
```

<pre>
    0       1
   / \     / 
  2---3   4
    
 5---6

vertices : 7
edges : 5
0 2 
0 3
2 3
1 4
5 6
DFS : 0 2 3 1 4 5 6
DFS : 0 2 3 1 4 5 6
</pre>

# Has Path 

2 vertices are given start vertex and end vertex and we have to check if there is a path betwween them .  
SV se start karenge and end mil gaya toh return true others return false.  
If DFS : check start and ending adjacent hai direct edge hai toh path  bhi hai toh return true. else start ke adjacent ko puchege path hai ya nai.

## DFS
```C++ 
bool hasPathDFS(int **edges, int n, int sv,int ev, bool *visited){
	
    if(sv == ev){
	return true;
    }
    
    visited[sv] = true;
    for (int i = 0; i < n; i++){

        if(edges[sv][i] == 1 && !visited[i]){

          return  hasPathDFS(edges, n, i,ev, visited);
        }
    }
    return false;
}

```

# Get Path 

## DFS 
We have a ev 
base : if (start == end) mil gaya path  
start vertex se DFS call karna hai adj pe  
if sv to ev ka koi path nai hai , s1 s2 s ke adj walo ka bhi direct path nai hai toh return NULL.  
agar s1 se mila path toh return that path  

arrayList<> getPath(adj[][] , s , e)  
if there exists a path : what to return  
If no path return NULL  

start traversing a path from start vertex to end vertex , if we reach end vertex that means there is a path  
if 0 has multiple neighbours , n1 will return path from n1 and e , no path NULL .  
n2 if not null there will be path.  
call recursion on all neighbors.  
if start == end {  
    create a new array list  
    add s to arralist and return  
}  
check path via all neighbours  
arraylist =getPath(neigh ith, end)
```C++ 
vector<int>* getPathHelper(int** edges , int n , int sv , int ev, bool* visited ){
    if(sv == ev){
        vector<int>* output = new vector<int>();
        output->push_back(ev);
        return output;
    }
    
    visited[sv] = true;
    for(int i=0 ; i < n ; i++){
        if(edges[sv][i] && !visited[i]){
            vector<int>* smallOutput = getPathHelper(edges , n , i , ev, visited);
            if(smallOutput != NULL){
                smallOutput->push_back(sv);
                return smallOutput;
            }
        }
    }
    return NULL;
}

vector<int>* getPath(int** edges , int n , int sv , int ev ){
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<int>* output = getPathHelper(edges ,n , sv , ev , visited);
    delete [] visited;
    return output;
}
```

## BFS
<pre>
        0
       / \
      1---2
           \
            3

DFS : 0 1 2 3
BFS : 0 2 3
</pre>

use a queue . jaise end vertex queue mai chala gaya hum ruk jaayege.  
humare upar wale queue mai pehle 0 jaayega , then 0 bahar aayega and 1 and 2 jaayega , fir vo dono bahr aake 3 jaayega . But kaise pata chalega 3 ko kisne daala tha ? keep a map and kuch bhi insert karenge to put it in the map ke usko kisne daala.  
Code Implementation :
<pre>
        0
      / | \
     1  2  3
     |  | 
    4   6
</pre>
vector getPath{  
    queue<> pendingVertices;  
    hashmap<int, int> map;  
    pv.push(start)  
    visited  
    loop till queue is empty  
    imsert all unvisited neighours  
    parent of neighbor will be the current vertex  
}  
if 0 is currentvertex = parent  
loop over neighbour ith which is child  
hashmap(i , cv)  
find every parent till it is 0  


# Is Connected 

start se end pe jaate hai n dekhte hai koi bhi vertex unvisited hai kya agar hua toh it is not a connected graph. 

```C++ 
void DFSHelper(int **edges, int n, int sv, bool* visited)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++){
        if (edges[sv][i] == 1 && !visited[i])
        {
            DFSHelper(edges, n, i , visited);
        }
    }

}

bool DFS(int **edges, int n, int sv)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    DFSHelper(edges,  n,  sv , visited);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
    delete [] visited ;

}
```

# Return all connected Components

if we have 3 connected componenets , we have total output in that we have other components. 
Initially we will go to the 1st connected component and print it.Once we are done w that , everything . Pass the vector with it. 



# Directed Graphs
This graph has  a specific direction. Like it can go fro A to B , but it cannot go from B to A. Example : one way roads.So humare edges mai  
edges[i][j] = 1  
edges[j][i] = 1  Ye nai karna hai


# Weighted Graphs

matlab ye graph ka weight hai . It can be length of the road , on social media when they got connected. 
<pre>
       5
    A --- B
  2  \   / 1
       C
</pre>
So here A-C-B will the the shortest path  
edges humne bool rakha tha  
edges[i][j] = 1  true  
toh 1 ke jagah hum yaha weight rakhenge  
edges[i][j] = 5  

