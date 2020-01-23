#include "Header.h"
void menu()
{	
	cout << "-------------------------------------DS KE--------------------------------------";
	cout << "0.Ket Thuc\n";
	cout << "1.Doc File\n";
	cout << "2.Ghi File\n";
	cout << "3.Giai phong DS ke.\n";
	cout << "4.Kiem tra cap dinh (u,v) co phai canh cua DT hay ko?\n";
	cout << "5.Tim BAC cua 1 dinh\n";
	cout << "6.Tim BAC Ra cua dinh\n";
	cout << "7.Tim BAC Vao cua dinh\n";
	cout << "8.Xuat TAP CANH tu DS ke ( DT CO huong )\n";
	cout << "9.Xuat TAP CANH tu DS ke ( DT VO huong )\n";
	cout << "10.Nhap dinh va canh -> DS ke cua DT CO huong\n";
	cout << "11.Nhap dinh va canh -> DS ke cua DT VO huong\n";
	cout << "12.Doi Huong Do Thi\n";
	cout << "13.Duyet BFS theo dinh V\n";
	cout << "14.Duyet BFS All Dinh\n";
	cout << "15.Duyet BFS va tim tap Dinh va Canh Vieng Tham theo dinh V\n";
	cout << "16.Duyet BFS va tim tap Dinh va Canh Vieng Tham All Dinh\n";
	cout << "17.Duyet DFS theo dinh V\n";
	cout << "18.Duyet DFS All Dinh\n";
	cout << "19.Duyet DFS va tim tap Dinh va Canh Vieng Tham theo dinh V\n";
	cout << "20.Duyet DFS va tim tap Dinh va Canh Vieng Tham All Dinh\n";
	cout << "21.Tinh So Thanh Phan Lien Thong cua DT\n";
	cout << "22.Kiem Tra DT co Lien Thong MANH hay ko?\n";
	cout << "23.Sap Xep TOPO\n";
	cout << "------------------------------------END------------------------------------------";
}
void Init(AdjacencyList &ht)
{
	for (int i = 0; i<ht.count; i++)
		ht.ds[i] = NULL;
}
//Cau 1
bool DocFile(AdjacencyList &ht, char* filename)
{
	FILE* fp;
	fp = fopen(filename, "r");
	if (fp == NULL)
		return false;
	fscanf(fp, "%d", &ht.count);
	Init(ht);
	for (int k = 0; k < ht.count; k++)
	{
		int test;
		fscanf(fp, "%d", &test);
		while (test>0){
			NodeVertexPointer p;
			p = new NodeVertex;
			fscanf(fp, "%d",&p->ver);
			p->link = NULL;
			if (ht.ds[k] == NULL) ht.ds[k] = p;
			else {
				NodeVertexPointer t = ht.ds[k];
				do {
					if (t->ver == p->ver)
					{
						delete p;
						return false;
					}
					else if (t->link == NULL) break;
					else t = t->link;
				} while (1);
				t->link = p;
			}
			test--;
		}
	}
	return true;
}
//Cau 2
bool GhiFile(AdjacencyList ht, char* filename)
{
	FILE* fp;
	fp = fopen(filename, "w");
	if (fp == NULL)
		return false;
	int test;
	fprintf(fp, "%d\n", ht.count);
	for (int k = 0; k < ht.count; k++)
	{
		test = 0;
		NodeVertexPointer p = ht.ds[k];
		while (ht.ds[k] != NULL)
		{
			test++;
			ht.ds[k]=ht.ds[k]->link;
		}
		fprintf(fp, "%d", test);
		while (p!=NULL){		
			fprintf(fp, " %d", p->ver);
			p = p->link;
		}
		fprintf(fp,"\n");
	}
	return true;
}
//Cau 4
bool KiemTraCanh(AdjacencyList ht, int u, int v)
{
	bool flag = false;
	NodeVertexPointer p = ht.ds[u];
	while (p!= NULL)
	{
		if (v == p->ver){
			flag = true;
			break;
		}
		p = p->link;
	}
	return flag;
}
//Cau 5,6,7
int TinhBacRa(AdjacencyList ht, int u)
{
	int Dem1 = 0;
	NodeVertexPointer p = ht.ds[u];
	while (p != NULL)
	{
		Dem1++;
		p = p->link;
	}
	return Dem1;
}
int TinhBacVao(AdjacencyList ht, int u)
{
	int Dem2 = 0;
	for (int i = 0; i!=u,i < ht.count; i++)
	{
		while (ht.ds[i] != NULL)
		{
			if (ht.ds[i]->ver == u)
				Dem2++;
			ht.ds[i] = ht.ds[i]->link;
		}
	}
	return Dem2;
}
//Cau 8
void TapCanhDoThi(AdjacencyList ht, ArrayEdge &x)
{
	for (int k = 0; k < ht.count; k++)
	{
		NodeVertexPointer p = ht.ds[k];
		while (p!=NULL)
		{
			x.ds[x.count].org = k;
			x.ds[x.count++].des = p->ver;
			p = p->link;
		}
	}
}
//Cau 9
void TapCanhDoThiVoHuong(AdjacencyList ht, ArrayEdge &x)
{
	int u, v,flag;
	for (int k = 0; k < ht.count; k++)
	{
		NodeVertexPointer p = ht.ds[k];
		while (p != NULL)
		{
			u = k;
			v = p->ver;
			flag = 0;
			for (int i = 0; i < x.count; i++)
			{
				if (u == x.ds[i].des&&v == x.ds[i].org)
					flag = 1;

			}
			if (flag == 0){
				x.ds[x.count].org = k;
				x.ds[x.count++].des = p->ver;
			}
			p = p->link;
		}
	}
}
//Cau 10
void BienDoiTapCanhCoHuongThanhDSKe(AdjacencyList &ht, ArrayEdge x)
{
	for (int i = 0; i < x.count; i++)
	{
		NodeVertexPointer p;
		p = new NodeVertex;
		p->ver = x.ds[i].des;
		p->link = NULL;
		if (ht.ds[x.ds[i].org] == NULL)
			ht.ds[x.ds[i].org] = p;
		else{
			NodeVertexPointer t = ht.ds[x.ds[i].org];
			do {
				if (t->ver == p->ver)
				{
					delete p;
					return;
				}
				else if (t->link == NULL) break;
				else t = t->link;
			} while (1);
			t->link = p;
		}
	}
}
//Cau 11
void BienDoiTapCanhVoHuongThanhDSKe(AdjacencyList &ht, ArrayEdge x)
{
	for (int i = 0; i < x.count; i++)
	{
		NodeVertexPointer p1,p2;
		p1 = new NodeVertex;
		p2 = new NodeVertex; 
		p1->ver = x.ds[i].des;
		p1->link = NULL;
		p2->ver = x.ds[i].org;
		p2->link = NULL;
		if (ht.ds[x.ds[i].org] == NULL)
			ht.ds[x.ds[i].org] = p1;
		else{
			NodeVertexPointer t1 = ht.ds[x.ds[i].org];
			do {
				if (t1->ver == p1->ver)
				{
					delete p1;
					return;
				}
				else if (t1->link == NULL) break;
				else t1 = t1->link;
			} while (1);
			t1->link = p1;
		}
		//Chen Canh doi
		if (ht.ds[x.ds[i].des] == NULL)
			ht.ds[x.ds[i].des] = p2;
		else{
			NodeVertexPointer t2 = ht.ds[x.ds[i].des];
			do {
				if (t2->ver == p2->ver)
				{
					delete p2;
					return;
				}
				else if (t2->link == NULL) break;
				else t2 = t2->link;
			} while (1);
			t2->link = p2;
		}
	}

}
//Cau 12
void DoiHuongDTCoHuong(AdjacencyList &ht)
{
	AdjacencyList test;
	test.count = ht.count;
	Init(test);
	for (int k = 0; k < ht.count; k++)
	{

		while (ht.ds[k] != NULL)
		{
			//Thuc bien Buoc chen
			NodeVertexPointer q;
			q = new NodeVertex;
			q->ver = k;
			q->link = NULL;
			if (test.ds[ht.ds[k]->ver] == NULL)
				test.ds[ht.ds[k]->ver] = q;
			else{
				NodeVertexPointer t = test.ds[ht.ds[k]->ver];
				do {
					if (t->ver == k)
					{
						delete q;
						return;
					}
					else if (t->link == NULL)
						break;
					else t = t->link;
				} while (1);
				t->link = q;
			}
			ht.ds[k] = ht.ds[k]->link;
		}
	}
	ht = test;
}
//Cau 13, 14
void BFS_Queue(AdjacencyList ht, int startV)
{
	//Khoi tao Danh Sach DAnh Dau
	VISIT visited;
	queue<int> Q;
	for (int i = 0; i < ht.count; i++)
		visited[i] = 0;
	Q.push(startV);
	visited[startV] = 1;
	cout << "Breadth first Search starting from vertex ";
	cout << startV << " : ";
	//Duyet Hang Doi Q ( lay gia tri ra va vao )
	while (!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		cout << v << " ";	
		NodeVertexPointer p = ht.ds[v];
		while (p != NULL)
		{
			//Danh dau dinh THAM.Neu da danh dau, bo qua Node nay. 
			if (visited[p->ver] == 0){
				visited[p->ver] = 1;
				Q.push(p->ver);
			}
			p = p->link;
		}
	}
	cout << endl;
}
//Cau 15, 16
void BFS_TapDinhVaCanhViengTham(AdjacencyList ht, int startV, ArrayVertex &av, ArrayEdge &ae)
{
		VISIT visited;
		queue<int> Q;
		for (int i = 0; i < ht.count; i++)
			visited[i] = 0;
		Q.push(startV);
		av.ds[av.count++] = startV;
		visited[startV] = 1;
		while (!Q.empty())
		{
			int v = Q.front();
			Q.pop();
			NodeVertexPointer p = ht.ds[v];
			while (p != NULL)
			{
				ae.ds[ae.count].org = v;
				ae.ds[ae.count++].des = p->ver;
				if (visited[p->ver] == 0){
					av.ds[av.count++] = p->ver;		
					visited[p->ver] = 1;
					Q.push(p->ver);
				}
				p = p->link;
			}
		}
}
//Cau 17, 18
void DFS_Stack(AdjacencyList ht, int startV, ArrayVertex &KQ)
{
	//Khoi tao Danh sach danh dau
	VISIT visited;
	stack<int> S;
	for (int i = 0; i < ht.count; i++)
		visited[i] = 0;
	S.push(startV);
	visited[startV] = 1;
	KQ.ds[KQ.count++] = startV;
	//Duyet theo stack S (lay gia tri ra va vao) va luu gia tri vao ArrayVertex KQ. Den khi nao Stack rong thi stop
	while (!S.empty())
	{
		int k = S.top();
		S.pop();
		NodeVertexPointer p = ht.ds[k];
		while (p != NULL)
		{
			if (visited[p->ver] == 0){
				visited[p->ver] = 1;
				S.push(k);
				S.push(p->ver);
				KQ.ds[KQ.count++] = p->ver;
				break;
			}
			p = p->link;
		}
	}
}
//Cau 19, 20
void DFS_TapDinhVaCanhViengTham(AdjacencyList ht, int startV, ArrayVertex &av, ArrayEdge &ae)
{
	VISIT visited;
	stack<int> S;
	for (int i = 0; i < ht.count; i++)
		visited[i] = 0;
	S.push(startV);
	visited[startV] = 1;
	av.ds[av.count++] = startV;
	while (!S.empty())
	{
		int k = S.top();
		S.pop();
		NodeVertexPointer p = ht.ds[k];
		while (p != NULL)
		{
			if (visited[p->ver] == 0){
				visited[p->ver] = 1;
				S.push(k);
				S.push(p->ver);
				av.ds[av.count++] = p->ver;
				ae.ds[ae.count].org = k;
				ae.ds[ae.count++].des = p->ver;
				break;
			}
			p = p->link;
		}
	}
}

void InDinh(ArrayVertex a)
{
	cout << a.ds[0];
	for (int i = 1; i < a.count; i++)
		cout << " -> " << a.ds[i];
}
void InTapCanh(ArrayEdge x)
{
	for (int i = 0; i < x.count; i++)
		cout << "{" << x.ds[i].org  << "," << x.ds[i].des  << "}";
}
//Cau 3 :Giai Phong DS ke
void Dispose(AdjacencyList &ht)
{
	NodeVertex* p;
	for (int i = 0; i<ht.count; i++)
	{
		while (ht.ds[i] != NULL)
		{
			p = ht.ds[i];
			ht.ds[i] = ht.ds[i]->link;
			delete p;
		}
	}
}
void Xuat(AdjacencyList ht)
{
	for (int i = 0; i < ht.count; i++)
	{
		cout << "(" << i << ") :";
		while (ht.ds[i] != NULL)
		{
			cout << ht.ds[i]->ver << " ";
			ht.ds[i] =ht.ds[i]->link;
		}
		cout << endl;
	}
}
//Cau 21
int SoThanhPhanLienThong(AdjacencyList ht)
{
	int SUCCESS, dem = 0, i, j, TPLT = 0;
	VISIT VS;
	for (i = 0; i < ht.count; i++)
		VS[i] = 0;
	
	do{
		j = 0;
		while (VS[j] == 1){
			j++;
		}
		VS[j] = 1;
		dem++;
		TPLT++;	
		//Duyet DS ke xem co di wa dinh nao wa' 2 lan khong? Neu co, --So Lien Thong va dung vong lap
		NodeVertexPointer test = ht.ds[j];
		while (test != NULL)
		{
			if (VS[test->ver] == 1)
			{
				TPLT--;
				break;
			}
			test = test->link;
		}
		//Duyet DS ke. Neu di wa het cac dinh, tra ve TPLT. Ngc lai, TPLT++ va tip tuc den khi nao qua het cac dinh thi thoi.
		do{
			SUCCESS = 0;
			for (i = 0; i < ht.count; i++)
			{
				
				if (VS[i] == 1)
				{
					NodeVertexPointer p = ht.ds[i];
					while (p != NULL){
						if (VS[p->ver] == 0)
						{
							//Danh dau dinh da duyet
							VS[p->ver] = 1;
							SUCCESS = 1;
							//So dinh da duyet
							dem++;
						}
						if (dem == ht.count)
							return TPLT;
						p = p->link;
					}
				}
			}
		} while (SUCCESS == 1);
	} while (dem < ht.count);
	return TPLT;
}
//Cau 22
bool KTLienThongManh(AdjacencyList ht)
{
	bool flag = false;
	int u;
	ArrayVertex arrv;
	//Dung DFS de lay dinh duyet cuoi cung 
	arrv.count = 0;
	DFS_Stack(ht, 0, arrv);
	//Kiem tra dinh duyet cuoi cung co duong di den diem xuat phat hay khong?
	VISIT VISITED;
	for (int i = 0; i < ht.count; i++)
		VISITED[i] = 0;
	arrv.count--;
	VISITED[arrv.ds[arrv.count]] = 1;
	if (ht.ds[arrv.ds[arrv.count]] == NULL)
		return flag;
	while (arrv.count>0){
		u = arrv.ds[arrv.count--];
		NodeVertexPointer p = ht.ds[u];
		while (p != NULL)
		{
			if (p->ver == 0)
			{
				flag = true;
				return flag;
			}
			if (VISITED[p->ver] == 0)
			{
				VISITED[p->ver] = 1;
				arrv.ds[++arrv.count] = u;
				arrv.ds[++arrv.count] = p->ver;
				break;
			}
			p = p->link;
		}
	}	
	return flag;
}
//Cau 23
//Kiem tra dinh co Canh Vao hay ko?
bool KT_S(AdjacencyList ht, int k)
{
	bool flag = true;
	for (int i = 0; i < ht.count; i++)
	{
		NodeVertexPointer p = ht.ds[i];
		while (p != NULL)
		{
			if (p->ver == k)
			{
				flag = false;
				return flag;
			}
			p = p->link;
		}
	}
	return flag;
}
bool TOPO(AdjacencyList ht, ArrayVertex &Topo)
{
	int Save;
	bool flag = true;
	queue<int> S;
	//Tap hop cac dinh khong co canh vao
	for (int i = 0; i < ht.count; i++)
		if (KT_S(ht,i) == true)
			S.push(i);
	//Duyet DS ke va lay dinh theo tieu chi  
	while (!S.empty())
	{
		int n = S.front();
		S.pop();
		Topo.ds[Topo.count++] = n;
		while (ht.ds[n] != NULL){
			NodeVertex* q;
			Save = ht.ds[n]->ver;
			q = ht.ds[n];
			ht.ds[n] = ht.ds[n]->link;
			delete q;
			if (KT_S(ht,Save)==true)
				S.push(Save);
		}
	}
	//Kiem tra DS con canh nao ko?Neu con,do thi co it nhat 1 chu trinh. Ngc lai, xuat thu tu TOPO
	for (int q = 0; q < ht.count; q++)
	{
		NodeVertexPointer p = ht.ds[q];
		if(p!=NULL){
			flag = false;
			break;
		}
	}
	return flag;
}