/***************************************************************/
/*             HW#9 : �����Լ��� �߻�Ŭ����                    */
/*  �ۼ��� : ������                    ��¥ : 2023�� 5�� 30��  */
/*                                                             */
/* ���� ���� : ���� ���� �Լ� �����ϰ� ��� ���� Ŭ������      */
/*             ���� ���� ����- - - - -                         */
/***************************************************************/
#include <iostream>
using namespace std;

class Calculator {
	void input() { // ���� �Է� �޴� �Լ� ����
		cout << "���� 2 ���� �Է��ϼ���>> ";
		cin >> a >> b;
	}
protected:
	int a, b; // ������ ���� a, b ����
	virtual int calc(int a, int b) = 0; // ����ϴ� ���� ���� �Լ�
public:
	void run() { // ����ϴ� �Լ� ����
		input();
		cout << "���� ���� " << calc(a, b) << endl;
	}
};

class Adder :public Calculator { // Calculator�� ��ӹ��� Adder Ŭ����
protected:
	int calc(int a, int b){ // ���� �Լ� ����
		return a + b; // �� ������ ���� ����
	}
};

class Subtractor :public Calculator { // Calculator�� ��ӹ��� Subtractor Ŭ����
protected:
	int calc(int a, int b) { // ���� �Լ� ����
		return a - b; // �� ������ ���� ����
	}
};

int main() {
	Adder adder; // Adder Ŭ���� ��ü adder ����
	Subtractor subtractor; // Subtractor ��ü subtractor ����
	adder.run(); // Adder ��ü�� run�Լ� ȣ��, �� ���� �Է� �޾� �� ����
	subtractor.run(); // Subtractor ��ü�� run�Լ� ȣ��, �� ���� �Է� �޾� �� ����
}