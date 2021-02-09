#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
	int elem;
	struct Link *next;
}link;

link *  initLink();

link * insertElem(link * p,int elem,int add);

link * delElem(link * p, int add);

int selectElem(link * p,int elem);

link *amendElem(link * p, int add, int newElem);

void display(link *p);

int main() {
	printf("setup 111\n");
	link *p=initLink();
	display(p);
	
	printf("setup 222\n");
	p=insertElem(p,5,4);
	display(p);
	
	printf("setup 333\n");
	p=delElem(p,3);
	display(p);
	
	printf("setup 444\n");
	int address=selectElem(p,2);
	if(address==-1){
		printf("setup 555 nothings\n");
	}else{
		printf("setup 666address %d\n",address);
	}
	printf("setup 777\n");
	p=amendElem(p,3,7);
	display(p);
	
	return 0;
}

link * initLink(){
	link * p=(link*)malloc(sizeof(link)); //创建一个头结点
	link * temp=p; //声名一个指针指向头节点，用于遍历链表
	//生成链表
	for (int i=1;i<5;i++){
		link *a=(link*)malloc(sizeof(link));
		a->elem=i;
		a->next=NULL;
		temp->next=a;
		temp=temp->next;
	}
	return p;
}

link * insertElem(link * p, int elem, int add){
	link * temp=p;
	for (int i=1;i<add;i++){
		if (temp==NULL) {
			printf("setup 888 invalid\n");
			return p;
		}
		temp=temp->next;
	}
	
	link * c=(link*)malloc(sizeof(link));
	c->elem=elem;
	c->next=temp->next;
	temp->next=c;
	return p;
}

link * delElem(link * p, int add) {
	link * temp=p;
	for(int i=1;i<add;i++){
		temp=temp->next;
	}
	link * del=temp->next;
	temp->next=temp->next->next;
	free(del);
	return p;
}


int selectElem(link * p,int elem){
	link * t=p;
	int i=1;
	while (t->next){
		t=t->next;
		if(t->elem==elem){
			return i;
		}
		i++;
	}
	return -1;
}

link *amendElem(link * p, int add, int newElem){
	link * temp=p;
	temp=temp->next;
	for(int i=1;i<add;i++){
		temp=temp->next;
	}
	temp->elem=newElem;
	return p;
}

void display(link *p){
	link* temp=p;
	while (temp->next){
		temp=temp->next;
		printf("%d",temp->elem);
	}
	printf("done\n");
}