#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cctype>  // std::isdigit
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>  //std::istringstream
#include <vector>

using Distance = int;
using Distances = std::vector<Distance>;
using Vertex = int;
using Graph_type = std::vector<std::vector<std::pair<Vertex, Distance>>>;

class Graph
{
    public:
        Graph() = default;
        void input_graph();
        void print_graph();
        int vertex_count = 0;
        Graph_type adj_matrix;

    private:
        const std::string graph_file_name = "graph.txt";
        
};

#endif // GRAPH_HPP