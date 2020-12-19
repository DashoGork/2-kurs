#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include < math.h >

using namespace std;


class Triangle {
private: int p1[2] = {0,0};
	   int p2[2] = {0,0};
	   int p3[2]={0,0};
public:
	Triangle() {
		
	}
	
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		p1[0] = x1;
		p1[1] = y1;
		p2[0] = x2;
		p2[1] = y2;
		p3[0] = x3;
		p3[1] = y3;
	}
	
	Triangle(int p01[2], int p02[2], int p03[2]) {
		p1[0] = p01[0];
		p1[1] = p01[1];
		p2[0] = p02[0];
		p2[1] = p02[1];
		p3[0] = p03[0];
		p3[1] = p03[1];
	}
	
	Triangle(int p00[3][2]) {
		p1[0] = p00[0][0];
		p1[1] = p00[0][1];
		p2[0] = p00[1][0];
		p2[1] = p00[1][1];
		p3[0] = p00[2][0];
		p3[1] = p00[2][1];
	}
	
	int get_points() {
		int n32[3][2];
		n32[0][0] = p1[0];
		n32[0][1] = p1[1];
		n32[1][0] = p2[0];
		n32[1][1] = p2[1];
		n32[2][0] = p3[0];
		n32[2][1] = p3[1];
		return n32[3][2];
	}
	
	int get_point(int num, int y) {
		if (num == 1) {
			if (y == 1) return p1[0];
			else if(y==2) return p1[1];
			else { cout << "Error!" << endl; return 0; }
		}
		else if (num == 2) {
			if (y == 1) return p2[0];
			else if (y == 2) return p2[1];
			else { cout << "Error!" << endl; return 0; }
		}
		else if (num == 3) {
			if (y == 1) return p3[0];
			else if (y == 2) return p3[1];
			else { cout << "Error!" << endl; return 0; }
		}
		else { cout << "Error!" << endl; return 0; }
	}
	
	void change_points(int n[3][2]) {
		p1[0]= n[0][0];
		p1[1] = n[0][1];
		p2[0] = n[1][0];
		p2[1] = n[1][1];
		p3[0] = n[2][0];
		p3[1] = n[2][1];
	
	
	}

	void change_point(int num, int y, int val) {
		if (num == 1) {
			if (y == 0)  p1[0]=val;
			else if (y == 1) p1[1] = val;
			else { cout << "Error!" << endl; return ; }
		}
		else if (num == 2) {
			if (y == 0)  p2[0] = val;
			else if (y == 1)  p2[1] = val;
			else { cout << "Error!" << endl; return ; }
		}
		else if (num == 3) {
			if (y == 0)  p3[0] = val;
			else if (y == 1) p3[1] = val;
			else { cout << "Error!" << endl; return ; }
		}
		else { cout << "Error!" << endl; return ; }
	}

	double per() {
		if (tr_ex()) {
			double s1 = pow((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]), 1 / 2);
			double s2 = pow((p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]), 1 / 2);
			double s3 = pow((p3[0] - p2[0]) * (p3[0] - p2[0]) + (p3[1] - p2[1]) * (p3[1] - p2[1]), 1 / 2);

			return(s1 + s2 + s3);
		}
		else {cout<< "Does not exist/не существует." << endl;
		return 0;
		}
	}

	void type() {
		if (tr_ex()) {
			double s1 = sqrt(((p1[0] - p2[0]) * (p1[0] - p2[0])) + ((p1[1] - p2[1]) * (p1[1] - p2[1])));
			double s2 = sqrt((p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]));
			double s3 = sqrt((p3[0] - p2[0]) * (p3[0] - p2[0]) + (p3[1] - p2[1]) * (p3[1] - p2[1]));
			if (s1 == s2 & s1 == s3 & s2 == s3) { cout << "Equilateral/равносторонний" << endl; return; }
			else if (s1 == s2 | s1 == s2 | s2 == s3) { cout << "Isosceles/равнобедренный" << endl; return; }
			else if (s1 * s1 + s3 * s3 == s2 * s2 | s1 * s1 + s2 * s2 == s3 * s3 | s2 * s2 + s3 * s3 == s1 * s1) { cout << "Right/прямоугольгый" << endl; return; }
			else { cout << "Neither/никакой" << endl; return; }
		}
		else cout << "Does not exist/не существует." << endl;
	}

	void show_tr() {
		cout << p1[0] << " " << p1[1] << endl << p2[0] << " " << p2[1] << endl << p3[0] << " " << p3[1] << endl;
	
	}
	bool tr_ex() {
		double s1 = sqrt(((p1[0] - p2[0]) * (p1[0] - p2[0])) + ((p1[1] - p2[1]) * (p1[1] - p2[1])));
		double s2 = sqrt((p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]));
		double s3 = sqrt((p3[0] - p2[0]) * (p3[0] - p2[0]) + (p3[1] - p2[1]) * (p3[1] - p2[1]));
		if ((s1 != 0) & (s2 != 0) & (s3 != 0))
		{
			if (s1 + s2 > s3 & s1 + s3 > s2 & s2 + s3 > s1)
				return true;
			else return false;
		}
		else return 0;
	}

};
class String {
private:
	char *str;
public:
	String() {
		str = 0;
	}
	String( char*s) {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}

	String(const char* s) {
		str = new char[strlen(s) + 1];
		strcpy(str, s);
	}

	/*~String() {
		delete[]str;
	}*/

	friend ostream& operator <<(ostream& out, const String& s) {
		cout << s.str<<endl;
		return out;
	}
	friend istream& operator >>(istream& in, const String&) {
		return in;
	}
	String operator +(const char* s) {
		String st;
		st.str = new char[strlen(s) + strlen(str) + 1];
		strcpy(st.str, str);
		strcat(st.str, s);
		return st;

	}
	

};

int main() {

	setlocale(LC_CTYPE, "rus");
	int p01[2] = { 0,0 };
	int p02[2] = { 8,0 };
	int p03[2] = { 0,8 };
	int coor[3][2] = { {0,0 },{0,4},{0,6} };
	String *s1;
	String s2 = String("Alex");
	String s3, s4;

	int menu_2 = 0;
	int menu_1;
	while (!menu_2) {
		

		cout << "1)1 задание" << endl;
		cout << "2)2 задание" << endl;
		cout << "3)Выход" << endl;
		cin >> menu_1;

		switch (menu_1)
		{
		case 1:
			cout << "Определить класс «string» и перегрузить операции ввода/вывода и операцию" << endl << "«+» сложения строк (добавление строки)" << endl;
			cout << "Работа класса String:" << endl;
			cout<<s2<<endl;
			
			 s3 =(s2) + " F.";
			 s4 = s3 + " 2132";
			 cout << s3<<endl;
			 cout << s4 << endl;
			break;
		case 2:
			cout << "Создать класс Triangle для представления треугольника. Поля данных должны включать координаты угловых точек треугольника. Требуется реализовать операции: получения и изменения полей данных, вычисления периметра, а также определения"<<endl<<"вида треугольника (равносторонний, равнобедренный или прямоугольный)." << endl;
			Triangle * a1, * a2, * a3, * a4;
			a1 = new Triangle();
			a2 = new Triangle(0, 0, 3, 0, 0, 4);
			
			a3 = new Triangle(coor);
			
			a4 = new Triangle(p01, p02, p03);

			cout << "Show triangles:" << endl;
			cout << "1 " << endl<<endl;
			a1->show_tr();
			cout << "2 " << endl << endl;
			a2->show_tr();
			cout << "3 " << endl << endl;
			a3->show_tr();
			cout << "4 " << endl << endl;
			a4->show_tr();

			cout << "Change points:" << endl;
			cout << "1 " << endl << endl;
			a1->show_tr();
			cout << "Turns into" << endl;
			a1->change_point(1, 0, 3);
			a1->change_point(1, 1, 5);
			a1->show_tr();

			cout << "Perimeters:" << endl;
			cout << a1->per() << endl;
			cout << a2->per() << endl;
			cout << a3->per() << endl;
			cout << a4->per() << endl;

			cout << "Types:" << endl;
			a1->type();
			a2->type();
			a3->type();
			a4->type();
			break;
		case 3:
			menu_2 = 1;
			break;
		default: cout << "Введите 1 или 2" << endl;
		}
	}




	system("pause");
	return 0;
}