#include <string>
#include <mysql.h>

#ifndef BOOK_H
#define BOOK_H

class Bbook
{
public:
	
	Book();
	
	~Book();
	
	
private:
	
	int id;
	std::string name;
	std::string author;
	int prince;
	int quantity;
	
	
	
	
	
	
};

#endif