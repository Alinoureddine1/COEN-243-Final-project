#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor to initialize an object
Student::Student() {
	fname = "";
	lname = "";
	id = 0;
	dateofbirth = "";
	gpa = 0.0;
	syear = 0;
	credits = 0.0;
	program = '\0';

}

//Constructor with initialized elements
Student::Student(string& a, string& b, int c, string& d, double e, int f, double h, char j) {
	fname = a;
	lname = b;
	id = c;
	dateofbirth = d;
	gpa = e;
	syear = f;
	credits = h;
	program = j;
}

//setter and getter fuctions
void Student::setfname(string& x) {
	fname = x;
}

string Student::getfname() {
	return fname;
}

void Student::setlname(string& x) {

	lname = x;
}

string Student::getlname() {

	return lname;
}

void Student::setid(int x) {
	id = x;

}

int Student::getid() {
	return id;
}

void Student::setbdate(string& x) {
	dateofbirth = x;

}

string  Student::getbdate() {
	return dateofbirth;
}

void Student::setgpa(double x) {
	gpa = x;
}

double Student::getgpa() {
	return gpa;
}

void Student::setsyear(int x) {
	syear = x;
}

int Student::getsyear() {
	return syear;
}

void Student::setcredits(double x) {
	credits = x;
}

double Student::getcredits() {
	return credits;

}

void Student::setprogram(char x) {
	program = x;
}

char Student::getprogram() {
	return program;
}

bool Student::CompleteProgram() {

	switch (program) {
	case 'B':
		if (credits == 140.0) {
			return true;
		}
		else { return false; };
		break;
	case 'M':
		if (credits == 16.0) { return true; }
		else { return false; };
		break;
	case 'P':
		if (credits == 12.0) { return true; }
		else { return false; };
		break;
	default:
		break;
	};

}

string Student::StudentStatus() {

	if (gpa >= 3.5) {
		return "A+";
	}
	else if (gpa >= 3 && gpa < 3.5) {
		return "A";
	}
	else if (gpa >= 2.5 && gpa < 3) {
		return "B";
	}
	else if (gpa >= 2 && gpa < 2.5) {
		return "C";

	}
	else { return "D"; };
}

// printing all student details
void Student::Print_Std_Info() {
	cout << "\nprinting Info for Student #" << id << ":\n";
	cout << "First name: " << fname << endl;
	cout << "Last name: " << lname << endl;
	cout << "ID: " << id << endl;
	cout << "Date of birth: " << dateofbirth << endl;
	cout << "GPA: " << fixed << setprecision(1) << gpa << endl;
	cout << "Start year: " << syear << endl;
	cout << "Credits completed: " << credits << endl;
	cout << "Program: " << program << endl;
	cout << "Student Status: " << StudentStatus() << endl;
	if (CompleteProgram()) { cout << "Student has completed their program." << endl; }
	else { cout << "Student has not yet completed their program\n"; };
}

int Student::Comapre_GPA(Student a, Student b) {
	if (a.gpa > b.gpa) { return a.id; }
	else { return b.id; };
}
