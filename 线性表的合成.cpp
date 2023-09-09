#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}node,*List;
  List a, b;
int locateElems(List L, int e);
int Lengths(List L);
int getElems(List L, int i, int& e);
int Inserts(List& L, int i, int& e);
void createList(List &L, int n) {

	L = (node*)malloc(sizeof(node));
	L->next = NULL;
   	for (int i = n; i > 0; i--) {
	node* p = (node*)malloc(sizeof(node));
	printf("输入第%d个元素", i);
	scanf_s("%d", &p->data);
	p->next = L->next;    
	 L->next = p;    

	}
}
void connect(List &a, List &b) {
	int a_len = Lengths(a);
	int b_len = Lengths(b);
	int e;
		for (int i = 1; i <= b_len; i++) {
		e = getElems(b, i, e);
	//判断元素重复，重复就不执行插入函数
		if (!locateElems(a, e)) {
			Inserts(a, a_len, e);
		}
	}
}
int Inserts(List &L, int i, int &e) {
	node* p = L; int j = 0;
	while (p && j < i) {
		p = p->next; j++;
	}
	if (!p || j > i) {
		return 0;
	}
	node* s = (node*)malloc(sizeof(node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return 1;
}
int locateElems(List L, int e) {
	node* p = L->next;
	//p为NULL后，会自动退出，不加会导致无限循环
	while (p && p->data != e) {
		p = p->next;
	}
	if (!p)return 0;
	return 1;
}
int getElems(List L, int i, int &e) {
	node* p = L->next; int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i) return 0;
	e = p->data;
	return e;
}
int Lengths(List L) {
	int cnt = 0;
	node* p = L->next;
	while (p) {
		cnt++;
		p = p->next;
		}
	return cnt;
}
//显示合成后的线性表
void traverlist(List L){
	node* p = L->next;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	}
int main() {
	int m,n,e;
	printf("a的个数n:");
	scanf_s("%d", &m);
	printf("元素：");
	createList(a, m);
	printf("b的个数n:");
	scanf_s("%d", &n);
	printf("元素：");
	createList(b, n);
	printf("\n");
	connect(a, b);
	printf("connect:");
	traverlist(a);
	return 0;
	
}
