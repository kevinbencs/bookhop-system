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
	MYSQL* book_shop;
	
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
	
	if (!(book_shop=mysql_init(NULL)))
	{
		std::cout<<"Hiba: mysql nem nyilt meg"<<std::endl;
	}
	else
	{
		if (!mysql_real_connect(book_shop,"localhost", user_name, password,"bookshop", 3306, NULL,0))
		{
			std::cout<<"Failde to connected to MYSQL database"<<std::endl;
			std::cout<<mysql_error(book_shop)<<std::endl;
		}
		else
		{
			//program többi része
			
			
			
			
		}
		
	}
	
	
	
	
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"Hol szeretnel valtoztatni?"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"1: konyvek"<<std::endl;
	std::cout<<"2: rendelesek"<<std::endl;
	std::cout<<"3: alkalmazottak"<<std::endl;
	std::cout<<"0: kilepes"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	cin>>number;
	
	
	
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"Mit szeretnel csinalni?"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"1: konyvek"<<std::endl;
	std::cout<<"2: rendelesek"<<std::endl;
	std::cout<<"3: alkalmazottak"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	cin>>number;
	
	
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"Mit szeretnel csinalni?"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"1: konyvek"<<std::endl;
	std::cout<<"2: rendelesek"<<std::endl;
	std::cout<<"3: alkalmazottak"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	cin>>number;
	
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"Mit szeretnel csinalni?"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	std::cout<<"1: konyvek"<<std::endl;
	std::cout<<"2: rendelesek"<<std::endl;
	std::cout<<"3: alkalmazottak"<<std::endl;
	std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	cin>>number;
	
	
	
	
	
	return 0;
}