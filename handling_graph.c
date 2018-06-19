int checkVertex(Vertex* head, int id){            //리스트에 중복인 id 있는지 확인
	Vertex* p=head;
	while(p!=NULL){
		if(p->id==id) return 1;
		else p=p->next;
	}
	return 0;
}
Vertex* findVertex(Vertex* head, int id){         //리스트에 id와 같은 노드 찾아서 반환 
	Vertex* p=head;
	while(p!=NULL){
		if(p->id==id) return p;
		else p=p->next;
	}
	return 0;
}
void insertVertex(Vertex** head, Vertex* v){      //리스트에 중복확인하고나서 tail에 노드 추가
	if(*head==NULL){
		*head=v; return;
	}
	Vertex* p=*head;
	if(!checkVertex(*head,v->id)){
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=v;
	}
}
void newEdge(Vertex* v1, Vertex* v2){             //정점간 간선생성
	addArrayF(v1); addArrayT(v2);
	v1->from[v1->size_from-1]=v2->id;
	v2->to[v2->size_to-1]=v1->id;
}
void getEdges(Vertex* v){                         //나가는,들어오는 간선의 정점 id로된 배열 생성
	int i=0,j=0;
	int size=v->size_from;
	int size_arr=size;
	int* arr=(int*)malloc(sizeof(int)*size);
	fr(i=0;i<size;i++) arr[i]=v->from[i];
	size=v->size_to;
	for(j=0;j<size;j++){
		if(!checkArray(v->from,v->size_from,v->to[i])){
			arr=addArrayInt(arr,size_arr);
			arr[size_arr++]=v->to[j];
		}
	}
	for(i=0;i<size_arr;i++)
		for(j=i;j<size_arr;j++)
			if(arr[i]>arr[j]) swap(&arr[i],&arr[j]);
	v->size_final=size_arr; v->final=arr;
}
void sortEdges(Vertex* v){                        //정점의 to,from 배열 정렬
	int size=v->size_from; int i=0,j=0;
	for(i=0;i<size;i++)
		for(j=i+1;j<size;j++)
			if(v->from[i]>v->from[j]) swap(&v->from[i],&v->from[j]);
	size=v->size_to;
	for(i=0;i<size;i++)
		for(j=i+1;j<size;j++)
			if(v->to[i]>v->to[j]) swap(&v->to[i],&v->to[j]);
}
void addArrayT(Vertex* v){                        //from배열에 동적할당
	if(v->to==NULL){
		v->to=(int*)malloc(sizeof(int));
		v->size_to++;
		return ;
	}
	int i=0;
	int* arr=(int*)malloc(sizeof(int)*(v->size_to+1));
	for(i=0;i<v->size_to;i++) arr[i]=v->to[i];
	v->size_to++;
}
void addArrayF(Vertex* v){                        //to배열에 동적할당
	if(v->to==NULL){
		v->from=(int*)malloc(sizeof(int));
		v->size_from++;
		return ;
	}
	int i=0;
	int* arr=(int*)malloc(sizeof(int)*(v->size_from+1));
	for(i=0;i<v->size_to;i++) arr[i]=v->from[i];
	v->size_from++;
}
int* addArrayInt(int* arr,int size){              //정수형 배열 동적할당 return 값 있음
	if(size==0) return (int*)malloc(sizeof(int));
	int* newarr=(int*)malloc(sizeof(int)+(size+1));
	for(int i=0;i<size;i++) newarr[i]=arr[i];
	return newarr;
}
int checkArray(int* arr, int size, int data){     //배열에 값이 있는지 검사해서 있으면 1 반환
	int i=0;
	for(;i<size;i++)
		if(arr[i]==data) return 1;
	}
	return 0;
}
void swap(int* n1, int* n2){                      //정수 값 교환
	int tmp=*n1;
	*n1=*n2;
	*n2=tmp;
}
