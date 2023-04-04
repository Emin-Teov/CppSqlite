#include <iostream>
#include <string>
#include "sqlite/sqlite3.h"
#include "SetDB.h"

using namespace std;
// void createDB(const char* s);

int main()
{
	/**
	* Create the database
	* 
	* Add the name of the database you want to create as an argument.
	*/
	// createDB("DB.db");

	SetDB db;

	/**
	* Create a table in the database
	* 
	* The created table can be modified by calling the this->table variable.
	*/
	/*
		db.sql = "CREATE TABLE IF NOT EXISTS products (id INTEGER PRIMARY KEY AUTOINCREMENT, "
		"seria_id CHAR(20) UNIQUE NOT NULL, "
		"name TEXT NOT NULL, "
		"date DATETIME NOT NULL default (STRFTIME('%Y-%m-%d %H:%M:%f', 'NOW')));";
		db.createTable();
	*/


	/**
	* Drop a table into the database
	*/
	/*
		db.sql = "DROP TABLE IF EXISTS products;";
		db.setQuery();
	*/


	/**
	* Insert the data into the table in two different ways
	* 
	* Arguments you need to include:
	*	where query,
	*	selected column(s),
	*	changed value(s),
	*/
	/*
		for (size_t i = 0; i < 10; i++)
		{
			db.sql += "INSERT INTO products (seria_id, name, date) VALUES('sdp2134" + to_string(i) + "', 'DGF7', strftime('%Y-%m-%d %H:%M:%S:%s'));";
		}
		db.setQuery();
	*/
	/*
		db.table = "products";
		db.columns = {"seria_id", "name"};
		db.values = {"sdp21647", "DGA7"};
		db.insert();
	*/


	/**
	* Delete the data into the table in two different ways
	* 
	* Arguments you need to include:
	*	where query,
	*/
	/*
		db.table = "products";
		db.remove("id = 2");	
	*/
	/*
		db.sql = "DELETE FROM products WHERE id = 5;";
		db.setQuery();	
	*/


	/**
	* Update the data into the table in three different ways
	* 
	* Arguments you need to include:
	*	where query,
	*	selected column(s),
	*	changed value(s),
	*/
	/*
		db.table = "products";
		db.columns = { "seria_id", "name" };
		db.values = { "sdp2047", "DGA11" };
		db.update("id = 3");
	*/
	/*
		db.update("id = 3", "name", "DGA20");
	*/
	/*
		db.sql = "UPDATE products SET name = 'DGA25' WHERE id = 7;";
		db.setQuery();
	*/


	/**
	* Select the data in the table
	* 
	* Arguments you need to include:
	*	selected columns,
	*	where query,
	*	order by,
	*	sort by,
	*/
	/*
		db.table = "products";
		// select(select = "*", query = "", order = "id", sort = "ASC")
		db.select();
		db.select("*", "name = 'DGA7'");
		db.select("*", "", "seria_id", "DESC");
	*/
}

/*
	void createDB(const char* s)
	{
		sqlite3* db;
		sqlite3_open(s, &db);
		sqlite3_close(db);
	}
*/

