#include <string>
#include "Employees.h"
#include <mysql.h>
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>



void get_helper(MYSQL* book_shop,int &id)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM book WHERE id="<<id;
	query=stmt.str();
	q=query.c_str();
	
	if (mysql_ping(book_shop))
	{
		std::cout<<"Error, imposeble to connet"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	mysql_query(book_shop,q);
	
	
	res_set=mysql_store_result(book_shop);
	
	if((row = mysql_fetch_row(res_set)) != NULL)
    {
		std::cout << "A konyv id-je " << row[0] <<std::endl;
        std::cout << "A konyv cime  " << row[1] <<std::endl;
		std::cout << "A szerzo neve " << row[2] <<std::endl;
        std::cout << "A konyv ara " << row[3] <<std::endl;
		std::cout << "Peldanyszam " << row[4] <<std::endl;
	}
	else
	{
		std::cout << "Nincs talalat az ID-re" << std::endl;
	}
	
	
	
}

void change_helper(MYSQL* book_shop,int &id,bool &FunctionIsOpened)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	bool LoopIsOpenedbool=true;
	int choice;
	
	
	stmt<<"SELECT * FROM book WHERE id="<<id;
	query=stmt.str();
	q=query.c_str();
	
	if (mysql_ping(book_shop))
	{
		std::cout<<"Error, imposeble to connet"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	mysql_query(book_shop,q);
	
	
	res_set=mysql_store_result(book_shop);
	
	if((row = mysql_fetch_row(res_set)) == NULL)
    {
		std::cout << "Nincs talalat az ID-re" << std::endl;
	}
	else
	{
	
		while(LoopIsOpened)
		{
			std::cout<<"Mit szeretne megvaltoztatni?"<<std::endl;
			std::cout<<std::endl;
			std::cout<<"1: konyv neve."<<std::endl;
			std::cout<<"2: szerzo neve."<<std::endl;
			std::cout<<"3: konyv ara."<<std::endl;
			std::cout<<"4: konyv darabszama."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			cin>>choice;
			system("cls");
			
			switch (choice)
			{
				case 1:
				std::cout<<"Adja meg a konyv uj nevet."<<std::endl;
				getline(std::cin,name);
				system("cls");
				stmt<<"UPDATE book SET name="<<name<<" WHERE id="<<id;
				query=stmt.str();
				q=query.c_str();
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Error, imposible to connet"<<std::endl;
					std::cout<<mysql_error(book_shop)<<std::endl;
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
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Error, imposeble to connet"<<std::endl;
					std::cout<<mysql_error(book_shop)<<std::endl;
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
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Error, imposeble to connet"<<std::endl;
					std::cout<<mysql_error(book_shop)<<std::endl;
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
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Error, imposeble to connet"<<std::endl;
					std::cout<<mysql_error(book_shop1)<<std::endl;
				}
				
				mysql_query(book_shop,q);
				
				mysql_store_result(book_shop);
				LoopIsOpened=false;
				FunctionIsOpened=false;
				break;
				
				case 0:
				LoopIsOpened=false;
				break;
				
				default:
				std::cout<<"Rossz szamot adott meg."<<std::endl;
				std::cout<<std::endl;
					
			}
		}
	
	}
	
}


void remove_helper(MYSQL* book_shop,int &id,bool &FunctionIsOpened)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM book WHERE id="<<id;
	query=stmt.str();
	q=query.c_str();
	
	if (mysql_ping(book_shop))
	{
		std::cout<<"Error, imposeble to connet"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	mysql_query(book_shop,q);
	
	
	res_set=mysql_store_result(book_shop);
	
	if((row = mysql_fetch_row(res_set)) == NULL)
    {
		std::cout << "Nincs talalat az ID-re" << std::endl;
	}
	else
	{
		stmt<<"DELETE FROM book WHERE id="<<id;
		query=stmt.str();
		q=query.c_str();
		
		
		mysql_query(book_shop,q);
		mysql_store_result(book_shop);
		FunctionIsOpened=false;
	}
	
	
	
	
}

int search(MYSQL* book_shop, std::string &name)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	getline(std::cin,name);
	
	stmt<<"SELECT * FROM book WHERE name REGEXP " <<name;
	query=stmt.str();
	q=query.c_str();
	
	if(mysql_ping(book_shop))
	{
		std::cout<<"Error, imposeble to connet"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	mysql_query(book_shop,q);
	
	res_set=mysql_store_result(book_shop);
	
	if((row = mysql_fetch_row(res_set)) != NULL)
    {
		std::cout << "A konyv id-je " << row[0] <<std::endl;
        std::cout << "A konyv cime  " << row[1] <<std::endl;
		std::cout << "A szerzo neve " << row[2] <<std::endl;
        std::cout << "A konyv ara " << row[3] <<std::endl;
		std::cout << "Peldanyszam " << row[4] <<std::endl;
		return 0;
	}
	else
	{
		std::cout << "Nincs talalat" << std::endl;
		return 1;
	}
	
}



Book::Book()
{
	
}


void Book::add(MYSQL* book_shop)
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
	
	if(mysql_ping(book_shop))
	{
		std::cout<<"Error, imposeble to connet"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	mysql_query(book_shop,q);
	
	mysql_store_result(book_shop);
	
	
}

void Book::change(MYSQL* book_shop)
{
	int choice;
	bool FunctionIsOpened=true;
	
	std::cout<<"Melyik konyv adatait akarja megvaltoztatni?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadasa."<<std::endl;
	std::cout<<"2: kereses nev alapjan."<<std::endl;
	std::cout<<"0: vissza."<<std::endl;
	cin>>choice;
	system("cls");
	
	while(FunctionIsOpened)
	{
	
		switch (number)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cin<<id;
			system("cls");
			change_helper(book_shop,id,FunctionIsOpened);
			break;
			
			case 2:
			std::cout<<"Adja meg a nevet."<<std::endl;
			getline(std::cin,name);
			system("cls");
			search(MYSQL* book_shop, std::string name)
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cin<<id;
			system("cls");
			change_helper(book_shop,id,FunctionIsOpened);
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem jo szamot adott meg."<<std::endl;
		}
	}
	
}


void Book::remove_book(MYSQL* book_shop)
{
	int choice;
	bool FunctionIsOpened=true;
	
	std::cout<<"Melyik konyvet akarja kitorolni az adatbazisbol?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadása"<<std::endl;
	std::cout<<"2: kereses nev alapjan."<<std::endl;
	std::cout<<"0: vissza."<<std::endl;
	cin>>choice;
	
	while(FunctionIsOpened)
	{
	
		switch (number)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cin<<id;
			system("cls");
			remove_helper(book_shop,id,FunctionIsOpened);
			break;
			
			case 2:
			getline(std::cin,name);
			std::cout<<"Adja meg a cimet."<<std::endl;
			getline(std::cin,name);
			system("cls");
			search(MYSQL* book_shop, std::string name)
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cin<<id;
			system("cls");
			remove_helper(book_shop,id,FunctionIsOpened);
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem jo szamot adott meg."<<std::endl;
		}
	}
	
}

void Book::get(MYSQL* book_shop)
{
	int choice,number;
	bool FunctionIsOpened=true;
	
	std::cout<<"Melyik konyv adatait akarod megjeleniteni az adatbazisbol?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadása"<<std::endl;
	std::cout<<"2: kereses cim alapjan."<<std::endl;
	std::cout<<"0: vissza."<<std::endl;
	cin>>choice;
	
	while(FunctionIsOpened)
	{
	
		switch (number)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cin<<id;
			system("cls");
			get_helper(book_shop,id);
			break;
			
			case 2:
			getline(std::cin,name);
			std::cout<<"Adja meg a konyv cimet."<<std::endl;
			getline(std::cin,name);
			system("cls");
			number = search(book_shop, name)
			if (number == 0) {FunctionIsOpened=false;}
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







Employees::Employees
{

}


Employees::add(MYSQL* book_shop)
{
	
	
}
	
Employees::change(MYSQL* book_shop)
{
	
	
}
	
Employees::remove_employee(MYSQL* book_shop)
{
	
	
	
}

Employees::get(MYSQL* book_shop)
{
	
	
	
}

Employees::get_all(MYSQL* book_shop)
{
	
	
}

Employees::~Employees
{
	
}