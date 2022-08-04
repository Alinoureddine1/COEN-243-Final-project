#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Student
{
private:
	string fname;
	string lname;
	int id;
	string dateofbirth;
	double gpa;
	int syear;
	double credits;
	char program;

public:
	Student();
	Student(string&, string&, int, string&, double, int, double, char);
	void setfname(string&);
	string getfname();
	void setlname(string&);
	string getlname();
	void setid(int);
	int getid();
	void setbdate(string&);
	string getbdate();
	void setgpa(double);
	double getgpa();
	void setsyear(int);
	int getsyear();
	void setcredits(double);
	double getcredits();
	void setprogram(char);
	char getprogram();
	bool CompleteProgram();
	string StudentStatus();
	void Print_Std_Info();
	int Comapre_GPA(Student, Student);


};

