#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <string.h>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

class Aeroport {
	char name[50];
	char type_of_plane[50];
	char day[12];
	int number_of_plane;
	int hour;
	int min;
public:

	void set_name(char *nname) {
		strcpy(name,nname);
	};
	void set_num(int nnumb) {
		number_of_plane = nnumb;
	};
	void set_type(char *ttype) {
		strcpy(type_of_plane, ttype);
	};
	void set_day(char *dday) {
		strcpy(day, dday);
	};
	void set_hour(int nhour) {
		hour=nhour;
	}
	void set_min(int nmin) {
		min = nmin;
	}
	void set_aero(char* name, char* day, int hour, int min, int number, char *type) {
		set_name(name);
		set_day(day);
		set_hour(hour);
		set_min(min);
		set_num(number);
		set_type(type);
	}
	
	char* get_name() {
		return name;
	};
	char* get_day() {
		return day;
	};
	char* get_type() {
		return type_of_plane;
	};
	int get_num() {
		return number_of_plane;
	};
	int get_hour() {
		return hour;
	};
	int get_min() {
		return min;
	};
	void Show() {		//Вывод
		cout << "Куда летит самолёт. " << name << endl;
		cout << "Лень недели отправки. " << day << endl;
		cout << "Время. " << hour << ":" << min << endl;
		cout << "Номер самолёта. " << number_of_plane << endl;
		cout << "Тип самолёта. " << type_of_plane << endl;
	}
	

	friend istream& operator>> (istream& stream, Aeroport& stud) {
		stream >> stud.name >> stud.day >> stud.hour >> stud.min>>stud.number_of_plane>>stud.type_of_plane;
		return stream;
	}

	friend ofstream& operator<< (ofstream& stream, Aeroport& stud) {
		stream << stud.name <<" "<< stud.day << " " << stud.hour << " " << stud.min << " " << stud.number_of_plane << " " << stud.type_of_plane;
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
char get_char_50() {
	while (true) {
		char a[50];
		cin >> a;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return a[50];
	}

}
char get_char_12() {
	while (true) {
		char a[12];
		cin >> a;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
			return a[12];
	}

}
void time_chek_hour(int h) {
	if (h > 24) cout << "Hours (0..24)" << endl;
}
void time_chek_min(int h) {
	if (h > 60) cout << "Min (0..60)" << endl;
}

void Search_day(Aeroport* list, int n) { //dodelaj!!
	ofstream res("Results.txt", ofstream::app);
	if (!(res.is_open())) {
		cout << "ww" << endl;
	}
	
	char des_day[12];
	cout << ("What day? ");
	cin >> des_day; cout << endl;
	res << "Results of work Search_day: "<<des_day << endl;
	for (int i = 0; i < n; i++) {
		if (strcmp(list[i].get_day(), des_day) == 0) {
			list[i].Show();
			res << list[i] << endl;
		}

	}
	res << endl;
	res.close();
};
void Search_name(Aeroport *list, int n) {
	ofstream res("Results.txt", ofstream::app);
	if (!(res.is_open())) {
		cout << "ww" << endl;
	}
	
	char des_name[12];
	cout << ("Where? ");
	cin >> des_name; cout << endl;
	res << "Results of work Search_name: " << des_name << endl;
	for (int i = 0; i < n; i++) {
		if (strcmp(list[i].get_name(), des_name) == 0) {
			list[i].Show();
			res << list[i]<<endl;
		}
	}
	res << endl;
	res.close();
};
void Search_day_and_time(Aeroport *list, int n) {
	ofstream res("Results.txt", ofstream::app);
	if (!(res.is_open())) {
		cout << "ww" << endl;
	}
	
	char des_day[12];
	int hour_s, min_s;
	cout << ("In what day? ");
	cin >> des_day; cout << endl;
	cout << ("After what time? Hour:"); cin >> hour_s; cout << "minutes: ";
	cin >> min_s; cout << endl;
	res << "Results of work Search_day_and_time: " << des_day<<" "<<hour_s<<":"<<min_s << endl;
	for (int i = 0; i < n; i++) {
		if (strcmp(list[i].get_day(), des_day) == 0 && (list[i].get_hour() > hour_s || list[i].get_min() > min_s)) {
			list[i].Show();
			res << list[i] << endl;
		}
	}
	res << endl;
	res.close();
};
void New_flight(Aeroport *list, int i) {
	char name[50], day[12], type[50];
	int num, hour, min;
	cout << "Where? "; cin >> name; list[i].set_name(name); cout << endl;
	cout << "When? "; cin >> day; list[i].set_day(day); cout << endl;
	cout << "Time. Hour: "; cin >> hour; list[i].set_hour(hour); cout << " min: "; cin >> min; list[i].set_min(min); cout << endl;
	cout << "Number: "; cin >> num; list[i].set_num(num); cout << endl;
	cout << "Type: "; cin >> type; list[i].set_type(type); cout << endl;
	cout << "====//====" << endl;
};

int main() {

	setlocale(LC_CTYPE, "rus");
	system("chcp 1251");
	
	int menu_1;

	cout << "In wich way you want to download the list? (enter only number)" << endl;
	cout << "1)Manyally" << endl;
	cout << "2)from file " << endl;
	menu_1=get_int();

	while (!(menu_1 == 1 || menu_1 == 2)) {
		cout << "Enter 1 or 2: ";
		cin >> menu_1;
	}

	int num1 = 0; 
	Aeroport* list;
	int num_of_ch = 0;
	switch (menu_1) {

	case 1:
		num_of_ch = 1;
		cout << "How many flights? "; num1 = get_int(); list = new Aeroport[num1];
		break;
	case 2:
		num_of_ch = 2;
		cout << "Working...: ";
		try {
			char* str = new char[1024];
			ifstream file("Aero1.txt");
			if (!file.is_open()) throw "Can't open";
			Aeroport* S;
			S = new Aeroport;
			while (!file.eof())
			{
				file.getline(str, 1024, '\n');
				num1++;
			}
			file.close();
			delete[]str;
			
		}
		catch (const char* exception) {
			cout << endl << "Error: " << exception << endl;
		}
		
		break;
	}

	if (num_of_ch==1) {
		list = new Aeroport[num1];
			New_flight(list, 0);
	}
	else {
		int y = 0;
		list = new Aeroport[num1];
		ifstream file1("Aero.txt");
		while (!file1.eof())
		{
			cout << endl;
			file1 >> list[y];
			list[y].Show();
			cout << endl;
			y++;
		}
		file1.close();
	}
	
	

	int menu_2 = 0;
	
	while (!menu_2) {
		int menu_21;
		cout << "What do you want to do:" << endl;
		cout << "1-Find by day" << endl;
		cout << "2-Find by place" << endl;
		cout << "3-Find by day and time" << endl;
		menu_21=get_int();

		while (!(menu_21 == 1 || menu_21 == 2 || menu_21 == 3)) {
			cout << "Enter 1, 2 or 3: ";
			cin >> menu_21;
		}



		switch (menu_21)
		{
			case 1:
				Search_day(list, num1);
			break;
		
			case 2:
				Search_name(list, num1);
			break;
		
			case 3:
				Search_day_and_time(list, num1);
			break;
		}
		cout << "Want to continue? 0-y/1-n" << endl;
		cin >> menu_2;
	}

	cout << endl;
	system("pause");
	return 0;
}

