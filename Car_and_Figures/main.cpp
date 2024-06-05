#include"Figures.h"

int main() {
	Figures* a[5];
	a[0] = new Rectangle(25,10, 10, 15);
	a[1] = new Square(1,2,3);
	a[2] = new Ellips(12, 2, 3, 4);
	a[3] = new Circle(12, 32, 1);
	

	Canvas c(60,60);
	c += a[0];
	c += a[1];
	c += a[2];
	c += a[3];
	c.print();
	c.relocate(13, 23);
	c.print();
	for (int i = 0; i < 4; i++) {
		delete a[i];
	}
}