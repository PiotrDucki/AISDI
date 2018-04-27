#ifndef AISDI_GRAPH_H
#define AISDI_GRAPH_H

#include <iostream>
#include <list>
#include <vector>


class Graph
{
public:
  using edge = std::pair<int,int>;
  #define visited  true
  #define notVisited false

private:
  unsigned int verticesCount;
  std::list <edge> edgeList;


  void removeEdgeAndItsVertices(edge edgeToErase)
  {
    for(auto it = edgeList.begin(); it != edgeList.end(); it++)
    {
      if(it->first == edgeToErase.first || it->first == edgeToErase.second ||
      it->second == edgeToErase.first || it->second == edgeToErase.second)
        edgeList.erase(it);
    }
  }

  bool checkIfGraphIsConected(edge eresedEdge)
  {
    bool *table = new bool[verticesCount];
    int firstElement = edgeList.begin()->first;

    for(int i = 0; i < verticesCount; i++)
      table[i] = notVisited;

    visitAllConectedNodes(firstElement, table);
    table[eresedEdge.first] = visited;
    table[eresedEdge.second] = visited;

    for(int i = 0; i < verticesCount; i++)
      if(table[i] == notVisited)
        return false;
    delete []table;
    return true;
  }

  void visitAllConectedNodes(int current, bool *table)
  {
    std:: vector <int> adjacencies;
    table[current] = visited;
    for(auto it = edgeList.begin(); it != edgeList.end(); it++)
    {
      if(it->first == current && table[it->second]== notVisited)
        adjacencies.push_back(it->second);
      if(it->second == current && table[it->first]== notVisited)
        adjacencies.push_back(it->first);
    }
    for(auto it = adjacencies.begin(); it != adjacencies.end(); it++)
    {
      visitAllConectedNodes(*it, table);
    }
  }

public:
  Graph()
  {
    verticesCount = 0;
  }

  Graph(int vCount, std::list <edge> eList)
  {
    verticesCount = vCount;
    edgeList = eList;
  }

  Graph& operator=(const Graph& other)
  {
    verticesCount = other.verticesCount;
    edgeList = other.edgeList;

    return *this;
  }

  void printEdges()
  {
      printf("********************** \n    GRAF   \n");
      for(auto it = edgeList.begin(); it != edgeList.end(); it++)
        printf(" %d %d \n", it->first, it->second);
  }

  void printExtensiveBridges()
  {
    std::list <edge> extensiveBridgesList;
    Graph temp;

    for(auto it = edgeList.begin(); it != edgeList.end(); it++)
    {
      temp = *this;
      temp.removeEdgeAndItsVertices(*it);
      if(temp.checkIfGraphIsConected(*it)==false)
        extensiveBridgesList.push_back(*it);
    }

    printf("bridges count %lu\n",  extensiveBridgesList.size()  );
    for(auto it = extensiveBridgesList.begin(); it != extensiveBridgesList.end(); it++)
      printf("%d %d\n",it->first, it->second );
   }
};

#endif /* AISDI_MAPS_HASHMAP_H */
