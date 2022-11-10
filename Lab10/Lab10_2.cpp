#include <iostream>
#include <string>
#define interface class
using namespace std;

interface DrawAPI {
public:
	// drawCircle에 대한 정의만 했다.
	virtual void drawCircle(int radius, int x, int y)=0;
};

class RedCircle : public DrawAPI {
public:
	// 빨간 원을 그리는 drawCircle 함수를 구현하였다.
	virtual void drawCircle(int radius, int x, int y) {
		cout << "Drawing Circle[ color: red, radius: "<< radius << ", x: " << x << ", " << y << "]" << endl;
	}
};

class GreenCircle : public DrawAPI {
public:
	// 초록 원을 그리는 drawCircle 함수를 구현하였다.
	virtual void drawCircle(int radius, int x, int y) {
		cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << "]" << endl;
	}
};

class Shape {
protected:
	DrawAPI* drawAPI;
	Shape(DrawAPI* _drawAPI) {
		drawAPI = _drawAPI;
	}
public:
	// draw에 대한 정의만 했다.
	virtual void draw() = 0;
};

class Circle : public Shape {
private:
	int x, y, radius;
public:
	Circle(int _x, int _y, int _radius, DrawAPI* drawAPI) : Shape(drawAPI) {
		x = _x;
		y = _y;
		radius = _radius;
	}

	// 현재 객체가 가진 x, y, radius값을 가지고
	//drawAPI의 drawCircle을 실행하도록 draw 함수를 구현하였다.
	virtual void draw() {
		drawAPI->drawCircle(radius, x, y);
	}
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle());
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle());

	redCircle->draw();
	greenCircle->draw();
	return 0;
}
