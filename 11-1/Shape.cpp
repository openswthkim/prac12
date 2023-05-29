/***************************************************************/
/*             HW#9 : �����Լ��� �߻�Ŭ����                    */
/*  �ۼ��� : ������                    ��¥ : 2023�� 5�� 30��  */
/*                                                             */
/* ���� ���� : ���� �Լ��� ����Ͽ� �� ������ �´� ���� ����   */
/*                - - - - - - -                                */
/***************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name; // �̸� ���ڿ� ���� ����
    int width, height; // �ʺ�� ���� ���� ����
public:
    Shape(string n = "", int w = 0, int h = 0) {
        name = n; width = w; height = h;
    }
    virtual double getArea() = 0;  // �����Լ� ����
    string getName() { return name; } // �̸� ����
};
class Oval : public Shape {
public:
    Oval(string n, int w, int h) : Shape(n, w, h) {} 
    // Shape Ŭ������ ��ӹ޾� Ÿ�� �Լ��� ǥ����
    double getArea() { return 3.14 * width * height; }
    // �����Լ��� ����� Ÿ���� ���̸� ����
};
class Rect : public Shape {
public:
    Rect(string n, int w, int h) : Shape(n, w, h) {}
    // �簢�� Ŭ������ ��� ������ �ʱ�ȭ
    double getArea() { return width * height; } // �簢���� ���� ����
};
class Triangular : public Shape {
public:
    Triangular(string n, int w, int h) : Shape(n, w, h) {}
    // �ﰢ�� Ŭ������ ��� ������ �ʱ�ȭ
    double getArea() { return width * height / 2; } // �ﰢ���� ���� ����
};
int main() {
    Shape *p[3]; // ������ �迭 ����
    p[0] = new Oval("��붱", 10, 20); // �迭 ù��°�� Ÿ�� ��ü ���� �Ҵ�
    p[1] = new Rect("����", 30, 40); // �迭 �ι�°�� �簢�� ��ü ���� �Ҵ�
    p[2] = new Triangular("�佺Ʈ", 30, 40); // �迭 ����°�� �ﰢ�� ��ü ���� �Ҵ�
    for (int i = 0; i < 3; i++)
        cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;
    // �� ��ü�� �̸��� ���� ���
    for (int i = 0; i < 3; i++) 
        delete p[i]; // �� ��ü �޸� ����
}