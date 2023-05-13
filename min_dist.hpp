#ifndef MIN_DIST_HPP
#define MIN_DIST_HPP

#include <functional> // std::greater
#include <limits> // std::max
#include <utility> // std::pair
#include <queue>

#include "graph.hpp"

class MinDist
{
public: 
    MinDist(const Graph& graph, const Vertex& src, const Vertex& dest) : 
            graph(graph), src(src), dest(dest){}
    Distance determine_distance();

private: 
    void dijkstra();
    
private:
    Graph graph;
    Vertex src;
    Vertex dest;
    Distances distances;
    std::priority_queue<std::pair<Distance, Vertex>, std::vector<std::pair<Distance, Vertex>>, std::greater<std::pair<Distance,Vertex>>> pq;

};

#endif // MIN_DIST_HPP