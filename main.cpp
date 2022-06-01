#include "PrefixTree.h"

using namespace std;
void printMenu()
{
	cout << "Введите [1], чтобы добавить запись о студенте вручную.\n"
		"Введите [2], чтобы добавить случайную запись о студенте.\n"
		"Введите [3], чтобы вывести таблицу.\n"
		"Введите [4], чтобы начать поиск по бору.\n"
		"Введите [5], чтобы начать линейный поиск.\n"
		"Введите [6], чтобы начать поиск с барьером.\n"
		"Введите [7], чтобы очистить консоль.\n"
		"Введите [0], чтобы закончить работу программы.\n";
	cout << "Ваш выбор: ";
}
void one_student(Student* stud) {
	string line = " --------------------------------------------------------------------------------\n";
	cout << line;
	cout << "|" << left << setw(40) << "           LFS" << "|" << setw(18) << " Report card number" << " | " << " Number of group" << " |" << endl;
	cout << line;
	cout << "|" << setw(40) <<stud->get_LFS() << "|" << setw(20) << stud->get_repcard_num() << "|" << setw(18) << stud->get_num_of_group() << "|" << endl;
	cout << line;
	
}
int main() {
	cout << "Практическая работа #9 ИКБО-03-21 Кушхов И.А. Вариант 15\n\n"
		"Задание 2 - Реализация поиска по бору.\n"
		"~~~~~~~~~~~~~~~~~Меню~~~~~~~~~~~~~~~\n";
	printMenu();
	unsigned menu;
	while (true) {
		cin >> menu;
		switch (menu) {
		case 1: {
			Student* temp = new Student;
			temp->enter_info();
			break;
		}
		case 2: {
			Student* temp = new Student;
			unsigned number;
			cout << "Enter the number of the students: ";
			cin >> number;
			temp->enter_random_info(number);
			break;
		}
		case 3:
			OutputTheInfo();
			break;
		case 4: {

			cout << "Enter the report card number of th. Student: ";
			string report_card_number;
			cin >> report_card_number;
			auto start = chrono::high_resolution_clock::now();
			Student* stud = bor->search_word(report_card_number);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float, milli> duration = end - start;
			cout << " runtime: " << duration.count() << endl;
			if (stud != nullptr) {
				one_student(stud);
			}
			else cout << "The student is not found! " << endl;
			break;
		}
		case 5: {
			cout << "Enter the report card number of th. Student: ";
			string report_card_number;
			cin >> report_card_number;
			auto start = chrono::high_resolution_clock::now();
			Student* stud = linear_search(report_card_number);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float, milli> duration = end - start;
			cout << " runtime: " << duration.count() << endl;
			if (stud != nullptr) {
				one_student(stud);
			}
			else cout << "The student is not found! " << endl;
			break;
		}
		case 6: {
			cout << "Enter the report card number of th. Student: ";
			string report_card_number;
			cin >> report_card_number;
			auto start = chrono::high_resolution_clock::now();
			Student* stud = barrier_search(report_card_number);
			auto end = chrono::high_resolution_clock::now();
			chrono::duration<float, milli> duration = end - start;
			cout << " runtime: " << duration.count() << endl;
			if (stud != nullptr) {
				one_student(stud);
			}
			else cout << "The student is not found! " << endl;
			break;
		}
		case 7: system("cls");
		case 0: return 0;
		}
		printMenu();
	}
}