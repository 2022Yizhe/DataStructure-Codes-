#include <stdio.h>
#include <malloc.h>
/*
	���ݽṹ�У��ڵ�����Ŀ�ʼ���֮ǰ����һ���ڵ��֮Ϊͷ��㣬ͷ������������Բ��洢�κ���Ϣ��
	Ҳ���Դ洢����ĳ��ȵȸ�����Ϣ��ͷ����ָ����洢ָ���һ������ָ�루����һ�����Ĵ洢λ�ã�
	��ṹ�������£�
	head��ͷָ�룩->|1|(ջ��/top��)->|2|->|3|->...->|maxsize|(ջ��/end��)
*/
typedef struct SNode {
	int date;
	SNode* next;
};

SNode* CreateStake() {
	//������ջͷ��㣬����ָ��
	SNode* S;
	S = (SNode*)malloc(sizeof(SNode));
	S->next = NULL;
	return S;
}

int isEmpty(SNode* S) {
	//�ж϶�ջS�Ƿ�Ϊ�գ���/�ǿ�-->����1/0��
	return (S->next == NULL);
}

void Push(int item, SNode* S) {
	//��Ԫ��itemѹ���ջS
	SNode* tmpCell;
	tmpCell = (SNode*)malloc(sizeof(SNode));
	tmpCell->date = item;
	tmpCell->next = S->next;
	S->next = tmpCell;
}

int Pop(SNode* S) {
	//ɾ����ջS��ջ��Ԫ�أ�������Ԫ��ֵ
	int topElem;
	SNode* topCell;
	if (isEmpty(S)) {
		printf("Debug:������ջΪ��");
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