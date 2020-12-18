#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include < math.h >

using namespace std;
template <class T>
class Vector {
	int n;
	T * vect;
public:
	Vector<T>() {
		n = 4;
		vect = new T[n];
		for (int i = 0; i < n; i++) {
			vect[i] = 1;
		}
	}; //constructor by default
	Vector<T>(int k) {
		n = k;
		if (n <= 0) { cout << "Неверные данные" << endl;
		return;
		}
		vect = new T[n];
		for (int i = 0; i < n; i++) {
			vect[i] = 1;
		}
	}; //constructor by n
	Vector<T>(int k, T* vec) {
		n = k;
		if (n <= 0) {
			cout << "Неверные данные" << endl;
			return;
		}
		vect = vec;
	}; //constructor by n
	Vector<T>(const Vector& ob) {
		n = ob.n;
		vect = new T[n + 1];
		if (!vect) {
			cout << "Error" << endl;
			return;
		}
		for (int i = 0; i < n; i++) {
			vect[i] = ob.vect[i];
		}
	}; //copy constructor
	~Vector<T>() { delete[] vect; }

	float Len(Vector* list) {

		float prod = 0;
		for (int i = 0; i < n; i++) {

			prod = prod + (vect[i] * vect[i]);
		}
		return sqrt(prod);
	};
	float Dot_Product(Vector* list1, Vector* list2) {
		float prod = 0;//proverka na n??
		for (int i = 0; i < (*list1).n; i++) {

			prod = prod + ((*list1).vect[i] * (*list2).vect[i]);
		}
		return prod;
	};
	Vector Sum(Vector* list1, Vector* list2) {
		Vector new_;
		for (int i = 0; i < (*list1).n; i++) {

			new_.vect[i] = ((*list1).vect[i] + (*list2).vect[i]);
		}
		return new_;
	}
	Vector Diff(Vector* list1, Vector* list2) {
		Vector new_;
		for (int i = 0; i < (*list1).n; i++) {

			new_.vect[i] = ((*list1).vect[i] - (*list2).vect[i]);
		}
		return new_;
	}
	Vector Multip(Vector* list1, int k) {
		for (int i = 0; i < (*list1).n; i++)
		{
			list1->vect[i] = list1->vect[i] * k;
		}
		return *list1;
	}

	void ShowV(Vector<T> n1) {
		for (int i = 0; i < n1.n; i++) {
			cout << n1.vect[i] << ' ';
		}
		cout << endl;
	}
	void ShowV(Vector<T> * n1) {
		for (int i = 0; i < n; i++) {
			cout << vect[i] << ' ';
		}
		cout << endl;
	}
	Vector operator +(Vector<T> v1) {
		Vector <T>new_;
		for (int i = 0; i < v1.n; i++) {

			new_.vect[i] = (this->vect[i] + v1.vect[i]);
		}
		return new_;
	}
	friend Vector operator *(int s, Vector v1) {
		Vector new_;
		for (int i = 0; i < v1.n; i++) {

			new_.vect[i] = (s * v1.vect[i]);
		}
		return new_;
	}
	friend float operator *(Vector v1, Vector v2) {
		float prod = 0;//proverka na n??
		for (int i = 0; i < v1.n; i++) {

			prod = prod + (v1.vect[i] * v2.vect[i]);
		}
		return prod;
	}
	friend Vector operator -(Vector<T> v1, Vector<T> v2) {
		Vector new_;
		for (int i = 0; i < v1.n; i++) {

			new_.vect[i] = (v1.vect[i] - v2.vect[i]);
		}
		return new_;
	}
	friend void operator ++(Vector v1) {
		for (int i = 0; i < v1.n; i++) {
			++v1.vect[i];
		}
	}
	friend void operator --(Vector v1) {
		for (int i = 0; i < v1.n; i++) {
			--v1.vect[i];
		}
	}
	Vector operator --(int s) {
		for (int i = 0; i < this->n; i++) {
			vect[i]--;
		}
		return 0;
	}
	Vector operator ++(int s) {
		for (int i = 0; i < this->n; i++) {
			vect[i]++;
		}
		return 0;
	}
	void SetVector(int b, T* vect1) {
		n = b;
		for (int i = 0; i < n; i++) {
			vect[i] = vect1[i];
		}
	}
	Vector<T>& operator[](const int i) {
		return vect[i];
	}
	int Getn() {
		return n;
	}
	T GetV(int i) {
		return vect[i];
	}
	int IsComplCol(Vector v1, Vector v2) {

		for (int i = 0; i < v1.Getn() - 1; i++) {
			int n = 0;
			if (v1.GetV(i) * v1.GetV(i + 1) == v2.GetV(i) * v2.GetV(i + 1)) {
				n++;
			}
			else return 0;

			return 1;
		}
	}
};
int get_numb() {
	while (true) {
		cout << "Введите размерность вектора: ";
		int a;
		cin >> a;

		if (cin.fail()| a<=0)
		{
			cout << "Ошибка ввода размерности вектора" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return a;
	}

}
int get_vect() {
	while (true) {
		cout << "Введите размерность вектора: ";
		int a;
		cin >> a;

		if (cin.fail() | a<= 0)
		{
			cout << "Ошибка ввода размерности вектора" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return a;
	}

}



int main() {

	setlocale(LC_CTYPE, "rus");


	int n = 4;
	float a1[4] = { 1,2,3,4 };
	float a2[4] = { 1.2,2.2,3.2,4.3 };

	Vector<int>* n1; 
	Vector<int>* n2; 
	Vector<float>* n3;
	Vector<float> *n4;
	n1 = new Vector<int>(n);
	n2 = new Vector<int>();
	n3 = new Vector<float>(n, a1);
	n4 = new Vector<float>(n, a2);

	int menu_2 = 0;
	int menu_1;
	while (!menu_2) {
		cout << "What to do:" << endl;
		cout << "1)Show all default vectors;" << endl;
		
		cout << "3)Module of the vector;" << endl;
		cout << "4)Dot product of two vectors;" << endl;
		cout << "5)Add two vectors;" << endl;
		cout << "6)Subsract one vector from another;" << endl;
		cout << "7)Multiply vector by const;" << endl;
		cout << "8)Find out are the vectors collinear or complanar;" << endl;
		cin >> menu_1;

		switch (menu_1)
		{
		case 1:
			n1->ShowV(n1);
			n2->ShowV(n2);
			n3->ShowV(n3);
			n4->ShowV(n4);
			break;
		
		case 3:
			cout << "Modules of default vectors: " << endl;
			cout << (n1->Len(n1)) << endl;
			cout << (n2->Len(n2)) << endl;
			cout << (n3->Len(n3)) << endl;
			cout << (n4->Len(n4)) << endl;
			break;

		case 4:
			cout << "Dot product of two default vectors: " << endl;
			cout << "n1 and n2 " << (n1->Dot_Product(n1, n2)) << endl;
			cout << "n3 and n4 " << (n3->Dot_Product(n3, n4)) << endl;
			cout << "n1 and n2 (op)" << (*(n1) * *(n2)) << endl;
			cout << "n3 and n4 (op)" << (*(n3) * *(n4)) << endl;
			break;

		case 5:
			cout << "Sum of two default vectors: " << endl;
			cout << "n1 + n2 (method)"; n1->ShowV(n1->Sum(n1, n2)); cout << endl;
			cout << "n3 + n4 (method)"; n3->ShowV(n3->Sum(n3, n4)); cout << endl;
			//cout << "n1 + n2 (op)"; n1->ShowV((*(n1)+n2)); cout << endl;
			//cout << "n3 + n4 (op)"; n3->ShowV((*(n3)+n4)); cout << endl;
			break;

		case 6:
			cout << "Difference between two default vectors: " << endl;
			cout << "n1 - n2 (method) "; n1->ShowV(n1->Diff(n1, n2)); cout << endl;
			cout << "n3 - n4 (method) "; n3->ShowV(n3->Diff(n3, n4)); cout << endl;
			//cout << "n1 - n2 (op) "; n1->ShowV(*(n1)-n2); cout << endl;
			//cout << "n3 - n4 (op) "; n3->ShowV((*(n3)-n4)); cout << endl;
			break;

		case 7:
			cout << "Multiplication  by : ";
			int k; cin >> k; cout << endl;
			cout << "n1*k "; n1->ShowV(n1->Multip(n1, k)); cout << endl;
			cout << "n2*k "; n1->ShowV(n2->Multip(n2, k)); cout << endl;
			//cout << "n3*k "; n1->ShowV(n3->Multip(n3, k)); cout << endl;
			//cout << "n4*k "; n1->ShowV(n4->Multip(n4, k)); cout << endl;
			cout << "n1*k (op)"; n1->ShowV(*(n1)*k); cout << endl;
			cout << "n2*k (op)"; n2->ShowV(*(n2)*k); cout << endl;
			cout << "n3*k (op)"; n3->ShowV(*(n3)*k); cout << endl;
			cout << "n4*k (op)"; n4->ShowV(*(n4)*k); cout << endl;
			break;

		case 8:
			cout << "Colinear or complanar& " << endl;
			cout << "n1 n2";
			if (n1->IsComplCol(*(n1), *(n2)))
				cout << " Compl";
			else cout << " Col";
			cout << endl;

			cout << "n3 n4";
			if (n3->IsComplCol(*(n3), *(n4)))
				cout << " Compl";
			else cout << " Col";
			cout << endl;
			break;
		case 9:
			cout << "Inc : " << endl;
			++(*n1); ++(*n2);
			cout << "++n1 "; n1->ShowV(n1);
			cout << "++n2 "; n2->ShowV(n2);
			--(*n1); --(*n2);
			cout << "--n1 "; n1->ShowV(n1);
			cout << "--n2 "; n1->ShowV(n1);
			cout << "Dec : " << endl;
			cout << "n1++ "; n1->ShowV((*n1)++);
			cout << "n2++ "; n2->ShowV((*n2)++);
			cout << "n1-- "; n1->ShowV((*n1)--);
			cout << "n2-- "; n2->ShowV((*n2)--);
			break;
		case 10:
		/*	n4->ShowV(n4);
			cout << "Enter number : ";
			int k1; cin >> k1; cout << endl;
			if (k1 >= 0 && k1 < n) {
				cout << ((*n4)[k1]) << endl;
			}
			else { cout << "Index is exceeded" << endl; }*/
			break;
		case 11:
			return 0;
			break;
		default: cout << "Enter 1-9" << endl;
		}
	}







cout << n1->Len(n1) << endl;
cout << n2->Len(n2) << endl;
cout << n3->Len(n3) << endl;
cout << n4->Len(n4) << endl;


cout << endl;
system("pause");
return 0;
}