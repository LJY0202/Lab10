#include <iostream>
#include <string>
#define interface class
using namespace std;

interface Shape {
public:
	virtual void draw() = 0;
};

class RoundedRectangle : public Shape {
public:
	virtual void draw(){
		cout << "Inside RoundedRectangle::draw() method." << endl;
	}
};

class RoundedSquare : public Shape {
public:
	virtual void draw(){
		cout << "Inside RoundedSquare::draw() method." << endl;
	}
};

class Rectangle : public Shape {
public:
	virtual void draw(){
		cout << "Inside Rectangle::draw() method." << endl;
	}
};

class Square : public Shape {
public:
	virtual void draw(){
		cout << "Inside Square::draw() method." << endl;
	}
};

class AbstractFactory {
public:
	virtual Shape * getShape(string shapeType) = 0;
};

class  ShapeFactory : public AbstractFactory {
public:
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