#include <iostream>
#include "Book.h"
#include <string>
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>
#include <cstdio>




Book::Book()
{
	
}




//give data of new book
void Book::add(MYSQL* book_shop,bool &BookIsOpened)
{
	
	const char* q;
	std::stringstream stmt;
	std::string query;
	bool FunctionIsOpened=true;
	
	while (FunctionIsOpened)
	{
		std::cout<<"Adja meg az adatokat"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<std::endl;
		
		std::cout<<"N�v"<<std::endl;
		std::cin.ignore();
		getline(std::cin,name);
		if (name=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"Szerz�"<<std::endl;
		getline(std::cin,author);
		if (author=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"�r"<<std::endl;
		std::cin>>price;
		if (price==0) {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"Mennyis�g"<<std::endl;
		std::cin>>quantity;
		if (quantity==0) {system("cls");break;}
		std::cout<<std::endl;
		
		
		stmt<<"INSERT INTO book(name,author,price,quantity) VALUES ('"<<name<<"','"<<author<<"','"<<price<<"','"<<quantity<<"')";
		query=stmt.str();
		q=query.c_str();
		
		
		if(mysql_ping(book_shop))
		{
			std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
			std::cout<<mysql_error(book_shop)<<std::endl;
		}
		
		
		if(mysql_query(book_shop,q))
		{
			std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
			rewind(stdin);
			getchar();
		}
		else
		{
			system("cls");
			std::cout<<"K�nyv adatai hozz�adva az adatb�zishoz."<<std::endl;
			std::cout<<std::endl;
		
			mysql_store_result(book_shop);
			FunctionIsOpened=false;
			BookIsOpened=false;
		}
	}
	
	
	
}






//search book by name
int book_search(MYSQL* book_shop, const std::string &name)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	
	const char* q;
	std::stringstream stmt;
	std::string query;
	
	stmt<<"SELECT * FROM book WHERE name REGEXP '"<<name<<"'";
	query=stmt.str();
	q=query.c_str();
	
	
	
	if(mysql_ping(book_shop))
	{
		std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	if(mysql_query(book_shop,q))
	{
		std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
		rewind(stdin);
		getchar();
	}
	
	res_set=mysql_store_result(book_shop);
	
	
	
	if (mysql_num_rows(res_set) !=0)
	{
		row= mysql_fetch_row(res_set);
		while(row != NULL)
    	{
			std::cout << "A k�nyv id-je " << row[0] <<std::endl;
        	std::cout << "A k�nyv c�me  " << row[1] <<std::endl;
			std::cout << "A szerz� neve " << row[2] <<std::endl;
        	std::cout << "A k�nyv �ra " << row[3] <<std::endl;
			std::cout << "P�ld�nysz�m " << row[4] <<std::endl;
			std::cout <<std::endl;
			row= mysql_fetch_row(res_set);
		}
		mysql_free_result(res_set);
		return 2;
	}
	else
	{
		std::cout << "Nincs tal�lat" << std::endl;
		std::cout<<std::endl;
		mysql_free_result(res_set);
		return 1;
	}
	
	
}






//search book by author's name
int author_search(MYSQL* book_shop, const std::string &author)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	
	const char* q;
	std::stringstream stmt;
	std::string query;
	
	stmt<<"SELECT * FROM book WHERE author REGEXP '"<<author<<"'";
	query=stmt.str();
	q=query.c_str();
	
	
	
	if(mysql_ping(book_shop))
	{
		std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	if(mysql_query(book_shop,q))
	{
		std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
		rewind(stdin);
		getchar();
	}
	
	res_set=mysql_store_result(book_shop);
	
	
	
	if (mysql_num_rows(res_set) !=0)
	{
		row= mysql_fetch_row(res_set);
		while(row != NULL)
    	{
			std::cout << "A k�nyv id-je " << row[0] <<std::endl;
        	std::cout << "A k�nyv c�me  " << row[1] <<std::endl;
			std::cout << "A szerz� neve " << row[2] <<std::endl;
        	std::cout << "A k�nyv �ra " << row[3] <<std::endl;
			std::cout << "P�ld�nysz�m " << row[4] <<std::endl;
			std::cout <<std::endl;
			row= mysql_fetch_row(res_set);
		}
		mysql_free_result(res_set);
		return 2;
	}
	else
	{
		std::cout << "Nincs tal�lat" << std::endl;
		std::cout<<std::endl;
		mysql_free_result(res_set);
		return 1;
	}
	
}






//update order details with using id
void book_change_help(MYSQL* book_shop,const int &id,bool &FunctionIsOpened, std::string &name, std::string &author, int &price, int &quantity,bool &BookIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	
	const char* q;
	std::stringstream stmt;
	std::string query;
	
	stmt<<"SELECT * FROM book WHERE id='"<<id<<"'";
	query=stmt.str();
	q=query.c_str();
	bool LoopIsOpened=true;
	int choice;
	
	
	
	if (mysql_ping(book_shop))
	{
		std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	if(mysql_query(book_shop,q))
	{
		std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
		rewind(stdin);
		getchar();
	}
	
	
	res_set=mysql_store_result(book_shop);
	
	if((row = mysql_fetch_row(res_set)) == NULL)
    {
		std::cout << "Nincs tal�lat az id-re" << std::endl;
		std::cout << std::endl;
		
	}
	else
	{
		stmt.clear();
		stmt.str("");
		while(LoopIsOpened)
		{
			std::cout<<"Mit szeretne megv�ltoztatni?"<<std::endl;
			std::cout<<std::endl;
			std::cout<<"1: k�nyv c�me."<<std::endl;
			std::cout<<"2: szerz� neve."<<std::endl;
			std::cout<<"3: k�nyv �ra."<<std::endl;
			std::cout<<"4: k�nyv darabsz�ma."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin>>choice;
			system("cls");
			
			switch (choice)
			{
				case 1:
				std::cout<<"Adja meg a k�nyv �j c�m�t."<<std::endl;
				std::cin.ignore();
				getline(std::cin,name);
				system("cls");
				
				stmt<<"UPDATE book SET name='"<<name<<"' WHERE id='"<<id<<"'";
				query=stmt.str();
				q=query.c_str();
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
					std::cout<<mysql_error(book_shop)<<std::endl;
				}
				
				if(mysql_query(book_shop,q))
				{
					std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
					rewind(stdin);
					getchar();
				}
				
				mysql_store_result(book_shop);
				LoopIsOpened=false;
				FunctionIsOpened=false;
				BookIsOpened=false;
				std::cout<<"A k�nyv c�me megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				
				case 2:
				std::cout<<"Adja meg a szerz� �j nev�t."<<std::endl;
				std::cin.ignore();
				getline(std::cin,author);
				system("cls");
				
				stmt<<"UPDATE book SET author='"<<author<<"' WHERE id='"<<id<<"'";
				query=stmt.str();
				q=query.c_str();
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
					std::cout<<mysql_error(book_shop)<<std::endl;
				}
				
				if(mysql_query(book_shop,q))
				{
					std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
					rewind(stdin);
					getchar();
				}
				
				mysql_store_result(book_shop);
				LoopIsOpened=false;
				FunctionIsOpened=false;
				BookIsOpened=false;
				std::cout<<"A szerz� neve megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				
				case 3:
				std::cout<<"Adja meg az �j �rat."<<std::endl;
				std::cin>>price;
				system("cls");
				
				stmt<<"UPDATE book SET price='"<<price<<"' WHERE id='"<<id<<"'";
				query=stmt.str();
				q=query.c_str();
				
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
					std::cout<<mysql_error(book_shop)<<std::endl;
				}
				
				if(mysql_query(book_shop,q))
				{
					std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
					rewind(stdin);
					getchar();
				}
				
				mysql_store_result(book_shop);
				LoopIsOpened=false;
				FunctionIsOpened=false;
				BookIsOpened=false;
				std::cout<<"A k�nyv �ra megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 4:
				std::cout<<"Adja meg a k�nyv �j darabsz�m�t."<<std::endl;
				std::cin>>quantity;
				system("cls");
				
				stmt<<"UPDATE book SET quantity='"<<quantity<<"' WHERE id='"<<id<<"'";
				query=stmt.str();
				q=query.c_str();
				
				
				if(mysql_ping(book_shop))
				{
					std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
					std::cout<<mysql_error(book_shop)<<std::endl;
				}
				
				if(mysql_query(book_shop,q))
				{
					std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
					rewind(stdin);
					getchar();
				}
				
				mysql_store_result(book_shop);
				LoopIsOpened=false;
				FunctionIsOpened=false;
				BookIsOpened=false;
				std::cout<<"A k�nyv darabsz�na megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 0:
				LoopIsOpened=false;
				break;
				
				default:
				std::cout<<"Rossz sz�mot adott meg."<<std::endl;
				std::cout<<std::endl;
					
			}
		}
	}
	mysql_free_result(res_set);
	
}



//update book details
void Book::change(MYSQL* book_shop,bool &BookIsOpened)
{
	int choice;
	bool FunctionIsOpened=true;
	int number;
	
	
	
	while(FunctionIsOpened)
	{
		std::cout<<"Melyik k�nyv adatait akarja megv�ltoztatni?"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"1: id megad�sa."<<std::endl;
		std::cout<<"2: keres�s c�m alapj�n."<<std::endl;
		std::cout<<"3: keres�s szerz� alapj�n."<<std::endl;
		std::cout<<"0: vissza."<<std::endl;
		std::cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin>>id;
			system("cls");
			if (id!=0 )
			{
				book_change_help(book_shop,id,FunctionIsOpened,name, author, price, quantity,BookIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg a c�met."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,name);
			system("cls");
			
			if (name!="0" )
			{
				number=book_search(book_shop, name);
				
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cin>>id;
					system("cls");
					if (id!=0 )
					{
						book_change_help(book_shop,id,FunctionIsOpened,name, author, price, quantity,BookIsOpened);
					}
				}
			}
			break;
			
			case 3:
			std::cout<<"Adja meg a szerz� nev�t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,author);
			system("cls");
			
			if (name!="0" )
			{
				number=author_search(book_shop, author);
				
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cin>>id;
					system("cls");
					book_change_help(book_shop,id,FunctionIsOpened,name, author, price, quantity,BookIsOpened);
				}
			}
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem j� sz�mot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
}





//remove one book from database with using id
void book_remove_help(MYSQL* book_shop,const int &id,bool &FunctionIsOpened,bool &BookIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	
	const char* q;
	std::stringstream stmt;
	std::string query;
	
	stmt<<"SELECT * FROM book WHERE id='"<<id<<"'";
	query=stmt.str();
	q=query.c_str();
	
	
	
	if (mysql_ping(book_shop))
	{
		std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	if(mysql_query(book_shop,q))
	{
		std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
		rewind(stdin);
		getchar();
	}
	
	
	res_set=mysql_store_result(book_shop);
	
	stmt.clear();
	stmt.str("");
	
	if((row = mysql_fetch_row(res_set)) == NULL)
    {
		std::cout << "Nincs tal�lat az id-re" << std::endl;
		std::cout << std::endl;
		mysql_free_result(res_set);
		
	}
	else
	{
		mysql_free_result(res_set);
		
		stmt<<"DELETE FROM book WHERE id='"<<id<<"'";
		query=stmt.str();
		q=query.c_str();
		
		if (mysql_ping(book_shop))
		{
			std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
			std::cout<<mysql_error(book_shop)<<std::endl;
		}
		
		if(mysql_query(book_shop,q))
		{
			std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
			rewind(stdin);
			getchar();
		}
		
		mysql_store_result(book_shop);
		std::cout<<"K�nyv t�r�lve az adatb�zisb�l."<<std::endl;
		std::cout<<std::endl;
		
		FunctionIsOpened=false;
		BookIsOpened=false;
	}
	
		
}




//remove one employee from database
void Book::remove(MYSQL* book_shop,bool &BookIsOpened)
{
	int choice;
	bool FunctionIsOpened=true;
	int number;
	
	
	
	while(FunctionIsOpened)
	{
		std::cout<<"Melyik k�nyvet akarja kit�r�lni az adatb�zisb�l?"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"1: id megad�sa"<<std::endl;
		std::cout<<"2: kereses c�m alapjan."<<std::endl;
		std::cout<<"3: keres�s szerz� alapj�n."<<std::endl;
		std::cout<<"0: vissza."<<std::endl;
		std::cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin>>id;
			system("cls");
			if (id!=0 )
			{
				book_remove_help(book_shop,id,FunctionIsOpened,BookIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg a c�met."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,name);
			system("cls");
			
			if (name!="0" )
			{
				number=book_search(book_shop, name);
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cout<<"0: vissza."<<std::endl;
					std::cin>>id;
					system("cls");
					if (id!=0 )
					{
						book_remove_help(book_shop,id,FunctionIsOpened,BookIsOpened);
					}
				}
			}
			break;
			
			case 3:
			std::cout<<"Adja meg a szerz� nev�t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,author);
			system("cls");
			
			if (author!="0" )
			{
				number=author_search(book_shop, author);
				
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cout<<"0: vissza."<<std::endl;
					std::cin>>id;
					system("cls");
					if (id!=0 )
					{
						book_remove_help(book_shop,id,FunctionIsOpened,BookIsOpened);
					}
				}
			}
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem j� sz�mot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
}






//display data of one book with using id
void book_get_help(MYSQL* book_shop,const int &id, bool &FunctionIsOpened,bool &BookIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	
	const char* q;
	std::stringstream stmt;
	std::string query;
	
	stmt<<"SELECT * FROM book WHERE id='"<<id<<"'";
	query=stmt.str();
	q=query.c_str();
	
	
	if (mysql_ping(book_shop))
	{
		std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	
	if(mysql_query(book_shop,q))
	{
		std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
		rewind(stdin);
		getchar();
	}
	
	
	res_set=mysql_store_result(book_shop);
	
	
	if((row = mysql_fetch_row(res_set)) != NULL)
    {
		std::cout << "A k�nyv id-je " << row[0] <<std::endl;
        std::cout << "A k�nyv c�me  " << row[1] <<std::endl;
		std::cout << "A szerz� neve " << row[2] <<std::endl;
        std::cout << "A k�nyv �ra " << row[3] <<std::endl;
		std::cout << "P�ld�nysz�m " << row[4] <<std::endl;
		std::cout<<std::endl;
		FunctionIsOpened=false;
		BookIsOpened=false;
	}
	else
	{
		std::cout << "Nincs tal�lat az id-re" << std::endl;
		std::cout<<std::endl;
	}
	
	mysql_free_result(res_set);
	
}



//display data of one book
void Book::get(MYSQL* book_shop, bool &BookIsOpened)
{
	int choice,number;
	bool FunctionIsOpened=true;
	
	
	
	while(FunctionIsOpened)
	{
		std::cout<<"Melyik k�nyv adatait akarod megjelen�teni az adatb�zisb�l?"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"1: id megad�sa"<<std::endl;
		std::cout<<"2: keres�s c�m alapj�n."<<std::endl;
		std::cout<<"3: keres�s szerz� alapj�n."<<std::endl;
		std::cout<<"0: vissza."<<std::endl;
		std::cin>>choice;
		system("cls");
		
		switch (choice)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin>>id;
			system("cls");
			
			if (id!=0 )
			{
				book_get_help(book_shop,id,FunctionIsOpened, BookIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg a k�nyv c�met."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,name);
			system("cls");
			
			if (name!="0" )
			{
				number = book_search(book_shop, name);
				if (number == 2) {FunctionIsOpened=false;BookIsOpened=false;}
			}
			break;
			
			case 3:
			std::cout<<"Adja meg a szerz� nev�t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,author);
			system("cls");
			
			if (author!="0" )
			{
				number = author_search(book_shop, author);
				if (number == 2) {FunctionIsOpened=false;BookIsOpened=false;}
			}
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem j� sz�mot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
}




//display data of all books
void Book::all_get(MYSQL* book_shop,bool &BookIsOpened)
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
		std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	if(mysql_query(book_shop,q))
	{
		std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
		rewind(stdin);
		getchar();
	}
	
	
	res_set=mysql_store_result(book_shop);
	row = mysql_fetch_row(res_set);
	
	while( row != NULL)
    {
		std::cout << "A k�nyv id-je " << row[0] <<std::endl;
        std::cout << "A k�nyv c�me  " << row[1] <<std::endl;
		std::cout << "A szerz� neve " << row[2] <<std::endl;
        std::cout << "A k�nyv �ra " << row[3] <<std::endl;
		std::cout << "P�ld�nysz�m " << row[4] <<std::endl;
		std::cout<<std::endl;
		row = mysql_fetch_row(res_set);
	}
	
	mysql_free_result(res_set);
	BookIsOpened=false;
	
}

	


Book::~Book()
{
	
}


