#ifndef _MOVIE
#define _MOVIE

#include<time.h>
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<vector>
using namespace std;

class movie
{
public:
	movie();
	~movie();
	void setNameOfmovie();
	string getNameOfmovie();
	void inputID();		//input the movie ID
	void getID();
	int getHour();
	void inputPriceParameter();		//the price parameter
	void locationOfmovie();		//which room has this movie
	void setTimeOfmovie();
	void startTime();		//开始上映的时间


	void showTime();
	void getLocation();
	int getLocation2();
	int getTimeOfmovie();

	int returnID();
	string returnRoom();
	string seatStatus();
	float generatePrice();
private:
	string nameOfmovie;
	int ID;
	float priceParameter;
	//private about the time of movie
	int startTimeMonth;
	int startTimeDay;
	int startTimeHour;
	int startTimeMinute;
	//////////////////////////////////
	int positionOfmovie;
	int lastingOfmovie;
};

#endif // !_MOVIE
