#include "Student_Staff.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Staff.h"
using namespace std;

Student_Staff::Student_Staff() {
	stdcount = 0;
	staffcount = 0;
	string fname1, lname1, fname2, lname2, phonenbr, dateofbirth;
	int id{ 0 }, syear{ 0 };
	double gpa{ 0.0 }, credits{ 0.0 }, salary{ 0.0 };
	char program{ '\0' }, bonuscode{ '\0' };
	int day{ 0 }, month{ 0 }, year{ 0 };
	ifstream readstudents, readstaff;
	readstudents.open("student.txt");
	readstaff.open("staff.txt");

	//checking if files were opened successfully 
	if (!readstudents) {
		cerr << "ERROR READING FILE\n";
		exit(0);
	};
	if (!readstaff) {
		cerr << "ERROR READING FILE\n";
		exit(0);
	};

	// counting number of students
	while (
		readstudents >> fname1 >> lname1 >> id >> dateofbirth >> gpa >> syear >> credits >> program)
	{
		stdcount++;
	};
	readstudents.close(); //closing the file

	//Allocating an array of students using a pointer
	students = new Student[stdcount];

	//opening the file again to store the data
	readstudents.open("student.txt");
	//filling the array
	for (int i = 0; i < stdcount; i++) {
		//reads inputs from a file
		readstudents >> fname1 >> lname1 >> id >> dateofbirth >> gpa >> syear >> credits >> program;
		//creating a student using constructor from class Student
		students[i] = Student(fname1, lname1, id, dateofbirth, gpa, syear, credits, program);
	}
	//The array is complete... closig the file
	readstudents.close();

	//counting number of staff
	while (
		readstaff >> fname2 >> lname2 >> id >> phonenbr >> day >> month >> year >> bonuscode >> salary)
	{
		staffcount++;
	};
	readstaff.close();

	//creaitng an array of staff
	staff = new Staff[staffcount];

	readstaff.open("staff.txt");

	//filling the array
	for (int i = 0; i < staffcount; i++) {
		readstaff >> fname2 >> lname2 >> id >> phonenbr >> day >> month >> year >> bonuscode >> salary;
		staff[i] = Staff(fname2, lname2, id, phonenbr, bonuscode, salary, day, month, year);

	};
	readstaff.close();


}

//fucntion to display the student wiht highest gpa(Array is given by the  user)
void Student_Staff::Highest_GPA(Student A[], int x) {
	//setting the grade of first student as highest
	int highestgpa = A[0].getgpa();
	int pos = 0;
	for (int i = 1; i < x; i++) {
		if (A[i].getgpa() > highestgpa) {
			pos = i;

		};

	};
	cout << "\nThe student with the  highest GPA is " << A->getfname() << " " << A->getlname() << " with a GPA " << A->getgpa() << endl;
}

//Same function as before but displaying the array imported from the text file
void Student_Staff::Highest_GPA_txt() {
	Highest_GPA(students, stdcount);
}

//function to return the number of undergraduates from a given array
int Student_Staff::N_of_UnderGrad(Student A[], int x) {
	int nb = 0;
	for (int i = 0; i < x; i++) {
		if ((char)A[i].getprogram() == 'B') {
			nb++;
		};


	}
	return nb;
}

// Same function as before but using the array given by txt
int Student_Staff::N_of_UnderGrad_txt() {
	return N_of_UnderGrad(students, stdcount);
}

//function to display the names of employees hired during the same year given by user
void Student_Staff::Same_Hire_Year(Staff A[], int x, int y) {
	cout << "\nList of employees hired during " << y << ":" << endl;
	for (int i = 0; i < x; i++) {
		if (A[i].getyearhired() == y) {
			cout << A[i].getfname() << " " << A[i].getlname() << endl;

		}

	}
}

// same function as before but using the array from txt
void Student_Staff::Same_Hire_Year_txt(int y) {
	Same_Hire_Year(staff, staffcount, y);
}

void Student_Staff::displaystudents() {

	for (int i = 0; i < stdcount; i++) {
		students[i].Print_Std_Info();
	}
}
void Student_Staff::displaystaff() {
	for (int i = 0; i < stdcount; i++) {
		staff[i].Print_Stf_Info();
	}

}