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

	/*void add_neighbour(char node)
	{
		neighbours.push_back(&Vertex(node));
	}*/

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

void bfs(Vertex v)
{
	map <char, int> level;
	level[v.value] = 0;
	vector<Vertex> visited;
	visited.push_back(v);
	int l = 1;
	queue<Vertex> frontier;
	frontier.push(v);
	while(!frontier.empty())
	{
		
		queue<Vertex> next;
		while(!frontier.empty())
		{
			Vertex i = frontier.front();
			frontier.pop();
			vector<Vertex*>::iterator node;
			for(node = i.neighbours.begin(); node != i.neighbours.end();node++)
			{
				Vertex* k = *node;
				if( !(find(visited.begin(),visited.end(),**node) != visited.end()) )
				{
					level[k->value] = l;
					next.push(**node);
					visited.push_back(**node);
				}
				
			}

		}
		frontier = next;
		l++;
	}
	
	for(map<char, int> :: iterator i = level.begin(); i != level.end(); i++)
	{
		cout<<i->first<<" "<<i->second<<endl;
	}

}
int main()
{
	Vertex vertex[] = {'z', 'a', 's', 'x', 'd', 'f', 'v', 'c'};
	vertex[0].add_neighbour(&vertex[1]);
	vertex[1].add_neighbour(&vertex[2]);vertex[1].add_neighbour(&vertex[0]);
	vertex[2].add_neighbour(&vertex[1]);vertex[2].add_neighbour(&vertex[3]);
	vertex[3].add_neighbour(&vertex[2]);vertex[3].add_neighbour(&vertex[4]);vertex[3].add_neighbour(&vertex[7]);
	vertex[4].add_neighbour(&vertex[3]);vertex[4].add_neighbour(&vertex[5]);vertex[4].add_neighbour(&vertex[7]);
	vertex[5].add_neighbour(&vertex[4]);vertex[5].add_neighbour(&vertex[6]);vertex[5].add_neighbour(&vertex[7]);
	vertex[6].add_neighbour(&vertex[5]);vertex[6].add_neighbour(&vertex[7]);
	vertex[7].add_neighbour(&vertex[3]);vertex[7].add_neighbour(&vertex[4]);vertex[7].add_neighbour(&vertex[5]);vertex[7].add_neighbour(&vertex[6]);
	bfs(vertex[2]);
	//printf("%d %d %d",vertex[0].neighbours[0].level, vertex[0].neighbours[1].level, vertex[0].neighbours[2].level);
}