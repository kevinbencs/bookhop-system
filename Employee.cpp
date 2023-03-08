#include <string>
#include "Employees.h"
#include <mysql.h>
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>



void get_helper(MYSQL* book_shop,int &id)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
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
		std::cout << "Az alkalmazott id-je " << row[0] <<std::endl;
        std::cout << "Az alkalmazott országa  " << row[1] <<std::endl;
		std::cout << "Az alkalmazott varosa " << row[2] <<std::endl;
        std::cout << "Az alkalmazott cime " << row[3] <<std::endl;
		std::cout << "Az alkalmazott fizetese " << row[4] <<std::endl;
		std::cout << "Az alkalmazott csatlakozasi datuma " << row[5] <<std::endl;
		std::cout << "Az alkalmazott pozicioja " << row[6] <<std::endl;
		std::cout << "Az alkalmazott neve " << row[7] <<std::endl;
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
			std::cout << "1: Az alkalmazott neve "  <<std::endl;
			std::cout << "2: Az alkalmazott országa  "  <<std::endl;
			std::cout << "3: Az alkalmazott varosa "  <<std::endl;
			std::cout << "4: Az alkalmazott cime " <<std::endl;
			std::cout << "5: Az alkalmazott fizetese " <<std::endl;
			std::cout << "6: Az alkalmazott csatlakozasi datuma " <<std::endl;
			std::cout << "7: Az alkalmazott pozicioja " <<std::endl;
			std::cout << "0: vissza."<<std::endl;
			cin>>choice;
			system("cls");
			
			switch (choice)
			{
				case 1:
				std::cout<<"Adja meg az alkalmazott nevet."<<std::endl;
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
				std::cout<<"Adja meg az alkalmazott orszagat."<<std::endl;
				getline(std::cin,name);
				system("cls");
				stmt<<"UPDATE book SET country="<<country<<" WHERE id="<<id;
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
				
				case 3:
				std::cout<<"Adja meg az alkalmazott varosat."<<std::endl;
				getline(std::cin,author);
				system("cls");
				stmt<<"UPDATE book SET city="<<city<<" WHERE id="<<id;
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
				std::cout<<"Adja meg az alkalmazott cimet."<<std::endl;
				std::cin>>price;
				system("cls");
				stmt<<"UPDATE book SET address="<<address<<" WHERE id="<<id;
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
				
				case 5:
				std::cout<<"Adja meg az alkalmazott fizeteset."<<std::endl;
				std::cin>>quantity;
				system("cls");
				stmt<<"UPDATE book SET salary="<<salary<<" WHERE id="<<id;
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
				
				case 6:
				std::cout<<"Adja meg az alkalmazott csatlakozasi datumat."<<std::endl;
				std::cin>>quantity;
				system("cls");
				stmt<<"UPDATE book SET joining_date="<<joining_date<<" WHERE id="<<id;
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
				
				case 7:
				std::cout<<"Adja meg az alkalmazott poziciojat."<<std::endl;
				std::cin>>quantity;
				system("cls");
				stmt<<"UPDATE book SET position="<<position<<" WHERE id="<<id;
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
	
	stmt<<"SELECT * FROM employees WHERE name REGEXP " <<name;
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
		std::cout << "Az alkalmazott id-je " << row[0] <<std::endl;
        std::cout << "Az alkalmazott országa  " << row[1] <<std::endl;
		std::cout << "Az alkalmazott varosa " << row[2] <<std::endl;
        std::cout << "Az alkalmazott cime " << row[3] <<std::endl;
		std::cout << "Az alkalmazott fizetese " << row[4] <<std::endl;
		std::cout << "Az alkalmazott csatlakozasi datuma " << row[4] <<std::endl;
		std::cout << "Az alkalmazott pozicioja " << row[4] <<std::endl;
		std::cout << "Az alkalmazott neve " << row[4] <<std::endl;
		return 0;
	}
	else
	{
		std::cout << "Nincs talalat" << std::endl;
		return 1;
	}
	
}



Employees::Employees
{

}


void Employees::add(MYSQL* book_shop)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	
	std::cout<<"Adja meg az adatokat"<<std::endl;
	std::cout<<"Nev";
	getline(std::cin,name);
	std::cout<<std::endl;
	std::cout<<"Orszag";
	getline(std::cin,country);
	std::cout<<std::endl;
	std::cout<<"Varos";
	getline(std::cin,city);
	std::cout<<std::endl;
	std::cout<<"Cim";
	getline(std::cin,address);
	std::cout<<std::endl;
	std::cout<<"Csatlakozasi datum";
	getline(std::cin,joining_date);
	std::cout<<std::endl;
	std::cout<<"Pozicio";
	getline(std::cin,position);
	std::cout<<std::endl;
	std::cout<<"Fizetes";
	std::cin>>salary;
	std::cout<<std::endl;
	
	
	stmt<<"INSERT INTO book(country,city,address,salary,joining_date,position,name) VALUES ("<<country<<","<<city<<","<<address<<","<<salary<<","<< joining_date<<","<<position<<"," <<name ")";
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
	
void Employees::change(MYSQL* book_shop)
{
	int choice;
	bool FunctionIsOpened=true;
	
	std::cout<<"Kinek az adatait akarja megvaltoztatni?"<<std::endl;
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
	
void Employees::remove_employee(MYSQL* book_shop)
{
	int choice;
	bool FunctionIsOpened=true;
	
	std::cout<<"Kit akar kitorolni az adatbazisbol?"<<std::endl;
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
			std::cout<<"Adja meg az alkalmazott nevet."<<std::endl;
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

void Employees::get(MYSQL* book_shop)
{
	int choice,number;
	bool FunctionIsOpened=true;
	
	std::cout<<"Kinek az adatait akarja megjeleniteni az adatbazisbol?"<<std::endl;
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
			get_helper(book_shop,id);
			break;
			
			case 2:
			getline(std::cin,name);
			std::cout<<"Adja meg az alkamazott nevet."<<std::endl;
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

void Employees::get_all(MYSQL* book_shop)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM book";
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
		std::cout << "Az alkalmazott id-je " << row[0] <<std::endl;
        std::cout << "Az alkalmazott országa  " << row[1] <<std::endl;
		std::cout << "Az alkalmazott varosa " << row[2] <<std::endl;
        std::cout << "Az alkalmazott cime " << row[3] <<std::endl;
		std::cout << "Az alkalmazott fizetese " << row[4] <<std::endl;
		std::cout << "Az alkalmazott csatlakozasi datuma " << row[5] <<std::endl;
		std::cout << "Az alkalmazott pozicioja " << row[6] <<std::endl;
		std::cout << "Az alkalmazott neve " << row[7] <<std::endl;
	}
	
}

Employees::~Employees
{
	
}