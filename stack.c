#include "header.h"

Node* newNode(int data){                      //스택에 이용되는 노드 생성
	Node* p=(Node*)malloc(sizeof(Node));
	p->data=data; p->next=NULL; p->prev=NULL;
	return p;
}
Stack* newStack(){                            //스택 변수 초기화
	Stack* p=(Stack*)malloc(sizeof(Stack));
	p->size=0; p->head=NULL; p->top=NULL;
	return p;
}
int isEmpty(Stack* s){                        //스택이 비었으면 1 반환
	if(s->head==NULL) return 1;
	else return0;
}
void push(Stack* s, int data){                //push
	Node* p=newNode(data);
	if(isEmpty(s)){
		s->head=p; s->top=p;
	}
	else{
		s->top->next=p;
		p->prev=s->top;
		s->top=p;
	}
	s->size++;
}
int pop(Stack* s){                            //pop
	if(isEmpty(s)) return 0;
	int i=0;
	if(s->size==1){
		s->size--;
		i=s->top->data;
		s->top=NULL;
		s->head=NULL;
		return i;
	}
	else{
		i=s->top->data;
		s->top=s->top->prev;
		s->size--;
		s->top->next=NULL;
		return i;
	}
}
void printStack(Stack* s){                    //head부터 스택 출력
	Node* p=s->head;
	while(p->next!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d\n",p->data);
}
int checkStack(Stack* s, int data){           //스택에 data값이 있는지 체크해서 있으면 1 반환 
	Node* p=s->head;
	while(p!=NULL){
		if(p->data==data) return 1;
		p=p->next;
	}
	return 0;
}
