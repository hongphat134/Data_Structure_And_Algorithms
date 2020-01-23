#include "iostream"
using namespace std;
typedef int TYPEINFO;
struct NODE {
	TYPEINFO info;
	NODE* left;
	NODE* right;
	int height;
};
typedef NODE* NODEPTR;
void initialize(NODEPTR &r){
	r = NULL;
}
int Empty(NODEPTR r){
	return r == NULL ? 1 : 0;
}
NODEPTR create_node(int x){
	NODEPTR p = new NODE;
	p->info = x;
	p->height = 0;
	p->left = NULL;
	p->right = NULL;
	return p;
}
TYPEINFO DoCaoCuacay(NODEPTR r){
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
int Height(NODEPTR r){
	return Empty(r)?-99:(-DoCaoCuacay(r->left) + DoCaoCuacay(r->right));
}
void Output(NODEPTR r){
	if (r != NULL){
		cout << r->info << " (" << r->height << ")\t";
		Output(r->left);
		Output(r->right);
	}
}
void insert_Tree(NODEPTR &r, TYPEINFO x){
	if (r == NULL){
		NODEPTR p = create_node(x);
		r = p;
	} 
	else
	{
		if (x < r->info)
			insert_Tree(r->left, x);
		else if (x>r->info)
			insert_Tree(r->right, x);
		r->height = Height(r);
	}
}
void RotateRightLeft(NODEPTR& r){
	NODEPTR s = r->right;
	NODEPTR p = s->left;
	r->right = p->left;
	p->left = r;
	s->left = p->right;
	p->right = s;
	switch (p->height){
	case 1:
		r->height = -1;
		s->height = 0;
		break;
	case 0:
		r->height = 0;
		s->height = 0;
		break;
	case -1:
		s->height = 1;
		r->height = 0;
		break;
	}
	p->height = 0;
	r = p;
}
void RotateLeftRight(NODEPTR& r){
	NODEPTR s = r->left;
	NODEPTR p = s->right;
	r->left = p->right;
	p->right = r;
	s->right = p->left;
	p->left= s;
	switch (p->height){
	case -1:
		r->height = 1;
		s->height = 0;
		break;
	case 0:
		r->height = 0;
		s->height = 0;
		break;
	case 1:
		s->height = -1;
		r->height = 0;
		break;
	}
	p->height = 0;
	r = p;
}
void remove(NODEPTR& r){
	//NODEPTR p;
	if (r != NULL){
		//p = r;
		remove(r->left);
		remove(r->right);
		//r = NULL;
		delete r;
	}
}
void RotateLeft(NODEPTR& r){
	NODEPTR s = r->left;
	r->left = s->right;
	s->right = r;
	switch (s->height){
	case -1:
		s->height = 0;
		r->height = 0;
		break;
	case 0:
		s->height = 1;
		r->height = -1;
		break; 
	}
	r = s;
}
void RotateRight(NODEPTR& r){
	NODEPTR s = r->right;
	r->right = s->left;
	s->left = r;
	switch (s->height){
	case 1:
		s->height = 0;
		r->height = 0;
		break;
	case 0: 
		s->height = -1;
		r->height = 1;
		break;
	}
	r = s;
}
void CanBang_Trai(NODEPTR &r){
	switch (r->left->height){
	case -1:
		RotateLeft(r);
		break;
	case 0:
		RotateLeft(r);
		break;
	case 1:
		RotateLeftRight(r);
		break;
	}
}
void CanBang_Phai(NODEPTR &r){
	switch (r->right->height){
	case -1:
		RotateRightLeft(r);
		break;
	case 0:
		RotateRight(r);
		break;
	case 1:
		RotateRight(r);
		break;
	}
}
NODEPTR Insert(NODEPTR& r, TYPEINFO a){
	if (r == NULL){
		NODEPTR p = create_node(a);
		r = p;
		return p;
	}
	else{
		if (a < r->info){	
			NODEPTR s=Insert(r->left, a);
			if (s == NULL) return NULL;
			switch (r->height){
			case 1: r->height = 0;
				return NULL;
			case 0: r->height = -1;
				return s;
			case -1: 	
				CanBang_Trai(r);
				return NULL;
			}
		}
		else if (a>r->info){
			NODEPTR s=Insert(r->right, a);
			if (s == NULL) return NULL;
			switch (r->height){
			case -1: r->height = 0;
				return NULL;
			case 0: r->height = 1;
				return s;
			case 1: CanBang_Phai(r);
				return NULL;
			}
		}
		else return NULL;
	}
}
int searchStandFor(NODEPTR &p,NODEPTR &q)
{
	int giatritrave;
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
		return 2;
	}
	else //chưa tìm được phần tử trái nhất
	{
		giatritrave = searchStandFor(p, q->left);
		if (giatritrave < 2) return giatritrave;
		switch (q->height)
		{
		case -1: q->height = 0;
			return 2;
		case 0: q->height = 1;
			return 1;
		case 1: CanBang_Phai(q);
			return 2;
		}
	}
}
int Remove(NODEPTR& r, TYPEINFO a){
	int giatritrave;
	if (r == NULL)
		return 0;
	if (r->info > a){
		giatritrave = Remove(r->left, a);
		if (giatritrave < 2)
			return giatritrave;
		switch (r->height){
		case -1: r->height = 0;
			return 2;
		case 0: r->height = 1;
			return 1;
		case 1: CanBang_Phai(r);
			return 2;
		}
	}
	else if (r->info < a){
		giatritrave = Remove(r->right, a);
		if (giatritrave < 2)
			return giatritrave;
		switch (r->height){
		case 1: r->height = 0;
			return 2;
		case 0: r->height = -1;
			return 1;
		case -1: CanBang_Trai(r);
			return 2;
		}
	}
	else{
		NODEPTR p = r;
		if (r->left == NULL){
			r = r->right; giatritrave = 2;
		}
		else if (r->right == NULL)
		{
			r = r->left; giatritrave = 2;
		}
		else
		{
			giatritrave = searchStandFor(p, r->right);
			if (giatritrave < 2) return giatritrave;
			switch (r->height)
			{
			case 1: r->height = 0;
				return 2;
			case 0: r->height = -1;
				return 1;
			case -1: CanBang_Trai(r);
				return 2;
			}
		}
		delete p;
		return giatritrave;
	}
}
void Input(NODEPTR &r){
	TYPEINFO x; NODEPTR p;
	while (true){
		cout << "\nNhap phan tu mun chen : "; cin >> x;
		if (x == -99) break;
		p=Insert(r, x);
		cout << "\nDS : ";
		Output(r);
	}
	cout << "\n\n\n";
}
void Delele(NODEPTR &r){
	TYPEINFO a,x;
	while(true){
		cout << "\nNhap phan tu mun xoa : "; cin >> x;
		if (x == -99) break;
		a = Remove(r, x);
		if (a == 0) cout << "\nNo Exist !";
		else if (a == 1) cout << "\nHeigh No Change !";
		else
			cout << "\nHeigh Change !";
		cout << "\nDS : ";
		Output(r);
	}
}

int main(){
	NODEPTR AVL;
	initialize(AVL);
	Input(AVL);
	Delele(AVL);
	remove(AVL);
	cout << "\n Clear !";
	return 0;
}