#include <string>
#include <mysql.h>

#ifndef EMPLOYEES_H
#define EMPLOYEES_H

class Employees
{
	Employees();
	
	~Employees();
	
	void add(MYSQL* book_shop);
	
	void change(MYSQL* book_shop);
	
	void remove_employee(MYSQL* book_shop);
	
	void get(MYSQL* book_shop);
	
	void get_all(MYSQL* book_shop);
	
	
private:
	
	int id;
	std::string name;
	std::string country;
	std::string city;
	std::string address;
	int salary;
	std::string joining_date;
	std::string position;
	
};

#endif