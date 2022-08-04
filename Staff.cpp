#include "Staff.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

// Constructor to initialize an object
Staff::Staff() {
	fname = "";
	lname = "";
	id = 0;
	phonenbr = "";
	bonuscode = '\0';
	currentsalary = 0;
	date.day = 0;
	date.month = 0;
	date.year = 0;

}

//Constructor with initialized elements
Staff::Staff(string& a, string& b, int c, string& d, char e, double f, int g, int h, int i) {
	fname = a;
	lname = b;
	id = c;
	phonenbr = d;
	bonuscode = e;
	currentsalary = f;
	date.day = g;
	date.month = h;
	date.year = i;

}

//getter / setter functions
int Staff::getyearhired() {
	return date.year;
}

void Staff::setfname(string& x) {
	fname = x;
}

string Staff::getfname() {
	return fname;
}

void Staff::setlname(string& x) {
	lname = x;
}

string Staff::getlname() {
	return lname;
}

void  Staff::setid(int x) {
	id = x;
}

int Staff::getid() {
	return id;
}

void Staff::setdate(int x, int y, int z) {
	date.day = x;
	date.month = y;
	date.year = z;
}

//string stream to build up a string
string Staff::getdate() {
	stringstream ss;
	string s;
	char x = '/';
	ss << date.day << x << date.month << x << date.year;
	ss >> s;
	return s;

}

string Staff::getphonenbr() {
	return phonenbr;
}

void Staff::setphonenbr(string& x) {
	phonenbr = x;
}
double Staff::getsalary() {
	return currentsalary;
}
void Staff::setsalary(double x) {
	currentsalary = x;
}
char Staff::getbonuscode() {
	return bonuscode;
}
void Staff::setbonuscode(char x) {
	bonuscode = x;
}

// print staff function
void Staff::Print_Stf_Info() {

	cout << "\nPrinting Info for Staff member #" << id << ":" << endl;
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "ID: " << id << endl;
	cout << "Phone number: " << phonenbr << endl;
	cout << "Date of hiring: " << getdate() << endl;
	cout << "Bonus code: " << bonuscode << endl;
	cout << "Current salary: $" << currentsalary << endl;
	cout << "Salary after bonus: $" << Calculate_Salary() << endl;
}

//function to calculate the new salary after bonus
double Staff::Calculate_Salary() {
	switch (bonuscode) {
	case 'A':
		return currentsalary * 1.08;
		break;

	case 'B':
		return currentsalary * 1.06;
		break;

	case 'C':
		return currentsalary * 1.03;
		break;

	case 'D':
		return currentsalary * 1.01;
		break;

	case 'E':
		return currentsalary;
		break;

	default:
		cout << "Error\n";
		return 0;
		break;
	}
}

// function to printout the name of the employee with more experience
string Staff::Compare_Exp(Staff a, Staff b) {
	if (a.date.year < b.date.year) {
		return a.fname + " " + a.lname;

	}
	else if (a.date.year > b.date.year) {
		return b.fname + " " + b.lname;

	}
	else {

		if (a.date.month < b.date.month) {
			return a.fname + " " + a.lname;
		}
		else if (a.date.month > b.date.month) {
			return b.fname + " " + b.lname;
		}
		else {
			if (a.date.day < b.date.day) {
				return a.fname + " " + a.lname;
			}
			else if (a.date.day > b.date.day) {
				return b.fname + " " + b.lname;

			}
			else { return a.fname + " " + a.lname; }
		};
	}
}