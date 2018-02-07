#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
#include <iostream>
#include <queue>

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

void dfs_visit(Vertex *v)
{
  cout<<"hi";
  for(auto i = v->neighbours.begin(); i != v->neighbours.end();i++)
  {
    Vertex* k = *i;
    if(k->parent != NULL)
    {
      k->parent = v;
      dfs_visit(k);
    }
  }
}

void dfs(Vertex *graph, int size)
{

  for(int i = 0;i<size; i++)
  {
    dfs_visit(&graph[i]);
  }
}
int main()
{
	Vertex vertex[] = { 'a', 'b', 'c', 'd', 'e', 'f'};
	vertex[0].add_neighbour(&vertex[1]); 	vertex[0].add_neighbour(&vertex[3]);
	vertex[1].add_neighbour(&vertex[4]);
	vertex[2].add_neighbour(&vertex[5]);vertex[2].add_neighbour(&vertex[4]);
	vertex[3].add_neighbour(&vertex[1]);
	vertex[4].add_neighbour(&vertex[3]);
	dfs(vertex, 6);
	
	cout<<vertex[1].parent->value<<"hi";
;
}
