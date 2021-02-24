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
	bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &inStack){
		//Whenever to come to a node, mark it visited,add in stack
		visited[node] = true;
		inStack[node]=true;
		

		
		for(T neighbour: adjList[node]){
			if(!visited[neighbour] && isCyclicHelper(neighbour,visited,inStack) || inStack[neighbour] ){
				return true;
			}
		}
		inStack[node]=false;
		return false;
	}

	bool isCyclic(){
		map<T,bool> visited;
		map<T,bool> inStack;
		
		//To check for cycle in each dfs tree
		
		for(auto i:adjList){
		    T node=i.first;
		    if(!visited[node]){
		        bool cyclePresent=isCyclicHelper(node,visited,inStack);
		        if(cyclePresent){
		            return true;
		        }
		    }
		}
		return false;
	
	}
};

int main(){

	Graph<int> g;
	g.addEdge(0,2,false);
	g.addEdge(0,1,false);
	g.addEdge(2,3,false);
	g.addEdge(2,4,false);
// 	g.addEdge(3,0,false);
	g.addEdge(4,5,false);
	g.addEdge(1,5);
	

	if(g.isCyclic()){
		cout<<"Cycle Present !";
	}
	else{
		cout<<"Cycle Not found!";
	}



return 0;
}
