#include <iostream>
#include <cmath>
using namespace std;
#define ABS(X) (((X)>0)?(X):-(X))
struct mypoint {
	double x;
	double y;
};

struct myline {
	mypoint start;
	mypoint end;
};

struct rectangle {
	mypoint start;
	double side;
};

void printRectangle(rectangle r) {
	cout << "{" << r.start.x << "," << r.start.y << "}" << " ";
	cout << "{" << r.start.x + r.side << "," << r.start.y << "}" << " ";
	cout << "{" << r.start.x + r.side << "," << r.start.y + r.side << "}"
			<< " ";
	cout << "{" << r.start.x << "," << r.start.y + r.side << "}" << endl;
}

/*
 * 4.Создайте структуру Время с элементами Часы, Минуты. Реализоватьследующую задачу
 - у прибора зафиксировано время начала работы и времязавершения работы в текущий
 день. Определить общее время работыприбора за неделю.
 */
struct mytime {
	int hour;
	int min;
};

int worktime(mytime start, mytime end) {
	int startmins = 60 * start.hour + start.min;
	int endmins = 60 * end.hour + end.min;
	return endmins - startmins;
}

void printtotaltime(int mins) {
	cout << mins / 60 << " hours and " << mins % 60 << " minutes ";
}

/*
 * Создайте структуру Дробь с элементами a – числитель, b – знаменатель.Даны две дроби.
 * Реализуйте с этими дробями арифметические действия:умножение и деление (можно написать
 * функции, реализующие этидействия)
 */
struct frac {
	int p;
	int q;
};

void print(frac f) {
	cout << f.p << "/" << f.q;
}

frac mul(frac f1, frac f2) {
	frac r { };
	r.p = f1.p * f2.p;
	r.q = f2.q * f2.q;
	return r;
}

frac div(frac f1, frac f2) {
	frac r { };
	r.p = f1.p * f2.q;
	r.q = f2.q * f2.p;
	return r;
}

double distX(mypoint p) {
	return ABS(p.x);
}

double distY(mypoint p) {
	return ABS(p.y);
}

double distO(mypoint p) {
	return sqrt(pow(distX(p), 2) + pow(distY(p), 2));
}

mypoint maxDistO(mypoint p1, mypoint p2) {
	return (distO(p1) > distO(p2) ? p1 : p2);
}

bool parallY(myline l) {
	return (l.start.x == l.end.x);
}

bool parallX(myline l) {
	return (l.start.y == l.end.y);
}

int main() {
	/*mypoint p1 { }, p2 { }, p3 { }, r { };
	 cout << "enter coords" << endl;
	 cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	 r = maxDistO(p1, maxDistO(p2, p3));
	 cout << r.x << " " << r.y << " " << distO(r);*/
	/*frac f1 { }, f2 { };
	 cout << "enter fracs" << endl;
	 cin >> f1.p >> f1.q >> f2.p >> f2.q;
	 print(f1);
	 cout << endl;
	 print(f2);
	 cout << endl;
	 cout << "f1*f2=";
	 print(mul(f1, f2));
	 cout << endl;
	 cout << "f1/f2=";
	 print(div(f1, f2));*/
	mytime s { }, e { };
	cout << "enter start time" << endl;
	cin >> s.hour >> s.min;
	cout << "enter end time" << endl;
	cin >> e.hour >> e.min;
	cout << "Total work time in a week was ";
	printtotaltime(worktime(s, e) * 7);
	//myline l{p1,p2};
	//cout << parallX(l) << " " << parallY(l) << endl;
}
