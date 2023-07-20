#include <iostream>
#include <vector>
using namespace std;

class Item {
public:
	Item(int n, int v);
	void getBestWealth();
	double findMinVolume_in_arrayInW();
	void swapV_2toUP_in_ArrayInW(int, int);
	void swapW_2toUP_in_ArrayInW(int, int);
	~Item();
private:
	static int size;
	int number, volume;
	int wealth, volumeRemain;
	vector<vector<double>> array;
	vector<vector<double>> arrayInW;
};
//�������ֵ����ֵ�ܶ�
int Item::size = 3;


Item::Item(int n, int v):number(n),volume(v),wealth(0),volumeRemain(v) {
	array.resize(n);
	//д����Ʒ����(����) 
	for (int i = 0; i < number; i++) {
		array[i].resize(size - 1);
		cin >> array[i][0] >> array[i][1];
		array[i].resize(size);
		array[i][2] = array[i][1] / array[i][0];
	}
	arrayInW = array;
	//������Ʒ����,����ֵ�ܶ����� 
	double min;
	for (int i = 0; i < number; i++) {
		for (int j = i + 1; j < number; j++) {
			swapW_2toUP_in_ArrayInW(i, j);
		}
	}
	//����ֵ�ܶ�һ��,�ٰ��������
	for (int i = 0, j = 1; j < number; i++, j++) {
		for (; j < number && arrayInW[i][2] == arrayInW[j][2]; j++) {
			swapV_2toUP_in_ArrayInW(i, j);
		}
	}
	//debug: in --> out		
	cout << "debug : in		" << endl;
	for (int i = 0; i < number; i++)
		cout << arrayInW[i][0] << " " << arrayInW[i][1] << " " << arrayInW[i][2] << endl;
	cout << "debug : out	" << endl;
}


void Item::getBestWealth() {
	while (volumeRemain > findMinVolume_in_arrayInW()) {
		if (volumeRemain > arrayInW[arrayInW.size() - 1][0]) {
			volumeRemain -= arrayInW[arrayInW.size() - 1][0];
			wealth += arrayInW[arrayInW.size() - 1][1];
			arrayInW.erase(arrayInW.begin() + (arrayInW.size() - 1));
		}
	}
	cout << wealth << endl;
}


double Item::findMinVolume_in_arrayInW() {
	double minVolume = arrayInW[0][0];
	for (int i = 1; i < arrayInW.size(); i++) {
		if (minVolume > arrayInW[i][0])
			minVolume = arrayInW[i][0];
	}
	return minVolume;
}


void Item::swapW_2toUP_in_ArrayInW(int i, int j) {
	if (arrayInW[i][2] > arrayInW[j][2]) {
		double min = arrayInW[j][0];
		arrayInW[j][0] = arrayInW[i][0];
		arrayInW[i][0] = min;

		min = arrayInW[j][1];
		arrayInW[j][1] = arrayInW[i][1];
		arrayInW[i][1] = min;

		min = arrayInW[j][2];
		arrayInW[j][2] = arrayInW[i][2];
		arrayInW[i][2] = min;
	}
}


void Item::swapV_2toUP_in_ArrayInW(int i, int j) {
	if (arrayInW[i][0] > arrayInW[j][0]) {
		double min = arrayInW[j][0];
		arrayInW[j][0] = arrayInW[i][0];
		arrayInW[i][0] = min;

		min = arrayInW[j][1];
		arrayInW[j][1] = arrayInW[i][1];
		arrayInW[i][1] = min;

		min = arrayInW[j][2];
		arrayInW[j][2] = arrayInW[i][2];
		arrayInW[i][2] = min;
	}
}
Item::~Item() {}


/*	�㷨һ��:
	1.��ȡ��ֵ�ܶ���Ϣ;
	2.��������ֵ�ܶ�����,����ֵ�ܶ�һ��,���ٰ����������;
	3.������ɴ���С��䱳��,ֱ��������������ʣ�౳������С����С��Ʒ�����end
*/	
int main() {
	int n, v;
	cin >> n >> v;
	Item package_1(n, v);
	package_1.getBestWealth();
	return 0;
}