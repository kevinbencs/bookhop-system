#include <string>
#include <mysql.h>

#ifndef BOOK_H
#define BOOK_H

class Book
{
public:
	
	Book(MYSQL* book_shop,int book_id,bool &FunctionIsOpened);
	
	~Book();
	
	void get(MYSQL* book_shop);
	
	void add(MYSQL* book_shop);
	
	void change(MYSQL* book_shop);
	
	void remove_book(MYSQL* book_shop);
	
	int get_price();
	
	int get_quantity();
	
private:
	
	int id;
	std::string name;
	std::string author;
	int price;
	int quantity;
	
	
	
	
	
	
};

#endif