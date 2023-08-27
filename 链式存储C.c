#include <stdio.h>
#include <malloc.h>
/*
	数据结构中，在单链表的开始结点之前设立一个节点称之为头结点，头结点的数据域可以不存储任何信息，
	也可以存储链表的长度等附加信息，头结点的指针域存储指向第一个结点的指针（即第一个结点的存储位置）
	其结构描述如下：
	head（头指针）->|1|(栈顶/top域)->|2|->|3|->...->|maxsize|(栈底/end域)
*/
typedef struct SNode {
	int date;
	SNode* next;
};

SNode* CreateStake() {
	//创建堆栈头结点，返回指针
	SNode* S;
	S = (SNode*)malloc(sizeof(SNode));
	S->next = NULL;
	return S;
}

int isEmpty(SNode* S) {
	//判断堆栈S是否为空，空/非空-->返回1/0；
	return (S->next == NULL);
}

void Push(int item, SNode* S) {
	//将元素item压入堆栈S
	SNode* tmpCell;
	tmpCell = (SNode*)malloc(sizeof(SNode));
	tmpCell->date = item;
	tmpCell->next = S->next;
	S->next = tmpCell;
}

int Pop(SNode* S) {
	//删除堆栈S的栈顶元素，并返回元素值
	int topElem;
	SNode* topCell;
	if (isEmpty(S)) {
		printf("Debug:操作堆栈为空");
		return NULL;
	}
	else {
		topCell = S->next;
		S->next = topCell->next;
		topElem = topCell->date;
		free(topCell);
		return topElem;
	}
}

int main() {
	SNode* Stack;
	Stack = CreateStake();
	
	Push(1, Stack);
	printf("%d!\n", Pop(Stack));

	Push(1, Stack);
	Push(2, Stack);
	Push(3, Stack);
	Push(4, Stack);
	Push(5, Stack);
	printf("%d!\n", Pop(Stack));

}