#include <iostream>
#include <mysql.h>
#include <vector>
#include <string>
#include <mysqld_error.h>
#include "Book.h"
#include "Employees.h"
#include "Orders.h"


int main()
{
	std::string user_name;
	std::string password;
	int number;
	
	std::cout<<"Log in:"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"User name: ";
	getline(std::cin,user_name);
	std::cout<<std::endl;
	std::cout<<"Password: ";
	std::cin>>password;
	
	
	system("cls");
	
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"Mit szeretnél csinálni?"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"1: konyvek"<<std::endl;
	std::cout<<"2: rendelesek"<<std::endl;
	std::cout<<"3: alkalmazottak"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	cin>>number;
	
	
	
	
	
	return 0;
}