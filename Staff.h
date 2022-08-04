#pragma once
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
#include <iomanip>
using namespace std;


struct Date {
	int day;
	int month;
	int year;


};

class Staff
{
private:
	string fname;
	string lname;
	int id;
	string phonenbr;
	char bonuscode;
	double currentsalary;
	Date date;
public:
	Staff();
	Staff(string&, string&, int, string&, char, double, int, int, int);
	void setfname(string&);
	string getfname();
	void setlname(string&);
	string getlname();
	void setid(int);
	int getid();
	void setdate(int, int, int);
	int getyearhired();
	string getdate();
	string getphonenbr();
	void setphonenbr(string&);
	double getsalary();
	void setsalary(double);
	char getbonuscode();
	void setbonuscode(char);
	void Print_Stf_Info();
	double Calculate_Salary();
	string Compare_Exp(Staff, Staff);
};

