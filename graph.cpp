#include "graph.hpp"

void Graph::input_graph()
{
    std::ifstream file(graph_file_name); 
    std::string line;
    auto count = 0;
    while (std::getline(file, line)) 
    {
        vertex_count++;
        adj_matrix.resize(count + 1);
        for(auto i = 0; i < line.size(); i++)
        {
            if(isdigit(line[i]))
            {
                std::string num_str(1, line[i]); 
                Vertex vertex = std::stoi(num_str);
                std::string second_num_str(1, line[i + 2]);
                Distance distance = std::stoi(second_num_str);

                adj_matrix[count].push_back(std::make_pair(vertex, distance));
                i += 5;
            }
        }
        count++;
    }   
}

void Graph::print_graph()
{
    std::ifstream file(graph_file_name); 
    std::string line;
    std::cout << std::endl << "Graph: " << std::endl;
    while (std::getline(file, line)) 
    {
        std::cout << line << std::endl;
    }
    std::cout << std::endl << std::endl;
}