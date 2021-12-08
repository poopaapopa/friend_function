#include <iostream>
using namespace std;

class Rect
{
	int width, height;
	char symb;
	friend void friend_put(Rect* r, char s);
public:
	Rect(int width, int height, char symb):width{width},height{height},symb{symb}{}
	void display()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << symb << " ";
			cout << "\n";
		}
		cout << "\n\n";
	}
};
void friend_put(Rect* r, char s)
{
	r->symb = s;
}


class Line;
class Point;
class Point
{
	float x;
	float y;
public:
	Point(float x = 0, float y = 0):x{x},y{y}{}
	friend float uclon(Point, Line);
};

class Line
{
	float a, b, c;
public:
	Line(float a, float b, float c):a{a},b{b},c{c}{}
	friend float uclon(Point, Line);
};

float uclon(Point p, Line l)
{
	return l.a * p.x + l.b * p.y + l.c;
}

int main()
{
	Rect A(5, 3, 'A');
	Rect B(3, 5, 'B');
	A.display();
	B.display();
	friend_put(&A, 'a');
	friend_put(&B, 'b');
	A.display();
	B.display();
	Point p(16.0, 12.3);
	Line l(10.0, -42.3, 24.0);
	cout << "\nResult " << uclon(p, l) << "\n";
	return 0;
}