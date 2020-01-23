#include "Header.h"
void main()
{
	char tenfile[MAXE];
	AdjacencyList ht;
	ArrayEdge x,ae;
	ArrayVertex av,KQ,Topo;
	int n,u, v,startV,a;
	do{
		system("cls");
		menu();
		cout << "Nhap chuc nang:";
		cin >> n;
		switch (n){
		case 1:
			cin.ignore();
			cout << "Nhap ten file : ";
			cin.getline(tenfile, MAXE);
			if (DocFile(ht,tenfile) == true)
			{
				cout << "Doc file thanh cong.\n";
				Xuat(ht);
			}
			else
				cout << "Ko doc dc file.\n";
			system("pause");
			break;
		case 2:
			cin.ignore();
			cout << "Nhap So Dinh : ";
			cin >> ht.count;
			Init(ht);
			for (int i = 0; i < ht.count; i++){
				while (1)
				{
					do{
						cout << "\n\nDinh "<<i<<" noi voi dinh :  ";
						cin >> a;
						cout << "Nhan -99 de thoat !";
						if (a >= ht.count)
							cout << "Nhap sai!\n";
					} while (a >= ht.count);
					if (a == -99)
						break;
					NodeVertexPointer p;
					p = new NodeVertex;
					p->ver = a;
					p->link = NULL;
					if (ht.ds[i] == NULL) ht.ds[i] = p;
					else {
						NodeVertexPointer t = ht.ds[i];
						do {
							if (t->ver == p->ver)
							{
								cout << "\nTrung gia tri!\n";
								break;
							}
							else if (t->link == NULL) break;
							else t = t->link;
						} while (1);
						if (t->ver!=p->ver)
							t->link = p;
					}
				}
			}
			cout << "\nNhap ten file : ";
			cin.ignore();
			cin.getline(tenfile, MAXE);
			if (GhiFile(ht, tenfile) == true)
			{
				cout << "Ghi file thanh cong.\n";
				Xuat(ht);
			}
			else
				cout << "Ko ghi dc file.\n";
			system("pause");
			break;
		case 3:
			Dispose(ht);
			Xuat(ht);
			system("pause");
			break;
		case 4:
			Xuat(ht);
			cout << "Nhap u va v:";
			cin >> u >> v;
			if (KiemTraCanh(ht, u, v) == false){
				cout << "No.\n";		
			}
			else
			{
				cout << "Yes.\n";
			}
			system("pause");
			break;
		case 5:
			Xuat(ht);
			cout << "Nhap dinh : ";
			cin >> u;
			cout << "Bac cua dinh " << u << " la : " << TinhBacRa(ht, u) + TinhBacVao(ht, u) << endl;
			system("pause");
			break;
		case 6:
			Xuat(ht);
			cout << "Nhap dinh : ";
			cin >> u;
			cout << "Bac Ra cua dinh " << u << " la : " << TinhBacRa(ht, u)<<endl;
			system("pause");
			break;
		case 7:
			Xuat(ht);
			cout << "Nhap dinh : ";
			cin >> u;
			cout << "Bac Vao cua dinh " << u << " la : " << TinhBacVao(ht, u) << endl;
			system("pause");
			break;
		case 8:
			x.count = 0;
			TapCanhDoThi(ht, x);
			Xuat(ht);
			cout << "\nKet Qua : \n";
			InTapCanh(x);
			cout << endl;
			system("pause");
			break;
		case 9:
			x.count = 0;
			TapCanhDoThiVoHuong(ht, x);
			Xuat(ht);
			cout << "\nKet Qua : \n";
			InTapCanh(x);
			system("pause");
			break;
		case 10:
			do{
				cout << "Nhap so dinh:";
				cin >> ht.count;
			} while (ht.count < 1);
			//Khoi tao DS ke
			Init(ht);
			do{
				cout << "Nhap so canh:";
				cin >> x.count;
				if (x.count<1 || x.count>(ht.count*(ht.count - 1)))
					cout << "Nhap sai.Xin nhap lai tu 1 => " << ht.count*(ht.count - 1) << endl;
			} while (x.count<1 || x.count>(ht.count*(ht.count - 1)));
			for (int j = 0; j < x.count; j++)
			{
				do{
					cout << "Canh " << j + 1 << " : \n";
					cin >> x.ds[j].org;
					cin >> x.ds[j].des;
					if (x.ds[j].org<0 || x.ds[j].org>=ht.count || x.ds[j].des<0 || x.ds[j].des>=ht.count || x.ds[j].org == x.ds[j].des)
						cout << "Nhap sai.Xin nhap lai!\n";
				} while (x.ds[j].org<0 || x.ds[j].org >= ht.count || x.ds[j].des<0 || x.ds[j].des >= ht.count || x.ds[j].org == x.ds[j].des); 
			}
			BienDoiTapCanhCoHuongThanhDSKe(ht,x);
			cout << "DANH SACH KE:\n";
			Xuat(ht);
			system("pause");
			break;
		case 11:
			do{
				cout << "Nhap so dinh:";
				cin >> ht.count;
			} while (ht.count < 1);
			//Khoi tao DS ke
			Init(ht);
			do{
				cout << "Nhap so canh:";
				cin >> x.count;
				if (x.count<1 || x.count>(ht.count*(ht.count - 1)))
					cout << "Nhap sai.Xin nhap lai tu 1 => " << ht.count*(ht.count - 1) << endl;
			} while (x.count<1 || x.count>(ht.count*(ht.count - 1)));
			for (int j = 0; j < x.count; j++)
			{
				do{
				cout << "Canh " << j + 1 << " : \n";
				cin >> x.ds[j].org;
				cin >> x.ds[j].des;
					if (x.ds[j].org<0 || x.ds[j].org>=ht.count || x.ds[j].des<0 || x.ds[j].des>=ht.count || x.ds[j].org == x.ds[j].des)
				cout << "Nhap sai.Xin nhap lai!\n";
				} while (x.ds[j].org<0 || x.ds[j].org>=ht.count || x.ds[j].des<0 || x.ds[j].des>=ht.count || x.ds[j].org == x.ds[j].des);
			}
			BienDoiTapCanhVoHuongThanhDSKe(ht, x);
			cout << "DANH SACH KE:\n";
			Xuat(ht);
			system("pause");
			break;
		case 12:
			Xuat(ht);
			DoiHuongDTCoHuong(ht);
			cout << "DS KE DA DOI HUONG: \n";
			Xuat(ht);
			system("pause");
			break;
		case 13:
			Xuat(ht);
			cout << "Nhap Dinh startV : ";
			cin >> startV;
			BFS_Queue(ht,startV);
			system("pause");
			break;
		case 14:
			Xuat(ht);
			for (int i = 0; i < ht.count; i++)
			{
				BFS_Queue(ht,i);
			}
			system("pause");
			break;
		case 15:
			Xuat(ht);
			av.count = 0;
			ae.count = 0;
			cout << "Nhap Dinh Start V : ";
			cin >> startV;
			BFS_TapDinhVaCanhViengTham(ht,startV,av,ae);
			cout << "DS Dinh av : ";
			InDinh(av);
			cout << "\nDS Canh ae : \n";
			InTapCanh(ae);
			system("pause");
			break;
		case 16:
			Xuat(ht);
			for (int i = 0; i < ht.count; i++)
			{
				av.count = 0;
				ae.count = 0;
				cout << "---Dinh " << i << "---";
				BFS_TapDinhVaCanhViengTham(ht, i, av, ae);
				cout << "\nDS Dinh av : ";
				InDinh(av);
				cout << "\nDS Canh ae : \n";
				InTapCanh(ae);
				cout <<"\n\n";
			}
			system("pause");
			break;
		case 17:
			Xuat(ht);
			KQ.count = 0;
			cout << "Nhap Dinh startV : ";
			cin >> startV;
			cout << "Depth first Search starting from vertex ";
			cout << startV << " : ";
			DFS_Stack(ht, startV,KQ);
			InDinh(KQ);
			system("pause");
			break;
		case 18:
			Xuat(ht);
			for (int i = 0; i < ht.count; i++){
				KQ.count = 0;
				cout << "Depth first Search starting from vertex ";
				cout << i << " : ";
				DFS_Stack(ht, i, KQ);
				InDinh(KQ);
				cout << endl;
			}
			system("pause");
			break;
		case 19:
			Xuat(ht);
			av.count = 0;
			ae.count = 0;
			cout << "Nhap Dinh Start V : ";
			cin >> startV;
			DFS_TapDinhVaCanhViengTham(ht, startV, av, ae);
			cout << "DS Dinh av : ";
			InDinh(av);
			cout << "\nDS Canh ae : \n";
			InTapCanh(ae);
			system("pause");
			break;
		case 20:
			Xuat(ht);
			for (int i = 0; i < ht.count; i++)
			{
				av.count = 0;
				ae.count = 0;
				cout << "---Dinh " << i << "---";
				DFS_TapDinhVaCanhViengTham(ht,i,av,ae);
				cout << "\nDS Dinh av : ";
				InDinh(av);
				cout << "\nDS Canh ae : \n";
				InTapCanh(ae);
				cout << "\n\n";
			}
			system("pause");
			break;
		case 21:
			Xuat(ht);
			cout << "So thanh phan lien thong cua do thi la " << SoThanhPhanLienThong(ht)<<endl;
			system("pause");
			break;
		case 22:
			Xuat(ht);
			if (SoThanhPhanLienThong(ht) == 1 && KTLienThongManh(ht) == true)
				cout << "\n\nYes.\n\n";
			else
				cout << "\nNo.\n\n";
			system("pause");
			break;
		case 23:
			Xuat(ht);
			Topo.count = 0;
			if (TOPO(ht, Topo) == true)
			{
				cout << "Sap Xep Topo : ";
				InDinh(Topo);
				cout << endl;
			}
			else
				cout << "Do thi co it nhat 1 chu trinh.\n";
			system("pause");
			break;
		default:
			break;
		}
	} while (n!=0);
}