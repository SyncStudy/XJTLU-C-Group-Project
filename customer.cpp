#include"customer.h"
#include"sqlite3.h"


void customer::setName(string name)
{
	Name = name;
	//Pass to the data base
}

void customer::setID(int id)		//Maybe this method is belong to admin
{
	ID = id;
}

void customer::setTelephonenumber(int Tel)
{
	telephonenumber = Tel;
	//Pass to the data base
}

void customer::setPassword(string password)
{
	Password = password;
	//Pass to the data base
}

string customer::getName()
{
	return Name;
}

int customer::getID()
{
	return ID;
}

int customer::getTelephonenumber()
{
	return telephonenumber;
}

void customer::setBoughtMovie(string MovieName)
{
	boughtMovie.push_back(MovieName);
}

void customer::browseMovie()
{
	//Display all of the recent films
}

void customer::buyTicket()
{
	int command;
	string theMovieSelected;
	string theTimeSelected;
	string theRoomSelected;
	int theSeatSelected;
	string seatStatus;
	float price=0.0;
	float fetchedPrice=0;
	string a;
	bool flag = false;
	cout << "Recent movies are as follows" << endl;
	//cout << Recent movies'names
	//cout << "Recent movies are as follows" << endl;
	sqlite3 *db = 0;
	int ret = sqlite3_open("./NEW.db", &db);
	char *s;
	ret = sqlite3_exec(db, "create table if not exists movieTimeSlot(ticketId int (20), movieId int(20), movieName varchar(20),room varchar(200), startingTime int(20), lastingTime int(20),SeatStatus varchar(750), price real(500) )", 0, 0, &s);
	if (ret != SQLITE_OK)
	{
		
		printf("create error\n");
		//return 1;
	}
	//printf("create success\n");
	const char *select_query = "SELECT DISTINCT movieId,  movieName from movieTimeSlot";
	char **db_result;
	int nrow, ncolumn;
	ret = sqlite3_get_table(db, select_query, &db_result, &nrow, &ncolumn, &s);
	if (ret != SQLITE_OK)
	{
		printf("select error\n");
		
		//return 1;
	}
	int i1, j1;
	for (i1 = 0; i1 < (nrow + 1)*ncolumn; i1 += ncolumn)
	{
		for (j1 = 0; j1 < ncolumn; j1++)
		{
			printf("%s  ", db_result[i1 + j1]);
		}
		printf("\n");
	}


	
	cout << "Please choose the ID of the movie you want to see (only existing movie ID is accepted) ." << endl;
	//cout << Available movies, if the room is full, won't display at here
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		if (!(a[i] >= '0'&&a[i] <= '9'))
		{
			flag = true;
			break;
		}
	}
	while (flag)
	{
		cout << "Invalid entry! Please input the ID of the movie again" << endl;
		cin >> a;
		for (int i = 0; i < a.size(); i++)
		{
			if (!(a[i] >= '0'&&a[i] <= '9'))
			{
				flag = true;
				break;
			}
			if ((i == (a.size() - 1)) && (a[i] >= '0'&&a[i] <= '9'))
			{
				flag = false;
				break;
			}
		}
		system("cls");
	}

	command = atoi(a.c_str());
	std::string insertStr = "SELECT  ticketid,movieid,moviename,room,startingtime,lastingtime,price from movieTimeSlot WHERE movieId=(" + to_string(command) +   ")";
	char *sqliteInsert = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？
	ret = sqlite3_get_table(db, sqliteInsert, &db_result, &nrow, &ncolumn, &s);
	if (ret != SQLITE_OK)
	{
		printf("select error\n");
		
		//return 1;
	}
	
	for (i1 = 0; i1 < (nrow + 1)*ncolumn; i1 += ncolumn)
	{
		for (j1 = 0; j1 < ncolumn; j1++)
		{
			printf("%s  ", db_result[i1 + j1]);
		}
		printf("\n");
	}


	//const char *select_query1 = "SELECT DISTINCT movieName from movieTimeSlot WHERE movieId=";
	//command is the index of the selection
	cout << "Please input the ticket ID (only existing ticket ID is accepted)";
	cin >> a;
	for (int i = 0; i < a.size(); i++)
	{
		if (!(a[i] >= '0'&&a[i] <= '9'))
		{
			flag = true;
			break;
		}
	}
	while (flag)
	{
		cout << "Invalid entry! Please input the ticket ID again" << endl;
		cin >> a;
		for (int i = 0; i < a.size(); i++)
		{
			if (!(a[i] >= '0'&&a[i] <= '9'))
			{
				flag = true;
				break;
			}
			if ((i == (a.size() - 1)) && (a[i] >= '0'&&a[i] <= '9'))
			{
				flag = false;
				break;
			}
		}
		system("cls");
	}

	command = atoi(a.c_str());

	

	 insertStr  = "select movieName from movieTimeSlot where ticketId= (" + to_string(command) + ")";
	char *select_query3 = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？

	//select_query1
	//std::string insertStr = "select movieName from movieTimeSlot ";
	char **db_result4;
	ret = sqlite3_get_table(db, select_query3, &db_result4, &nrow, &ncolumn, &s);
	theMovieSelected = db_result4[1];

	insertStr = "select startingtime from movieTimeSlot where ticketId= (" + to_string(command) + ")";

	//theMovieSelected = movieName
	//theTimeSelected = startingTime
	//theRoomSelected = room

	
	 select_query3 = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？
	ret = sqlite3_get_table(db, select_query3, &db_result4, &nrow, &ncolumn, &s);
	theTimeSelected = db_result4[1];


	insertStr = "select room from movieTimeSlot where ticketId= (" + to_string(command) + ")";


	 select_query3 = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？
	ret = sqlite3_get_table(db, select_query3, &db_result4, &nrow, &ncolumn, &s);
	theRoomSelected = db_result4[1];



	insertStr = "select seatstatus from movieTimeSlot where ticketId= (" + to_string(command) + ")";
	select_query3 = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？
	ret = sqlite3_get_table(db, select_query3, &db_result4, &nrow, &ncolumn, &s);
	seatStatus = db_result4[1];


	cout << "Please choose the seat." << endl;
	selectSeat(theRoomSelected, theSeatSelected,seatStatus);
	if (seatStatus[theSeatSelected] == '1')
	{
		do
		{
			cout << "This seat is occupied, please select another seat." << endl;
			selectSeat(theRoomSelected, theSeatSelected,seatStatus);
		} while (seatStatus[theSeatSelected] == '1');
		seatStatus[theSeatSelected] = '1';
		//Store the new seatStatus into database
		//
		string updateStr = "update movieTimeSlot set SeatStatus=('" + seatStatus + "') where ticketId=(" + to_string(command) + ")";
		char *sqliteUpdate = const_cast<char*>(updateStr.c_str());
		ret = sqlite3_exec(db, sqliteUpdate, 0, 0, &s);
		if (ret != SQLITE_OK)
		{
			sqlite3_close(db);
			printf("update error1\n");
			system("pause");
		}
		printf("update success\n");
	}
	else
	{
		seatStatus[theSeatSelected] = '1';
		//Store the new seatStatus into database
		string updateStr = "update movieTimeSlot set SeatStatus=('" + seatStatus + "') where ticketId=(" + to_string(command) + ")";
		char *sqliteUpdate = const_cast<char*>(updateStr.c_str());
		ret = sqlite3_exec(db, sqliteUpdate, 0, 0, &s);
		if (ret != SQLITE_OK)
		{
			sqlite3_close(db);
			printf("update error\n");

		}
		printf("update success\n");
	}
	
	char **db_result6;
	insertStr = "select price from movieTimeSlot where ticketId= (" + to_string(command) + ")";
	select_query3 = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？
	ret = sqlite3_get_table(db, select_query3, &db_result6, &nrow, &ncolumn, &s);
	price = stof(db_result6[1]);


	
	
	cout << "Your ticket is:" << endl;
	cout << "Movie:\t" << theMovieSelected << endl;
	cout << "Time:\t" << theTimeSelected << endl;
	cout << "Room:\t" << theRoomSelected << endl;
	cout << "Seat:\t" << theSeatSelected+1 << endl;
	cout << "Price:\t" << price << endl;


	insertStr = "select totalprice from movietimeslot where movieName= ('" + theMovieSelected + "' )and price>0";

	char **db_result5;
	select_query3 = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？
	ret = sqlite3_get_table(db, select_query3, &db_result5, &nrow, &ncolumn, &s);
	fetchedPrice = stof(db_result5[1]);

	//Add the Price to the database (theMovieSelected)
	fetchedPrice = fetchedPrice + price;
	string updateStr = "update movietimeslot set totalprice=(" + to_string(fetchedPrice) + ") where movieName=('" + theMovieSelected + "')";
	char *sqliteUpdate = const_cast<char*>(updateStr.c_str());
	ret = sqlite3_exec(db, sqliteUpdate, 0, 0, &s);
}



void customer::selectSeat(string theRoomSelected, int &theSeatSelected, string seatStatus)
{
	if (theRoomSelected == "smallroom 1" || theRoomSelected == "smallroom 2" || theRoomSelected == "smallroom 3" || theRoomSelected == "smallroom 4" || theRoomSelected == "smallroom 5")
	{
		cout << "Please choose the number of your seat from 001 to 300 (enter the corresponding number):" << endl;
		int i = 0, j = 0, a = 1;
		cout << "ROW" << "                   SCREEN" << endl;
		cout << endl;
		while (i < 300)
		{
			if (i == 15 * j)
			{
				cout << a << "  ";
				if (a < 10)
				{
					cout << " ";
				}
				a++;
			}
			cout << seatStatus[i] << "  ";
			if (i == 14 + 15 * j)
			{
				cout << endl;
				j++;
			}
			i++;
		}
		cin >> theSeatSelected;
		theSeatSelected--;
		system("cls");
	}

	else if (theRoomSelected == "bigroom 1" || theRoomSelected == "bigroom 2" || theRoomSelected == "bigroom 3")
	{
		cout << "Please choose the number of your seat from 001 to 750 (enter the corresponding number):" << endl;
		int i = 0, j = 0, a = 1;
		cout << "ROW" << "                                 SCREEN" << endl;
		cout << endl;
		while (i < 750)
		{
			if (i == 0 + 25 * j || i == 0)
			{
				cout << a << "  ";
				if (a < 10)
				{
					cout << " ";
				}
				a++;
			}
			cout << seatStatus[i] << "  ";
			if (i == 24 + 25 * j)
			{
				cout << endl;
				j++;
			}
			i++;
		}
		cin >> theSeatSelected;
		theSeatSelected--;
		system("cls");
	}
}
