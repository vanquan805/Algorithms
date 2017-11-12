#include <stdio.h>
#include <stdlib.h>

// Khoi tao node
struct Node
{
    int value;
    Node * Next;
};
// Khoi tao struct hang doi
struct Queue
{
    Node * Front, *Rear; 
    int count; 
};

//Khoi tao hang doi rong
void Init(Queue &Q)
{
    Q.Front = Q.Rear = NULL;
    Q.count = 0;
}


//kiem tra Queue rong
int Isempty (Queue Q) 
{
    if (Q.count == 0)
        return 1;
    return 0;
}

//tao 1 Node
Node *MakeNode(int x) 
{
    Node *P = (Node*) malloc(sizeof(Node));
    P->Next = NULL;
    P->value = x;
    return P;
}

//them phan tu vao cuoi Queue
void Push(Queue &Q, int x) 
{
    Node *P = MakeNode(x);
    if (Isempty(Q)==1)
    {
        Q.Front = Q.Rear = P;
    }
    else 
    { 
        Q.Rear->Next = P;
        Q.Rear = P;
    }
    Q.count++;
}

//Lay phan tu dau trong danh sach L
int Pop(Queue &Q) 
{
    if (Isempty(Q)==1) 
    {
        printf("Hang doi rong !");
        return 0;
    }
    else
    {
        int x = Q.Front->value;
        
        if (Q.count == 1)
            Init(Q);
        else{
        	Q.Front = Q.Front->Next;
        	Q.count--;
		}
        return x;
    }
}

// Tim kiem theo be rong
void breadth_first_search(Queue &L){
	
	//Dung neu danh sach L rong
	if(Isempty(L)==1)
		return;
	
	//Lay phan tu dau tien trong danh sach L
	int x = Pop(L);
	printf("%d\t", x);
	
	// dung neu tim thay
	if(x%3==0)
		return;
	
	//Them phan tu vao cuoi danh sach L
	Push(L,	x+1);
	Push(L,	2*x);
	
	//Tiep tuc tim kiem
	return breadth_first_search(L);
}

int main(){
	
	int a;
	Queue L;
	Init(L);
	printf("Nhap vao a1: ");
	scanf("%d", &a);
	Push(L, a);
	printf("\nQua trinh tim kiem\n");
	
	breadth_first_search(L);
	
	printf("\nKet thuc qua trinh tim kiem\n");

	return 0;
}
