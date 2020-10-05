package Kruskal;
import java.util.*;
class edge implements Comparable<edge>
{
int u,v,w;
edge(int u1, int v1, int w1)
{
u=u1;
v=v1;
w=w1;
}
@Override
public int compareTo(edge o)
{
// TODO Auto-generated method stub
return this.w - o.w;
}
}
public class Kruskal
{
Scanner sc=new Scanner(System.in);
int n,e;
int graph[][];
edge[] e1;
int mst[][];
int parent[];
void create()
{
int i,u,v,w;
System.out.println("Enter number of vertices ");
n=sc.nextInt();
graph=new int[n+1][n+1];
parent=new int[n+1];
System.out.println("Enter number of edges ");
e=sc.nextInt();
e1=new edge[e];
for(i=0;i<e;i++)
{
System.out.println("FOR EDGE "+(i+1)+" : ");
System.out.println("Enter starting vertice");
u=sc.nextInt();
System.out.println("Enter ending vertice");
v=sc.nextInt();
System.out.println("Enter weight of edge");
w=sc.nextInt();
graph[u][v]=w; //for un-directed graph
e1[i]=new edge(u,v,w);
}
}
void display()
{
System.out.println("Graph is : ");
int i,j;
for (i= 0; i<graph.length;i++)
{
for (j=0;j<graph.length;j++)
{
if (graph[i][j]!=0)
{
System.out.println(+i
+ "----> " + j + " = " + graph[i][j]);
}
}
}
}
void mst()
{
int i;
mst = new int[graph.length][graph.length];
Arrays.sort(e1);
int[] parent = new int[n + 1];
int[] size = new int[n+ 1];
for (i=0;i<graph.length;i++)
{
parent[i] =i;
size[i] = 1;
}
int visit = 0;
int c = 1;
while (c <= n - 1)
{
edge e = e1[visit];
visit++;
if (isCyclic(e.u, e.v, parent))
continue;
union(findParent(e.u, parent),
findParent(e.v, parent), parent, size);
mst[e.u][e.v] = e.w;
c++;
}
}
boolean isCyclic(int u, int v, int[] parents)
{
return findParent(u, parents) == findParent(v,
parents);
}
void union(int u, int v, int[] parents, int[] size)
{
u = findParent(u, parents);
v = findParent(v, parents);
if (size[u] > size[v]) {
parents[v] = u;
size[u] += size[v];
} else {
parents[u] = v;
size[v] += size[u];
}
}
int findParent(int u, int[] parents)
{
if (parents[u] == u)
{
return u;
}
else
{
parents[u] = findParent(parents[u],
parents);
return parents[u];
}
}
void display_MST()
{
int cost=0,i,j;
System.out.println("Minimum Spanning Tree Formed is :
");
System.out.println();
for (i=1;i<mst.length;i++)
{
for (j=0;j<mst.length;j++)
{
if (mst[i][j] != 0)
{
System.out.println(i + " ---->
" + j + " = " + mst[i][j]);
cost=cost+mst[i][j];
}
}
}
System.out.println();
System.out.println("Minimum Spanning tree is of cost :
"+cost);
}
public static void main(String[] args)
{
Scanner sc=new Scanner(System.in);
Kruskal k=new Kruskal();
System.out.println("---------KRUSKAL's ALGORITHM ----
-------");
System.out.println();
System.out.println("Enter values : ");
k.create();
System.out.println();
k.display();
k.mst();
System.out.println();
k.display_MST();
sc.close();
}
}