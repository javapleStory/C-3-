#include <iostream>
using namespace std;

class Printer
{
	string model;
	string manufacturer;
	int availablePage;
public:
	Printer(string model, string m, int page) { this->model = model; this->manufacturer = m; this->availablePage = page; }
	virtual ~Printer() {}
	virtual void print(int page)
	{
		cout << "����Ʈ�Ͽ����ϴ�." << endl;
		this->availablePage -= page;


	}
	virtual void show()
	{
		cout << model << ", " << manufacturer << ", �������� : " << availablePage;
	}
	int getPage() { return availablePage; }
};

class InkJetPrinter :public Printer
{
	int availabeInk;
public:
	InkJetPrinter(string model, string m, int page, int ink) : Printer(model, m, page)
	{
		this->availabeInk = ink;
	}
	~InkJetPrinter() {}
	void print(int page)
	{
		if (availabeInk < page || getPage() < page)
		{
			if (getPage() < page)
				cout << "������ �����Ͽ� �μ��� �� �����ϴ�." << endl;
			else
				cout << "��ũ�� �����Ͽ� �μ��� �� �����ϴ�." << endl;
		}
		else
		{
			Printer::print(page);
			availabeInk -= page;
		}
	}
	void show()
	{
		Printer::show();
		cout << ", ���� ��ũ : " << availabeInk << endl;
	}
	int getInk() { return availabeInk; }
};

class LaserPrinter : public Printer
{
	int availabletoner;
public:
	LaserPrinter(string model, string m, int page, int toner) : Printer(model, m, page)
	{
		this->availabletoner = toner;
	}
	~LaserPrinter(){}
	void print(int page)
	{
		if (availabletoner < page * 0.5 || getPage() < page)
		{
			if(getPage() < page)
				cout << "������ �����Ͽ� �μ��� �� �����ϴ�." << endl;
			else
				cout << "��ʰ� �����Ͽ� �μ��� �� �����ϴ�." << endl;
		}
		else 
		{
			Printer::print(page);
			availabletoner -= page * 0.5; // ��ĳ�����ؼ� Ŭ�������ο����� �������پ˾�
		}
	}
	void show()
	{
		Printer::show();
		cout << ", ���� ��� : " << availabletoner << endl;
	}
	int getToner() { return availabletoner; }
};

int main()
{
	int num = 0, page;
	string s = "y";
	Printer* p[2] = {
		new InkJetPrinter("Officejet V40", "HP", 5, 10),
		new LaserPrinter("SCX-6x45", "�Ｚ����", 3, 20)
	};
	cout << "���� �۵����� 2���� �����ʹ� ������ ����." << endl;
	cout << "��ũ�� : "; p[0]->show();
	cout << "������ : "; p[1]->show();
	while (s == "y")
	{
		cout << endl;
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է� : ";
		cin >> num >> page;
		if (num == 1)
		{
			p[0]->print(page);
		}
		else if (num == 2)
		{
			p[1]->print(page);
		}
		else cout << "�߸��� ������ ��ȣ�Դϴ�. �ٽ� �������ּ���. " << endl;
		
		for (int i = 0; i < 2; i++)
		{
			p[i]->show();
		}
		
		cout << "��� ����Ʈ�Ͻðڽ��ϱ�? (y/n)";
		cin >> s;
		if (s == "n") break;
	}
}