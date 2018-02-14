#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Vertex
{
private:
	//char value;
	//char parent;
public:
	vector<Vertex*> neighbours;
	int level = 0;
	char value;
	Vertex* parent = NULL;
	bool visited = 0;

	void add_neighbour(Vertex* v)
	{
		neighbours.push_back(v);
	}

	Vertex(char val)
	{
		value = val; 
	}

	bool operator==(const Vertex& rhs) const 
	{
    return value == rhs.value;
    } 

	
};

std::stack<Vertex*> call_stack;

void dfs_visit(Vertex *v)
{

  for(auto i = v->neighbours.begin(); i != v->neighbours.end();i++)
  {
    Vertex* k = *i;
    if(k->parent == NULL)
    {
      //cout<<"calling dfs_visit "<<k->value<<endl;
      k->parent = v;
      k->visited = 1;
      dfs_visit(k);
    }
  }
   call_stack.push(v);
   //cout<<"dfs visit of "<<v->value<<" finished\n";

}

void dfs(Vertex *graph, int size)
{

  for(int i = 0;i<size; i++)
  {
  	//cout<<"source vertex "<<(graph+i)->value<<endl;
    if(!(graph+i)->visited)
    dfs_visit(graph + i);
  }
}

int main()
{
	Vertex vertex[] = { 'a', 'b', 'c', 'd', 'e', 'f'};
vertex[0].add_neighbour(&vertex[1]); 
	vertex[1].add_neighbour(&vertex[2]);
	vertex[2].add_neighbour(&vertex[5]);
	vertex[3].add_neighbour(&vertex[2]);vertex[3].add_neighbour(&vertex[4]);
	vertex[4].add_neighbour(&vertex[5]);
	dfs(vertex, 6);
	cout<<"Topological order is ";
	while(!call_stack.empty())
	{
	    cout<<call_stack.top()->value<<", ";
	    call_stack.pop();
	}
	
	

}
