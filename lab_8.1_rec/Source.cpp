#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

using namespace std;

void print_line(char* s, int i) {

	if (i == 0) {
		cout << "line: ";
	}
	cout << s[i];
	if (s[i+1] != '\0') {
		print_line(s, i + 1);
	}
	else {
		cout << endl;
	}

}

int count(char* s, int i, int k,int i_s) {


	if (s[i] == '.') {
		k++;
		i_s = i;
	}

	if (i >= 0 && k != 4) {
		return count(s, i -1, k, i_s);
	}
	else if (k < 4) {
		return -1;
	}
	else {
		return i_s;
	}


}

void move_insert(char* s, int i, int k) {
	s[k + 1] = s[k];
	if (k > i + 1) {
		move_insert(s, i, k - 1);
	}
}

void chenge(char* s, int i) {
		if (s[i] == '.') {
			move_insert(s, i, strlen(s));
			s[i] = '*';
			s[i + 1] = '*';
		}

		if (s[i+1] != '\0') {
			chenge(s, i + 1);
		}
}



void main() {
	char s[101];


	cout << "Enter string: "; cin.getline(s, 100);
	print_line(s, 0);

	int p = count(s, strlen(s), 0, 0);

	chenge(s,0);

	print_line(s, 0);

	cout << "4th \".\" on position " << p << endl;
}