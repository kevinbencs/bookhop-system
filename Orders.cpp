#include <string>
#include "Orders.h"
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>
#include "Book.h"




void get_helper(MYSQL* book_shop,int &id)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM orders WHERE id="<<id;
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
		std::cout << "A rendeles id-je " << row[0] <<std::endl;
        std::cout << "A konyv id-je  " << row[1] <<std::endl;
		std::cout << "A rendelo neve " << row[2] <<std::endl;
		std::cout << "A rendelo orszaga " << row[3] <<std::endl
		std::cout << "A rendelo varosa " << row[4] <<std::endl
		std::cout << "A rendelo cime " << row[5 <<std::endl
        std::cout << "A konyv darabszama " << row[6] <<std::endl;
		std::cout << "A rendeles datuma " << row[7] <<std::endl
		std::cout << "A rendeles ara " << row[8] <<std::endl;
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
			std::cout << "1: a rendelo neve " << std::endl;
			std::cout << "2: a rendelo orszaga " << std::endl
			std::cout << "3: a rendelo varosa " << std::endl
			std::cout << "4: a rendelo cime " << std::endl
			std::cout << "5: a konyv darabszama " << std::endl;
			std::cout<<"0: vissza."<<std::endl;
			cin>>choice;
			system("cls");
			
			switch (choice)
			{
				case 1:
				std::cout<<"Adja meg a rendelo uj nevet."<<std::endl;
				getline(std::cin,customer);
				system("cls");
				stmt<<"UPDATE orders SET customer="<<customer<<" WHERE id="<<id;
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
				std::cout<<"Adja meg a rendelo orszagat."<<std::endl;
				getline(std::cin,author);
				system("cls");
				stmt<<"UPDATE orders SET country="<<country<<" WHERE id="<<id;
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
				std::cout<<"Adja meg a rendelo varosat."<<std::endl;
				std::cin>>price;
				system("cls");
				stmt<<"UPDATE orders SET city="<<city<<" WHERE id="<<id;
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
				std::cout<<"Adja meg a rendelo cimet."<<std::endl;
				std::cin>>quantity;
				system("cls");
				stmt<<"UPDATE orders SET address="<<address<<" WHERE id="<<id;
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
				
				case 5:
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
	
	stmt<<"SELECT * FROM orders WHERE id="<<id;
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
	
	stmt<<"SELECT * FROM orders WHERE name REGEXP " <<name;
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
		std::cout << "A rendeles id-je " << row[0] <<std::endl;
        std::cout << "A konyv id-je  " << row[1] <<std::endl;
		std::cout << "A rendelo neve " << row[2] <<std::endl;
		std::cout << "A rendelo orszaga " << row[3] <<std::endl
		std::cout << "A rendelo varosa " << row[4] <<std::endl
		std::cout << "A rendelo cime " << row[5 <<std::endl
        std::cout << "A konyv darabszama " << row[6] <<std::endl;
		std::cout << "A rendeles datuma " << row[7] <<std::endl
		std::cout << "A rendeles ara " << row[8] <<std::endl;
		return 0;
	}
	else
	{
		std::cout << "Nincs talalat" << std::endl;
		return 1;
	}
	
}



Orders::Orders
{

}

Orders::add(MYSQL* book_shop)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	bool FunctionIsOpened=true;
	bool BookAddIsOpened=true;
	
	
	while (FunctionIsOpened)
	{
		std::cout<<"Adja meg az adatokat."<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"Rendelo neve ";
		getline(std::cin,customer);
		if (customer=='0') {break;}
		std::cout<<std::endl;
		
		std::cout<<"A rendelo orszaga ";
		getline(std::cin,country);
		if (country=='0') {break;}
		std::cout<<std::endl;
		
		std::cout<<"A rendelo varosa ";
		getline(std::cin,city);
		if (city=='0') {break;}
		std::cout<<std::endl;
		
		std::cout<<"A rendelo cime ";
		getline(std::cin,address);
		if (address=='0') {break;}
		std::cout<<std::endl;
		
		while (BookAddIsOpened)
		{
			std::cout<<"A konyv id-je ";
			std::cin>>book_id;
			if (book_id==0) {break;}
			std::cout<<std::endl;
			Book book_data(book_shop, book_id,BookAddIsOpened);
		}
		if (book_id==0) {break;}
	
		std::cout<<"A konyv darabszama ";
		std::cin>>quantity;
		if (quantity==0) {break;}
		else {FunctionIsOpened=false;}
		std::cout<<std::endl;
		
		
		
		price=quantity*book_data.get_price();
		
		stmt<<"INSERT INTO book(book_id,customer,country,city,address,quantity,dt_ordered,price) VALUES ("<<book_id<<","<<customer<<","<<country<<","<<city<<","<<address<<","<<quantity<<","<<"CURDATE()"<<","<<price")";
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
	
	
	
}
	
Orders::change(MYSQL* book_shop)
{
	int choice;
	bool FunctionIsOpened=true;
	
	std::cout<<"Melyik rendeles adatait akarja megvaltoztatni?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadasa."<<std::endl;
	std::cout<<"2: kereses a rendelo neve alapjan."<<std::endl;
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
	
Orders::remove_order(MYSQL* book_shop)
{
	int choice;
	bool FunctionIsOpened=true;
	
	std::cout<<"Melyik rendelest akarja kitorolni az adatbazisbol?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadása"<<std::endl;
	std::cout<<"2: kereses a rendelo neve alapjan."<<std::endl;
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
			std::cout<<"Adja meg a nevet."<<std::endl;
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
	
Orders::get(MYSQL* book_shop)
{
	int choice,number;
	bool FunctionIsOpened=true;
	
	std::cout<<"Melyik konyv adatait akarod megjeleniteni az adatbazisbol?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megadása."<<std::endl;
	std::cout<<"2: kereses rendelo neve alapjan."<<std::endl;
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
			std::cout<<"Adja meg a rendelo nevet."<<std::endl;
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
	



Orders::Orders
{
	
}
