#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Vertex
{
private:
	//char value;
	//char parent;
public:
	vector<Vertex> neighbours;
	int level = 0;
	char value;

	void add_neighbour(char node)
	{
		neighbours.push_back(Vertex(node));
	}

	void add_neighbour(Vertex v)
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
	vector<Vertex> visited ;
	visited.clear();
	int l = 1;
	std::vector<Vertex> frontier = {v};
	while(!frontier.empty())
	{
		vector<Vertex> next;
		vector<Vertex>::iterator i;
		for(i = frontier.begin();i < frontier.end();i++)
		{
			//printf("enter frontie\n");
			vector<Vertex>::iterator node;
			for(node = i->neighbours.begin(); node < i->neighbours.end();node++)
			{
				//printf("enter neighbours\n");
				if( !(find(visited.begin(),visited.end(),*node) != visited.end()) )
				{
					//printf("enter if\n");
					node->level = l;
					printf("%c %d\n",frontier[0].neighbours[0].value, frontier[0].neighbours[0].level);
					next.push_back(*node);
				}
				
			}
		}
		frontier = next;
		l++;
		//printf("%d ",l);

	}
	

}
int main()
{
	Vertex vertex[] = {'a', 'b', 'c'};
	vertex[0].add_neighbour('b');
	vertex[0].add_neighbour('c');
	bfs(vertex[0]);
	//printf("%d %d %d",vertex[0].neighbours[0].level, vertex[0].neighbours[1].level, vertex[0].neighbours[2].level);
}