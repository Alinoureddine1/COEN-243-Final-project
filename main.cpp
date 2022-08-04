
#include "Student_Staff.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Staff.h"
using namespace std;

int main()
{
	string fname;
	string lname;
	int id = 0;
	string dateofbirth;
	double gpa = 0;
	int syear = 0;
	double credits = 0;
	char program = 0;
	Student test;


	Student_Staff conU;
	conU.Highest_GPA_txt();
	cout << "The nb of undergraduate students is:" << conU.N_of_UnderGrad_txt() << endl;
	conU.displaystudents();
	conU.displaystaff();
	conU.Same_Hire_Year_txt(2002);


	//testing the exception handling in case a user wanted to enter a student
	cout << "Enter first name of the student: ";
	cin >> fname;
	cout << "Enter the Last Name: ";
	cin >> lname;
	cout << "Enter ID: ";
	cin >> id;
	cout << "ENter dat of birth: ";
	cin >> dateofbirth;

	cout << "Enter the GPA (between 0 and 4.4 only): ";
	cin >> gpa;
	try {

		if (gpa < 0 || gpa> 4.4) {
			throw gpa;
		}


	}
	catch (int ex) {
		cout << "This GPA IS invalid" << ex;


	}
	cout << "gpa recorded successfully " << gpa << endl;


	cout << "Enter the year this student started school: ";
	cin >> syear;

	cout << "Enter the number of credits completed: ";
	cin >> credits;

	cout << "Enter the program\nB:Bachelor\nM:Masters\nP:PHDs\n";
	cin >> program;
	try {
		if (program != 'B' && program != 'M' && program != 'P') { throw program; }

	}
	catch (char ex) {
		cout << "The char entered is not an option\n";

	}
	test = Student(fname, lname, id, dateofbirth, gpa, syear, credits, program);
}


