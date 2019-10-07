
//This questions uses the algorithm - topological Ordering

/* Problem ->

 * you are given a list of projects and list of dependencies (uses graph here)
 * In which the first is dependent on second (if we have (1,3) = 1, then  3 is dependent of 1) 
 * All of a project's dependencies must be built before the project is.
 * Find a build order that will allow the projects to be built. 
 * If their is no valid built order return error.
 
 
 * Approach ->
 
 *Build a graph and compute indegree of each node.
 *here the indegree of particular node indicate that, on how many nodes that particular node is dependent
 *choose the node with zero indegree and update the graph by removing it's dependencies by setting indegree[i] = -1

*/

#include <bits/stdc++.h>
using namespace std;

#define error -1000

//choose node with zero incoming edge

int choose_zero(int p, int indegree[])
{
    for(int i = 0; i<p; i++)
    {
        if(indegree[i] == 0)
        {
            return i;
            
        }
    }
    
     return error;
     
}

int main() {
  
  int p = 6;	
  int projects[p] = {0,1,2,3,4,5};
  int indegree[p];
  int zero_in;
  
 int Graph[p][p] = {
     {0,0,0,1,0,0},   //If their is an directed edge from i to j -> Graph[i][j] = 1
     {0,0,0,1,0,0},
     {0,0,0,0,0,0},
     {0,0,1,0,0,0},
     {0,0,0,0,0,0},
     {1,0,0,0,0,0}
 };
 
 //compute number of incoming edges to particular node
 
 for(int i = 0; i<p; i++)
 {
     indegree[i] =  0;
     
     for(int j = 0; j<p; j++)
     {
         indegree[i] = indegree[i] + Graph[j][i];
         
     }
 }

 
 for(int i = 0; i<p; i++)
 {
    zero_in = choose_zero(p, indegree);
    
    if(zero_in != error)
     {
        cout<<zero_in<<endl;   // printing the node in order which follow the conditions
        
        indegree[zero_in] = -1;
        
        //update the Graph
        
        for(int k = 0; k<p; k++)
        {
            if(Graph[zero_in][k] == 1)
            {
                indegree[k] = indegree[k] - 1;
                
            }
        }
    }
    
    else
    cout<<"order not possible"<<endl;
 }
 	return 0;
}
