#include <iostream>
using namespace std;

class SNode {
private:
	int date;
	SNode* next;
public:
	SNode();
	SNode(int);
	void debug();
	bool isEmpty();
	void Push(int);
	int Pop();
	~SNode();
};

SNode::SNode() { next = NULL; }
SNode::SNode(int n) { date = n; next = NULL; }
SNode::~SNode(){}
void SNode::debug() { 
	if (isEmpty())
		cout << "debug: ������ջΪ��" << endl;
	else 
		cout << "debug: date = " << next->date << endl; 
}
bool SNode::isEmpty() {
	return (next == NULL);
}
void SNode::Push(int n) {
	//�����ù��캯�����ɽڵ㣬������ڵ�ǰ��(Push)������;Ӧ��ʹ��new����
	//SNode tempSNode(n);
	SNode* tempSNode = new SNode;
	tempSNode->date = n;
	tempSNode->next = next;
	next = tempSNode;
}
int SNode::Pop() {
	if (isEmpty()) {
		cout << "������ջΪ��" << endl;
		return NULL;
	}
	else {
		int topElem;
		//debug();
		SNode* topCellptr = next;
		topElem = topCellptr->date;
		next = topCellptr->next;
		//debug();
		return topElem;
	}
}

int main() {
	SNode Stack;

	cout << "TEST 1" << endl;
	Stack.Push(1);
	cout << Stack.Pop() << endl;

	cout << "TEST 2" << endl;
	Stack.Push(1);
	Stack.Push(2);
	Stack.Push(3);
	Stack.Push(4);
	Stack.Push(5);
	cout << Stack.Pop() << endl;
	return 0;
}