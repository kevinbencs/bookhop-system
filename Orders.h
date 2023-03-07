#include <string>
#include <mysql.h>

#pragma once

class Orders
{
	Orders();
	
	~Orders();
	
	add(MYSQL* book_shop);
	
	change(MYSQL* book_shop);
	
	remove_order(MYSQL* book_shop);
	
	get(MYSQL* book_shop);
	
	
	
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