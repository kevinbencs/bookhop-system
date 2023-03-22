#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
#include "Book.h"
#include "Employee.h"
#include "Orders.h"

char* HOST="localhost";
char* NAME="root";
char* PASS="";


void books(MYSQL* book_shop);

void employees(MYSQL* book_shop);

void orders(MYSQL* book_shop);

int main()
{
	MYSQL* book_shop;

	int choice;
	bool ProgramIsOpened=true;
	setlocale(LC_ALL,"hun");
	
	//connect mysql
	if (!(book_shop=mysql_init(NULL)))
	{
		std::cout<<"Hiba: mysql nem ny�lt meg"<<std::endl;
	}
	else
	{
		if (!mysql_real_connect(book_shop, HOST, NAME, PASS,"bookshop", 3306, NULL,0))
		{
			std::cout<<"Nem siker�lt csatlakozni a MYSQL adatb�zishoz"<<std::endl;
			std::cout<<mysql_error(book_shop)<<std::endl;
		}
		else
		{
			while(ProgramIsOpened)
			{
				
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				std::cout<<"K�NYVEBOLT MENEDZSMENT RENDSZER"<<std::endl;
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				std::cout<<"1: k�nyvek"<<std::endl;
				std::cout<<"2: rendel�sek"<<std::endl;
				std::cout<<"3: alkalmazottak"<<std::endl;
				std::cout<<"0: kil�p�s"<<std::endl;
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				std::cin>>choice;
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
					orders(book_shop);
					break;
					
					case 3:
					employees(book_shop);
					break;
					
					default:
					std::cout<<"Rossz sz�mot adott meg."<<std::endl;
					std::cout<<std::endl;
				}
			}
		}
	}
	
	mysql_close(book_shop);
	
	return 0;
}







void books(MYSQL* book_shop)
{
	int choice;
	Book first;
	bool BookIsOpened=true;
	
	while(BookIsOpened)
	{
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"K�nyvek"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: �j k�nyv bevitele"<<std::endl;
		std::cout<<"2: k�nyv adatainak megv�ltoztat�sa"<<std::endl;
		std::cout<<"3: k�nyv t�rl�se"<<std::endl;
		std::cout<<"4: egy k�nyv adatainak megjelen�t�se"<<std::endl;
		std::cout<<"5: az �sszes k�nyv adatainak megjelen�t�se"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		
		std::cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 0:
			BookIsOpened=false;
			break;
			
			//give data of new book
			case 1:
			first.add(book_shop,BookIsOpened);
			break;
			
			//update book details
			case 2:
			first.change(book_shop,BookIsOpened);
			break;
			
			//remove one book from database
			case 3:
			first.remove(book_shop,BookIsOpened);
			break;
			
			//display data of one book
			case 4:
			first.get(book_shop,BookIsOpened);
			break;
			
			//display data of all books
			case 5:
			first.all_get(book_shop,BookIsOpened);
			break;
			
			default:
			std::cout<<"Rossz sz�mot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
	
}






void orders(MYSQL* book_shop)
{
	int choice;
	Orders first;
	bool OrdersIsOpened=true;
	
	while(OrdersIsOpened)
	{
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"Rendel�sek"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: rendel�s bevitele"<<std::endl;
		std::cout<<"2: rendel�s adatainak megv�ltoztat�sa"<<std::endl;
		std::cout<<"3: rendel�s t�rl�se"<<std::endl;
		std::cout<<"4: rendel�s megjelen�t�se"<<std::endl;
		std::cout<<"5: az �sszes rendel�s adatainak megjelen�t�se"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	
		std::cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 0:
			OrdersIsOpened=false;
			break;
			
			//give data of new order
			case 1:
			first.add(book_shop,OrdersIsOpened);
			break;
			
			//update order details
			case 2:
			first.change(book_shop,OrdersIsOpened);
			break;
			
			//remove one order from database
			case 3:
			first.remove(book_shop,OrdersIsOpened);
			break;
			
			//display data of one order
			case 4:
			first.get(book_shop,OrdersIsOpened);
			break;
			
			//display data of all orders
			case 5:
			first.all_get(book_shop,OrdersIsOpened);
			break;
			
			default:
			std::cout<<"Rossz sz�mot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
	
}








void employees(MYSQL* book_shop)
{
	int choice;
	Employees first;
	bool EmployeeIsOpened=true;
	
	while(EmployeeIsOpened)
	{
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"Munkav�llal�k"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: �j munkav�llal� adatainak bevitele"<<std::endl;
		std::cout<<"2: munkav�llal� adatainak szerkeszt�se"<<std::endl;
		std::cout<<"3: munkav�llal� t�rl�se"<<std::endl;
		std::cout<<"4: egy munkav�llal� adatainak megjelen�t�se"<<std::endl;
		std::cout<<"5: az �sszes munkav�llal� adatainak megjelen�t�se"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
	
		std::cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 0:
			EmployeeIsOpened=false;
			break;
			
			//give data of new employee
			case 1:
			first.add(book_shop,EmployeeIsOpened);
			break;
			
			//update employee details
			case 2:
			first.change(book_shop,EmployeeIsOpened);
			break;
			
			//remove one employee from database
			case 3:
			first.remove(book_shop,EmployeeIsOpened);
			break;
			
			//display data of one employee
			case 4:
			first.get(book_shop,EmployeeIsOpened);
			break;
			
			//display data of all employees
			case 5:
			first.all_get(book_shop,EmployeeIsOpened);
			break;
			
			default:
			std::cout<<"Rossz sz�mot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
	
}
