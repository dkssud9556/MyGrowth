/*
	���� �����ڴ� �ڱ� �ڽŰ� ���� ������ ��ü�� ���ڷ� ���� �� �ִ� �����ڸ� ���Ѵ�.
	���� �����ڴ� ���� ���������� �ʾƵ� ����Ʈ ���� �����ڰ� �������� ������ ������ 
	���� �Ҵ��� ������ϴ� ��쿡�� ����Ʈ ���� �����ڰ� ���� ���縦 �ϱ� ������ ������
	�� ���� �ֱ� ������ ���� ���� �����ڸ� ����� ���.
*/

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "���� : ���" << endl;
			break;
		case SENIOR:
			cout << "���� : ����" << endl;
			break;
		case ASSIST:
			cout << "���� : �븮" << endl;
			break;
		case MANAGER:
			cout << "���� : ����" << endl;
			break;
		}
	}
}

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char* myname, const char* mycompany, const char* myphone, int myposition) {
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		len = strlen(mycompany) + 1;
		company = new char[len];
		strcpy(company, mycompany);
		len = strlen(myphone) + 1;
		phone = new char[len];
		strcpy(phone, myphone);
		position = myposition;
	}
	NameCard(const NameCard& copy):position(copy.position) {
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		phone = new char[strlen(copy.phone) + 1];
		strcpy(phone, copy.phone);
	}
	void ShowNameCardInfo() {
		cout << "�̸�: " << name << endl << "ȸ��: " << company << endl << "��ȭ��ȣ: " << phone << endl;
		COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard() {
		delete[]name;
		delete[]phone;
		delete[]company;
		cout << "�Ҹ�" << endl;
	}
};

int main() {
	NameCard manClerk("Kim", "ȸ��", "��ȭ��ȣ", COMP_POS::CLERK);
	NameCard copy1 = NameCard(manClerk);
	NameCard manSenior("Ahn", "ȸ��", "��ȭ��ȣ", COMP_POS::SENIOR);
	NameCard copy2 = NameCard(manSenior);
	
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}