#include <string>
#include <mysql.h>

#pragma once

class Orders
{
	Orders();
	
	~Orders();
	
	
private:
	
	int id;
	int book_id;
	std::string customer;
	std::string country;
	std::string city;
	std::string address1;
	int quantity;
	std::string dt_ordered;
	
};