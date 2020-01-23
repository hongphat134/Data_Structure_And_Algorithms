#include "iostream"
using namespace std;
#pragma warning (disable:4715)
typedef int TYPEINFO;
struct NODE
{
	TYPEINFO info;
	NODE* left;
	NODE* right;
};
typedef NODE* BST;


BST create_node(TYPEINFO x);
void InitBST(BST& r);
void InitNodeBST(BST& r);
void PreOrder(BST r);
void InOrder(BST r);
void PostOrder(BST r);
TYPEINFO MucCuaCay(BST r, TYPEINFO a);
void DoCaoCuaCay(BST r,TYPEINFO &heigh);
TYPEINFO DoCaoCuaNut(BST r,TYPEINFO a);
void Insert_Tree(BST &r, TYPEINFO x);
BST Insert(BST& r, TYPEINFO a);
BST Find(BST r, TYPEINFO a);
int Remove(BST& r, TYPEINFO a);
void Remove(BST& r);
void InPut(BST &r);
int Read(BST& r, char* filename);
int Write(BST r, char* filename);
TYPEINFO DoCaoCuacay(BST r);
TYPEINFO Dem_SoNut(BST r);
TYPEINFO Dem_NutLa(BST r);
TYPEINFO Dem_NutTrungGian(BST r);
//-------------------------------------------------------------------
void main()
{
	BST Tree;
	InitBST(Tree);
	InPut(Tree);
	InOrder(Tree);
	cout << "\nSo nut : " << Dem_NutTrungGian(Tree)-1;
	cout << "\nDa xoa  vung nho.\n";
	Remove(Tree);
}
//--------------------------------------------------------------------
void InitBST(BST& r){
	r = NULL;
}
BST create_node(TYPEINFO x)
{
	BST p;
	p = new NODE;
	p->info = x;
	p->left = p->right = NULL;
	return p;
}
void InPut(BST &r)
{
	TYPEINFO x;
	while (1){
		cout << "Nhap x : ";
		cin >> x;
		if (x == -99) break;
		Insert_Tree(r, x);
	}
}
void InitNodeBST(BST& r){
	r = new NODE;
	r->left = r->right = NULL;
}
void PreOrder(BST r){
	if (r != NULL){
		cout << r->info << "\t";
		PreOrder(r->left);
		PreOrder(r->right);
	}
}
TYPEINFO MucCuaCay(BST r, TYPEINFO a){
	TYPEINFO Dem = 0;
	while (r != NULL){
		if (a < r->info){
			Dem++;
			r = r->left;
		}
		else if (a>r->info){
			r = r->right;
			Dem++;
		}
		//Trường hợp a = r->info
		else break;
	}
	if (r == NULL)
		return -1;
	else
		return Dem;
}
void InOrder(BST r){
	if (r != NULL){
		InOrder(r->left);
		cout << r->info << "\t";
		InOrder(r->right);
	}
}
void PostOrder(BST r){
	if (r != NULL){
		PostOrder(r->left);
		PostOrder(r->right);
		cout << r->info << "\t";
	}
}
void Remove(BST& r){
	BST p;
	if (r != NULL){
		p = r;
		Remove(r->left);
		Remove(r->right);
		r = NULL;
		delete p;
	}
}
BST Find(BST r, TYPEINFO a){
	if (r != NULL){
		if (r->info == a)
			return r;
		else if (a < r->info) Find(r->left, a);
		else if (a > r->info) Find(r->right, a);
	}
	else return NULL;
}
BST Insert(BST& r, TYPEINFO a){
	if (r == NULL){
		BST p = create_node(a);
		r = p;
		return r;
	}
	else{
		if (a < r->info) Insert(r->left, a);
		else if (a>r->info) Insert(r->right, a);
		else return NULL;
	}
}
void DoCaoCuaCay(BST r, TYPEINFO &heigh){
	if (r == NULL) return;
	if (r->left != NULL&&r->right != NULL){
		TYPEINFO a = 0, b = 0;
		DoCaoCuaCay(r->left,a);
		DoCaoCuaCay(r->right,b);
		if (a > b)
			heigh = a;
		else
			heigh = b;
	}
	else if (r->left != NULL&&r->right == NULL){
		DoCaoCuaCay(r->left, heigh);
	}
	else if (r->right != NULL&&r->left == NULL){
		DoCaoCuaCay(r->right, heigh);
	}
	else return;
	heigh++;
}
TYPEINFO DoCaoCuacay(BST r){
	if (r == NULL) return -1;
	if (r->left != NULL&&r->right != NULL){
		if (DoCaoCuacay(r->left) > DoCaoCuacay(r->right))
			return DoCaoCuacay(r->left) + 1;
		else
			return DoCaoCuacay(r->right) + 1;
	}
	else if (r->left != NULL&&r->right == NULL){
		return DoCaoCuacay(r->left) + 1;
	}
	else if (r->right != NULL&&r->left == NULL){
		return DoCaoCuacay(r->right) + 1;
	}
	else return 0;
}
TYPEINFO DoCaoCuaNut(BST r,TYPEINFO a){
	TYPEINFO heigh=0;
	//Di chuyển trỏ r đến node giá trị = a
	while (r != NULL){
		if (r->info < a)
			r = r->right;
		else if (r->info>a)
			r = r->left;
		else break;
	}
	if (r == NULL)
		return -1;
	else{
		heigh=DoCaoCuacay(r);
		return heigh;
	}
}
int Remove(BST& r, TYPEINFO a){
	BST q, p;
	if (r == NULL)
		return 0;
	else{
		if (a < r->info) Remove(r->left, a);
		else{
			if (a>r->info) Remove(r->right, a);
			else{
				//Trường hợp 1 con
				q = r;
				if (q->right == NULL) r = r->left;
				else{
					if (q->left == NULL) r = r->right;
					else{ //Trường hợp 2 con
						for (p = q->left; p->right; p = p->right);
						p->right = q->right;
						//Lấy gt min ở nhánh trái thay thế cho q
						r = q->left;
					}
				}
				delete q;
				return 1;
			}
		}
	}
}
void Insert_Tree(BST &r, TYPEINFO x)
{
	if (r == NULL){
		BST p = create_node(x);
		r = p;
	}
	else
	{
		if (x < r->info) Insert_Tree(r->left, x);
		else if (x>r->info) Insert_Tree(r->right, x);
	}
}
int Read(BST& r, char* filename)
{
	FILE *f;
	TYPEINFO point;
	fopen_s(&f, filename, "rt");
	if (f == NULL) return 0;
	while (1){
		point = 0;
		fscanf_s(f, "%d", &point);
		if (!point)
			break;
		Insert_Tree(r, point);
	}
	fclose(f);
	return 1;
}
int Write(BST r, char* filename)
{
	FILE *f;
	fopen_s(&f, filename, "wt");
	if (f == NULL) return 0;
	fprintf_s(f, "%d ", r->info);
	BST q = r->left;
	BST s;
	while (q != NULL){
		fprintf_s(f, "%d ", q->info);
		s = q->right;
		while (s != NULL){
			fprintf_s(f, "%d ", s->info);
			s = s->right;
		}
		q = q->left;
	}
	BST z = r->right;
	while (z != NULL){
		fprintf_s(f, "%d ", z->info);
		s = z->left;
		while (s != NULL){
			fprintf_s(f, "%d ", s->info);
			s = s->left;
		}
		z = z->right;
	}
	fclose(f);
	return 1;
}
TYPEINFO Dem_SoNut(BST r){
	if (r->left != NULL&&r->right != NULL){
		return Dem_SoNut(r->left) + Dem_SoNut(r->right)+1;
	}
	else if (r->left != NULL && r->right == NULL){
		return Dem_SoNut(r->left) + 1;
	}
	else if (r->right != NULL && r->left == NULL){
		return Dem_SoNut(r->right) + 1;
	}
	else return 1;
}
TYPEINFO Dem_NutLa(BST r){
	if (r->left != NULL&&r->right != NULL)
		return Dem_NutLa(r->left) + Dem_NutLa(r->right);
	else if (r->left != NULL && r->right == NULL)
		return Dem_NutLa(r->left);
	else if (r->right != NULL && r->left == NULL)
		return Dem_NutLa(r->right);
	else return 1;
}
TYPEINFO Dem_NutTrungGian(BST r){
	//Trường hợp có cả 2 con
	if (r->left != NULL&&r->right != NULL)
		return Dem_NutTrungGian(r->left) + Dem_NutTrungGian(r->right)+1;
	//Trường hợp có 1 con trái
	else if (r->left != NULL && r->right == NULL)
		return Dem_NutTrungGian(r->left)+1;
	//Trường hợp có 1 con phải
	else if (r->right != NULL && r->left == NULL)
		return Dem_NutTrungGian(r->right)+1;
	else return 0;
}