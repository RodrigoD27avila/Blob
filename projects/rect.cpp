#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

struct Rect {
	int x, y, w, h;

	Rect (int x, int y, int w, int h)
		: x(x), y(y), w(w), h(h)
		{}

	Rect (Point p1, Point p2)
		: x(p1.x), y(p1.y), w(p2.x-p1.x), h(p2.y-p1.y)
		{}

	bool collideWith(const Rect &rect);
};

bool Rect::collideWith(const Rect &rect)
{
	int la, lb;	
	int ra, rb;	
	int ta, tb;	
	int ba, bb;

	la = x;
	ra = x + w;
	ta = y;
	lb = y + h;
	
	lb = rect.x;
	rb = rect.x + rect.w;
	tb = rect.y;
	lb = rect.y + rect.h;

	return (ba <= tb || la >= bb || ra <= lb || la >= rb);
}



int main()
{

	Rect r1(0 , 0 , 100, 100);
	Rect r2(90, 90, 100, 100);

	if (r1.collideWith(r2)) {
		cout << "Collide" << endl;
	} else {
		cout << "Not Collide" << endl;
	}

}
