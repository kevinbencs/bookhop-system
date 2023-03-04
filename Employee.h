#include <string>
#include <mysql.h>

#ifndef EMPLOYEES_H
#define EMPLOYEES_H

class Employees
{
	Employees();
	
	~Employees();
	
	add(MYSQL* book_shop);
	
	change(MYSQL* book_shop);
	
	remove_employee(MYSQL* book_shop);
	
	
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