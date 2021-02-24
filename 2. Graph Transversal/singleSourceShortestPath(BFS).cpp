#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <limits.h>
using namespace std;

template<class T>
class Graph{
    map<T,list<T>> adjList;
public:
    Graph(){
        
    }
    
    void addEdge(T u,T v ,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    
    void print(){
        //Iterate over the map
        for(auto i:adjList){
            cout<<i.first<<"->";
            
            //i.second is LL
            
            for(T entry:i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }
    }
    
    void bfs(T src){
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;
        for(auto i:adjList){
            dist[i.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;;
        parent[src]=src;
        while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();
            
            //for the neighbours of the current node ,find out the nodes which is unvisited
            
            for(T neighbour:adjList[node]){
                if(dist[neighbour]==INT_MAX){
                    q.push(neighbour);
                    dist[neighbour]=dist[node]+1;
                    parent[neighbour]=node;
                }
            }
            
        }
        
        for(auto i:adjList){
            T node=i.first;
            cout<<"Dist of "<<node<<" from "<<src <<" is "<<dist[node]<<endl;
        }
        
        cout<<"Path Parent"<<endl;
        
        // for(auto i:parent){
        //     cout<<"Parent of "<<i.first<<" is "<<i.second<<endl;
        // }
    }
};

int main() {
	// your code goes here
	Graph <int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	
	g.bfs(0);
	return 0;
}
