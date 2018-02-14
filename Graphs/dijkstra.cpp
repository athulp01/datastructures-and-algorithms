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
public:
    typedef struct Edge
    {
        Vertex* vertex;
        int weight;
    };
	vector<Edge> neighbours;
	char value;
	void add_neighbour(Vertex* v)   {neighbours.push_back(v);}
	bool operator==(const Vertex& rhs) const    {return value == rhs.value;}
	
    void addNeighbour(Vertex* v, int weight)
    {
        struct Edge e = {v, weight
        neighbours.push_back(e)
    }
};
