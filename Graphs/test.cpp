#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Vertex
{
private:
	
	//char parent;
public:
	vector<Vertex> neighbours;
	int level;
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
	
};

int main()
{
	Vertex vertex[] = {'a', 'b', 'c'};
	vertex[0].add_neighbour(vertex[1]);
	vertex[0].add_neighbour(vertex[2]);
	std::vector<Vertex> v = {vertex[0],vertex[1]};
	std::vector<Vertex> frontier = {vertex[0]};
	vector<Vertex>::iterator i;
		for(i = frontier.begin();i < frontier.end();i++)
		{
			printf("%c", i->value);
			if( find(v.begin(),v.end(),*i) != v.end() )
			{
				printf("found");
			}
		}
		
}