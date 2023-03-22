#ifndef ORDERS_H
#define ORDERS_H

#include <string>
#include <mysql.h>




class Orders
{
public:
		
	Orders();
	
	~Orders();
	
	void add(MYSQL* ,bool &); //give data of new order
	
	void change(MYSQL* ,bool &); //update order details
	
	void remove(MYSQL* ,bool &); //remove one order from database
	
	void get(MYSQL* ,bool &); //display data of one order
	
	void all_get(MYSQL* ,bool &); //display data of one orders
	
	
	
private:
	
	int id; // Primary key
	int book_id; // Primary key of book
	std::string customer;
	std::string country;
	std::string city;
	std::string address;
	int quantity;
	std::string dt_ordered;
	int price;
	
};

#endif
