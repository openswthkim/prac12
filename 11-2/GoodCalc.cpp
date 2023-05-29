/***************************************************************/
/*             HW#9 : �����Լ��� �߻�Ŭ����                    */
/*  �ۼ��� : ������                    ��¥ : 2023�� 5�� 30��  */
/*                                                             */
/* ���� ���� : ���� ���� �Լ� �����ϰ� ���� ���ε� Ȱ��        */
/*                - - - - - - -                                */
/***************************************************************/
#include <iostream>
using namespace std;

class Calculator {
public:
	virtual int add(int a, int b) = 0; // �� ������ �� ���� �޴� ���� �Լ�
	virtual int subtract(int a, int b) = 0; // �� ������ �� ���� �޴� ���� �Լ�
	virtual double average(int a[], int size) = 0; // �迭 a�� ��� ���� �޴� ���� �Լ� 
};
class GoodCalc : public Calculator { // ���� ���� �Լ� ����
public:
	int add(int a, int b) { return a + b; } // �� ������ ���� ����
	int subtract(int a, int b) { return a - b; } // �� ������ ���� ����
	double average(int a[], int size) { // �迭 a�� ����� ����ϰ� ����
		double sum = 0; // �Ǽ��� ���� ����
		for (int i = 0; i < size; i++) // �迭�� ũ�⸸ŭ �ݺ�
			sum += a[i]; // �հ踦 ����
		return sum / size; // ��հ� ����
	}
};
int main() {
	int a[] = { 1,2,3,4,5 }; // �迭 a �ʱ�ȭ
	Calculator *p = new GoodCalc(); // GoodCalc ��ü�� ����Ű�� Calculator ������ ����
	cout << p->add(2, 3) << endl; // GoodCalc�� add�Լ� ȣ��
	cout << p->subtract(2, 3) << endl; // GoodCalc�� subtract�Լ� ȣ��
	cout << p->average(a, 5) << endl; // GoodCalc�� average�Լ� ȣ��
	delete p; // ���� �Ҵ�� �޸� ����
}