#include "iostream"

#define ORDER 5
#define MAX ORDER-1
#define MIN ORDER/2
typedef struct tagNODE
{
	int NumTree;
	int Key[ORDER - 1];
	tagNODE* Branch[ORDER];
}NODE, *NODEPTR, *BTREE;

tagNODE* create_node(int value)
{
	tagNODE* node = new tagNODE;
	node->NumTree = 2;
	node->Key[0] = value;
	for (int i = 0; i <= MAX; i++)
		node->Branch[i] = NULL;
	return node;
}

void TinhTien(BTREE &btree, int vt)
{
	for (int i = btree->NumTree - 2; i >= vt; i--)
	{
		//Tinh tien cac gia tri
		btree->Key[i + 1] = btree->Key[i];
	}
	for (int i = btree->NumTree - 1; i >= vt; i--){
		//Tinh tien cac nhanh'
		btree->Branch[i + 1] = btree->Branch[i];
	}
}

NODEPTR Insert(BTREE &btree, NODEPTR father, int value)
{
	if (btree == NULL) btree = create_node(value);
	else{
		int vitri = -999;
		for (int i = 0; i < btree->NumTree - 1; i++)
		{
			if (value < btree->Key[i]){
				vitri = i; break;
			}
		}
		if (vitri == -999) vitri = btree->NumTree - 1;
		NODEPTR returnNode = NULL;
		bool flag = false;
		if (btree->Branch[vitri] != NULL){
			returnNode = Insert(btree->Branch[vitri], btree, value);
			flag = true;
			if (returnNode != NULL){
				value = returnNode->Key[0];
				vitri = -999;
				for (int i = 0; i < btree->NumTree - 1; i++)
				{
					if (value < btree->Key[i]){
						vitri = i; break;
					}
				}
				if (vitri == -999) vitri = btree->NumTree - 1;

				//Bien doi returnNode
				returnNode->Key[0] = returnNode->Key[1];
				returnNode->Key[1] = returnNode->Key[2];
			}
		}
		if (returnNode != NULL || !flag){
			if (btree->NumTree <= MAX){
				if (vitri != btree->NumTree - 1)TinhTien(btree, vitri);
				if (returnNode != NULL){
					if (vitri == 0)	btree->Branch[0] = btree->Branch[1];
					btree->Branch[vitri + 1] = returnNode;
				}
				btree->Key[vitri] = value;
				btree->NumTree++;
				return NULL;
			}
			else{
				//Tach Node
				NODEPTR newNode;
				int saveValue;
				if (vitri == 0){
					saveValue = btree->Key[1];
					btree->Key[1] = btree->Key[0];
					btree->Key[vitri] = value;
				}
				else if (vitri == 1)
				{
					saveValue = btree->Key[1];
					btree->Key[vitri] = value;
				}
				else if (vitri == 2) saveValue = value;
				else if (vitri == 3){
					saveValue = btree->Key[2];
					btree->Key[2] = value;
				}
				else if (vitri == 4){
					saveValue = btree->Key[2];
					btree->Key[2] = btree->Key[3];
					btree->Key[3] = value;
				}
				btree->NumTree = 3;
				if (father == NULL) {
					newNode = create_node(btree->Key[2]);
					newNode->Key[1] = btree->Key[3];
					newNode->NumTree = 3;
					if (vitri == 2 || vitri == 3){
						//newNode->Branch[0] = btree->Branch[2];
						//newNode->Branch[2] = btree->Branch[4];
					}
					else if (vitri == 4){
						newNode->Branch[0] = btree->Branch[3];
						newNode->Branch[1] = btree->Branch[4];
					}
					else if (vitri == 1){
						newNode->Branch[0] = btree->Branch[2];
						newNode->Branch[1] = btree->Branch[3];
						newNode->Branch[2] = btree->Branch[4];
					}
					else if (vitri == 0)
					{
						newNode->Branch[0] = btree->Branch[2];
						newNode->Branch[1] = btree->Branch[3];
						newNode->Branch[2] = btree->Branch[4];
					}
					if (returnNode != NULL){
						//BUG
						if (vitri < MIN){
							btree->Branch[vitri + 1] = returnNode;
						}
						else{
							newNode->Branch[vitri - MIN] = returnNode;
						}
					}
					NODEPTR fatherNode = create_node(saveValue);
					//Tinh tien lai newNode
					fatherNode->Branch[0] = btree;
					fatherNode->Branch[1] = newNode;
					btree = fatherNode;
					return NULL;
				}
				else{
					newNode = create_node(saveValue);
					newNode->NumTree = 3;
					newNode->Key[1] = btree->Key[2];
					newNode->Key[2] = btree->Key[3];
					if (vitri == 2){
						if (returnNode != NULL)	newNode->Branch[0] = returnNode; //returnNode => 60 65
						newNode->Branch[1] = btree->Branch[3];
						newNode->Branch[2] = btree->Branch[4];
						//btree->Branch[2] = NULL;
					}
					else if (vitri == 3){
						newNode->Branch[1] = btree->Branch[3];
						newNode->Branch[2] = btree->Branch[4];
						if (returnNode != NULL)btree->Branch[2] = returnNode;
					}
					else if (vitri == 4){
						newNode->Branch[0] = btree->Branch[3];
						newNode->Branch[1] = btree->Branch[4];
						if (returnNode != NULL) newNode->Branch[2] = returnNode;
					}
					else if (vitri == 1){
						newNode->Branch[1] = btree->Branch[3];
						newNode->Branch[2] = btree->Branch[4];
						if (returnNode != NULL)btree->Branch[2] = returnNode;

					}
					else if (vitri == 0){
						newNode->Branch[1] = btree->Branch[3];
						newNode->Branch[2] = btree->Branch[4];
						btree->Branch[2] = btree->Branch[1];
						btree->Branch[0] = NULL;
						if (returnNode != NULL)btree->Branch[1] = returnNode;
					}
					return newNode;
				}
			}
		}
	}
	return NULL;
}





void Output(BTREE btree)
{
	if (btree != NULL)
	{
		for (int i = 0; i <= btree->NumTree - 1; i++){
			Output(btree->Branch[i]);
			if (i != btree->NumTree - 1) std::cout << btree->Key[i] << " ";
		}
	}
}
void clear(BTREE &btree)
{
	if (btree != NULL)
	{
		//clear cac nhanh trc
		for (int i = 0; i <= btree->NumTree - 1; i++)
			clear(btree->Branch[i]);
		delete btree;
	}
}

//int main(){
//	/*
//	BTREE root = NULL;
//	int value;
//	do
//	{
//
//	cout << "\nNhap gia tri: "; cin >> value;
//	if (value == -99) break;
//	Insert(root,NULL,value);
//	Output(root);
//
//	} while (1);
//
//	clear(root);*/
//	return 0;
//
//}