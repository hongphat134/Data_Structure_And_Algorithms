#include "iostream"
using namespace std;
#define MAX 100

typedef int TYPEINFO;

struct HangUuTien
{
	TYPEINFO list[MAX];
	TYPEINFO count;
};

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

bool IsEmpty(HangUuTien x)
{
	return x.count == 0;
}

bool IsFull(HangUuTien x)
{
	return x.count == MAX - 1;
}

void AdjustedTreeOrderDepartmentHeapToRoot(HangUuTien &x, int vtcon)
{
	//So sanh khoa cha va khoa con
	if (x.list[(vtcon-1)/2] > x.list[vtcon])
	{
		swap(x.list[(vtcon - 1) / 2], x.list[vtcon]);
		//Thay doi gt Vi Tri Con de tiep tuc kiem tra
		vtcon = (vtcon - 1) / 2;
		if (vtcon > 0)  AdjustedTreeOrderDepartmentHeapToRoot(x, vtcon);
	}	
}

void AdjustedTreeOrderDepartmentRootToHeap(HangUuTien &x,int vt)
{
	//Co it nhat 1 con
	if ((vt * 2) + 1 < x.count)
	{
		//Co 2 con
		if ((vt * 2) + 2 < x.count)
		{
			//Tim Vi Tri gia tri nho nhat giua 2 con
			int Min = x.list[(vt * 2) + 1] < x.list[(vt * 2) + 2] ? (vt * 2) + 1 : (vt * 2) + 2;

			if (x.list[Min] < x.list[vt])
			{
				swap(x.list[Min], x.list[vt]);
				vt = Min;
			}
		}

		//Co 1 con
		else
		{
			if (x.list[(vt * 2) + 1] < x.list[vt])
			{
				swap(x.list[(vt * 2) + 1], x.list[vt]);
				vt = (vt * 2) + 1;
			}

		}
		AdjustedTreeOrderDepartmentRootToHeap(x, vt);
	}	
	//Ko co con nao thi thoat ham
	return;
}

void Insert(HangUuTien &x, TYPEINFO a)
{
	if (!IsFull(x))
	{
		x.list[x.count++] = a;
		int vtcon = x.count - 1;
		AdjustedTreeOrderDepartmentHeapToRoot(x, vtcon);
	}
}

void Delete(HangUuTien &x)
{
	if (!IsEmpty(x))
	{
		x.list[0] = x.list[x.count - 1];
		x.count--;
		AdjustedTreeOrderDepartmentRootToHeap(x, 0);		
	}
}

void Output(HangUuTien x)
{
	for (int i = 0; i < x.count ; i++)
	{
		cout << x.list[i] << "\t";
	}
}

int main()
{
	HangUuTien ds;
	ds.count = 9;
	ds.list[0] = 4; ds.list[1] = 6; ds.list[2] = 13; ds.list[3] = 9; ds.list[4] = 7; ds.list[5] = 15; ds.list[6] = 14; ds.list[7] = 12; ds.list[8] = 10;

	//Insert(ds, 1);

	//Delete(ds);

	Output(ds);

	return 0;
}