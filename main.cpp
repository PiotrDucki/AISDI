#include <iostream>
#include <list>
#include <utility>
#include "Graph.h"



using edge = std::pair<int,int>;
using edgesList = std::list<edge>;


Graph readGraph()
{
  int verticesCount;
  int u, w;

  std::cin>>verticesCount;
  edgesList edgesListFromInput;
  while(std::cin>>u>>w)
    edgesListFromInput.push_back(std::make_pair(u, w));

  Graph graph(verticesCount,edgesListFromInput);
  return graph;
}

int main()
{

  Graph g = readGraph();
  g.printExtensiveBridges();

  return 0;
}
