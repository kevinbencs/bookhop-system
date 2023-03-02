#include <string>
#include <mysql.h>

#ifndef EMPLOYEES_H
#define EMPLOYEES_H

class Employees
{
	Employees();
	
	~Employees();
	
	
private:
	
	int id;
	std::string country;
	std::string city;
	std::string address1;
	int salary;
	std::string joining_date;
	std::string position;
	
};

#endif