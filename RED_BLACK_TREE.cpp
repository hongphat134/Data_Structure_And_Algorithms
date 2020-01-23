//#include "iostream"
//using namespace std;
//typedef int TYPEINFO;
//struct NODE_RBT{
//	TYPEINFO info;
//	NODE_RBT* left;
//	NODE_RBT* right;
//	NODE_RBT* parent;
//	TYPEINFO color;
//};
//void initialize(NODE_RBT* &r){
//	r = NULL;
//}
//NODE_RBT* create_node(TYPEINFO x){
//	NODE_RBT* p = new NODE_RBT;
//	p->left = p->right = NULL;
//	p->info = x;
//	p->color = 1;
//	return p;
//}
//void Change_Color(int &a, int &b){
//	int temp = a;
//	a = b;
//	b = temp;
//}
//void Search_Root(NODE_RBT* &r){
//	while (r->parent != NULL){
//		r = r->parent;
//	}
//}
//void Left_Left_case(NODE_RBT* r){
//	NODE_RBT* g = r->parent;
//	r->parent = g->parent;
//	if (g->parent != NULL){
//		if (g->parent->info > r->info)
//			g->parent->left = r;
//		else
//			g->parent->right = r;
//	}
//	g->left = r->right;
//	if (r->right!=NULL)
//		r->right->parent = g;
//	r->right = g;
//	g->parent = r;
//	Change_Color(r->color, g->color);
//}
//void Right_Right_case(NODE_RBT* r){
//	NODE_RBT* g = r->parent;
//	r->parent = g->parent;
//	if (g->parent != NULL){
//		if (g->parent->info > r->info)
//			g->parent->left = r;
//		else
//			g->parent->right = r;
//	}
//	g->right = r->left;
//	if (r->left!=NULL)
//		g->right->parent = g;		
//	r->left = g;
//	g->parent = r;
//	Change_Color(r->color, g->color);
//}
//void Left_Right_case(NODE_RBT* r){
//	NODE_RBT* x = r->right;
//	r->right = x->left;
//	x->left = r;
//	x->parent = r->parent;
//	r->parent = x;
//	Left_Left_case(x);
//}
//void Right_Left_case(NODE_RBT* r){
//	NODE_RBT* x = r->left;
//	r->left = x->right;
//	x->right = r;
//	x->parent = r->parent;
//	r->parent = x;
//	Right_Right_case(x);
//}
//void RB_insert_fixup(NODE_RBT* &x){
//	if (x->parent == NULL)
//		x->color = 0;
//	else if (x->parent->color == 1)
//	{
//		NODE_RBT *grand = x->parent->parent;
//		if (grand->right != NULL&&grand->left!=NULL){
//			if (grand->left->color == grand->right->color)
//			{
//				grand->left->color = grand->right->color = 0;
//				grand->color = 1;
//				RB_insert_fixup(grand);
//			}
//			else{
//				if (grand->info<x->parent->info){
//					if (x->parent->info < x->info) Right_Right_case(x->parent);
//					else Right_Left_case(x->parent);
//				}
//				else if (grand->info>x->parent->info){
//					if (x->parent->info>x->info) Left_Left_case(x->parent);
//					else Left_Right_case(x->parent);
//				}
//			}
//		}
//		else{
//			NODE_RBT* p = x->parent;
//			if (grand->info > p->info){
//				if (x->info < p->info)
//					Left_Left_case(p);
//				else
//					Left_Right_case(p);
//			}
//			else{
//				if (x->info>p->info)
//					Right_Right_case(p);
//				else
//					Right_Left_case(p);
//			}
//		}
//	}
//}
//int Insert(NODE_RBT* &T,TYPEINFO a){
//	NODE_RBT* p = NULL; NODE_RBT* z = T;
//	NODE_RBT* x = create_node(a);
//	while (z != NULL){
//		p = z;
//		if (z->info == x->info) return 0;
//		else if (z->info > x->info)
//			z = z->left;
//		else z = z->right;
//	}
//	x->parent = p;
//	if (p == NULL){
//		T = x;
//	}
//	else if (p->info < x->info)
//		p->right = x;
//	else
//		p->left = x;
//	RB_insert_fixup(x);
//	Search_Root(T);
//	return 1;
//}
//NODE_RBT* searchStandFor(NODE_RBT* T,NODE_RBT* p){
//	if (p->right == NULL)
//	{
//		NODE_RBT* children = p->left;
//		NODE_RBT* father = p->parent;
//		if (father->parent!=NULL)
//			father->right = children;
//		else
//			father->left = children;
//		if (children != NULL){
//			children->parent = father;
//		}
//		return p;
//	}
//	return searchStandFor(T, p->right);
//}
//int Delete_Root(NODE_RBT* &T,NODE_RBT* z){
//	if (z->left == NULL&&z->right == NULL)
//		T = NULL;
//	// Chi co 2 node : root va u
//	else if (z->left != NULL && z->right == NULL){
//		T = z->left;
//		T->color = 0;
//		T->parent = NULL;
//	}
//	else if (z->left == NULL&&z->right != NULL){
//		T = z->right;
//		T->color = 0;
//		T->parent = NULL;
//	}
//	//
//	//Root dang xet co' 2 con
//	else{
//		NODE_RBT* Replace = searchStandFor(T, T->left);
//		Replace->left = T->left;
//		Replace->right = T->right;
//		//Bien' de xac dinh node lay la do hay den?
//		int LuuMau = Replace->color;
//		Replace->color = T->color;
//		NODE_RBT* Xet = Replace->parent;
//		Replace->parent = T->parent;
//		if (T->left != NULL)
//			T->left->parent = Replace;
//		if (T->right != NULL)
//			T->right->parent = Replace;
//		T = Replace;
//		//if (Xet != NULL){
//			if (Xet->left != NULL&&Xet->right != NULL){
//				if (Xet->left->color == 1) Xet->left->color = 0;
//			}
//			else{
//				NODE_RBT* p;
//				if (Xet->right != NULL){
//					p = Xet->right;
//					if (p->right != NULL)
//					{
//						if (p->left==NULL||p->left->color)
//							p->right->color = 0;
//						Right_Right_case(p);
//					}
//					else if (p->left != NULL){
//						p->left->color = 0;
//						Right_Left_case(p);
//					}
//					else {
//						if (!LuuMau) p->color = 1;
//					}
//				}
//				else if (Xet->left != NULL){
//					p = Xet->left;
//					if (p->left != NULL){
//						p->left->color = 0;
//						Left_Left_case(p);
//					}
//					else if (p->right != NULL){
//						p->right->color = 0;
//						Left_Right_case(p);
//					}
//					else{
//						if (!LuuMau) p->color = 1;
//					}
//				}
//				else Xet->color = 0;
//				Search_Root(T);
//			}
//		}
//	//	else{
//	//		if (T->left != NULL&&T->right == NULL)
//	//			T->left->color = 1;
//	//		else if (T->right != NULL&&T->left == NULL)
//	//			T->right->color = 1;
//	//	}
//	//}
//	delete z;
//	return 1;
//}
//int Delete(NODE_RBT* &T, TYPEINFO a){
//	 NODE_RBT* u = T;	
//	int color=-1; // 0 la  ben trai , 1 la ben phai
//	while (u!= NULL){
//		if (u->info == a) break;
//		else if (u->info > a){
//			u = u->left;
//			color = 0;
//		}
//		else{
//			u = u->right;
//			color = 1;
//		}
//	}
//	if (u == NULL)
//		return 0;
//	if (color == -1){
//		return Delete_Root(T, u);
//	}
//	if (u->left != NULL&&u->right == NULL){
//		NODE_RBT* v = u->left;
//		v->parent = u->parent;
//		v->color = 0;
//		if (!color) u->parent->left = v;
//		else u->parent->right = v;
//		delete u;
//	}
//	else if (u->right != NULL&&u->left == NULL){
//		NODE_RBT* v = u->right;
//		v->parent = u->parent;
//		v->color = 0;
//		if (!color) u->parent->left = v;
//		else u->parent->right = v;
//		delete u;
//	}
//	else if (u->left == NULL&&u->right == NULL){
//		if (!u->color){
//			NODE_RBT* s;
//			if (!color){
//				s = u->parent->right;
//				u->parent->left = NULL;
//			}
//			else
//			{
//				s = u->parent->left;
//				u->parent->right = NULL;
//			}
//
//
//			if (s->left != NULL&&s->right == NULL){
//				if (!color){
//					Change_Color(s->color, s->left->color);
//					s->color = 0;
//					Right_Left_case(s);
//				}
//				else Left_Left_case(s);
//			}
//			else if (s->right != NULL&&s->left == NULL){
//				if (!color){
//					Right_Right_case(s);
//					s->right->color = 0;
//				}
//				else{
//					Change_Color(s->color, s->right->color);
//					s->color = 0;
//					Left_Right_case(s);
//				}
//			}
//			else if (s->right != NULL&&s->left != NULL){
//				if (!color){
//					Right_Right_case(s);
//					s->left->color = 0;
//				}
//				else Left_Left_case(s);
//			}
//			else{
//				if (s->parent->color == 1) Change_Color(s->color, s->parent->color);
//				else s->color = 1;
//			}
//			delete u;
//		}
//		else{
//			if (!color) u->parent->left = NULL;
//			else u->parent->right = NULL;
//			delete u;
//		}
//	}
//	//Xoa nut la do va den
//	//else if (u->left == NULL&&u->right == NULL){
//	//	//xoa nut la' do
//	//	NODE_RBT* cha = u->parent;
// //		if (u->color == 1){
//	//		if (!color) cha->left = NULL;
//	//		else cha->right = NULL;
//	//		delete u;
//	//	}
//	//	//xoa nut la' den
//	//	else if (u->color == 0){
//	//		if (!color){
//	//			cha->left = NULL;
//	//			NODE_RBT* s = cha->right;
//	//			// s la node anh em cua nut u
//	//			if (s->color == 0){
//	//				//Con cua s
//	//				if (s->right != NULL&&s->left == NULL){
//	//					if (s->right->color == 1){
//	//						Right_Right_case(s);
//	//						s->right->color = 0;
//	//					}
//	//					else if (s->right->color == 0){
//	//						if (cha->color == 1) Change_Color(cha->color, s->color);
//	//					}
//	//				}
//	//				else if (s->left != NULL&&s->right == NULL){
//	//					if (s->left->color == 1){
//	//						Left_Left_case(s);
//	//						s->left->color = 0;
//	//					}
//	//					else if (s->left->color == 0){
//	//						if (cha->color == 1) Change_Color(cha->color, s->color);
//	//					}
//	//				}
//	//				else if (s->left==NULL&&s->right==NULL)
//	//				{
//	//					if (cha->color==1)	Change_Color(cha->color, s->color);
//	//					else if (cha->color == 0) s->color = 1;
//	//					//con` TH cha cua s mau` den
//	//				}
//	//			}
//	//			else if (s->color == 1){
//	//				Change_Color(cha->color, s->color);
//	//				Left_Left_case(s);
//	//				s->right->color = 0;
//	//			}
//	//		}
//	//		else{
//	//			cha->right = NULL;
//	//			NODE_RBT* s = cha->left;
//	//			if (s->color == 0){
//	//				if (s->right != NULL&&s->left == NULL){
//	//					if (s->right->color == 1){
//	//						Right_Right_case(s);
//	//						s->right->color = 0;
//	//					}
//	//					else if (s->right->color == 0){
//	//						if (cha->color == 1) Change_Color(cha->color, s->color);
//	//					}
//	//				}
//	//				else if (s->left != NULL&&s->right == NULL){
//	//					if (s->left->color == 1){
//	//						Left_Left_case(s);
//	//						s->left->color = 0;
//	//					}
//	//				}
//	//				else{
//	//					Change_Color(cha->color, s->color);
//	//				}
//	//			}
//	//			else if (s->color == 1){
//	//				Change_Color(cha->color, s->color);
//	//				Right_Right_case(s);
//	//				s->left->color = 0;
//	//			}
//	//		}
//	//		delete u;
//	//	}
//	//}
//	Search_Root(T);
//	return 1;
//}
//void Output(NODE_RBT* r){
//	if(r != NULL){
//		cout << r->info << " Color : " << r->color << "  Dia chi  : " << r <<"  Dia chi cha : "<<r->parent<< endl;
//		Output(r->left);
//		Output(r->right);
//	}
//}
//void remove(NODE_RBT* &r){
//	if (r != NULL){
//		remove(r->left);
//		remove(r->right);
//		delete r;
//	}
//}
//
//int main(){
//	NODE_RBT* root;
//	root = new NODE_RBT;
//	initialize(root);
//	TYPEINFO x;
//	while (true){
//		cout << "\nNhap x : "; cin >> x;
//		if (x == 0) break;
//		if (!Insert(root, x))
//			cout << "\ninsert FAIL !";
//		else{
//			cout << "\ninsert SUCCESS !";
//			cout << "\nDanh Sach : \n";
//
//			Output(root);
//		}
//	}
//	while (true){
//		cout << "\nNhap x mun xoa : "; cin >> x;
//		if (x == 0) break;
//		if (!Delete(root, x))
//			cout << "\nDelete FAIL ! ";
//		else{
//			cout << "\nDelete SUCCESS ! ";
//			cout << "\nDanh Sach : \n";
//			Output(root);
//		}
//	}
//	remove(root);
//	cout << "\nDa CLEAR !";
//	return 0;
//}