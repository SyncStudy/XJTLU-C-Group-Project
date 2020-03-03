#ifndef _CUSTOMER
#define _CUSTOMER

#include<time.h>
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;

class customer
{
	friend class Admin;

protected:
	string Name;			//Name of customer
	int ID;					//ID of customer
	string Password;		//Passward				(maybe need a initial password)
	int telephonenumber;				//Telephone number of customer
	vector<string> boughtMovie;			//Movies that customer has bought
	
public:
	//customer(string name = "Not Given", int Bought = 0);	//Constructor
	void setName(string name);		//Set the name
	void setID(int id);				//Set the ID
	void setTelephonenumber(int Tel);			//Set the Telephonenumber
	void setPassword(string password);			//Set the password

	string getName();				//Get the name
	int getID();					//Get the ID
	int getTelephonenumber();					//Get the Telephonenumber
	
	void browseMovie();
	
	void buyTicket();

	void setBoughtMovie(string MovieName);					//Set the movies has bought
	void selectSeat(string theRoomSelected, int &theSeatSelected, string seatStatus);			//Select the seat
};

#endif