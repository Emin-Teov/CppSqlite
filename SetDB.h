#pragma once
#include <iostream>
#include <vector>
#include "sqlite/sqlite3.h"

using namespace std;

class SetDB
{
private:
	/**
	* Specify the name of the selected database as the value of the constant s.
	*/
	const char* s = "DB.db";

	sqlite3* DB;
	char* messageError;

	static int callback(void* NotUsed, int argc, char** argv, char** ColName)
	{
		cout << "count: " << argc << endl;
		for (int i = 0; i < argc; i++) {
			cout << ColName[i] << ": " << argv[i] << endl;
		}
		cout << endl;

		return 0;
	}
public:
	string sql;
	string table;
	vector <string> columns;
	vector <string> values;

	void createTable()
	{
		try
		{
			int result = 0;
			result = sqlite3_open(s, &DB);
			result = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (result != SQLITE_OK) {
				cerr << "Error in createTable function.\n";
				sqlite3_free(messageError);
			}
			sqlite3_close(DB);
		}
		catch (const exception& e)
		{
			cerr << e.what();
		}
	}

	/**
	* Multifunctional method
	*/
	void setQuery()
	{
		if (!sql.empty()) {
			int result = sqlite3_open(s, &DB);
			result = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (result != SQLITE_OK) {
				cerr << "Error in query function." << endl;
				sqlite3_free(messageError);
			}
		}
		else {
			cerr << "Your SQL statement is empty.";
		}
	}

	void insert()
	{
		if (!table.empty() && !columns.empty() && !values.empty()) {
			string set_columns;
			string set_values;

			for (auto ic = columns.begin(); ic != columns.end(); ic++)
			{
				set_columns += *ic + ",";
			}
			set_columns.pop_back();

			for (auto iv = values.begin(); iv != values.end(); iv++)
			{
				set_values += "'" + *iv + "',";
			}
			set_values.pop_back();

			sql = "INSERT INTO " + table + " (" + set_columns + ") VALUES(" + set_values + ");";

			int result = sqlite3_open(s, &DB);
			result = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (result != SQLITE_OK) {
				cerr << "Error in insert function." << endl;
				sqlite3_free(messageError);
			}
		}
		else {
			cerr << "Your SQL statement is incorrect" << endl;
		}
	}

	void remove(string const& query)
	{
		if (!table.empty()) {
			string sql = "DELETE FROM " + table + " WHERE " + query + ";";

			int result = sqlite3_open(s, &DB);
			result = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
			if (result != SQLITE_OK) {
				cerr << "Error in remove function." << endl;
				sqlite3_free(messageError);
			}
		}
		else {
			cerr << "Your SQL statement don't have a table name" << endl;
		}
	}

	void update(string const& query)
	{
		if (!table.empty() && !columns.empty() && !values.empty()) {
			string set_query;
			for (size_t i = 0; i < columns.size(); i++)
			{
				set_query = columns[i] + " = '" + values[i] + "',";
			}
			set_query.pop_back();
		
			sql = "UPDATE " + table + " SET " + set_query + " WHERE " + query + ";";
			int result = sqlite3_open(s, &DB);
			result = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (result != SQLITE_OK) {
				cerr << "Error in update function." << endl;
				sqlite3_free(messageError);
			}
		}
		else {
			cerr << "Your SQL statement is incorrect" << endl;
		}
	}

	void update(string const& query, string const& column, string const& value)
	{
		if (!table.empty() && !column.empty() && !value.empty()) {
			sql = "UPDATE " + table + " SET " + column + " = '" + value + "' WHERE " + query + ";";
			int result = sqlite3_open(s, &DB);
			result = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
			if (result != SQLITE_OK) {
				cerr << "Error in update function." << endl;
				sqlite3_free(messageError);
			}
		}
		else {
			cerr << "Your SQL statement is incorrect" << endl;
		}
	}

	void select(string const& select="*", string query="", string const& order="id", string const& sort="ASC")
	{
		if (!table.empty()) {
			if (!query.empty()) {
				query = "WHERE " + query;
			}
			sql = "SELECT " + select +" FROM " + table + " " + query + " ORDER BY " + order + " " + sort + ";";
			int result = sqlite3_open(s, &DB);
			result = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

			if (result != SQLITE_OK) {
				cerr << "Error in select function." << endl;
				sqlite3_free(messageError);
			}
		}
	}
};