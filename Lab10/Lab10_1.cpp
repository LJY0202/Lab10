#include <iostream>
#include <string>
#define interface class
using namespace std;

interface Shape {
public:
	// draw() 에 대한 정의만 해놓은 상태.
	virtual void draw() = 0;
};

class RoundedRectangle : public Shape {
public:
	// 둥근 직사각형을 그리는 함수.
	virtual void draw(){
		cout << "Inside RoundedRectangle::draw() method." << endl;
	}
};

class RoundedSquare : public Shape {
public:
	// 둥근 정사각형을 그리는 함수.
	virtual void draw(){
		cout << "Inside RoundedSquare::draw() method." << endl;
	}
};

class Rectangle : public Shape {
public:
	// 직사각형을 그리는 함수.
	virtual void draw(){
		cout << "Inside Rectangle::draw() method." << endl;
	}
};

class Square : public Shape {
public:
	// 정사각형을 그리는 함수.
	virtual void draw(){
		cout << "Inside Square::draw() method." << endl;
	}
};

class AbstractFactory {
public:
	// Shape type의 객체를 반환하는 정의만 해놓은 상태.
	virtual Shape * getShape(string shapeType) = 0;
};

class  ShapeFactory : public AbstractFactory {
public:
	// 사용자로부터 RECTANGLE or SQUARE를 입력받아 해당하는 Shape type의 객체를 반환
	virtual Shape* getShape(string shapeType) {
		if (!shapeType.compare("RECTANGLE")) {
			return new Rectangle();
		}
		else if (!shapeType.compare("SQUARE")) {
			return new Square();
		}
		return nullptr;
	}
};

class  RoundedShapeFactory : public AbstractFactory {
public:
	// 사용자로부터 RECTANGLE or SQUARE를 입력받아 해당하는 Shape type의
	// rounded 객체를 반환
	virtual Shape* getShape(string shapeType) {
		if (!shapeType.compare("RECTANGLE")) {
			return new RoundedRectangle();
		}
		else if (!shapeType.compare("SQUARE")) {
			return new RoundedSquare();
		}
		return nullptr;
	}
};

class FactoryProducer {
public:
	// rounded가 true냐 false냐에 따라 상황에 맞는 ShapeFactory 객체를 반환한다.
	static AbstractFactory* getFactory(bool rounded) {
		if (rounded) {
			return new RoundedShapeFactory();
		}
		else {
			return new ShapeFactory();
		}
	}
};

int main() {
	AbstractFactory* shapeFactory1 = (new FactoryProducer)->getFactory(false);
	Shape* shape1 = shapeFactory1->getShape("RECTANGLE");
	Shape* shape2 = shapeFactory1->getShape("SQUARE");
	shape1->draw();
	shape2->draw();

	AbstractFactory* shapeFactory2 = (new FactoryProducer)->getFactory(true);
	Shape* shape3 = shapeFactory2->getShape("RECTANGLE");
	Shape* shape4 = shapeFactory2->getShape("SQUARE");
	shape3->draw();
	shape4->draw();
	return 0;
}
