#include <iostream>
#include <graph.h>

int main()
{
  std::vector<int> vec{ 0, 1, 2, 3, 4, 5, 6, 7 };
  algo::Graph<int> g(vec);
  g.setEdge(0, 1);
  g.setEdge(0, 2);
  g.setEdge(0, 3);
  g.setEdge(0, 4);
  g.setEdge(1, 5);
  g.setEdge(2, 6);
  g.setEdge(3, 1);
  g.setEdge(3, 5);
  g.setEdge(3, 7);
  g.setEdge(4, 2);
  g.setEdge(5, 3);
  g.setEdge(5, 6);
  g.setEdge(6, 2);
  g.setEdge(6, 4);
  g.setEdge(6, 5);
  g.display();
  g.depth_first_search(0);
  return 0;
}
