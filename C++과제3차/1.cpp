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
		cout << "프린트하였습니다." << endl;
		this->availablePage -= page;


	}
	virtual void show()
	{
		cout << model << ", " << manufacturer << ", 남은종이 : " << availablePage;
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
				cout << "용지가 부족하여 인쇄할 수 없습니다." << endl;
			else
				cout << "잉크가 부족하여 인쇄할 수 없습니다." << endl;
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
		cout << ", 남은 잉크 : " << availabeInk << endl;
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
				cout << "용지가 부족하여 인쇄할 수 없습니다." << endl;
			else
				cout << "토너가 부족하여 인쇄할 수 없습니다." << endl;
		}
		else 
		{
			Printer::print(page);
			availabletoner -= page * 0.5; // 업캐스팅해서 클래스내부에서도 못쓰는줄알았
		}
	}
	void show()
	{
		Printer::show();
		cout << ", 남은 토너 : " << availabletoner << endl;
	}
	int getToner() { return availabletoner; }
};

int main()
{
	int num = 0, page;
	string s = "y";
	Printer* p[2] = {
		new InkJetPrinter("Officejet V40", "HP", 5, 10),
		new LaserPrinter("SCX-6x45", "삼성전자", 3, 20)
	};
	cout << "현재 작동중인 2대의 프린터는 다음과 같다." << endl;
	cout << "잉크젯 : "; p[0]->show();
	cout << "레이저 : "; p[1]->show();
	while (s == "y")
	{
		cout << endl;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력 : ";
		cin >> num >> page;
		if (num == 1)
		{
			p[0]->print(page);
		}
		else if (num == 2)
		{
			p[1]->print(page);
		}
		else cout << "잘못된 프린터 번호입니다. 다시 선택해주세요. " << endl;
		
		for (int i = 0; i < 2; i++)
		{
			p[i]->show();
		}
		
		cout << "계속 프린트하시겠습니까? (y/n)";
		cin >> s;
		if (s == "n") break;
	}
}