/*
Author: Quan
Description: hill climbing search with tree & stack
*/

#include <stdio.h>
#include <stdlib.h>

struct Tree{
	int value;
	struct Tree *left;
	struct Tree *right;
};

struct Node{
	Tree *Data;
	Node *Next;
};

struct Stack{
	Node *Top;
};

Tree *MakeTree(int value){
	Tree *p = (Tree*)malloc(sizeof(Tree));
	p->value= value;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void Init(Stack &S){
	S.Top = NULL;
}

Node *MakeNode(Tree *data){
	Node *p = (Node*)malloc(sizeof(Node));
	p->Next = NULL;
	p->Data = data;
	return p;
}

void Push(Stack &S, Tree *item){
	Node *p = MakeNode(item);
	p->Next = S.Top;
	S.Top = p;
}

Tree *Pop(Stack &S){
	Tree *x = S.Top->Data;
	S.Top = S.Top->Next;
	return x;
}

//Them va sap xep phan tu vao L
void PushL(Stack &S, Tree *T){
	if(T->left!=NULL && T->right!=NULL){
		if(T->left->value>T->right->value){
			Push(S, T->left);
			Push(S, T->right);
		}
		else{
			Push(S, T->right);
			Push(S, T->left);
		}
	}else{
		if(T->left!=NULL){
			Push(S, T->left);
		}
		
		if(T->right!=NULL){
			Push(S, T->right);
		}
	}
}

// Tim kiem leo doi
struct Tree *hill_climbing_search(Stack &S, int value){
	
	// dung neu khong tim thay
	if(S.Top==NULL){
		return NULL;
	}
	
	// Lay phan tu dau tien trong danh sach L
	struct Tree *x = Pop(S);
	
	printf("%d\t", x->value);
	
	// tra ve tree neu tim thay
	if(x->value==value){
		return x;
	}
	
	// Them phan tu vao L neu chua tim thay
	PushL(S, x);
	
	// tiep tuc tim kiem
	return hill_climbing_search(S, value);
}

int main(){
	struct Stack L;
	
	// Khoi tao du lieu 
	struct Tree *T = MakeTree(12);
	T->left = MakeTree(1);
	T->right = MakeTree(2);
	
	T->left->left = MakeTree(3);
	T->left->right = MakeTree(2);
	T->left->right->left = MakeTree(0);
	T->left->right->right = MakeTree(6);
	T->right->right = MakeTree(3);
	T->right->right->right = MakeTree(0);
	
	// Them phan tu dau tien vao L
	Push(L, T);
	
	printf("Qua trinh tim kiem\n");
	Tree *search = hill_climbing_search(L, 0);
	printf("\nKet Thuc qua trinh tim kiem\n");
//	PushMin(S, T);
//	if(search!=NULL){
		printf("%d\t", search->value);
//	}
//	
//	printf("%d\t", Pop(S)->value);
//	printf("%d", Pop(S)->value);
	return 0;
}
