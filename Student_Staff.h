#pragma once
#include "Staff.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Student.h"
using namespace std;


class Student_Staff {

private:
	int stdcount;
	int staffcount;
	Student* students;
	Staff* staff;

public:
	Student_Staff();
	void Highest_GPA(Student A[], int x);
	void Highest_GPA_txt();
	int N_of_UnderGrad(Student A[], int x);
	int N_of_UnderGrad_txt();
	void Same_Hire_Year(Staff A[], int x, int y);
	void Same_Hire_Year_txt(int y);
	void displaystudents();
	void displaystaff();
};

