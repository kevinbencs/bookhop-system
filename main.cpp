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
		std::cout<<"Hiba: mysql nem nyílt meg"<<std::endl;
	}
	else
	{
		if (!mysql_real_connect(book_shop, HOST, NAME, PASS,"bookshop", 3306, NULL,0))
		{
			std::cout<<"Nem sikerült csatlakozni a MYSQL adatbázishoz"<<std::endl;
			std::cout<<mysql_error(book_shop)<<std::endl;
		}
		else
		{
			while(ProgramIsOpened)
			{
				
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				std::cout<<"KÖNYVEBOLT MENEDZSMENT RENDSZER"<<std::endl;
				std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
				std::cout<<"1: könyvek"<<std::endl;
				std::cout<<"2: rendelések"<<std::endl;
				std::cout<<"3: alkalmazottak"<<std::endl;
				std::cout<<"0: kilépés"<<std::endl;
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
					std::cout<<"Rossz számot adott meg."<<std::endl;
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
		std::cout<<"Könyvek"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: új könyv bevitele"<<std::endl;
		std::cout<<"2: könyv adatainak megváltoztatása"<<std::endl;
		std::cout<<"3: könyv törlése"<<std::endl;
		std::cout<<"4: egy könyv adatainak megjelenítése"<<std::endl;
		std::cout<<"5: az összes könyv adatainak megjelenítése"<<std::endl;
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
			std::cout<<"Rossz számot adott meg."<<std::endl;
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
		std::cout<<"Rendelések"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: rendelés bevitele"<<std::endl;
		std::cout<<"2: rendelés adatainak megváltoztatása"<<std::endl;
		std::cout<<"3: rendelés törlése"<<std::endl;
		std::cout<<"4: rendelés megjelenítése"<<std::endl;
		std::cout<<"5: az összes rendelés adatainak megjelenítése"<<std::endl;
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
			std::cout<<"Rossz számot adott meg."<<std::endl;
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
		std::cout<<"Munkavállalók"<<std::endl;
		std::cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<std::endl;
		std::cout<<"1: új munkavállaló adatainak bevitele"<<std::endl;
		std::cout<<"2: munkavállaló adatainak szerkesztése"<<std::endl;
		std::cout<<"3: munkavállaló törlése"<<std::endl;
		std::cout<<"4: egy munkavállaló adatainak megjelenítése"<<std::endl;
		std::cout<<"5: az összes munkavállaló adatainak megjelenítése"<<std::endl;
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
			std::cout<<"Rossz számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
	
}
