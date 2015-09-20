#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
namespace algo {

  template <class dataType>                                 // Type of data vertex will hold
  class Graph {
    int numOfVertices;                                      // number of vertices.
    struct Vertex;                                          // forward declaration of vertex structure
    struct Node {                                           // linkedlist for mapping edges in the graph
      Vertex * vertexPtr;                                   // points to the vertex to which the edge is adjecent
      Node * next;                                          // points to the next edge belonging to same vertex
    };

    enum visitedState{                                      // Enum representing visited state of vertex
      WHITE,                                                // not yet visited
      GRAY,                                                 // being visited
      BLACK                                                 // visited
    };
    struct Vertex {
      visitedState state;                                   // state of vertex, visited/being visited/done
      dataType data;                                        // the template data
      Node * list;                                          // Pointer to all edges (linkedlist)
    };

    std::vector<Vertex> vertices;                           // vector of all vertices.

    Node * getNode(Vertex * v)                              // allocate and initialize a newnode for the adj list.
    {
      Node * newNode = new Node;
      newNode->vertexPtr = v;
      newNode->next = nullptr;
      return newNode;
    }

    void insertAtEnd( Node * & node, Vertex * v)            //insert at the end of adjacency list of vertex.
    {
      Node *newNode = getNode(v);
      if ( node == nullptr ) {
        node = newNode;
      } else {
        Node * temp = node;
        while( temp->next != nullptr ) {
          temp = temp->next;
        }
        temp->next = newNode;
      }
    }

    void deleteAllAfter( Node * node )                     // delete the adjacency list of the vertex.
    {
      Node * nextNode;
      while( node != nullptr ) {
        nextNode = node->next;
        delete(node);
        node = nextNode;
      }
    }

    void depth_first_traversal_util(Vertex * v) {
      v->state = GRAY;
      std::cout << v->data << " ";
      Node * node = v->list;
      while( node != nullptr ) {
        if (node->vertexPtr->state == WHITE) {
          depth_first_traversal_util(node->vertexPtr);
        }
        node = node->next;
      }
      v->state = BLACK;
    }

    public:
    Graph() = default;
    Graph(std::vector<dataType> & values)
      : numOfVertices(values.size()),
        vertices(numOfVertices)
    {
      for ( int i = 0; i < numOfVertices; ++i ) {
        vertices[i].data = values[i];
        vertices[i].list = nullptr;
        vertices[i].state = WHITE;
      }
    }

    void setEdge(dataType data1, dataType data2)
    {
      for (int i = 0; i < numOfVertices; ++i) {
        if (vertices[i].data == data1) {
          for ( int j = 0; j < numOfVertices; ++j) {
            if (vertices[j].data == data2) {
              insertAtEnd(vertices[i].list, &vertices[j]);
              break;
            }
          }
          break;
        }
      }
    }

    void display()
    {
      Node * node;
      for ( int i = 0; i < numOfVertices; ++i ) {
        std::cout << "Vertex:" << vertices[i].data << " ";
        std::cout << "Connections: ";
        node = vertices[i].list;
        while( node != nullptr ) {
          std::cout << node->vertexPtr->data << " ";
          node = node->next;
        }
        std::cout << std::endl;
      }
    }

    void depth_first_search(dataType startElem)
    {
      for( int i = 0; i < numOfVertices; ++i ) {
        vertices[i].state = WHITE;
      }
      for ( int i = 0; i < numOfVertices; ++i) {
        if (vertices[i].data == startElem) {
          depth_first_traversal_util(&vertices[i]);
          break;
        }
      }
      std::cout << std::endl;
    }

    ~Graph()
    {
      for( int i = 0; i < numOfVertices; ++i ) {
        deleteAllAfter(vertices[i].list);
      }
    }

  }; //end of class graph
} //end of namespace algo


#endif
