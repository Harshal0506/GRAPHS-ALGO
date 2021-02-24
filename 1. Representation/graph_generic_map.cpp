#include <iostream>
#include <map>
#include <list>
using namespace std;

template<class T>
class Graph{
    map<T,list<T>> adjList;
public:
    Graph(){
        
    }
    
    void addEdge(T u,T v,bool bidir=true){
        
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
};





int main() {
	// your code goes here
	Graph<string> g;
	g.addEdge("Putin","Trump",false);
	g.addEdge("Putin","Modi",false);
	g.addEdge("Putin","Pope");
	g.addEdge("Modi","Trump",true);
	g.addEdge("Yogi","Prabhu",false);
	g.addEdge("Modi","Yogi",true);
	g.addEdge("Prabhu","Modi",false);
	
	g.print();
	
	
	Graph<int>g2;
	g2.addEdge(1,2);
	g2.addEdge(100,2);
// 	g2.addEdge(100,3,false);
// 	g2.addEdge(3,100,false);
	
	g2.addEdge(100,3);
	g2.print();
	return 0;
}
