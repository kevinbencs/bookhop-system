#include "Book.h"
#include <string>
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>

Book::Book()
{
	
}

Book::add(MYSQL* book_shop)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	
	std::cout<<"Add meg az adatokat"<<std::endl;
	std::cout<<"Nev";
	getline(std::cin,name);
	std::cout<<std::endl;
	std::cout<<"Szerzo";
	getline(std::cin,author);
	std::cout<<std::endl;
	std::cout<<"Ar";
	std::cin>>price;
	std::cout<<std::endl;
	std::cout<<"Mennyiseg";
	std::cin>>quantity;
	std::cout<<std::endl;
	
	stmt<<"INSERT INTO book(name,author,price,quantity) VALUES ("<<name<<","<<author<<","<<price<<","<<quantity ")";
	query=stmt.str();
	q=query.c_str();
	
	if(mysql_ping(bookshop))
	{
		std::cout<<"Error, imposeble to connet"<<std::endl;
		std::cout<<mysql_error(employee1)<<std::endl;
	}
	
	mysql_query(book_shop,q);
	
	mysql_store_result(book_shop);
	
	
}

Book::change(MYSQL* book_shop)
{
	int number;
	bool FunctionIsOpened=true;
	bool LoopIsOpened=true;
	
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	std::cout<<"Melyik konyv adatait akarja megvaltoztatni?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadasa."<<std::endl;
	std::cout<<"2: kereses nev alapjan."<<std::endl;
	std::cout<<"0: vissza."<<std::endl;
	cin>>number;
	system("cls");
	
	while(FunctionIsOpened)
	{
	
		switch (number)
		{
			case 1:
			
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cin<<id;
			system("cls");
			
			while(LoopIsOpened)
			{
				std::cout<<"Mit szeretne megvaltoztatni?"<<std::endl;
				std::cout<<std::endl;
				std::cout<<"1: konyv neve."<<std::endl;
				std::cout<<"2: szerzo neve."<<std::endl;
				std::cout<<"3: konyv ara."<<std::endl;
				std::cout<<"4: konyv darabszama."<<std::endl;
				std::cout<<"0: vissza."<<std::endl;
				cin>>number;
				system("cls");
				
				switch (number)
				{
					case 1:
					std::cout<<"Adja meg a konyv uj nevet."<<std::endl;
					getline(std::cin,name);
					system("cls");
					stmt<<"UPDATE book SET name="<<name<<" WHERE id="<<id;
					query=stmt.str();
					q=query.c_str();
					
					if(mysql_ping(bookshop))
					{
						std::cout<<"Error, imposeble to connet"<<std::endl;
						std::cout<<mysql_error(employee1)<<std::endl;
					}
					
					mysql_query(book_shop,q);
					
					mysql_store_result(book_shop);
					LoopIsOpened=false;
					FunctionIsOpened=false;
					break;
					
					case 2:
					std::cout<<"Adja meg a szerzo uj nevet."<<std::endl;
					getline(std::cin,author);
					system("cls");
					stmt<<"UPDATE book SET author="<<author<<" WHERE id="<<id;
					query=stmt.str();
					q=query.c_str();
					
					if(mysql_ping(bookshop))
					{
						std::cout<<"Error, imposeble to connet"<<std::endl;
						std::cout<<mysql_error(employee1)<<std::endl;
					}
					
					mysql_query(book_shop,q);
					
					mysql_store_result(book_shop);
					LoopIsOpened=false;
					FunctionIsOpened=false;
					break;
					
					case 3:
					std::cout<<"Adja meg az uj arat."<<std::endl;
					std::cin>>price;
					system("cls");
					stmt<<"UPDATE book SET price="<<price<<" WHERE id="<<id;
					query=stmt.str();
					q=query.c_str();
					
					if(mysql_ping(bookshop))
					{
						std::cout<<"Error, imposeble to connet"<<std::endl;
						std::cout<<mysql_error(employee1)<<std::endl;
					}
					
					mysql_query(book_shop,q);
					
					mysql_store_result(book_shop);
					LoopIsOpened=false;
					FunctionIsOpened=false;
					break;
					
					case 4:
					std::cout<<"Adja meg a konyv darabszamat."<<std::endl;
					std::cin>>quantity;
					system("cls");
					stmt<<"UPDATE book SET quantity="<<quantity<<" WHERE id="<<id;
					query=stmt.str();
					q=query.c_str();
					
					if(mysql_ping(bookshop))
					{
						std::cout<<"Error, imposeble to connet"<<std::endl;
						std::cout<<mysql_error(employee1)<<std::endl;
					}
					
					mysql_query(book_shop,q);
					
					mysql_store_result(book_shop);
					LoopIsOpened=false;
					FunctionIsOpened=false;
					break;
					
					case 0:
					LoopIsOpened=false;
					break;
					
				}
			}
			break;
			
			case 2:
			getline(std::cin,name);
			FunctionIsOpened=false;
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem jo szamot adott meg."<<std::endl;
		}
	}
	
}


Book::remove_book(MYSQL* book_shop)
{
	int number;
	bool FunctionIsOpened=true;
	
	std::cout<<"Kit akar kitorolni az adatbazisbol?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadása"<<std::endl;
	std::cout<<"2: kereses nev alapjan."<<std::endl;
	std::cout<<"0: vissza."<<std::endl;
	cin>>number;
	
	while(FunctionIsOpened)
	{
	
		switch (number)
		{
			case 1:
			std::cin<<id;
			FunctionIsOpened=false;
			break;
			
			case 2:
			getline(std::cin,name);
			FunctionIsOpened=false;
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem jo szamot adott meg."<<std::endl;
		}
	}
	
}

Book::~Book()
{
	
}


