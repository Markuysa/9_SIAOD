#include <string>
#include <map>
#include <random>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
using namespace std;
class Student {
private:
	string report_card_num; // Номер зачетки
	int num_of_group; // Номер группы 
	string LFS_name; // ФИО
public:
	/// <Setters>
	void set_report_num(string num) { this->report_card_num = num; };
	void set_num_of_group(int num) { this->num_of_group = num; };
	void set_LFS(string name) { this->LFS_name = name; };
	/// </Setters>
	
	/// <Getters>
	string get_LFS() { return this->LFS_name; }
	string get_repcard_num() { return this->report_card_num; }
	int get_num_of_group() { return this->num_of_group; }
	///	</Getters>

	void enter_random_info(unsigned number); // Add random info abt th student
	void enter_info(); // Add the info about the student
};
struct TreeNode{

	map <char, TreeNode*> childr;
	bool is_end = false;
	Student* std_ptr;
};
class Trie {
private:
	TreeNode* root;
public:
	Trie() {
		this->root = new TreeNode;
	}
	void insert_word(string & word, Student* std_ptr);
	Student* search_word(string& word);
};
vector <Student*> table;
Trie* bor = new Trie;
void Trie::insert_word(string& word,Student* std_ptr) {
	TreeNode* temp = root;
	for (size_t i = 0; i < word.size(); i++) {
		char letter = char(word[i]);
		if (temp->childr.find(letter) == temp->childr.end())
			temp->childr[letter] = new TreeNode;
		temp = temp->childr[letter];
	}
	temp->is_end = true;
	temp->std_ptr = std_ptr;
}
Student* Trie::search_word(string& word) {
	TreeNode* temp = this->root;
	for (size_t i = 0; i < word.size(); i++) {
		char letter = word[i];
		if (temp->childr.find(letter) == temp->childr.end())
				return nullptr;
		temp = temp->childr[letter];
	}
	return temp->std_ptr;
}

void Student::enter_info() {
	cout << "Enter the info about the Student>>>\n1. Number of group = ";
	cin >> this->num_of_group;
	cin.clear();
	cout << "2. Last, First and Second name of the Student: ";
	cin.ignore(100, '\n');
	getline(cin, this->LFS_name);
	cout << "3. Report card num = ";
	cin >> this->report_card_num;
	cout << "Info added succesfully\n";
	table.push_back(this);
	bor->insert_word(report_card_num,this);
}
string generate_LFS() {
	string result = "";
	for (size_t i = 0; i < 3; i++) {
		int index = rand() & 10 + 1;
		for (size_t j = 0; j <= index; j++) {
			result += (char)(rand() % 26 + 97);
		}
		result += ' ';
	}
	return result;
}
string generate_card_num() {
	string result = "";
	int index = rand() % 10 + 5;
	for (size_t i = 0; i < index; i++) {
		result += (char)(rand() % 9 + 48);
	}
	for (size_t i = 0; i < 4; i++) {
		result += (char)(rand() % 36 + 65);
	}
	return result;
}
void Student::enter_random_info(unsigned number) {
	srand(time(0));
	Student* temp = this;
	for (size_t i = 0; i < number; i++) {
		temp->num_of_group = rand() % 100;
		temp->LFS_name = generate_LFS();
		temp->report_card_num = generate_card_num();
		table.push_back(temp);
		bor->insert_word(temp->report_card_num, temp);
		temp = new Student;
	}
	cout << "Info added succesfully" << endl;
}
void OutputTheInfo() {
	string line = " --------------------------------------------------------------------------------\n";
	cout << line;
	cout << "|" << left << setw(40) << "           LFS" << "|" << setw(18) << " Report card number" << " | " << " Number of group" << " |" << endl;
	cout << line;
	for (size_t i = 0; i < table.size(); i++) {
		cout << "|" << setw(40) << table.at(i)->get_LFS() << "|" << setw(20) << table.at(i)->get_repcard_num() << "|" << setw(18) << table.at(i)->get_num_of_group() << "|" << endl;
		cout << line;
	}
}
Student* linear_search(string num_of_repord_card) {
	for (size_t i = 0; i < table.size(); i++) {
		if (table[i]->get_repcard_num() == num_of_repord_card)
			return table[i];
	}
	return nullptr;
}
Student* barrier_search(string report_card_number) {
	size_t counter = 0;
	if (table.back()->get_repcard_num()== report_card_number) return table.back();
	table.back()->set_report_num(report_card_number);
	for (counter = 0; table.at(counter)->get_repcard_num() != report_card_number; counter++) {}
	if (counter == table.size() - 1) return nullptr;
	return table.at(counter);
	
}