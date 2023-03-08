#include <iostream>
#include <mysql.h>
#include <vector>
#include <string>
#include <mysqld_error.h>
#include "Book.h"
#include "Employees.h"
#include "Orders.h"

HOST="localhost";
NAME="root";
PASS="WaTHjid1";


FUNCTIONISOPENED-ET BE KELL RAKNI A FUGGVENYEKBE

void books(MYSQL* book_shop);

void employees(MYSQL* book_shop);

void orders(MYSQL* book_shop);

int main()
{
	MYSQL* book_shop

	
	int choice;
	bool ProgramIsOpened=true;
	
	if (!(book_shop=mysql_init(NULL)))
	{
		std::cout<<"Hiba: mysql nem nyilt meg"<<std::endl;
	}
	else
	{
		if (!mysql_real_connect(book_shop, HOST, NAME, PASS,"bookshop", 3306, NULL,0))
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
				cin>>choice;
				system("cls");
				
				
				switch (choice)
				{
					case 0:
					ProgramIsOpened=false;
					break;
					
					case 1:
					books(book_shop);
					break;
					
					
					case 2:
					employees(book_shop);
					break;
					
					case 3:
					orders(book_shop);
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



void books(MYSQL* book_shop)
{
	int choice;
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
		std::cout<<"4: konyv adatainak megjelenitese"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		
		cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 0:
			FunctionIsOpened=false;
			break;
			
			case 1:
			first.add(book_shop);
			FunctionIsOpened=false;
			break;
			
			case 2:
			first.change(book_shop)
			FunctionIsOpened=false;
			break;
			
			case 3:
			first.remove_book(book_shop);
			FunctionIsOpened=false;
			break;
			
			case 4:
			first.get(book_shop);
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Rossz számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
		
		
	}
	
	
}


void orders(MYSQL* book_shop)
{
	int choice;
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
	
		cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 0:
			FunctionIsOpened=false;
			break;
			
			case 1:
			first.add(book_shop);
			FunctionIsOpened=false;
			break;
			
			case 2:
			first.change(book_shop)
			FunctionIsOpened=false;
			break;
			
			case 3:
			first.remove_employee(book_shop);
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Rossz számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
		
		
	}
	
	
}

void employees(MYSQL* book_shop)
{
	int choice;
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
	
		cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 0:
			FunctionIsOpened=false;
			break;
			
			case 1:
			first.add(book_shop);
			FunctionIsOpened=false;
			break;
			
			case 2:
			first.change(book_shop)
			FunctionIsOpened=false;
			break;
			
			case 3:
			first.remove_order(book_shop);
			FunctionIsOpened=false;
			break;
			
			case 4:
			first.get(book_shop);
			FunctionIsOpened=false;
			break;
			
			case 5:
			first.get_all(book_shop);
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Rossz számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
		
		
	}
	
	
}