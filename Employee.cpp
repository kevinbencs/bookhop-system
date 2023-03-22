#include <iostream>
#include <string>
#include "Employee.h"
#include <mysql.h>
#include <mysqld_error.h>
#include <sstream>




Employees::Employees()
{

}

//give data of new employee
void Employees::add(MYSQL* book_shop,bool &EmployeeIsOpened)
{
	std::stringstream stmt;
	std::string query;
	const char* q;
	bool FunctionIsOpened=true;
	
	while (FunctionIsOpened)
	{
		std::cout<<"Adja meg az adatokat"<<std::endl;
		std::cout<<"0: vissza"<<std::endl;
		std::cout<<std::endl;
		
		std::cout<<"Név ";
		std::cin.ignore();
		getline(std::cin,name);
		if (name=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"Ország ";
		getline(std::cin,country);
		if (country=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"Város ";
		getline(std::cin,city);
		if (city=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"Cím ";
		getline(std::cin,address);
		if (address=="0") system("cls");{break;}
		std::cout<<std::endl;
		
		std::cout<<"Csatlakozási dátum (év-hónap-nap) ";
		getline(std::cin,joining_date);
		if (joining_date=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"Pozíció ";
		getline(std::cin,position);
		if (position=="0") {system("cls");break;}
		std::cout<<std::endl;
		
		std::cout<<"Fizetés ";
		std::cin>>salary;
		if (salary==0) {system("cls");break;}
		std::cout<<std::endl;
		system("cls");
		
		stmt.clear();
		stmt.str("");
		stmt<<"INSERT INTO employees(country,city,address,salary,joining_date,position,name) VALUES ('"<<country<<"','"<<city<<"','"<<address<<"','"<<salary<<"','"<< joining_date<<"','"<<position<<"','" <<name <<"')";
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
		}else
		{
			system("cls");
			std::cout<<"Alkalmazott hozzáadva az adatbázishoz."<<std::endl;
			std::cout<<std::endl;
		
			mysql_store_result(book_shop);
			FunctionIsOpened=false;
			EmployeeIsOpened=false;
		}	
	}
	
	
}




//search employee by name
int employee_search(MYSQL* book_shop, const std::string &name)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	
	stmt<<"SELECT * FROM employees WHERE name REGEXP '" <<name<<"'";
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
		while((row = mysql_fetch_row(res_set)) != NULL)
    	{
		std::cout << "Az alkalmazott id-je " << row[0] <<std::endl;
        std::cout << "Az alkalmazott országa  " << row[1] <<std::endl;
		std::cout << "Az alkalmazott városa " << row[2] <<std::endl;
        std::cout << "Az alkalmazott címe " << row[3] <<std::endl;
		std::cout << "Az alkalmazott fizetése " << row[4] <<std::endl;
		std::cout << "Az alkalmazott csatlakozási dátuma " << row[5] <<std::endl;
		std::cout << "Az alkalmazott pozíciója " << row[6] <<std::endl;
		std::cout << "Az alkalmazott neve " << row[7] <<std::endl;
		std::cout<<std::endl;
		}
		
		mysql_free_result(res_set);
		return 2;
	}
	else
	{
		std::cout << "Nincs találat" << std::endl;
		std::cout<<std::endl;
		mysql_free_result(res_set);
		return 1;
	}
	
}




//update employee details with using id
void employee_change_help(MYSQL* book_shop,const int &id,bool &FunctionIsOpened,std::string name,std::string country,std::string city,std::string address,int salary,std::string joining_date,std::string position,bool &EmployeeIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	bool LoopIsOpened=true;
	int choice;
	
	
	stmt<<"SELECT * FROM employees WHERE id='"<<id<<"'";
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
		std::cout << "Nincs találat az ID-re" << std::endl;
	}
	else
	{
	
		while(LoopIsOpened)
		{
			std::cout<<"Mit szeretne megváltoztatni?"<<std::endl;
			std::cout<<std::endl;
			std::cout << "1: Az alkalmazott neve "  <<std::endl;
			std::cout << "2: Az alkalmazott országa  "  <<std::endl;
			std::cout << "3: Az alkalmazott városa "  <<std::endl;
			std::cout << "4: Az alkalmazott címe " <<std::endl;
			std::cout << "5: Az alkalmazott fizetése " <<std::endl;
			std::cout << "6: Az alkalmazott csatlakozási dátuma " <<std::endl;
			std::cout << "7: Az alkalmazott pozíciója " <<std::endl;
			std::cout << "0: vissza."<<std::endl;
			std::cin>>choice;
			system("cls");
			
			switch (choice)
			{
				case 1:
				std::cout<<"Adja meg az alkalmazott nevét."<<std::endl;
				std::cin.ignore();
				getline(std::cin,name);
				system("cls");
				stmt.clear();
				stmt.str("");
				stmt<<"UPDATE employees SET name='"<<name<<"' WHERE id='"<<id<<"'";
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
				EmployeeIsOpened=false;
				std::cout<<"Az alkalmazott neve megváltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 2:
				std::cout<<"Adja meg az alkalmazott országát."<<std::endl;
				std::cin.ignore();
				getline(std::cin,country);
				system("cls");
				stmt.clear();
				stmt.str("");
				stmt<<"UPDATE employees SET country='"<<country<<"' WHERE id='"<<id<<"'";
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
				EmployeeIsOpened=false;
				std::cout<<"Az alkalmazott országa megváltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 3:
				std::cout<<"Adja meg az alkalmazott városát."<<std::endl;
				std::cin.ignore();
				getline(std::cin,city);
				system("cls");
				stmt.clear();
				stmt.str("");
				stmt<<"UPDATE employees SET city='"<<city<<"' WHERE id='"<<id<<"'";
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
				EmployeeIsOpened=false;
				std::cout<<"Az alkalmazott városa megváltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 4:
				std::cout<<"Adja meg az alkalmazott címét."<<std::endl;
				std::cin.ignore();
				getline(std::cin,address);
				system("cls");
				stmt.clear();
				stmt.str("");
				stmt<<"UPDATE employees SET address='"<<address<<"' WHERE id='"<<id<<"'";
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
				EmployeeIsOpened=false;
				std::cout<<"Az alkalmazott címe megváltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 5:
				std::cout<<"Adja meg az alkalmazott fizetését."<<std::endl;
				std::cin>>salary;
				system("cls");
				stmt.clear();
				stmt.str("");
				stmt<<"UPDATE employees SET salary='"<<salary<<"' WHERE id='"<<id<<"'";
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
				EmployeeIsOpened=false;
				std::cout<<"Az alkalmazott fizetése megváltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 6:
				std::cout<<"Adja meg az alkalmazott csatlakozási dátumát."<<std::endl;
				std::cin.ignore();
				getline(std::cin,joining_date);
				system("cls");
				stmt.clear();
				stmt.str("");
				stmt<<"UPDATE employees SET joining_date='"<<joining_date<<"' WHERE id='"<<id<<"'";
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
				EmployeeIsOpened=false;
				std::cout<<"Az alkalmazott csatlakozási dátuma megváltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 7:
				std::cout<<"Adja meg az alkalmazott pozícióját."<<std::endl;
				std::cin.ignore();
				getline(std::cin,position);
				system("cls");
				stmt.clear();
				stmt.str("");
				stmt<<"UPDATE employees SET position='"<<position<<"' WHERE id='"<<id<<"'";
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
				EmployeeIsOpened=false;
				std::cout<<"Az alkalmazott pozíciója megváltoztatva."<<std::endl;
				std::cout<<std::endl;
				
				break;
				
				case 0:
				LoopIsOpened=false;
				break;
				
				default:
				std::cout<<"Rossz számot adott meg."<<std::endl;
				std::cout<<std::endl;
					
			}
		}
	
	}
	mysql_free_result(res_set);
	
}



//update employee details
void Employees::change(MYSQL* book_shop,bool &EmployeeIsOpened)
{
	int choice;
	bool FunctionIsOpened=true;
	int number;
	
	
	while(FunctionIsOpened)
	{
		std::cout<<"Kinek az adatait akarja megváltoztatni?"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"1: id megadása."<<std::endl;
		std::cout<<"2: keresés név alapján."<<std::endl;
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
				employee_change_help(book_shop,id,FunctionIsOpened,name, country, city, address, salary, joining_date, position,EmployeeIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg a nevét."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,name);
			system("cls");
			
			if (name!="0" )
			{
				number=employee_search(book_shop, name);
				
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cout<<"0: vissza."<<std::endl;
					std::cin>>id;
					system("cls");
					if (id!=0 )
					{
						employee_change_help(book_shop,id,FunctionIsOpened,name, country, city, address, salary, joining_date, position,EmployeeIsOpened);
					}
				}
			}
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem jó számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
	
}





//remove one employee from database with using id
void employee_remove_help(MYSQL* book_shop,const int &id,bool &FunctionIsOpened,bool &EmployeeIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt.clear();
	stmt.str("");
	stmt<<"SELECT * FROM employees WHERE id='"<<id<<"'";
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
		std::cout << "Nincs találat az id-re" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		stmt.clear();
		stmt.str("");
		
		stmt<<"DELETE FROM employees WHERE id='"<<id<<"'";
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
		
		std::cout<<"Alkalmazott törölve az adatbázisból."<<std::endl;
		std::cout<<std::endl;
		mysql_store_result(book_shop);
		FunctionIsOpened=false;
		EmployeeIsOpened=false;
	}
	mysql_free_result(res_set);
	
	
}





//remove one employee from database
void Employees::remove(MYSQL* book_shop,bool &EmployeeIsOpened)
{
	int choice;
	bool FunctionIsOpened=true;
	int number;
	
	
	while(FunctionIsOpened)
	{
		std::cout<<"Kit akar kitörölni az adatbázisból?"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"1: id megadása"<<std::endl;
		std::cout<<"2: keresés név alapján."<<std::endl;
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
				employee_remove_help(book_shop,id,FunctionIsOpened,EmployeeIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg az alkalmazott nevét."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,name);
			system("cls");
			
			if (name!="0" )
			{
				
				number=employee_search(book_shop, name);
				
				if (number == 2)
				{
					std::cout<<"Adja meg az id-t."<<std::endl;
					std::cin>>id;
					system("cls");
					if (id!=0 )
					{
						employee_remove_help(book_shop,id,FunctionIsOpened,EmployeeIsOpened);
					}
				}	
			}
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem jó számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
	
}




//display data of one employee with using id
void employee_get_help(MYSQL* book_shop,const int &id,bool &FunctionIsOpened, bool &EmployeeIsOpened)
{
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	std::stringstream stmt;
	std::string query;
	const char* q;
	
	stmt<<"SELECT * FROM employees WHERE id='"<<id<<"'";
	query=stmt.str();
	q=query.c_str();
	
	if (mysql_ping(book_shop))
	{
		std::cout<<"Error, imposeble to connet"<<std::endl;
		std::cout<<mysql_error(book_shop)<<std::endl;
	}
	
	if(mysql_query(book_shop,q))
	{
		std::cout<<"Error "<<mysql_error(book_shop)<<std::endl;
		rewind(stdin);
		getchar();
	}
	
	
	res_set=mysql_store_result(book_shop);
	
	if((row = mysql_fetch_row(res_set)) != NULL)
    {
		std::cout << "Az alkalmazott id-je " << row[0] <<std::endl;
        std::cout << "Az alkalmazott országa  " << row[1] <<std::endl;
		std::cout << "Az alkalmazott városa " << row[2] <<std::endl;
        std::cout << "Az alkalmazott címe " << row[3] <<std::endl;
		std::cout << "Az alkalmazott fizetése " << row[4] <<std::endl;
		std::cout << "Az alkalmazott csatlakozási dátuma " << row[5] <<std::endl;
		std::cout << "Az alkalmazott pozíciója " << row[6] <<std::endl;
		std::cout << "Az alkalmazott neve " << row[7] <<std::endl;
		std::cout <<  std::endl;
		FunctionIsOpened=false;
		EmployeeIsOpened=false;
	}
	else
	{
		std::cout << "Nincs találat az ID-re" << std::endl;
		std::cout <<  std::endl;
	}
	
	mysql_free_result(res_set);
	
}


//display data of one employee
void Employees::get(MYSQL* book_shop,bool &EmployeeIsOpened)
{
	int choice,number;
	bool FunctionIsOpened=true;
	
	
	
	while(FunctionIsOpened)
	{
		std::cout<<"Kinek az adatait akarja megjeleníteni az adatbázisból?"<<std::endl;
		std::cout<<std::endl;
		std::cout<<"1: id megadása"<<std::endl;
		std::cout<<"2: keresés név alapján."<<std::endl;
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
				employee_get_help(book_shop,id,FunctionIsOpened,EmployeeIsOpened);
			}
			break;
			
			case 2:
			std::cout<<"Adja meg az alkamazott nevét."<<std::endl;
			std::cout<<"0: vissza."<<std::endl;
			std::cin.ignore();
			getline(std::cin,name);
			system("cls");
			if (name!="0" )
			{
				number = employee_search(book_shop, name);
				if (number == 2) {FunctionIsOpened=false;EmployeeIsOpened=false;}
			}
			break;
			
			case 0:
			FunctionIsOpened=false;
			break;
			
			default:
			std::cout<<"Nem jó számot adott meg."<<std::endl;
			std::cout<<std::endl;
		}
	}
	
	
	
}



//display data of all employees
void Employees::all_get(MYSQL* book_shop,bool &EmployeeIsOpened)
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
		std::cout << "Az alkalmazott id-je " << row[0] <<std::endl;
        std::cout << "Az alkalmazott országa  " << row[1] <<std::endl;
		std::cout << "Az alkalmazott városa " << row[2] <<std::endl;
        std::cout << "Az alkalmazott címe " << row[3] <<std::endl;
		std::cout << "Az alkalmazott fizetése " << row[4] <<std::endl;
		std::cout << "Az alkalmazott csatlakozási dátuma " << row[5] <<std::endl;
		std::cout << "Az alkalmazott pozíciója " << row[6] <<std::endl;
		std::cout << "Az alkalmazott neve " << row[7] <<std::endl;
		std::cout<<std::endl;
		row = mysql_fetch_row(res_set);
	}
	
	mysql_free_result(res_set);
	EmployeeIsOpened=false;
	
}





Employees::~Employees()
{
	
}
