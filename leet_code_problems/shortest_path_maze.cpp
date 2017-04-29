/*
 * Given a matrix with cell values 0 or 1. Find the length of the shortest path from (a1, b1)
 * to (a2, b2), such that:
 * Path can only be constructed through cells which have value 1.
 * You can only travel in 4 possible directions, i.e. left, right, up and down.
 *
 * For example: Given matrix:
 * Input:
 * mat[ROW][COL]  = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
 *                   {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
 *                   {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
 *                   {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
 *                   {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
 *                   {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
 *                   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
 *                   {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
 *                   {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
 * Source = {0, 0};
 * Destination = {3, 4};
 * Output:
 * Shortest Path is 11
 *
 * We will use breadth first search, we start from source cell (and distance 0)
 * and explore neighbors in all possible directions, and keep adding
 * distance from source node for each cell, so for a cell we reach, 
 * its shortest path = shortest path of parent + 1. We stop when we have reached
 * destination. If we have explored all possible valid cells from source cell,
 * we return false, i.e. we do not have valid path from source.
 */


#include <iostream>
#include <queue>
#include <limits>

struct Point
{
    int x;
    int y;
};

struct Node
{
    Point point;
    int distance;
};

bool valid(const std::vector<std::vector<int>>& matrix, int x, int y)
{
    return (x >= 0 && x < matrix[0].size() && y >= 0 && y < matrix.size());
}

int shortestPath(const std::vector<std::vector<int>>& matrix,
    const Point& source,
    const Point& destination)
{
    // An auxillary matrix to keep track of visited points
    // initially all cells are marked unvisited.
    //
    std::vector<std::vector<bool>> visited(
       matrix.size(),
       std::vector<bool>(matrix[0].size(), false));

    // Possible moves from a cell.
    //
    std::vector<int> row = {-1, 0, 0, 1};
    std::vector<int> col = {0, -1, 1, 0};
    
    std::queue<Node> nodeQueue;

    // mark the source cell visited and push it to queue.
    //
    visited[source.x][source.y] = true;
    nodeQueue.push({source.x, source.y, 0});

    while (!nodeQueue.empty())
    {
        // pop the front of the queue.
        Node current = nodeQueue.front();
        nodeQueue.pop();

        Point point = current.point;

        // if we have reached destination return distance.
        if (point.x == destination.x && point.y == destination.y)
        {
            return current.distance;
        }

        for (int i = 0; i < 4; ++i)
        {
            int r = point.x + row[i];
            int c = point.y + col[i];

            if (valid(matrix, r, c) &&
                matrix[r][c] && !visited[r][c])
            {
                visited[r][c] = true;
                Node adjNode = {r, c, current.distance + 1};
                nodeQueue.push(adjNode);
            }
        }
    }
    return std::numeric_limits<int>::max();
}

int main()
{
    const std::vector<std::vector<int>> matrix = 
        {{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
         { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
         { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
         { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
         { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
         { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
         { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
         { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
         { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    
    Point source = {0, 0};
    Point destination = {3, 4};
    int distance = shortestPath(matrix, source, destination);
    if (distance != 
        std::numeric_limits<int>::max())
    {
        std::cout << "The distance between ("
            << source.x << ", " << source.y
            << ") and destination (" << destination.x
            << ", " << destination.y << ") is "
            << distance << std::endl;
    }
    else
    {
        std::cout << "The path does not exist between ("
            << source.x << ", " << source.y
            << ") and destination (" << destination.x
            << ", " << destination.y << ") is "
            << distance << std::endl;
    }
    return 0;
}
