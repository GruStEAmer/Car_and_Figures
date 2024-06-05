#pragma once
#include<iostream>
#include<string>
using std::string;


class Figures {
protected:
	int x, y;
	string name;
public:
	Figures(int x, int y) :x(x), y(y) {};
	virtual int S() = 0;
	virtual int P() = 0;
	virtual void print() = 0;
	virtual int get_first() = 0;
	virtual int get_second() = 0;
	friend class Canvas;
};


//Rect
class Rectangle : public Figures {
protected:
	int h, w;
public:
	Rectangle(int x, int y, int w, int h) :Figures(x, y), w(w), h(h) {
		name = "Rectangle";
		if (x > w) std::swap(x,w);
		if (y > h) std::swap(y,h);
	};
	int S() {
		return w * h;
	}
	int P() {
		return 2 * (w + h);
	}
	void print() {
		std::cout << name;
	}
	int get_first() {
		return w;
	}
	int get_second() {
		return h;
	}
};
class Square :public Rectangle {
public:
	Square(int x, int y, int w): Rectangle(x,y,w,w){ name = "Square"; }
};
//Rect


//Ellips
class Ellips :public Figures {
protected: 
	int a,b;
public:
	Ellips(int x, int y, int a, int b) :Figures(x, y), a(a), b(b) { 
		name = "Ellips";
		if (x > a) std::swap(x, a);
		if (y > b) std::swap(y, b);
	};
	int S() {
		return static_cast<int>(a * b * 3.14);
	}
	int P() {
		return static_cast<int>(4 * ((3.14 * a * b + (a - b)) / (a + b)));
	}
	void print() {
		std::cout << name;
	}
	int get_first() {
		return a;
	}
	int get_second() {
		return b;
	}
};
class Circle :public Ellips {
public:
	Circle(int x, int y, int r) : Ellips(x, y, r, r) { name = "Circle"; };
};
//Ellips




class Canvas {
	string canv;
	int x, y;
public:
	Canvas(int x, int y) : x(x), y(y) {
		canv.resize(x * y);
		for (int i = 0; i < x * y; i++) {
			canv[i] = ' ';
		}
	};
	void print() {
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				std::cout << canv[i * x + j];
			}
			std::cout << "\n";
		}
	}
	void relocate(int x1, int y1) {
		string ans;
		ans.resize((x + x1) * (y + y1));

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				ans[x * (i + x1) + (j + y1)] = canv[x * i + j];
			}
		}
		canv = ans;
	}
	void operator+=(Figures* f) {
		if (f-> name == "Rectangle" || f->name == "Square") {
			for (int i = f->x; i < f->get_first() + f->x; i++) {
				for (int j = f->y; j < f->get_second() + f->y; j++) {
					canv[i * x + j] = '*';
				}
			}
		}
		else if (f->name == "Ellips" || f->name == "Circle") {
			for (int i = f->x; i < f->get_first() + f->x; i++) {
				for (int j = f->y; j < f->get_second() + f->y; j++) {
					canv[i * x + j] = '@';
				}
			}
		}
	}
};