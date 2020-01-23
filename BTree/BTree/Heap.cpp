#include "iostream"
using namespace std;

struct node{
	int data;
	node* left;
	node* right;
};

typedef struct node *heap;

heap Create(int data){
	heap h = new node;
	h->data = data;
	h->left = nullptr; h->right = nullptr;
	return h;
}

void Insert(heap &tree,static int data){
	if (tree == nullptr){
		tree = Create(data);
		return;
	}
	else{
		if (tree->left == nullptr) Insert(tree->left, data);
		else if(tree->right == nullptr) Insert(tree->right, data);
		else{
			Insert(tree->left, data); Insert(tree->right, data);
		}
	}
}

void Print(heap tree){
	if (tree != nullptr){
		cout << tree->data;
		Print(tree->left);
		Print(tree->right);		
	}
}

void Clear(heap &tree){
	if (tree != nullptr){
		Clear(tree->left);
		Clear(tree->right);
		delete tree;
	}
}
int main(){
	heap a = nullptr;
	Insert(a, 5);
	Insert(a, 3);
	Insert(a, 4); Insert(a, 6); Insert(a, 7); Insert(a, 8); Insert(a, 9);
	Print(a);
	Clear(a);
	system("pause");
	return 0;
}