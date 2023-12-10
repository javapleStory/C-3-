#include <iostream>
using namespace std;

class Shape
{
	string name;
public:
	Shape(string name) { this->name = name; }
	~Shape() {}
	virtual string getName() { return name; }
	virtual double getArea() { return 0.0; }
};

class Oval : public Shape
{
	int width;
	int height;
public:
	Oval(string name, int w, int h) : Shape(name)
	{
		this->width = w;
		this->height = h;
	}
	string getName() { string n = Shape::getName(); return n; }
	~Oval() {}
	double getArea() { return width * height * 3.14; }
};

class Rect : public Shape
{
	int width;
	int height;
public:
	Rect(string name, int w, int h) : Shape(name)
	{
		this->width = w;
		this->height = h;
	}
	~Rect() {}
	string getName() { string n = Shape::getName(); return n; }
	double getArea() { return width * height; }
};

class Triangular : public Shape
{
	int width;
	int height;
public:
	Triangular(string name, int w, int h) : Shape(name)
	{
		this->width = w;
		this->height = h;
	}
	~Triangular() {}
	string getName() { string n = Shape::getName(); return n; }
	double getArea() { return width * height; }
};


int main()
{
	Shape* p[3];
	p[0] = new Oval("ºó´ë¶±", 10, 20);
	p[1] = new Rect("Âû¶±", 30, 40);
	p[2] = new Triangular("Åä½ºÆ®", 30, 40);

	for (int i = 0; i < 3; i++)
	{
		cout << p[i]->getName() << ", ³ÐÀÌ´Â " << p[i]->getArea() << endl;
	}
	for (int i = 0; i < 3; i++) delete p[i];
}