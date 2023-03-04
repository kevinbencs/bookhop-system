#include <iostream>
#include <mysql.h>
#include <vector>
#include <string>
#include <mysqld_error.h>
#include "Book.h"
#include "Employees.h"
#include "Orders.h"


void book();

void employees();

void orders();

int main()
{
	MYSQL* book_shop;
	
	std::string user_name;
	std::string password;
	int number;
	bool ProgramIsOpened=true;
	
	
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
			while(ProgramIsOpened)
			{
				
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				std::cout<<"Hol szeretnel valtoztatni?"<<std::endl;
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				std::cout<<"1: konyvek"<<std::endl;
				std::cout<<"2: rendelesek"<<std::endl;
				std::cout<<"3: alkalmazottak"<<std::endl;
				std::cout<<"0: kilepes"<<std::endl;
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				cin>>number;
				system("cls");
				
				
				switch (number)
				{
					case 0:
					ProgramIsOpened=false;
					break;
					
					case 1:
					book();
					break;
					
					
					case 2:
					employees();
					break;
					
					case 3:
					orders();
					break;
					
					default:
					std::cout<<"Rossz számot adott meg."<<std::endl;
					std::cout<<std::endl;
					
				}
				
				
			}
			
			
		}
		
		
	}
	
	
	
	
	return 0;
}



void book()
{
	int number;
	Book first;
	bool FunctionIsOpened=true;
	
	while(FunctionIsOpened)
	{
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"Mit szeretnel csinalni?"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: uj konyv bevitele"<<std::endl;
		std::cout<<"2: konyv adatainak megvaltoztatasa"<<std::endl;
		std::cout<<"3: konyv torlese"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		
		cin>>number;
		system("cls");
		
		switch (number)
		{
			case 0:
			FunctionIsOpened=false;
			break;
			
			case 1:
			first.set();
			FunctionIsOpened=false;
			break;
			
			case 2:
			first.change()
			FunctionIsOpened=false;
			break;
			
			case 3:
			first.remove();
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Rossz számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
		
		
	}
	
	
	
	
}


void employees()
{
	int number;
	Employees first;
	bool FunctionIsOpened=true;
	
	while(FunctionIsOpened)
	{
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"Mit szeretnel csinalni?"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: rendelés bevitele"<<std::endl;
		std::cout<<"2: rendeles adatainak megvaltoztatasa"<<std::endl;
		std::cout<<"3: rendeles torlese"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	
		cin>>number;
		system("cls");
		
		switch (number)
		{
			case 0:
			FunctionIsOpened=false;
			break;
			
			case 1:
			first.set();
			FunctionIsOpened=false;
			break;
			
			case 2:
			first.change()
			FunctionIsOpened=false;
			break;
			
			case 3:
			first.remove();
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Rossz számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
		
		
	}
	
	
	
}

void orders()
{
	int number;
	Employees first;
	bool FunctionIsOpened=true;
	
	while(FunctionIsOpened)
	{
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"Mit szeretnel csinalni?"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: uj munkavallalo adatainak bevitele"<<std::endl;
		std::cout<<"2: munkavallalo adatainak szerkesztese"<<std::endl;
		std::cout<<"3: munkavallalo torlese"<<std::endl;
		std::cout<<"4: egy munkavallalo adatainak megtekintese"<<std::endl;
		std::cout<<"5: az osszes munkavallalo adatainak megtekintese"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	
		cin>>number;
		system("cls");
		
		switch (number)
		{
			case 0:
			FunctionIsOpened=false;
			break;
			
			case 1:
			first.set();
			FunctionIsOpened=false;
			break;
			
			case 2:
			first.change()
			FunctionIsOpened=false;
			break;
			
			case 3:
			first.remove();
			FunctionIsOpened=false;
			break;
			
			case 4:
			first.get();
			FunctionIsOpened=false;
			break;
			
			case 5:
			first.get_all();
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Rossz számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
		
		
	}
	

	
	
	
	
	
}