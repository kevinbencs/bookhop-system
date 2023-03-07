#include <string>
#include <mysql.h>

#ifndef BOOK_H
#define BOOK_H

class Book
{
public:
	
	Book();
	
	~Book();
	
	void get(MYSQL* book_shop);
	
	void add(MYSQL* book_shop);
	
	void change(MYSQL* book_shop);
	
	void remove_book(MYSQL* book_shop);
	
	
private:
	
	int id;
	std::string name;
	std::string author;
	int prince;
	int quantity;
	
	
	
	
	
	
};

#endif