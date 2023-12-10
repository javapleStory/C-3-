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
	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
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
	cout << "������ ���� ū ���ڴ� " << pizza[p].getName() << "�Դϴ�." << endl;
}