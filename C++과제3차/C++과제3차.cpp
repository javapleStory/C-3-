#include <iostream>
using namespace std;

class Circle
{
	int radius;
public:
	Circle() { }
	~Circle() {}
	int getRadius() { return radius; }
	void setCircle(int radius) { this->radius = radius; }
};

class NamedCircle : public Circle
{
	string name;
public:
	NamedCircle() {}
	~NamedCircle() {}
	void setNamedCircle(int radius, string name)
	{
		setCircle(radius);
		this->name = name;
	}
	string getName() { return name; }
};


int main()
{
	int rad, max, p;
	string name;

	NamedCircle pizza[5];
	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << " : ";
		cin >> rad >> name;
		pizza[i].setNamedCircle(rad, name);
	}

	max = pizza[0].getRadius();
	for (int i = 1; i < 5; i++)
	{
		if (max < pizza[i].getRadius())
		{
			max = pizza[i].getRadius();
			p = i;
		}
	}
	cout << "면적이 가장 큰 피자는 " << pizza[p].getName() << "입니다." << endl;
}