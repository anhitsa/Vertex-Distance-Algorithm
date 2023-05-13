#include <limits>  //max

#include "graph.hpp"
#include "min_dist.hpp"

Vertex input_vertex(const std::string& msg)
{
    std::cout << msg;
    Vertex vertex;
    std::cin >> vertex;
    return vertex;
}

void print_result(const Vertex& src, const Vertex& dest, const Distance& distance) {
    std::cout << "\nDistance between vertex " << src
        << " and vertex " << dest << " is " << distance << "." << std::endl << std::endl;
}

int main() {
    Graph graph;
    graph.input_graph();
    graph.print_graph();

    auto src = input_vertex("Input source: ");
    auto dest = input_vertex("Input destination: ");

    MinDist min_distance(graph, src, dest);
    auto distance = min_distance.determine_distance();

    print_result(src, dest, distance);
}