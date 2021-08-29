#include <iostream>
#include <climits>
using namespace std;

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

int main() {
    // Write your code here
    int n , e;
    cin >> n >> e;
    
    // making the matrix and removing garbage
    int **edges = new int *[n];
    for(int i =0 ; i < n ; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    //taking input
    for (int i = 0; i < e; i++)
    {
        int f, s, w; // f -first vertex , s- second vertex
        cin >> f >> s >> w;
        edges[f][s] = w; // denoting we have a edge
        edges[s][f] = w; // (0,1) and (1,0) dono edges honge
    }

// cout << endl;
dijkstra(edges , n);

for(int i =0 ;i < n ; i++){
    delete [] edges[i];
}
delete [] edges;
    
}





