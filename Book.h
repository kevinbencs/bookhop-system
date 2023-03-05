#include <string>
#include <mysql.h>

#ifndef BOOK_H
#define BOOK_H

class Book
{
public:
	
	Book();
	
	~Book();
	
	set(MYSQL* book_shop);
	
	add(MYSQL* book_shop);
	
	change(MYSQL* book_shop);
	
	remove_book(MYSQL* book_shop);
	
	
private:
	
	int id;
	std::string name;
	std::string author;
	int prince;
	int quantity;
	
	
	
	
	
	
};

#endif