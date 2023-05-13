#include "min_dist.hpp"

Distance MinDist::determine_distance()
{
    distances.resize(graph.vertex_count);
    std::fill_n(distances.begin(), distances.size(), std::numeric_limits<int>::max());
    distances[src] = 0;
    pq.push({0,src});
    dijkstra();
    return distances[dest];
}

void MinDist::dijkstra()
{
    while(!pq.empty())
    {
        auto dis = pq.top().first;
        auto node = pq.top().second;
        pq.pop();

        for(auto pair : graph.adj_matrix[node])
        {
            auto adjVertex = pair.first;
            auto edgeWeight = pair.second;

            if(dis + edgeWeight < distances[adjVertex])
            {
                distances[adjVertex] = dis + edgeWeight;
                pq.push({distances[adjVertex], adjVertex});
            }
        }
    }
}