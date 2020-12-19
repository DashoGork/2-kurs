#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <string.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

struct symbol
{
    char inf;

    symbol* next;//spisok

};

class Steck {
public:
    symbol* s;
    Steck() {
        s = NULL;
    }
    Steck(const Steck& a);
    Steck(char j) {
        symbol* new_ = new symbol;
        new_->inf = j;
        if (s == 0) {
            new_->next = 0;
            s = new_;
        }
        else {
            new_->next = s;
            s = new_;
        }
    };
    ~Steck() {
        if (s != NULL) {
            symbol* now = s;
            while (s) {
                s = s->next;
                delete now;
                now = s;
            }
        }

    }

    void GetNow() {
        return;
    }
    void EnterS(char sm) {
        cout << "Rabbb enter" << endl;
        symbol* wer = new symbol;
        wer->inf = sm;
        wer->next = NULL;
        if ((wer == NULL)) {
            wer->next = NULL;
            s = wer;
        }
        else {
            wer->next = s;
            s = wer;
        }
    }
    void Show() {
        if (s == 0) { cout << "Empty" << endl; return; }
        else {
            cout << "Steck" << endl;
            symbol* now = s;
            while (now) {
                cout << now->inf << ' ';
                now = now->next;
            }
        }
        cout << endl;
    }
    void EnterList(string way) {
        ifstream f(way);
        symbol* now = NULL, * last = s;
        if (!f) {
            cout << "Error" << endl;
            return;
        }
        char symb;
        while (!f.eof()) {
            now = new symbol;
            f >> symb;
            if (f.eof()) return;
            now->inf = symb;
            now->next = last;
            if (last == NULL) {
                s = last = now;
            }
            else {
                last = now;
                s = now;
            }

        }
    }
    int Numb(Steck& s1) {
        int i = 0;
        if (s == NULL) {
            cout << "Empty " << endl;
            return 0;
        }
        symbol* now = s;
        symbol* nn = now->next;

        int k;
        Steck n;
        while (nn) {
            i++;
            nn = nn->next;
        }

        return i + 1;
    }
    void Order(Steck& a) {
        int i = 0;
        symbol* now1 = a.s, * now2 = NULL, * now3 = s;
        while (now1) {
            now2 = new symbol;
            now2->inf = now1->inf;

            now2->next = now3;
            if (now3 == NULL) {
                s = now3 = now2;
                now1 = now1->next;
            }
            else {
                now3 = now2;
                now1 = now1->next;
                s = now2;

            }
        }

    }
    friend ofstream& operator<< (ofstream& stream, Steck& stud) {
        symbol* now = stud.s;
        while (now) {
            stream << now->inf << ' ';
            now = now->next;
        }
        return stream;
    }
};
int get_int() {
    while (true) {
        cout << "Enter value: ";
        int a;
        cin >> a;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else
            return a;
    }

}


class Pair {
private: 
    double a1, a2;
public:
    Pair() {
        a1 = 0;
        a2 = 0;
    }

    Pair(double a, double b) {
        a1 = a;
        a2 = b;
    }
    Pair operator +(Pair n) {
        return Pair(this->a1 + n.a1, this->a2 + n.a2);
    }
    Pair operator *(Pair n) {
        return Pair(this->a1 * n.a1, this->a2 * n.a2);
    }
    void Show() {
        cout << "(" << this->a1 << ", " << this->a2 << ")" << endl;
    }
    ~Pair() {
    }

};
class Complex :Pair {
private:
    double a1, a2, i1, i2;
public:
    Complex() {
        a1 = 0;
        i1 = 1;
        a2 = 1;
        i2 = 0;
    }

    Complex(double na1, double ni1, double na2, double ni2) {
        a1 = na1;
        i1 = ni1;
        a2 = na2;
        i2 = ni2;
    }

    void Show() {
        cout << "(" << this->a1 << " + ( " << this->i1<<"i ), " << this->a2 << " + ( " << this->i2 << "i)) " << endl;
    }

    Complex operator +(Complex n) {
        return Complex(this->a1 + n.a1, this->i1 + n.i1, this->a2 + n.a2, this->i2 + n.i2);
    }
    Complex operator -(Complex n) {
        return Complex(this->a1 - n.a1, this->i1 - n.i1, this->a2 - n.a2, this->i2 - n.i2);
    }
    Complex operator *(Complex n) {
        return Complex(this->a1 * n.a1, this->i1 * n.i1, this->a2 * n.a2, this->i2 * n.i2);
    }
    ~Complex() {}
};

class Array {
private:
    int size;
    char *mas = new char[size];
public:
    Array() {
        size = 5;
        for (int i = 0; i < size; i++) {
            mas[i] = 'a';
        }
    }
    Array(int n_size, char* n_m) {
        size = n_size;
        for (int i = 0; i < size; i++) {
            mas[i] = n_m[i];
        }
    }

    Array( char* n_m) {
        size = sizeof(n_m);
        for (int i = 0; i < size; i++) {
            mas[i] = n_m[i];
        }
    }

    char operator[](const int number) {
        if (number<0 || number>size) return 0;
        return mas[number];
    }

    virtual char* sum(char *n1,double ns1, char *n2, double ns2) {
        int s1 = ns1, s2 = ns2,s_max,s_min;
        if (s1 > s2) {
            s_max = s1;
            s_min = s2;
        }
        else if (s1 < s2) {
            s_max = s2;
            s_min = s1;
        }
        else s_min = s_max = s1;
        char *n_m = new char[s_max];
        if (s1 != s2) {
            for (int i = 0; i < s_min; i++) {
                n_m[i] = n1[i] + n2[i];
            }
            if (s1 > s2) {
                for (int i = s_min; i < s_max; i++) {
                    n_m[i] = n1[i];
                }
            }
            else {
                for (int i = s_min; i < s_max; i++) {
                    n_m[i] = n2[i];
                }
            
            }
        }
        else{
            for (int i = 0; i < s_min; i++) {
                n_m[i] = n1[i] + n2[i];
            }
        }
        Array n_m1 = Array(s_max,n_m);
        //delete[] n_m;
        return n_m;
    }
    
    void Show() {
        cout << "Number of elements: " << size << endl;
        for (int i = 0; i < size; i++) {
            cout << ' ' << mas[i] << ' ';
        }
        cout << endl;
    }
    int get_s() {
        return size;
    }
    char* get_m() {
        return mas;
    }
    int get_max_s(Array* n1, Array* n2) {
        int s1 = n1->size, s2 = n2->size;
        if (s1 > s2) {
            return s1;
        }
        else if (s1 < s2) {
            return s2;
        }
        else return s1;
    }
};
class Fraction :Array {
private:
    int size;
    char* mas = new char[size];
public:
    Fraction() {
        size = 1;
        mas[0] = 1.2;
    }

    Fraction(int n_s,char * n_m) {
        size = n_s;
        for (int i = 0; i < size; i++) {
            mas[i] = n_m[i];
        }
    }

    virtual char* sum(char* n1, double ns1, char* n2, double ns2) override {
        int s1 = ns1, s2 = ns2, s_max, s_min;
        if (s1 > s2) {
            s_max = s1;
            s_min = s2;
        }
        else if (s1 < s2) {
            s_max = s2;
            s_min = s1;
        }
        else s_min = s_max = s1;
        char* n_m = new char[s_max];
        if (s1 != s2) {
            for (int i = 0; i < s_min; i++) {
               
                
                n_m[i] = (n1[i] - '0' + n2[i] - '0')+'0';
          
            }
            if (s1 > s2) {
                for (int i = s_min; i < s_max; i++) {
                    n_m[i] = n1[i];
                }
            }
            else {
                for (int i = s_min; i < s_max; i++) {
                    n_m[i] = n2[i];
                }

            }
        }
        else {
            for (int i = 0; i < s_min; i++) {
                n_m[i] = char((n1[i] - '0') + (n2[i] - '0'));
            }
        }
        
        
        //Fraction n_m1 = Fraction(s_max, n_m);
       // delete[] n_m;
        return n_m;
    
    }
    int get_max_s(Fraction* n1, Fraction* n2) {
        int s1 = n1->size, s2 = n2->size;
        if (s1 > s2) {
            return s1;
        }
        else if (s1 < s2) {
            return s2;
        }
        else return s1;
    }
    void Show() {
        cout << "Number of elements: " << size << endl;
        for (int i = 0; i < size; i++) {
            cout << ' ' << mas[i] << '/'<<mas[i+1] <<"; ";
            i++;
        }
        cout << endl;
    }

    int get_s() {
        return size;
    }
    char* get_m() {
        return mas;
    }
};
class MString :Array {
private:
    int size;
    char* mas = new char[size];
public:
    MString() {
        size = 2;
        mas[0] = 'a';
        mas[1] = '/0';
    }

    MString(int n_s, string n_m) {
        size = n_s;
        strcpy(mas, n_m.c_str());
    }
    
    void Show() {
        cout << "Number of elements: " << size << endl;
        for (int i = 0; i < size; i++) {
            cout << ' ' << mas[i];
           
        }
        cout << endl;
    }

    virtual char* sum(char* n1, double ns1, char* n2, double ns2) override {
       int size1 = ns1 + ns2;
        char *n_m=new char[size1]();
        strcat(n_m, n1);
        strcat(n_m, n2);
        
        
        return n_m;
    }
    
    int get_s() {
        return size;
    }
    
    char* get_m() {
        return mas;
    }
};

int main() {

    setlocale(LC_CTYPE, "rus");

    Steck s1, s2, s3, s4;
    s1.EnterList("1.txt");
    s2.EnterList("2.txt");
    s3.Order(s1);
    s4.Order(s2);
    try {
        ofstream res("1_Results.txt", ofstream::app);
        if (!(res.is_open())) throw "Can't open";
        res << s3;
        res.close();
    }
    catch (const char* ex) { cout << endl << "Error: " << ex << endl; }

    try {
        ofstream res2("2_Results.txt", ofstream::app);
        if (!(res2.is_open())) throw "Can't open";
        res2 << s4;
        res2.close();
    }
    catch (const char* ex) { cout << endl << "Error: " << ex << endl; }

    Pair p1, p2, p3;
    p1 = Pair(2, 3);
    p2 = Pair(5, 7);

    Complex c1, c2, c3;
    c1 = Complex(1, 1, 2, 2);
    c2 = Complex(2, 2, 1, 1);
    
    
    char a1m[3] = {'q','w','s'};
    char a2m[5] = { 'q','w','t','r','t' };
    Array a1 = Array(3,a1m);
    Array a2 = Array(5,a2m);
    char f1m[4] = { '1','2','3','4' };
    char f2m[6] = { '1','2','3','4','5','6' };
    Fraction f1 = Fraction(4, f1m);
    Fraction f2 = Fraction(6, f2m);
    string s1m = "Hello";
    string s2m = " World";
    MString ms1 = MString(6, s1m);
    MString ms2 = MString(6, s2m);
    int menu = 1;
    int v;

    while (menu) {

        cout << "MENU" << endl;
        cout << "1. 1 task" << endl;
        cout << "2. 3 task" << endl;
        cout << "3. 4 task" << endl;
        cout << "4- exit" << endl << endl;

        v = get_int();
        cout << endl;
        switch (v) {
        case 1:
        {
            s1.Show();
            s2.Show();
            cout << endl;
            s3.Show();
            s4.Show();
            cout << endl;
            break;
        }
        case 2:
        {
            p1.Show();
            p2.Show();
            p3 = p1 + p2;
            p3.Show();
            cout << "Работа класса Complex" << endl;
            c1.Show();
            c2.Show();
            c3 = c1 + c2;
            c3.Show();
            (c1 - c2).Show();
            (c1 * c2).Show();
            (c1 + c2).Show();
            break;
        }
        case 3:
        {
            (a1).Show();
           (a2).Show();
           Array a3 = Array(a1.get_max_s(&a1,&a2), a1.sum(a1.get_m(),a1.get_s(), a2.get_m(),a2.get_s()));
           a3.Show();
            cout << endl;
            cout << "Работа класса Fraction" << endl;
            f1.Show();
            f2.Show();
            Fraction f3 = Fraction(f1.get_max_s(&f1, &f2), f1.sum(f1.get_m(), f1.get_s(), f2.get_m(), f2.get_s()));
            f3.Show();
            cout << endl;
            ms1.Show();
            ms2.Show();
            //cout << ms1.get_s()+ ms2.get_s() << " ms1.get_s()" << endl;
           char* n33= ms1.sum(ms1.get_m(), ms1.get_s(), ms2.get_m(), ms2.get_s());

            MString ms3 = MString(ms1.get_s() + ms2.get_s(), n33);
            ms3.Show();
            break;
        }

        case 4:
        {
            menu = 0;
            break;
        }
        default: cout << "Enter 1-4" << endl;
        }
    }
    cout << endl;
    system("pause");
    return 0;
}