#include <iostream> 
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

long long getBFSMaxIndex(vector< long long>graph[] , int start , long long int vertices , long long int &index)
{
    queue<long long>bfs_queue;
    int counter[vertices+1];
    memset(counter , -1 , sizeof(counter));

    bfs_queue.push(start);
    counter[start] = 0;
    while(!bfs_queue.empty())
    {
        long long int temp = bfs_queue.front();
        bfs_queue.pop();
        for(int i=0 ; i < graph[temp].size() ; ++i)
        {
            long long int adjacent = graph[temp][i];
            if(counter[adjacent] == -1)
            {
                bfs_queue.push(adjacent);
                counter[adjacent] = counter[temp] + 1;
            }
        }
    }

    long long int maxDistance = 0;
    for(int i=1 ; i <= vertices ; ++i)
    {
        if(counter[i] > maxDistance)
        {
             maxDistance = counter[i];
             index = i;
        }
    }
    return maxDistance;

}

int getLongestPath(vector<long long>graph[] , int start , long long int vertices)
{

    long long int index=-1 , maxValue;
    maxValue = getBFSMaxIndex(graph , start , vertices , index); 
    start = index;   index = -1;
    maxValue = getBFSMaxIndex(graph , start  , vertices , index);

    return maxValue;
}

int main() 
{
    /*
        PROBLEM SOLVED USING 2 BFS METHOD.
    */
    long long int vertices;
    cin >> vertices;
    long long int edges = vertices - 1;
    long long int vertice1 , vertice2;
    vector<long long>graph[vertices+1];
    for(int _=0 ; _<edges ; _++)
    {
        cin >> vertice1 >> vertice2;
        graph[vertice1].push_back(vertice2);
        graph[vertice2].push_back(vertice1);

    }
    long long int distance = getLongestPath(graph , 1 , vertices);
    cout << distance << endl;
    return 0;
}