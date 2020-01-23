#include "Header.h"
void INIT(AdjacencyMatrix &a)
{
	a.n = 0;
}
void INit(ArrayVertex &dsVERTEX)
{
	dsVERTEX.count = 0;
}
void init(ArrayEdge &x)
{
	x.count = 0;
}
void swap(VERTEX &a, VERTEX &b)
{
	VERTEX temp = a;
	a = b;
	b = temp;
}
bool ReadFile(AdjacencyMatrix &a, char* filename)
{
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL) return false;
	fscanf(fp, "%d", &a.n);
	for (VERTEX i = 0; i < a.n; i++)
	{
		for (VERTEX j = 0; j < a.n; j++)
		{
			fscanf(fp, "%d", &a.mt[i][j]);
		}
	}
	fclose(fp);
	return true;
}
void OutPut(AdjacencyMatrix a)
{
	for (VERTEX i = 0; i < a.n; i++)
	{
		cout << endl;
		for (VERTEX j = 0; j < a.n; j++)
		{
			cout << a.mt[i][j] << " ";
		}
	}
}
VERTEX TimDinhKe(AdjacencyMatrix a,VERTEX u)
{
	VERTEX DinhKeMin = -1, flag = 0, LuuTrongSoMin;
	for (VERTEX i = 1; i < a.n; i++)
	{
		if (a.mt[u][i] != 0)
		{
			if (!flag){
				LuuTrongSoMin = a.mt[u][i];
				DinhKeMin = i;
				flag = 1;
			}
			else if (LuuTrongSoMin > a.mt[u][i])
			{
				LuuTrongSoMin = a.mt[u][i];
				DinhKeMin = i;
			}
		}
	}
	return DinhKeMin;
}
ArrayEdge SapXepCanhDESC(ArrayEdge x)
{
	ArrayEdge SapXep;
	SapXep = x;
	for (VERTEX i = 0; i < SapXep.count - 1; i++)
	{
		for (VERTEX j = i + 1; j < SapXep.count; j++)
		{
			if (SapXep.ds[j].weight > SapXep.ds[i].weight)
			{
				swap(SapXep.ds[i], SapXep.ds[j]);
			}
		}
	}
	return SapXep;
}
bool CheckTree(AdjacencyMatrix VH)
{
	//Khoi tao danh sach VERTEX chua xet
	VISIT visitted, LuuVet;
	stack<VERTEX> S;
	for (VERTEX i = 0; i < VH.n; i++)
		visitted[i] = 0;
	for (VERTEX i = 0; i < VH.n; i++)
		LuuVet[i] = 0;
	//Duyet VERTEX 0
	visitted[0] = 1;
	VERTEX SUCCESS, u = VH.n, w, dem = 1;
	S.push(0);
	while (!S.empty()){
		SUCCESS = 0;
		LuuVet[u] = 1;//0
		u = S.top();
		S.pop();
		for (w = 0; w < VH.n; w++)
		{
			if (VH.mt[u][w] != 0 && visitted[w] == 0)
			{
				S.push(u);
				S.push(w);
				visitted[w] = 1;
				dem++;
				SUCCESS = 1;
				break;
			}
		}
		//Dò LuuVet với các đỉnh đã đánh dấu de kiem tra co tao chu trinh hay ko ?
		if (SUCCESS == 1){
			for (VERTEX i = 0; i < VH.n; i++)
			{
				//Ko do` cap dinh vua` xet
				if (i != u){
					if (LuuVet[i] == 1)
					{
						if (VH.mt[w][i] != 0)
							return false;
					}
				}
			}
		}
		if (dem == VH.n)
			return true;
	}
	return false;;
}
void OutPutArrayVertex(ArrayVertex dsdinh)
{
	for (VERTEX i = 0; i < dsdinh.count; i++)
		cout << dsdinh.ds[i] << "  ";
}
void OutPutArrayEdge(ArrayEdge x)
{
	for (VERTEX i = 0; i < x.count; i++)
		cout << "{" << x.ds[i].org << "," << x.ds[i].des << "}\t"<<x.ds[i].weight<<endl;
}
void Dijkstra(AdjacencyMatrix a, VERTEX u, ArrayVertex &TrongSoMin, ArrayVertex &Save)
{
	VERTEX DinhXet, min;
	ArrayVertex DanhDau;
	TrongSoMin.count = a.n;
	//Khởi tạo mảng 1 chiều
	for (VERTEX i = 0; i < TrongSoMin.count; i++){
		//Khởi tạo mảng lưu trọng số nhỏ nhất
		TrongSoMin.ds[i] = LIMIT;
		//Khởi tạo mảng đánh dấu
		DanhDau.ds[i] = 0;
		//Khởi tạo mảng lưu vết đi
		Save.ds[i] = u;
	}
	TrongSoMin.ds[u] = 0;
	DanhDau.ds[u] = 1;
	DinhXet = u;
	do{
		//Tìm đường đi có trọng số nhỏ nhất 
		for (VERTEX i = 0; i < TrongSoMin.count; i++)
		{
			if (a.mt[DinhXet][i] != 0 && (a.mt[DinhXet][i] + TrongSoMin.ds[DinhXet] < TrongSoMin.ds[i]) && DanhDau.ds[i] == 0)
			{
				TrongSoMin.ds[i] = a.mt[DinhXet][i] + TrongSoMin.ds[DinhXet];
				Save.ds[i] = DinhXet;
			}
		}
		min = LIMIT;
		for (VERTEX j = 0; j < TrongSoMin.count; j++){
			if (min>TrongSoMin.ds[j] && DanhDau.ds[j] == 0){
				min = TrongSoMin.ds[j];
				DinhXet = j;
			}
		}
		DanhDau.ds[DinhXet] = 1;
	} while (min < LIMIT);
}
//Chạy tay 
void DIIJKSTRA(AdjacencyMatrix a, VERTEX u){
	cout << u << "\t";
	for (VERTEX i = 0; i < a.n; i++){
		if (i != u)
			cout << i << "\t";
	}
	cout << endl;
	cout << "[" << u << "," << u << "]   ";
	for (VERTEX i = 1; i < a.n; i++){
		cout << "~\t";
	}
	cout << endl;
	VERTEX DinhXet, min; 
	ArrayEdge Again;
	ArrayVertex DanhDau;
	for (VERTEX i = 0; i < a.n; i++)
	{
		Again.ds[i].org = 0;
	}
	VISIT TrongSoMin, Save;
	//Khởi tạo mảng 1 chiều
	for (VERTEX i = 0; i < a.n; i++){
		//Khởi tạo mảng lưu trọng số nhỏ nhất
		TrongSoMin[i] = LIMIT;
		//Khởi tạo mảng đánh dấu
		DanhDau.ds[i] = 0;
		//Khởi tạo mảng lưu vết đi
		Save[i] = u;
	}
	TrongSoMin[u] = 0;
	DanhDau.ds[u] = 1;
	DinhXet = u;
	do{
		//Tìm đường đi có trọng số nhỏ nhất 
		for (VERTEX i = 0; i < a.n; i++)
		{
			if (a.mt[DinhXet][i] != 0 && (a.mt[DinhXet][i] + TrongSoMin[DinhXet] < TrongSoMin[i]) && DanhDau.ds[i] == 0)
			{
				TrongSoMin[i] = a.mt[DinhXet][i] + TrongSoMin[DinhXet];
				Save[i] = DinhXet;
				cout << "[" << TrongSoMin[i] << "," << DinhXet << "]   ";
				Again.ds[i].org = TrongSoMin[i];
				Again.ds[i].des = DinhXet;
			}
			else{
				if (DanhDau.ds[i])
					cout << "-\t";
				else if (Again.ds[i].org != 0)
						cout << "[" << Again.ds[i].org << "," << Again.ds[i].des << "]   ";
				else
					cout << "~\t";
			}
		}
		cout << endl;
	
		min = LIMIT;
		for (VERTEX j = 0; j < a.n; j++){
			if (min>TrongSoMin[j] && DanhDau.ds[j] == 0){
				min = TrongSoMin[j];
				DinhXet = j;
			}
		}
		DanhDau.ds[DinhXet] = 1;
	} while (min < LIMIT);
	/*for (VERTEX i = 0; i < a.n; i++){
		cout << "-\t";
	}*/
	cout << "\n\nGhi chu :\t- : Da duyet\t~ : unlimit\t* : dinh dang xet\n";
}
void VetDuongDi(ArrayVertex Save,VERTEX u,VERTEX D)
{
	stack<VERTEX> S;
	S.push(Save.ds[D]);
	VERTEX i = Save.ds[D];
	while (i != u){
	i = Save.ds[i];
	S.push(i);
	}	
	while (!S.empty()){
		cout << S.top() << " -> ";
		S.pop();
	}
	cout << D;
}
ArrayVertex DSDinhMin(ArrayVertex a, VERTEX u, VERTEX v)
{
	ArrayVertex LuuVet;
	INit(LuuVet);
	LuuVet.ds[LuuVet.count++] = a.ds[v];
	VERTEX i = a.ds[v];
	while (i != u){
		i = a.ds[i];
		LuuVet.ds[LuuVet.count++] = i;
	}
	return LuuVet;
}
ArrayVertex Search_U_V(AdjacencyMatrix a, VERTEX u, VERTEX v)
{
	ArrayVertex Min;
	INit(Min);
	VERTEX k,SUCCESS=-1;
	VISIT visited;
	stack<VERTEX> s;
	for (int i = 0; i < a.n; i++)
		visited[i] = 0;
	//Duyệt Depth First Search
	s.push(u);
	visited[u] = 1;
	while(!s.empty()){
		if (SUCCESS == 0)
			Min.count--;
		SUCCESS = 0;
		k = s.top(); 
		if (k == v)
		{
			Min.ds[Min.count++] = v;
			break;
		}
		s.pop();
			/*for (VERTEX i = a.n-1; i > 0;--i)*/
		for (VERTEX i = 0; i < a.n;i++)
		if (a.mt[k][i] != 0 && !visited[i]) {
			Min.ds[Min.count++] = k;
			s.push(k);
			s.push(i);
			SUCCESS = 1;
			visited[i] = 1;
			break;
		}
	}
	return Min;
}
VERTEX Muc_Cua_Dinh(AdjacencyMatrix a, VERTEX u, VERTEX v)
{
	VERTEX Muc=-1,k, SUCCESS = -1;
	VISIT visited;
	stack<VERTEX> s;
	for (int i = 0; i < a.n; i++)
		visited[i] = 0;
	//Duyệt Depth First Search
	s.push(u);
	visited[u] = 1;
	while (!s.empty()){
		if (SUCCESS == 0)
			Muc--;
		SUCCESS = 0;
		k = s.top();
		s.pop();
		if (k == v)
		{
			Muc++;
			break;
		}
		/*for (VERTEX i = a.n-1; i > 0;--i)*/
		for (VERTEX i = 0; i < a.n; i++)
		if (a.mt[k][i] != 0 && !visited[i]) {
			Muc++;
			s.push(k);
			s.push(i);
			SUCCESS = 1;
			visited[i] = 1;
			break;
		}
	}
	return Muc;
}
ArrayVertex Search_ToTien(AdjacencyMatrix a, VERTEX u, VERTEX v)
{
	ArrayVertex ToTien;
	INit(ToTien);
	VERTEX DoSau = Muc_Cua_Dinh(a, u, v), k, Muc = -1,SUCCESS=-1;
	VISIT visited;
	stack<VERTEX> s;
	for (int i = 0; i < a.n; i++)
		visited[i] = 0;
	//Duyệt Depth First Search
	s.push(u);
	visited[u] = 1;
	ToTien.ds[ToTien.count++] = u;
	while (!s.empty()){
		if (SUCCESS == 0){
			Muc--;
		}
		SUCCESS = 0;
		k = s.top();
		s.pop();
		/*for (VERTEX i = a.n-1; i > 0;--i)*/
		for (VERTEX i = 0; i < a.n; i++){
			if (a.mt[k][i] != 0 && !visited[i]) {
				Muc++;
				if (Muc<DoSau-1)
					ToTien.ds[ToTien.count++] = i;
				s.push(k);
				s.push(i);
				SUCCESS = 1;
				visited[i] = 1;
				break;
			}
		}
	}
	return ToTien;
}
VERTEX Search_Cha(AdjacencyMatrix a, VERTEX u, VERTEX v)
{
	VERTEX k,Cha=-1;
	stack<VERTEX> S;
	VISIT VISITED;
	for (int i = 0; i < a.n; i++)
		VISITED[i] = 0;
	S.push(u);
	VISITED[u] = 1;
	while (!S.empty()){
		k = S.top();
		S.pop();
		for (VERTEX w = 0; w<a.n; w++)
		{
			if (a.mt[k][w] != 0 && VISITED[w] == 0){
				VISITED[w] = 1;
				S.push(k);
				S.push(w);
				if (w == v){
					Cha = k;
					return Cha;
				}
				break;
			}
		}
	}
	return Cha;
}
ArrayVertex Search_Con(AdjacencyMatrix a, VERTEX u, VERTEX v)
{
	VERTEX k;
	ArrayVertex TapCon;
	INit(TapCon);
	VISIT visited;
	stack<VERTEX> S;
	for (VERTEX i = 0; i < a.n; i++)
		visited[i] = 0;
	S.push(u);
	visited[u] = 1;
	while (!S.empty()){
		k = S.top();
		if (k == v)
			break;
		S.pop();
		for (VERTEX i = 0; i < a.n; i++)
		{
			if (a.mt[k][i] != 0 && !visited[i])
			{
				S.push(k);
				S.push(i);
				visited[i] = 1;
				break;
			}
		}
	}
	//Tìm con
	for (VERTEX i = 0; i < a.n; i++){
		if (a.mt[k][i] != 0 && !visited[i])
			TapCon.ds[TapCon.count++] = i;
	}
	return TapCon;
}
ArrayVertex Search_ConChau(AdjacencyMatrix a, VERTEX u, VERTEX v)
{
	VERTEX k, i, DoSau = Muc_Cua_Dinh(a, u, v), Muc = -1, SUCCESS = -1;
	ArrayVertex TapConChau;
	INit(TapConChau);
	VISIT visited;
	stack<VERTEX> s;
	for (i = 0; i < a.n; i++)
		visited[i] = 0;
	s.push(u);
	visited[u] = 1;
	while (!s.empty()){
		if (SUCCESS == 0)
			Muc--;
		else
			Muc++;
		SUCCESS = 0;
		k = s.top();
		s.pop();
		for (i = 0; i < a.n;i++){
			if (a.mt[k][i] != 0 && !visited[i]) {	
				if (Muc >= DoSau)
					TapConChau.ds[TapConChau.count++] = i;
				s.push(k);
				s.push(i);
				SUCCESS = 1;
				visited[i] = 1;
				break;
			}	
		}

	}
	return TapConChau;
}
void Floyd(AdjacencyMatrix a, AdjacencyMatrix &PointMin, AdjacencyMatrix &Trace)
{
	INIT(PointMin);
	INIT(Trace);
	PointMin.n = a.n;
	Trace.n = a.n;
	VISIT visited;
	//Khởi tạo mảng đánh dấu
	for (VERTEX i = 0; i < a.n; i++)
		visited[i] = 0;
	//Khởi tạo mảng lưu trọng số nhỏ nhất
	for (VERTEX i = 0; i < a.n; i++){
		for (VERTEX j = 0; j < a.n; j++){
			if (i == j)
				PointMin.mt[i][j] = 0;
			else if (a.mt[i][j] == 0)
				PointMin.mt[i][j] = LIMIT;
			else
				PointMin.mt[i][j] = a.mt[i][j];
		}
	}
	//Khởi tạo mọi đường đi ban đầu đều trực típ
	for (VERTEX i = 0; i < a.n; i++){
		for (VERTEX j = 0; j < a.n; j++){
			Trace.mt[i][j] = j;
		}
	}
	//Duyệt hảng
	for (VERTEX i = 0; i < a.n; i++){
		//Duyệt cột 
		for (VERTEX j = 0; j < a.n; j++){
			if (i != j){
				//Duyệt hết cột j
				for (VERTEX k = 0; k < a.n; k++){
					if (i != k&&k!=j&&PointMin.mt[i][j] + PointMin.mt[k][i] < PointMin.mt[k][j])
					{
						PointMin.mt[k][j] = PointMin.mt[i][j] + PointMin.mt[k][i];
						Trace.mt[k][j] = i;
					}
				}
			}
		}
	}
}
ArrayVertex Floyd_Min(AdjacencyMatrix a, VERTEX u, VERTEX v)
{
	ArrayVertex DSMin;
	INit(DSMin);
	VERTEX Consider;
	Consider = a.mt[u][v];
	DSMin.ds[DSMin.count++] = u;
	DSMin.ds[DSMin.count++] = Consider;
	while (Consider != v)
	{
		Consider=a.mt[Consider][v];
		DSMin.ds[DSMin.count++] = Consider;
	}
	return DSMin;
}
VERTEX Root(VISIT Parent,int x)
{
	VERTEX Goc;
	Goc = x;
	/*while (Parent[Goc] >= 0)*/
	while (Parent[Goc] != Goc)
		Goc = Parent[Goc];
	return Goc;
}
ArrayEdge Prim(AdjacencyMatrix a)
{
	ArrayEdge PrimList;
	init(PrimList);
	VISIT Free, Trace,d;
	VERTEX i,u,Min,DinhXet;
	u = 0;
	for (i = 0; i < a.n; i++)
		Free[i] = 0;
	for (i = 0; i < a.n; i++)
		Trace[i] = -1;
	for (i = 0; i < a.n; i++)
		d[i] = LIMIT;
	d[0] = 0;
	Free[u] = 1;
	DinhXet = u;
	do{
		for ( i=0; i < a.n; i++){
			if (!Free[i] && a.mt[DinhXet][i] != 0&&a.mt[DinhXet][i]<d[i])
			{
				d[i] = a.mt[DinhXet][i];
				Trace[i] = DinhXet;
			}
		}
		//di chuyển đến đỉnh có trọng số nhỏ nhất
		Min = LIMIT;
		for (i = 0; i < a.n; i++)
		{
			if (d[i] < Min&&!Free[i])
			{
				Min = d[i];
				DinhXet = i;
			}
		}
		PrimList.ds[PrimList.count].org = Trace[DinhXet];
		PrimList.ds[PrimList.count].des = DinhXet;
		PrimList.ds[PrimList.count++].weight = a.mt[Trace[DinhXet]][DinhXet];
		Free[DinhXet] = 1;
	} while (PrimList.count < a.n - 1);
	return PrimList;
}
ArrayEdge KRUSKAL(AdjacencyMatrix a){
	VISIT father;
	VERTEX i, u, v, Root1, Root2;
	//Khởi tạo mảng đánh dấu
	for (i = 0; i < a.n; i++)
		father[i] = i;
	ArrayEdge ListEdge, TapCanhDESC, TapCanh;
	init(ListEdge);
	init(TapCanhDESC);
	init(TapCanh);
	//Lưu  cạnh và trọng số
	for (i = 0; i < a.n; i++){
		for (VERTEX j = i + 1; j < a.n; j++){
			if (a.mt[i][j] != 0){
				TapCanh.ds[TapCanh.count].org = i;
				TapCanh.ds[TapCanh.count].des = j;
				TapCanh.ds[TapCanh.count++].weight = a.mt[i][j];
			}
		}
	}
	//Tập cạnh đã sắp xếp giảm dần
	TapCanhDESC = SapXepCanhDESC(TapCanh);
	//Chèn cạnh vào ListEdge
	while (TapCanhDESC.count >= 0 && ListEdge.count < a.n - 1){
		u = TapCanhDESC.ds[TapCanhDESC.count - 1].org;
		v = TapCanhDESC.ds[TapCanhDESC.count - 1].des;
		TapCanhDESC.count--;
		//Tìm gôc của đỉnh u
		Root1 = Root(father, u);
		//Tìm gốc của đỉnh v
		Root2 = Root(father, v);
		//Kiểm tra ko cùng gốc thì chèn
		if (Root1 != Root2){
			ListEdge.ds[ListEdge.count].org = u;
			ListEdge.ds[ListEdge.count].des = v;
			ListEdge.ds[ListEdge.count++].weight = a.mt[u][v];
			//Nối gốc của u vs gốc của v lại với nhau
			father[Root2] = Root1;
		}	
	}
	return ListEdge;
}
//void toposort(int no_vertex) {
//	for (int v = 0; v < no_vertex; ++v) {
//		if (!seen[v]) {
//			dfs(v);
//		}
//	}
//	// print out topo order
//	for (auto v : topo_order) {
//		std::cout << v << " ";
//	}
//}