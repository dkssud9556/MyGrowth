/*
	복사 생성자는 자기 자신과 같은 형태의 객체를 인자로 받을 수 있는 생성자를 말한다.
	복사 생성자는 직접 선언해주지 않아도 디폴트 복사 생성자가 생기지만 생성자 내에서 
	동적 할당을 해줘야하는 경우에는 디폴트 복사 생성자가 얕은 복사를 하기 때문에 문제가
	될 수도 있기 때문에 직접 복사 생성자를 만들어 줬다.
*/

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "직급 : 사원" << endl;
			break;
		case SENIOR:
			cout << "직급 : 주임" << endl;
			break;
		case ASSIST:
			cout << "직급 : 대리" << endl;
			break;
		case MANAGER:
			cout << "직급 : 과장" << endl;
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
		cout << "이름: " << name << endl << "회사: " << company << endl << "전화번호: " << phone << endl;
		COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard() {
		delete[]name;
		delete[]phone;
		delete[]company;
		cout << "소멸" << endl;
	}
};

int main() {
	NameCard manClerk("Kim", "회사", "전화번호", COMP_POS::CLERK);
	NameCard copy1 = NameCard(manClerk);
	NameCard manSenior("Ahn", "회사", "전화번호", COMP_POS::SENIOR);
	NameCard copy2 = NameCard(manSenior);
	
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}