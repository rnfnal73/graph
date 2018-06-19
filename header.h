#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct vertex{
        int id,size_to,size_from,size_final;
        int* to,*from,*final;
        struct vertex* next;
}Vertex;

typedef struct node{
	int data;
	struct node* next,*prev;
}Node_s;

typedef struct stack{
	struct node* head;
	struct node* top;
	int size;
}Stack;

Vertex* cpVertex(Vertex* v); //정점을 복사해서 반환
int checkVertex(Vertex* head, int id); //리스트에 중복인 id 있는지 확인
Vertex* findVertex(Vertex* head, int id); //리스트에 id와 같은 노드 찾아서 반환
void insertVertex(Vertex** head, Vertex* v); //리스트에 중복확인하고나서 tail에 노드 추가

void newEdge(Vertex* v1, Vertex* v2); //정점간 간선생성
void getEdges(Vertex* v); //나가는,들어오는 간선의 정점 id로된 배열 생성
void sortEdges(Vertex* v); //정점의 to,from 배열 정렬

Node* newNode(int data); //스택에 이용되는 노드 생성
Stack* newStack(); //스택 변수 초기화
int isEmpty(Stack* s); //스택이 비었으면 1 반환
void push(Stack* s, int data);  //push
int pop(Stack* s); //pop
void printStack(Stack* s; //head부터 스택 출력
int checkStack(Stack* s, int data); //스택에 data값이 있는지 체크해서 있으면 1 반환

void addArrayF(Vertex* v); //from배열에 동적할당
void addArrayT(Vertex* v); //to배열에 동적할당
int* addArrayInt(int* arr,int size); //정수형 배열 동적할당 return 값 있음
int checkArray(int* arr, int size, int data); //배열에 값이 있는지 검사해서 있으면 1 반환
void swap(int* n1, int* n2); //정수 값 교환
