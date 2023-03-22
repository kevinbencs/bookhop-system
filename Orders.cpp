#include <iostream>
#include <string>
#include "Orders.h"
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>
#include "Book.h"





Orders::Orders()
{

}


// check id of book and quantity of book for Orders::add(MYSQL* book_shop,bool &OrdersIsOpened)
void book_id_check(MYSQL* book_shop,const int &book_id,bool &BookAddIsOpened, int &OrderPrice, const int &OrderQuantity,int &book_quantity)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	int book_price;
	
	
	const char* q;
	std::stringstream stmt;
	std::string query;
	
	stmt<<"SELECT * FROM book WHERE id='"<<book_id<<"'";
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
	
	
	if((row = mysql_fetch_row(res_set)) == NULL)
    {
		std::cout << "Nincs tal�lat a k�nyv id-re" << std::endl;
		std::cout << std::endl;
	}
	else
	{
        stmt.clear();
		stmt.str("");
		
		query = row[3];
        stmt<<query;
        stmt>>book_price;
        
        stmt.clear();
		stmt.str("");
		
        query= row[4];
        stmt<<query;
        stmt>>book_quantity;
        
        if (book_quantity<OrderQuantity) {
        	std::cout<<"Nincs el�g mennyis�g az adott k�nyvb�l."<<std::endl;
        	std::cout<<std::endl;
		}
		else
		{
			OrderPrice=book_price*OrderQuantity;
			BookAddIsOpened=false;
		}
	}
	
}




//give data of new order
void Orders::add(MYSQL* book_shop,bool &OrdersIsOpened)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	bool FunctionIsOpened=true;
	bool BookAddIsOpened=true;
	int book_quantity;
	
	while (FunctionIsOpened)
	{
		std::cout<<"Adja meg az adatokat."<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"Rendel� neve ";
		std::cin.ignore();
		getline(std::cin,customer);
		if (customer=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"A rendel� orsz�ga ";
		getline(std::cin,country);
		if (country=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"A rendel� v�rosa ";
		getline(std::cin,city);
		if (city=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"A rendel� c�me ";
		getline(std::cin,address);
		if (address=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"A k�nyv darabsz�ma ";
		std::cin>>quantity;
		std::cout<<std::endl;
		if (quantity==0) {system("cls");break;}
		
		
		std::cout<<std::endl;
		std::cout<<quantity<<std::endl;
		std::cout<<std::endl;
		while (BookAddIsOpened)
		{
			std::cout<<"A k�nyv id-je ";
			std::cin>>book_id;
			if (book_id==0) {break;}
			book_id_check(book_shop, book_id,BookAddIsOpened,price, quantity,book_quantity);
		}
		
		if (book_id==0) {system("cls");break;}
		
		system("cls");
		
		
		
		stmt<<"INSERT INTO orders(book_id,customer,country,city,address,quantity,dt_ordered,price) VALUES ('"<<book_id<<"','"<<customer<<"','"<<country<<"','"<<city<<"','"<<address<<"','"<<quantity<<"',"<<"CURDATE()"<<",'"<<price<<"')";
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
		
		stmt.clear();
		stmt.str("");
		book_quantity-=quantity;
			
		stmt<<"UPDATE book SET quantity='"<<book_quantity<<"' WHERE id='"<<book_id<<"'";
		query=stmt.str();
		q=query.c_str();
		
		if(mysql_ping(book_shop))
		{
			std::cout<<"Hiba, nincs kapcsolat a mysql-el"<<std::endl;
			std::cout<<mysql_error(book_shop)<<std::endl;
		}
		
		mysql_query(book_shop,q);
		
		if(mysql_query(book_shop,q))
		{
			std::cout<<"Hiba "<<mysql_error(book_shop)<<std::endl;
			rewind(stdin);
			getchar();
		}
		else
		{
			mysql_store_result(book_shop);
			FunctionIsOpened=false;
			OrdersIsOpened=false;
		}
		
	}
	
	
}





//search order by customer's name
int order_search(MYSQL* book_shop, const std::string &customer)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM orders WHERE customer REGEXP '" <<customer<<"'";
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
			std::cout << "A rendel�s id-je " << row[0] <<std::endl;
        	std::cout << "A k�nyv id-je  " << row[1] <<std::endl;
			std::cout << "A rendel� neve " << row[2] <<std::endl;
			std::cout << "A rendel� orsz�ga " << row[3] <<std::endl;
			std::cout << "A rendel� v�rosa " << row[4] <<std::endl;
			std::cout << "A rendel� c�me " << row[5] <<std::endl;
        	std::cout << "A k�nyv darabsz�ma " << row[6] <<std::endl;
			std::cout << "A rendel�s d�tuma " << row[7] <<std::endl;
			std::cout << "A rendel�s �ra " << row[8] <<std::endl;
			std::cout <<std::endl;
			row= mysql_fetch_row(res_set);
		}
		
		return 2;
	}
	else
	{
		std::cout << "Nincs tal�lat" << std::endl;
		std::cout << std::endl;
		return 1;
	}
	mysql_free_result(res_set);
	
}





//update quantity of order details with using id
int order_quantity_help(MYSQL* book_shop,const int &id, const int &book_id, int &quantity,  int &price,const int &order_quantity)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	int book_quantity;
	
	
	stmt<<"SELECT * FROM book WHERE id='"<<book_id<<"'";
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
	
	row = mysql_fetch_row(res_set);
	
	
	stmt.clear();
	stmt.str("");
	
	
	query = row[4];
	stmt<<query;
    stmt>>book_quantity;
    
	mysql_free_result(res_set);
	
	book_quantity-=quantity;
	
	if (book_quantity<0){
		std::cout<<"Nincs el�g k�nyv "<<std::endl;
		std::cout<<std::endl;
		return 1;
	}
	
	stmt.clear();
	stmt.str("");
	
	
	stmt<<"UPDATE book SET quantity='"<<book_quantity<<"' WHERE id='"<<book_id<<"'";
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
	
				
	stmt.clear();
	stmt.str("");
	
	quantity+=order_quantity;
		
	price/=order_quantity;
		
	price*=quantity;
	
	stmt<<"UPDATE orders SET price='"<<price<<"' WHERE id='"<<id<<"'";
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
	
	
	stmt.clear();
	stmt.str("");
	
	stmt<<"UPDATE orders SET quantity='"<<quantity<<"' WHERE id='"<<id<<"'";
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
	
	return 2;
}






//update order details with using id
void order_change_help(MYSQL* book_shop,const int &id,bool &FunctionIsOpened,std::string &customer, std::string &country, std::string &city, std::string& address, int &quantity, int &price,bool &OrdersIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_RES *res_set2;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	bool LoopIsOpened=true;
	int choice;
	//int book_quantity;
	int book_id;
	int order_quantity;
	
	
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
			std::cout << "1: a rendel� neve " << std::endl;
			std::cout << "2: a rendel� orsz�ga " << std::endl;
			std::cout << "3: a rendel� v�rosa " << std::endl;
			std::cout << "4: a rendel� c�me " << std::endl;
			std::cout << "5: a k�nyv darabsz�ma " << std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin>>choice;
			system("cls");
			
			switch (choice)
			{
				case 1:
				std::cout<<"Adja meg a rendel� �j nevet."<<std::endl;
				std::cin.ignore();
				getline(std::cin,customer);
				system("cls");
				stmt<<"UPDATE orders SET customer='"<<customer<<"' WHERE id='"<<id<<"'";
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
				OrdersIsOpened=false;
				std::cout<<"A rendel� neve megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 2:
				std::cout<<"Adja meg a rendel� orsz�g�t."<<std::endl;
				std::cin.ignore();
				getline(std::cin,country);
				system("cls");
				stmt<<"UPDATE orders SET country='"<<country<<"' WHERE id='"<<id<<"'";
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
				OrdersIsOpened=false;
				std::cout<<"A rendel� orsz�ga megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 3:
				std::cout<<"Adja meg a rendel� v�ros�t."<<std::endl;
				std::cin.ignore();
				getline(std::cin,city);
				system("cls");
				stmt<<"UPDATE orders SET city='"<<city<<"' WHERE id='"<<id<<"'";
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
				OrdersIsOpened=false;
				std::cout<<"A rendel� v�rosa megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 4:
				std::cout<<"Adja meg a rendel� c�m�t."<<std::endl;
				std::cin.ignore();
				getline(std::cin,address);
				system("cls");
				stmt<<"UPDATE orders SET address='"<<address<<"' WHERE id='"<<id<<"'";
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
				OrdersIsOpened=false;
				std::cout<<"A rendel� c�me megv�ltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 5:
				
				std::cout<<"Adja meg a k�nyv darabsz�m�t."<<std::endl;
				std::cin>>quantity;
				system("cls");
				
				
				stmt<<"SELECT * FROM orders WHERE id='"<<id<<"'";
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
				
				stmt.clear();
				stmt.str("");
				
				query = row[8];
        		stmt<<query;
        		stmt>>price;
        		
        		stmt.clear();
				stmt.str("");
				
        		
        		query = row[1];
        		stmt<<query;
        		stmt>>book_id;
        		
        		stmt.clear();
				stmt.str("");
				
				
        		query= row[6];
       			stmt<<query;
       			stmt>>order_quantity;
       			
				mysql_free_result(res_set);
				
				stmt.clear();
				stmt.str("");
				
				
				order_quantity_help(book_shop,id, book_id,quantity, price,order_quantity);
				
				LoopIsOpened=false;
				FunctionIsOpened=false;
				OrdersIsOpened=false;
				std::cout<<"A megrendelt k�nyv darabsz�ma megv�ltoztatva."<<std::endl;
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
	
}





//update order details
void Orders::change(MYSQL* book_shop,bool &OrdersIsOpened)
{
	int choice;
	bool FunctionIsOpened=true;
	int number;
	
	std::cout<<"Melyik rendel�s adatait akarja megv�ltoztatni?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megad�sa."<<std::endl;
	std::cout<<"2: kereses a rendel� neve alapj�n."<<std::endl;
	std::cout<<"0: vissza."<<std::endl;
	std::cin>>choice;
	system("cls");
	
	while(FunctionIsOpened)
	{
	
		switch (choice)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin>>id;
			system("cls");
			if (id!=0 )
			{
				order_change_help(book_shop,id,FunctionIsOpened, customer,  country,  city,  address, quantity,price,OrdersIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg a nevet."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,customer);
			system("cls");
			
			if (customer!="0" )
			{
				number=order_search(book_shop, customer);
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cout<<"0: vissza."<<std::endl;
					std::cin>>id;
					system("cls");
					if (id!=0 )
					{
						order_change_help(book_shop,id,FunctionIsOpened, customer,  country,  city,  address, quantity,price,OrdersIsOpened);
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





//remove one employee from database with using id
void order_remove_help(MYSQL* book_shop,const int &id,bool &FunctionIsOpened,bool &OrdersIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM orders WHERE id='"<<id<<"'";
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
	
	if((row = mysql_fetch_row(res_set)) == NULL)
    {
		std::cout << "Nincs tal�lat az is-re" << std::endl;
		std::cout << std::endl;
	}
	else
	{
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
		
		std::cout<<"Rendel�s t�r�lve az adatb�zisb�l."<<std::endl;
		std::cout<<std::endl;
		mysql_store_result(book_shop);
		FunctionIsOpened=false;
		OrdersIsOpened=false;
	}
	mysql_free_result(res_set);
		
}




//remove one employee from database
void Orders::remove(MYSQL* book_shop,bool &OrdersIsOpened)
{
	int choice;
	bool FunctionIsOpened=true;
	int number;
	
	std::cout<<"Melyik rendel�st akarja kit�r�lni az adatb�zisb�l?"<<std::endl;
	std::cout<<std::endl;
	std::cout<<"1: id megad�sa"<<std::endl;
	std::cout<<"2: keres�s a rendel� neve alapj�n."<<std::endl;
	std::cout<<"0: vissza."<<std::endl;
	std::cin>>choice;
	system("cls");
	
	while(FunctionIsOpened)
	{
	
		switch (choice)
		{
			case 1:
			std::cout<<"Adja meg az id-t."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin>>id;
			system("cls");
			if (id!=0 )
			{
				order_remove_help(book_shop,id,FunctionIsOpened,OrdersIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg a nevet."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,customer);
			system("cls");
			
			if (customer!="0" )
			{
				number=order_search(book_shop, customer);
				
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cout<<"0: vissza."<<std::endl;
					std::cin>>id;
					system("cls");
					if (id!=0 )
					{
						order_remove_help(book_shop,id,FunctionIsOpened,OrdersIsOpened);
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





//display data of one employee with using id
void order_get_help(MYSQL* book_shop,const int &id, bool &FunctionIsOpened,bool &OrdersIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM orders WHERE id='"<<id<<"'";
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
		std::cout << "A rendel�s id-je " << row[0] <<std::endl;
        std::cout << "A k�nyv id-je  " << row[1] <<std::endl;
		std::cout << "A rendel� neve " << row[2] <<std::endl;
		std::cout << "A rendel� orsz�ga " << row[3] <<std::endl;
		std::cout << "A rendel� v�rosa " << row[4] <<std::endl;
		std::cout << "A rendel� c�me " << row[5]<<std::endl;
        std::cout << "A k�nyv darabsz�ma " << row[6] <<std::endl;
		std::cout << "A rendel�s d�tuma " << row[7] <<std::endl;
		std::cout << "A rendel�s �ra " << row[8] <<std::endl;
		std::cout<<std::endl;
		FunctionIsOpened=false;
		OrdersIsOpened=false;
	}
	else
	{
		std::cout << "Nincs tal�lat az id-re" << std::endl;
		std::cout << std::endl;
	}
	
	mysql_free_result(res_set);
	
}






//display data of one order
void Orders::get(MYSQL* book_shop,bool &OrdersIsOpened)
{
	int choice,number;
	bool FunctionIsOpened=true;
	
	
	
	while(FunctionIsOpened)
	{
		std::cout<<"Melyik k�nyv adatait akarod megjelen�teni az adatb�zisb�l?"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"1: id megad�sa."<<std::endl;
		std::cout<<"2: keres�s rendel� neve alapj�n."<<std::endl;
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
				order_get_help(book_shop,id,FunctionIsOpened,OrdersIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg a rendel� nevet."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,customer);
			system("cls");
			
			if (customer!="0" )
			{
				number = order_search(book_shop, customer);
				if (number == 2) {FunctionIsOpened=false;OrdersIsOpened=false;}
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
	

//display data of all orders
void Orders::all_get(MYSQL* book_shop,bool &OrdersIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM employees";
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
		std::cout << "A rendel�s id-je " << row[0] <<std::endl;
        std::cout << "A k�nyv id-je  " << row[1] <<std::endl;
		std::cout << "A rendel� neve " << row[2] <<std::endl;
		std::cout << "A rendel� orsz�ga " << row[3] <<std::endl;
		std::cout << "A rendel� v�rosa " << row[4] <<std::endl;
		std::cout << "A rendel� c�me " << row[5]<<std::endl;
        std::cout << "A k�nyv darabsz�ma " << row[6] <<std::endl;
		std::cout << "A rendel�s d�tuma " << row[7] <<std::endl;
		std::cout << "A rendel�s �ra " << row[8] <<std::endl;
		std::cout<<std::endl;
		row = mysql_fetch_row(res_set);
	}
	
	mysql_free_result(res_set);
	OrdersIsOpened=false;
	
}




Orders::~Orders()
{
	
}
