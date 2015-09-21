#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <queue>

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

    //private methods
    Node * getNode( Vertex * );                             // allocate and initialize a newnode for the adj list.
    void insertAtEnd( Node * & , Vertex * );                // insert at the end of adjacency list of vertex.
    void deleteAllAfter( Node * );                          // delete the adjacency list of the vertex.
    void depth_first_traversal_util(Vertex * );             // Private utility function for DFS

  public:
    Graph() = default;                                      // Default constructor
    Graph(std::vector<dataType> &);                         // Constructor which takes vector of vertex data
    void setEdge(dataType, dataType);                       // For setting a edge of graph
    void display() const;                                   // Print current config of the graph.
    void breadth_first_search(dataType);                    // Breadth first traversal of the graph
    void depth_first_search(dataType);                      // Depth first traversal of the graph
    ~Graph();
  }; //end of class Graph


  template <typename dataType>
  typename Graph<dataType>::Node *
  algo::Graph<dataType>::getNode(Vertex * v)                // allocate and initialize a newnode for the adj list.
  {
    Node * newNode = new Node;
    newNode->vertexPtr = v;
    newNode->next = nullptr;
    return newNode;
  }

  template <typename dataType>
  void Graph<dataType>::insertAtEnd( Node * & node, Vertex * v)  // insert at the end of adjacency list of vertex.
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

  template <typename dataType>
  void Graph<dataType>::deleteAllAfter( Node * node )                  // delete the adjacency list of the vertex.
  {
    Node * nextNode;
    while( node != nullptr ) {
      nextNode = node->next;
      delete(node);
      node = nextNode;
    }
  }


  template <typename dataType>
  Graph<dataType>::Graph(std::vector<dataType> & values)              // Non default constructor, takes a vector of vertices data
    : numOfVertices(values.size()),
      vertices(numOfVertices)
  {
    for ( int i = 0; i < numOfVertices; ++i ) {
      vertices[i].data = values[i];
      vertices[i].list = nullptr;
      vertices[i].state = WHITE;
    }
  }

  template <typename dataType>
  void Graph<dataType>::setEdge(dataType data1, dataType data2)       // Setting individual edge of the graph.
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

  template <typename dataType>
  void Graph<dataType>::display() const                               // Prints the current config of the graph
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

  template <typename dataType>
  void Graph<dataType>::breadth_first_search(dataType startElem)      // Breadth first traversal of the graph
  {
    //mark all vertices as not visited, i.e. state = WHITE
    for ( int i = 0; i < numOfVertices; ++i ) {
      vertices[i].state = WHITE;
    }

    // search for the vertex containing start element
    Vertex * startVertex = nullptr;
    for ( int i = 0; i < numOfVertices; ++i ) {
      if ( vertices[i].data == startElem ) {
        startVertex = &vertices[i];
        break;
      }
    }

    //Return if start vertex not found
    if ( startVertex == nullptr ) {
      return;
    }

    //Create a queue for traversing breadth wise.
    std::queue<Vertex *> vertexQueue;

    //mark the first vertex as being processed
    startVertex->state = GRAY;
    //push the first vertex
    vertexQueue.push(startVertex);
    Vertex * currVertex = nullptr;

    while( !vertexQueue.empty() ) {
      currVertex = vertexQueue.front();
      vertexQueue.pop();
      currVertex->state = BLACK;
      std::cout << currVertex->data << " ";
      Node * adjVertex = currVertex->list;
      while( adjVertex != nullptr ) {
        if ( adjVertex->vertexPtr->state == WHITE ) {
          adjVertex->vertexPtr->state = GRAY;
          vertexQueue.push(adjVertex->vertexPtr);
        }
        adjVertex = adjVertex->next;
      }
    }
    std::cout << std::endl;
  }

  template <typename dataType>
  void Graph<dataType>::depth_first_traversal_util(Vertex * v)            // Depth first search private utility function
  {
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

  template <typename dataType>
  void Graph<dataType>::depth_first_search(dataType startElem)          // Public function for depth first traversal
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


  template <typename dataType>
  Graph<dataType>::~Graph()
  {
    for( int i = 0; i < numOfVertices; ++i ) {
      deleteAllAfter(vertices[i].list);
    }
  }
} //end of namespace algo


#endif
