#include "Header.h"
void main()
{
	VERTEX u,v,chon,sum;
	AdjacencyMatrix a;
	ArrayEdge x;
	INIT(a);
	if (ReadFile(a, "floyd.txt") == true)
		cout << "Read File Success.";
	else
		cout << "Error!";
	OutPut(a);
	do{
		cout << "\nNhap Lua Chon : ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			cout << "\nNhap dinh u : ";
			cin >> u;
			if (TimDinhKe(a, u) == -1)
				cout << "Dinh "<<u<<" ko co dinh ke.";
			else
				cout << "Dinh ke cua dinh "<<u<<" co trong so nho nhat la : " << TimDinhKe(a, u);
			break;
		case 2:
			init(x);
			ArrayEdge SapXep;
			cout << "Nhap so canh : ";
			cin >> x.count;
			for (VERTEX i = 0; i < x.count; i++)
			{
				cout << "Canh " << i + 1 << " : \n";
				cout << "Org : "; cin >> x.ds[i].org;
				cout << "Des : "; cin >> x.ds[i].des;
				cout << "Trong so : ";
				cin >> x.ds[i].weight;
				cout << endl;
			}
			SapXep=SapXepCanhDESC(x);
			cout << "Tap canh da sap xep DESC :\n ";
			OutPutArrayEdge(SapXep);
			break;
		case 3:
			if (CheckTree(a) == true)
				cout << "Yes.";
			else
				cout << "No.";
			break;
		case 4:
			u = 0;
			ArrayVertex TrongSoMin, Save;
			Dijkstra(a, u, TrongSoMin, Save);
			for (VERTEX i = 0; i < a.n; i++)
			{
				cout << "\nDuong di ngan nhat tu " << u << " -> " << i << " : ";
				cout << TrongSoMin.ds[i];
			}
			for (VERTEX j = 1; j < a.n; j++){
				cout << "\nVet duong di tu " << u << " -> " << j << " : ";
				VetDuongDi(Save, u, j);
			}
			break;
		case 5:
			ArrayVertex LuuVet,Min;
			cout << "---------Mang Luu Vet----------\n";
			cout << "Nhap so dinh : ";
			cin >> LuuVet.count;
			for (VERTEX i = 0; i < LuuVet.count; i++){
				cout << "Dinh " << i << " : "; cin >> LuuVet.ds[i];
			}
			u = 0;
			cout << "Nhap v : "; cin >> v;
			Min = DSDinhMin(LuuVet, u, v);
			cout <<"DS Dinh la duong di ngan nhat tu "<< u << " -> "<<v<<" : ";
			for (VERTEX i = Min.count - 1; i >= 0; i--)
				cout << Min.ds[i] << " -> ";
			cout <<v;
			break;
		case 6:
			ArrayVertex Search;
			cout << "Nhap u (ROOT) : "; cin >> u;
			cout << "Nhap v : "; cin >> v;
			Search=Search_U_V(a, u, v);
			cout << "Duong di tu " << u << " -> " << v << " : ";
			OutPutArrayVertex(Search);
			break;
		case 7:
			cout << "Nhap u (ROOT) : "; cin >> u;
			cout << "Nhap v : "; cin >> v;
			cout << " Muc cua dinh " <<v<<" vs "<<u<<" la root : "<< Muc_Cua_Dinh(a, u, v);
			break;
		case 8:
			ArrayVertex ToTien;
			cout << "Nhap u (ROOT) : "; cin >> u;
			cout << "Nhap v : "; cin >> v;
			ToTien = Search_ToTien(a, u, v);
			if (ToTien.count == 0)
				cout << "Dinh " << v << " la dinh ROOT.";
			else{
				cout << "Cac dinh to tien cua dinh " << v << " : ";
				OutPutArrayVertex(ToTien);
			}
			break;
		case 9:

			cout << "Nhap u (ROOT) : "; cin >> u;
			cout << "Nhap v : "; cin >> v;
			if (Search_Cha(a, u, v) == -1)
				cout << "dinh Root ko co Cha.";
			else
				cout <<"Cha cua dinh "<<v<<" la : "<< Search_Cha(a, u, v);
			break;
		case 10:
			ArrayVertex TapCon;
			cout << "Nhap u (ROOT) : "; cin >> u;
			cout << "Nhap v : "; cin >> v;
			TapCon = Search_Con(a, u, v);
			if (TapCon.count == 0)
				cout << "Dinh " << v << " Khong co con.";
			else{
				cout << "Cac con cua dinh " << v << " : ";
				OutPutArrayVertex(TapCon);
			}
			break;
		case 11:
			ArrayVertex TapConChau;
			cout << "Nhap u (ROOT) : "; cin >> u;
			cout << "Nhap v : "; cin >> v;
			TapConChau = Search_ConChau(a, u, v);
			if (TapConChau.count == 0)
				cout << "Dinh " << v << " Khong co con.";
			else{
				cout << "Cac dinh con chau cua dinh " << v << " : ";
				OutPutArrayVertex(TapConChau);
			}
			break;
		case 12:
			AdjacencyMatrix PointMin, Trace;
			Floyd(a, PointMin, Trace);
			cout << "C' : ";
			OutPut(PointMin);
			cout << "\nTrace : ";
			OutPut(Trace);
			break;
		case 13:
			ArrayVertex DSMin;
			cout << "Nhap u : "; cin >> u;
			cout << "Nhap v : "; cin >> v;	
			DSMin = Floyd_Min(a, u, v);
			cout << "duong di ngan nhat giua 2 dinh " << u << " va " << v << " : ";
			OutPutArrayVertex(DSMin);
		case 14:
			if (Prim(a).count < a.n - 1)
				cout << "Do thi khong lien thong.";
			else{
				OutPutArrayEdge(Prim(a));
				sum = 0;
				for (VERTEX i = 0; i < Prim(a).count; i++)
					sum += Prim(a).ds[i].weight;
				cout << "Tong trong so cay khung nho nhat la : " << sum;
			}
			break;
		case 15:
			if (KRUSKAL(a).count < a.n - 1)
				cout << "Do thi khong lien thong.";
			else{
				OutPutArrayEdge(KRUSKAL(a));
				sum = 0;
				for (VERTEX i = 0; i < KRUSKAL(a).count; i++)
					sum += KRUSKAL(a).ds[i].weight;
				cout << "Tong trong so cay khung nho nhat la : " << sum;
			}
			break;
		case 16:
			u = 0;
			DIIJKSTRA(a, u);
			break;
		default:
			break;
		}
	} while (chon != 0);
}