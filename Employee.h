#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <string>
#include <mysql.h>



class Employees
{
public:
	
	Employees();
	
	~Employees();
	
	void add(MYSQL* ,bool &); //give data of new employee
	
	void change(MYSQL* ,bool &); //update employee details
	
	void remove(MYSQL* ,bool &); //remove one employee from database
	
	void get(MYSQL* ,bool &); //display data of one employee
	
	void all_get(MYSQL* ,bool &); //display data of all employees
	
	
private:
	
	int id; // Primary key
	std::string name;
	std::string country;
	std::string city;
	std::string address;
	int salary;
	std::string joining_date;
	std::string position;
	
};

#endif
