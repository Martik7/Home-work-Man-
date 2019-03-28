#include <iostream>
#include <conio.h>
#define n 8
using namespace std;

/*
Описать структуру Man(Фамилия, Имя, Номер телефона, Дата рождения).
*/
struct Man {
	char surname[20];
	char name[20];
	char phone[14];
	int data[3];
};
int main() {
	int i, j, k;
	Man obj[n];
	for (i = 0; i<n; i++) {
		cout << "Familija cheloveka " << i << ":\n";
		cin >> obj[i].surname;
		cout << "Imya cheloveka " << i << ":\n";
		cin >> obj[i].name;
		cout << "Nomer telefona cheloveka " << i << ":\n";
		cin >> obj[i].phone;
		cout << "Data cheloveka " << i << " CHISLO-MESYAZ-GOD:\n";
		cin >> obj[i].data[0] >> obj[i].data[1] >> obj[i].data[2];
	}
	Man temp;
	for (k = n - 1; k>0; k--) {
		for (i = 0; i<k; i++) {
			if ((obj[i].data[0] > obj[i + 1].data[0]) || (obj[i].data[1] > obj[i + 1].data[1]) || (obj[i].data[2] > obj[i + 1].data[2])) {
				temp = obj[i];
				obj[i] = obj[i + 1];
				obj[i + 1] = temp;
			}
		}
	}
	int s = 0, month;
	cout << "Vvedite mesyaz rojdenija cheloveka:\n";
	cin >> month;
	if ((month < 1) || (month > 12)) {
		cout << "Vy vveli nevernyj nomer mesyaza:\n";
	}
	else {
		cout << "Ludy, rodivshiesya v ukazannom mesyaze:\n";
		for (i = 0; i<n; i++) {
			if (obj[i].data[1] == month) {
				cout << obj[i].surname << " " << obj[i].name << ", " << obj[i].phone << ", " << obj[i].data[0] << "." << obj[i].data[1] << "." << obj[i].data[2] << endl;
				s++;
			}
			else {
				if ((obj[i].data[1] < 1) || (obj[i].data[1] > 12)) {
					cout << "Mesyaza s nomerom " << obj[i].data[1] << "ne suchestvuet!\n";
					break;
				}
				else if ((s == 0) && (i == n - 1)) {
					cout << "takih ludej net\n";
				}
			}
		}
	}
	system("pause");
	return 0;
}