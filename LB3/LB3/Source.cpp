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
        symbol* now1 = a.s, * now2=NULL,*now3=s;
        while (now1) {
            now2 = new symbol;
            now2->inf = now1->inf;
            
            now2->next = now3;
            if (now3==NULL) {
                s = now3 = now2;
                now1 = now1->next;
            }
            else {
               now3=now2;
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


int main() {

	setlocale(LC_CTYPE, "rus");
	
    Steck s1,s2,s3,s4;
    s1.EnterList("1.txt");
    s2.EnterList("2.txt");
    s3.Order(s1); 
    s4.Order(s2);
    try { ofstream res("1_Results.txt", ofstream::app);
    if (!(res.is_open())) throw "Can't open";
    res << s3;
    res.close();
    } 
    catch (const char* ex) { cout << endl <<"Error: "<<ex<< endl; }
   
    try {
        ofstream res2("2_Results.txt", ofstream::app);
        if (!(res2.is_open())) throw "Can't open";
        res2 << s4;
        res2.close();
    }
    catch (const char* ex) { cout << endl << "Error: " << ex << endl; }


    int menu = 1;
    int v;

    while(menu) {
        
        cout << "MENU" << endl;
        cout << "1 - show" << endl;
        cout << "2 - count" << endl;
        cout << "3- order" << endl;
        cout << "4- exit" << endl<<endl;
        
        v = get_int();
        cout << endl;
        switch (v) {
        case 1:
        {
            s1.Show();
            s2.Show();
            cout << endl;
            break;
        }
        case 2:
        {
            cout << s1.Numb(s1) + s2.Numb(s2) << endl << endl;;
            break;
        }
        case 3:
        {
            s3.Show();
            s4.Show();
            cout << endl;
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