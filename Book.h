#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <mysql.h>



class Book
{
public:
	
	
	Book();
	
	~Book();
	
	void add(MYSQL* ,bool &); //give data of new book
	
	void change(MYSQL* ,bool &); //update book details
	
	void remove(MYSQL* ,bool &); //remove one book from database
	
	void get(MYSQL*,bool &); //display data of one book
	
	void all_get(MYSQL* ,bool &); //display data of all books
	
	
	
private:
	
	int id; // Primary key
	std::string name;
	std::string author;
	int price;
	int quantity;
	
	
	
	
	
	
};

#endif
