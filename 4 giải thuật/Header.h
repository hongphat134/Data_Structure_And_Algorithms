#include "iostream"
#include "stack"
#include "math.h"
using namespace std;
#define LIMIT 999
typedef int VERTEX;
//MAXV: số đỉnh tối đa của đồ thị
const VERTEX MAXV = 20;
//MAXE: số cạnh tối đa của đồ thị
const VERTEX MAXE = MAXV*MAXV;
//VERTEX: Kiểu của một đỉnh trong đồ thị

//EDGE: Kiểu của một cạnh trong đồ thị
struct EDGE
{
	VERTEX org; //Origin
	VERTEX des; //Destination
	VERTEX weight;
};
//ArrayVertex: danh sách đỉnh của đồ thị
struct ArrayVertex
{
	VERTEX ds[MAXV];
	VERTEX count;
};
//ArrayEdge: danh sách cạnh của đồ thị
struct ArrayEdge
{
	EDGE ds[MAXE];
	VERTEX count;
};
//Ma trận kề của đồ thị (Adjacency-matrix)
struct AdjacencyMatrix
{
	VERTEX mt[MAXV][MAXV];
	VERTEX n;
};
//Mảng xác định các đỉnh đã được viếng thăm.
typedef VERTEX VISIT[MAXV];
bool ReadFile(AdjacencyMatrix &a, char* filename);
void swap(VERTEX &a, VERTEX &b);
void INIT(AdjacencyMatrix &a);
void INit(ArrayVertex &dsdinh);
void init(ArrayEdge &x);
void OutPut(AdjacencyMatrix a);
VERTEX TimDinhKe(AdjacencyMatrix a,VERTEX u);
ArrayEdge SapXepCanhDESC(ArrayEdge x);
void OutPutArrayEdge(ArrayEdge x);
void OutPutArrayVertex(ArrayVertex dsdinh);
bool CheckTree(AdjacencyMatrix VH);
void Dijkstra(AdjacencyMatrix a, VERTEX u, ArrayVertex &TrongSoMin, ArrayVertex &Save);
void DIIJKSTRA(AdjacencyMatrix a, VERTEX u);
void VetDuongDi(ArrayVertex Save, VERTEX u, VERTEX D);
ArrayVertex DSDinhMin(ArrayVertex a,VERTEX u,VERTEX v);
ArrayVertex Search_U_V(AdjacencyMatrix a, VERTEX u, VERTEX v);
VERTEX Muc_Cua_Dinh(AdjacencyMatrix a, VERTEX u, VERTEX v);
ArrayVertex Search_ToTien(AdjacencyMatrix a, VERTEX u, VERTEX v);
VERTEX Search_Cha(AdjacencyMatrix a,VERTEX u,VERTEX v);
ArrayVertex Search_Con(AdjacencyMatrix a, VERTEX u, VERTEX v);
ArrayVertex Search_ConChau(AdjacencyMatrix a, VERTEX u, VERTEX v);
void Floyd(AdjacencyMatrix a,AdjacencyMatrix &PointMin,AdjacencyMatrix &Trace);
ArrayVertex Floyd_Min(AdjacencyMatrix a,VERTEX u,VERTEX v);
ArrayEdge Prim(AdjacencyMatrix a);
VERTEX Root(VISIT Parent, int x);
ArrayEdge KRUSKAL(AdjacencyMatrix a);
