#include "iostream"
#include "queue"
#include "stack"
using namespace std;
const int MAXV = 20;
const int MAXE = MAXV*MAXV;
typedef int VISIT[MAXV];
struct EDGE
{
	int org; //Origin
	int des; //Destination
};
//Tap Dinh
struct ArrayVertex
{
	int  ds[MAXV];
	int count;
};
//Tap Canh
struct ArrayEdge
{
	EDGE ds[MAXE];
	int count;
};
struct NodeVertex
{
	int ver; //Vertex
	NodeVertex* link;
};
typedef NodeVertex* NodeVertexPointer;
struct AdjacencyList
{
	NodeVertexPointer ds[MAXV];
	int count;
};
void menu();
void Init(AdjacencyList &ht);
void InDinh(ArrayVertex a);
bool DocFile(AdjacencyList &ht, char* filename);
bool GhiFile(AdjacencyList ht, char* filename);
bool KiemTraCanh(AdjacencyList ht, int u, int v);
int TinhBacRa(AdjacencyList ht,int u);
int TinhBacVao(AdjacencyList ht, int u);
void InTapCanh(ArrayEdge x);
void TapCanhDoThi(AdjacencyList ht, ArrayEdge &x);
void TapCanhDoThiVoHuong(AdjacencyList ht, ArrayEdge &x);
void BienDoiTapCanhCoHuongThanhDSKe(AdjacencyList &ht, ArrayEdge x);
void BienDoiTapCanhVoHuongThanhDSKe(AdjacencyList &ht, ArrayEdge x);
void DoiHuongDTCoHuong(AdjacencyList &ht);
void BFS_Queue(AdjacencyList ht, int startV);
void BFS_TapDinhVaCanhViengTham(AdjacencyList ht, int startV, ArrayVertex &av, ArrayEdge &ae);
void DFS_Stack(AdjacencyList ht, int startV, ArrayVertex &KQ);
void DFS_TapDinhVaCanhViengTham(AdjacencyList ht, int startV, ArrayVertex &av, ArrayEdge &ae);
void Xuat(AdjacencyList ht);
void Dispose(AdjacencyList &ht);
int SoThanhPhanLienThong(AdjacencyList ht);
bool KTLienThongManh(AdjacencyList ht);
bool KT_S(AdjacencyList ht, int k);
bool TOPO(AdjacencyList ht, ArrayVertex &Topo);