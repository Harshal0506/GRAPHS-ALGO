#include<iostream>
#include<map>
#include<list>
using namespace std;


template<typename T>
class Graph{

	map<T,list<T> > adjList;

public:
	Graph(){

	}
	void addEdge(T u, T v,bool bidir=true){

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
	void dfsHelper(T node,map<T,bool> &visited,list <T> &ordering){
		//Whenever to come to a node, mark it visited
		visited[node] = true;
		

		//Try to find out a node which is neigbour of current node and not yet visited
		for(T neighbour: adjList[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited,ordering);
			}
		}
		
		ordering.push_front(node);
		
	}

	void dfsTopologicalSort(){
		map<T,bool> visited;
		list<T> ordering;
		for(auto i:adjList){
		    // i is pair (node,list of nodes)
		    T node=i.first;
		    if(!visited[node]){
		        dfsHelper(node,visited,ordering);
		    }
		    
		    
		}
		//print all the elements in ordering
		for(T element : ordering){
		    cout<<element<<"-->";
		}
	}
};

int main(){

	Graph<string> g;
	g.addEdge("English","Programming Logic",false);
	g.addEdge("Maths","Programming Logic",false);
	g.addEdge("Programming Logic","HTML",false);
	g.addEdge("Programming Logic","Python",false);
	g.addEdge("Programming Logic","Java",false);
	g.addEdge("Programming Logic","JS",false);
	g.addEdge("Python","Web Dev",false);
	g.addEdge("HTML","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("JS","Web Dev",false);
	g.addEdge("Java","Web Dev",false);
	g.addEdge("Python","Web Dev",false);
	
	
	g.dfsTopologicalSort();


return 0;
}