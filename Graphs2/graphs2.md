# Spanning Tress
Tree is basically a graph which is connected and acyclic.  
Spanning Tree means a tree which connects all the vertices . For a  given graphs we can have multiple spanning trees.  
<pre>
    0-----1
    | \ / |
    | / \ |
    2-----3

this is a given graph for which we can have varipus spanning trees  
    0-----1
    | 
    | 
    2-----3

    0-----1
        /
      / 
    2-----3

    0   1
    | \ |
    2   3
</pre>
In a spanning tree we have  
- Vertices : n  
- Edges : n - 1  
- graph : weighted  
***So now are graph is  WEIGHTED , CONNECTED , UNDIRECTED.***
Minimum spanning Tree is a spanning tree whose weight is minimum.  
So include all the edges whose weight is minimum.  

# Kruskal's Algorithm 
It helps us to figure out the Minimum Spanning Tree MST of our graph.  
What we have to do ?  
We have to figure out the min wieght wala edge and usse daalna hai . we have to maintiain a count while adding each edge as the edges possible are (v-1). while adding each edge we have to be carefull to check whether it is forming a cycle or not.  

## Cycle detection 

1. Checking vertices (Fail)
Somehow we can maintain the vertices which are already added. 
- If out of 2 vertices 1 vertice is already added then no issue we can add that vertice.  
- If both vertices are are present we cannot say whether or not it will form a cycle.  
SO WE CANNOT USE THIS ...  
2. Check Path  
So before inserting to vertices , check whether there already exsits a path between them .  
we are just calling hasPath on each v1 and v2 we are enterning.  
Complexity : O(V + E) of hasPath. worst case num of edges V^2. So complexity wise it is very bad.  
3. Union-find 
if v1 and v2 both are inserted before we can add a edge.  
we had a problem if both v1 and v2 are already present.  
So we can just check here if both the vertices are in the same components.  
ALGORITHM :  
- initially assume jitne vertices hai utne disjoint sets hai which are not related to each other.  
- we will maintain a parent array and vo vertices ka parent kon hai.
- so there will be v1 and v2 , p1 and p2 for parents. agar parents are same they lie in the same component. If parents are diffrent p1 != p2 i.e they are in diff components and we are safe toh join.  
- abhi dono maise ek child ko parent banana hai.  
- agar parent same aaya toh skip that edge.  
- remember we have to find the topmost parent.
COMPLEXITY : if our parent tree is in one line : O(V) so finally it is O(V).

## Implementation 

Soo we are going to get total num of edges n , edges e. fir ek ek edge milega source , destination , weight .  
Yaha we are choosing edges based on their weight . min wale edge ko sabse pehle lena hai. So adjecency matrix won't be able to help us here.  
So will create a edge class :  
edge {  
    source  
    destiation  
    weight  
}  
Fir ek input array banayenge of type edge and size e.  
Then another array output of type edge and size n-1.  
1. take input
2. sort the input array in increasing order.sort(a , a+n) i.e a=array , a+n =end  . here a is basically the start and a +n is the end.
3. Make a array for parent of size n and type int.Initailize this array with same index value. 0 ka parent 0 , 1 ka 1.
4. Maintain a count and now traverse over the input array  till n-1. Run a loop while(count < n-1) 
5. Cycle detection using union find. now if we are inserting 2 vertices v1 , v2. Now calulate the parent of v1 and v2 with parent array. If parent is diff put in the MST and count++.Now connect both the parents. If parents are same skip the edge.
4. return output

```C++ 
#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
};

// comaprator to sort array of type class
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight; // to sort in increasing array
}

int findParent(int v, int *parent)
{
    // agar index and data ke val same hui i.e 0 ka parent 0 means we got topmost parent
    if (parent[v] == v)
    {
        return v;
    }

    return findParent(parent[v], parent);
}
void kruskals(Edge *input, int n, int e)
{

    //sort thr input array in asec order based on weights
    sort(input, input + e, compare);

    Edge *output = new Edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge currentEdge = input[i]; // min edge aagayi isme

        // check if we can add current edge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.destination, parent);

        if (sourceParent != destParent)
        {
            // output[i] = input[i]; we can't use i bcz input mai hum thode chize skip kare hai
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}
```

## Time complexity 
vertices = v , edges = E  
1. Take input - size : E
2. Sort input array : ElogE
3. Pick n-1 edges and put in MST  
-> perform cycle detection : agar linear ban gaya toh O(V) in worst case.
-> put in MST : ek edge ke liye V time so E edges ke liye O(EV)

**So overall complexity : O(ElogE + EV)**  
We cannot improve the sorting ka complexity but we can improve the union find ka .  
**Union by Rank and Path Compression** is a better version of union find all. here we will just try to keep our parent tree balanced and not linear.  
So humara complexity hoga :  O(ElogE + ElogV)  

# Prim's Algorithm

we are going to maintain :  
vertex , parent , weight  
visited , unvisited  

Like kruskal Prims is also a greedy algorithm. GREEDY ALGORITHM MEANS IF WE HAVE MULTIPLE OPTIONS WE ARE GOING TO CHOOSE WHAT IS BEST FOR US. see we have many edges but we are choosing only those whose weight is minimum. 
<pre>     
        1-------3
      / |      /|
    0   |    /  |
      \ |  /    |
        2-------4

vertex      parent       weight    visited    unvisited
0           -1           0         {}         {0,1,2,3,4}
1            0           4         {0}        {1,2,3,4}
2            0,1        8,2        {0,1}       {2,3,4}
3            1,2        6,3       {0,1,2}      {3,4}
4            2,3        9,5       {0,1,2,3}     {4}
                                  {0,1,2,3,4}

</pre>

1. So we need to check if the vertex is visited or no.We only have to work on unvisited vertex. We have to keep parent and weight of wvery vertex.   
2. We can keep 3 arrays :  
- bool visited[] : 0 -(n-1) true is visited 
- weights[]
- parent[]
3. So to store the graph we will use adjacency matrix.  
4. We are supposed to visit all the vertices.  
**for** a vertex in a vertex set v -> u:v we have to  
a = pick the min weight vertex unvisited  
5. **for** travel all neighbours of a which are unvisited and decide wheter to update parent & weight of the neighbour.
6. end both for loop  
```C++ 
int minWeightVertex(bool* visited, int* weights , int n){
    
    int minVertex = -1;
    // initially minVertex -1 hoga tabhi hum kisse compare karenge
    for(int i =0 ; i< n ; i++){
        if(!visited[i] && (minVertex == -1 ||  weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Prims(int **edges, int n){
    bool *visited = new bool[n];
    int *weights = new int[n];
    int *parents = new int[n];
    
    // setting default values for all
    for(int i =0 ; i < n ; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    // initializing the 1st vertex
    parents[0] = -1;
    weights[0] = 0;

    for(int i = 0 ; i < n - 1 ; i++){
        // Find minVertex
        int minVertex = minWeightVertex(visited,weights,  n);
        visited[minVertex] = true;

        //Explore unvisited neighbbours
        for(int j =0 ; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weights[j]){  // if humare paas better weight aaya toh usse pick karo
                    weights[j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }

    for(int i = 1; i < n ; i++){
        if(parents[i] < i){
            cout << parents[i] << " "<< i << " " << weights[i] << endl;
        }
        else{
            cout << i << " "<< parents[i] << " " << weights[i] << endl;

        }
    }
}
```

<pre>
input :
5 7
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
2 4 5
output :
0 1 4
1 2 2
2 3 3
2 4 5

</pre>

COMPLEXITY :  
- 1st for loop to traverse the vertices : (n-1)  
- Find min vertex() : O(n)
- for loop for going through adjecency matrix : n x (n-1)
- TOTAL : O(n^2) n=no. of vertices .  

to improve this :  
- we are using adjecency matrix, so if we have 10 vertex and suppose vertex 2 ke 2 he neighbors hai , ideally i should be going on that only. But yaha mai har neighbor pe jaari hu.  
**Hum adjecency matrizx ke jagah adjecency list use karte sakte hai.**  
- findMinVertex mai bhi hum bohot traverse karre hai. **Priority Queue** can be used here . but aage humara weight ka value change hora hai tabhi hume priority queue bhi update karna hoga. 
If we implement this (E + V)logV = (E + n)logn  

# Dijkstra's Algorithm
<pre>
        1-------3  weights  0-1 : 4
      / |      /|           0-2 : 8     
    0   |    /  |           1-2 : 2
      \ |  /    |           1-3 : 5
        2-------4           3-2 : 5
                            3-4 : 4
                            2-4 : 9
</pre>
If we have a graph directed/undirected , it can have cycles , it should not we negative weights. So we can use Dijkstra's algorithm to find the shortest path between any 2 nodes.

**one thing I can do is mere source se sabke liye shortest distance nikalugi , toh destination ka bhi mil hee jayega.**

- Initially sabke dist mai inifinity daal diya tha.  
- pehle 0 ka distance khudse 0 mark kar dete hai.Now I will pick a vertex with min vertex. and 0 ko visited mark kar dete. Abhi 0 ke neighbors pe jaate hai.So 0 to  1 jaaneka cost hai 4. 0-2 is 8. visited {0}
- Next 1 pe jaayege . 1 ke neighbors hai 0 , 2 , 3. 0 is visited so 2,3 pe jaate hai.  
path cost via 1 = dist[1] + 1-2ka edge = 4 + 2 = 6. So pehele 2 ka distance tha 8 and 6 kam hai toh update kar diya.  visited {0, 1}
- next go to 2 . 2 ke unvisited hau 3, 4.  
cost = dist[2] + 2to3 = 6 + 5 = 11 , but 3 ka tha 9 which is less so do not update.  
cost = dist[2] + 2-4 = 6 + 9 = 15.upadte as initially infinity  
visited {0, 1,2}
- next go to 3, 3 ka unvisted is 4.  
cost = dist[3] + 3to4 = 9 + 4 = 13 . update as initially it was 15.  
- **So the Final min cost is 13.**

what we are doing here : 
1. current vertex choose kiya which is the min.
2. uske neighbours pick kiye, and uss vertex ke through neighbour tak pohchne ka cost nikala , agar exisiting se kam hai toh update kiya.

What do we need in this ?  
- bool Visited array
-  distance array  
- for vtimes I have to find mindistancevertex
- minVertex = [visited]
- for minvertex explore neighbours   
curren_dist = dist[minvertex] + weight[min to neighbour]  
if dist[neighbor] > current_dist{  
    dist[neighbor] = current_dist  
}

```C++ 
int minDistanceVertex(bool* visited, int* distance , int n){
    
    int minVertex = -1;
    // initially minVertex -1 hoga tabhi hum kisse compare karenge
    for(int i =0 ; i< n ; i++){
        if(!visited[i] && (minVertex == -1 ||  distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(int **edges, int n){
    bool *visited = new bool[n];
    int *distance = new int[n];
    
    // setting default values for all
    for(int i =0 ; i < n ; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    // initializing the 1st vertex : source ka distance khudse 0 he hoga
    distance[0] = 0;

    for(int i = 0 ; i < n - 1 ; i++){
        // Find minVertex
        int minVertex = minDistanceVertex(visited, distance,  n);
        visited[minVertex] = true;

        //Explore unvisited neighbbours
        for(int j =0 ; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int currentDistance = distance[minVertex] + edges[minVertex][j];
                if(currentDistance < distance[j]){  // if humare paas better weight aaya toh usse pick karo
                    distance[j] = currentDistance;
                }
            }
        }
    }

    for(int i = 0; i < n ; i++){
            cout << i << " " << distance[i] << endl;
        
    }
}
```
<pre>
input :
5 7
0 1 4
0 2 8
1 3 5
1 2 2
2 3 5
2 4 9
3 4 4

output:
0 0
1 4
2 6
3 9
4 13
</pre>

COMPLEXITY :
- 1st for loop : O(n)
- for neighbour : minvertx = n , for loop = n = 2n
- total : (n-1) * 2n = **O(n^2)**

How to improve it ?  
for loop of minVertex : adjecency list use instead of adjecency matrix.  
To figure out minVertex use priority queue.but as the distance changes the priority queue will also heapify  
**O(v + e)logv = O(n + e)logn**