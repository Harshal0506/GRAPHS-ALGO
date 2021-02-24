#include <iostream>
#include <map>
#include <list>
#include <queue>
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
    
    void dfsHelper(T node ,map<T,bool> &visited){
        //Whenever to come to a node mark it visited
        
        visited[node]=true;
        cout<<node<<" ";
        
        for(T neighbour:adjList[node]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }
    
    
    void dfs(T src){
        map<T,bool> visited;
        int component=1;
        dfsHelper(src,visited);
        cout<<endl;
        for(auto i:adjList){
            T first=i.first;
            
            if(!visited[first]){
                dfsHelper(first,visited);
                component++;
            }
        }
        
        cout<<"The current graph had "<<component<<" component/s";
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
	
	
	
	g.addEdge(6,7);
	g.addEdge(7,8);
	g.addEdge(6,8);
	
	g.addEdge(9,10);
	g.dfs(0);
	return 0;
}
