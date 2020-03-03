#include"movie.h"
#include"sqlite3.h"
#include"customer.h"
#define _CRT_SECURE_NO_WARNINGS
void administor(movie &Temp);
const char *select_query = "SELECT * from movieTimeSlot";
const char *select_query1 = "SELECT startingtime, lastingtime, room from movieTimeSlot";
const char *copyquery = "SELECT DISTINCT moviename, totalprice from movietimeslot where totalprice>0; ";
const char *select_query2 = "SELECT DISTINCT movieId,  movieName from movieTimeSlot";
int nrow, ncolumn;
char ** db_result;
int ret;
sqlite3 *db = 0;
char *s = 0;
string keyword;
void compare(movie &Temp, vector<string> room, vector<int> startingTime, vector<int> lastingTime);
void cus(customer &temp);
string password= "123";
string inputPw;

int main()
{
	
	ret = sqlite3_open("./NEW.db", &db);
	ret = sqlite3_exec(db, "create table if not exists movieTimeSlot(ticketId INTEGER PRIMARY KEY autoincrement, movieId int(20), movieName varchar(20),room varchar(200), startingTime int(20), lastingTime int(20),SeatStatus varchar(750), price real(500), totalPrice real(500) )", 0, 0, &s);
	//ret = sqlite3_exec(db, "create table if not exists movieStatics(movieName varchar(20), price real(500) )", 0, 0, &s);

	
	movie Temp;
	customer TempC;
	bool flag = true;
	while (flag == true)
	{
		int y;
		string a;
		cout << "what is your identity?\n\t";
		cout << "1. administrator\n\t2. customer\n\t3. exit\n";
		bool flag2 = false;
		cin >> a;
		if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '3'))
		{
			flag2 = true;
			system("cls");
		}
		while (flag2)
		{
			cout << "Invalid entry! Please input the option again" << endl;
			cout << "\t1. administrator\n\t2. customer\n\t3. exit\n";
			cin >> a;
			if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '3'))
			{
				flag2 = true;
			}
			if (((a.size() == 1)) && (a[0] >= '1'&&a[0] <= '3'))
			{
				flag2 = false;
			}
			system("cls");
		}
		y = atoi(a.c_str());

		switch (y)
		{
		case 1:
			while (1)
			{
				//password=123
				cout << "Input your password (see on user manual):";
				cin >> inputPw;
				if (inputPw == password)
				{
					break;
				}
			}
			system("cls");
			administor(Temp);
			break;

		case 2:
			system("cls");
			cus(TempC);
			break;

		case 3:
			flag = false;

		}
	}

	cout << "Thank you for your using" << endl;
	return 0;
}

void administor(movie &Temp)
{
	bool flag = true;
	string a;
	int option;
	while (flag == true)
	{
		system("cls");
		cout << "What do you want to do?\n\t";
		cout << "1. Surf all the movie\n\t2. Add new movie\n\t3. Delete movie\n\t4. Retrive Statistical Info\n\t5. Exit\n";
		bool flag2 = false;
		cin >> a;
		if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '5'))
		{
			flag2 = true;
			system("cls");
		}
		while (flag2)
		{
			cout << "Invalid entry! Please input the option again" << endl;
			cout << "\t1. Surf all the movie\n\t2. Add new movie\n\t3. Delete movie\n\t4. Retrive Statistical Info\n\t5. Exit\n";
			cin >> a;
			if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '5'))
			{
				flag2 = true;
			}
			if (((a.size() == 1)) && (a[0] >= '1'&&a[0] <= '5'))
			{
				flag2 = false;
			}
			system("cls");
		}
		option = atoi(a.c_str());
		switch (option)
		{
		case 1:
			system("cls");
			//Display all movie arrangement

			cout << "Recent movies are as follows" << endl;
			
			if (ret != SQLITE_OK)
			{
			
				printf("create error\n");
				//return 1;
			}
			printf("create success\n");
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
					printf("%-15s  ", db_result[i1 + j1]);
				}
				printf("\n");
			}
			system("pause");
			
			break;

		case 2:
		{
			bool flag1 = true;
			while (flag1 == true)
			{
				system("cls");
				movie();
				Temp.~movie();
				Temp.setNameOfmovie();
				Temp.inputID();
				Temp.inputPriceParameter();
				Temp.locationOfmovie();
				Temp.startTime();
				
				vector<string> vara;
				vector<string> varb;
				vector<string>varc;
				vector<int> IVera;
				vector<int> IVerb;
				char *s1=0;
				int ret1 = 0;//movie
			
				sqlite3 *db1 = 0;
				char ** db1_result;
				int nrow1, ncolumn1;
				
				ret = sqlite3_open("./NEW.db", &db1);
				
				int recordLength;
				const char *countQuery = "SELECT COUNT(*) AS myCount FROM  movieTimeSlot ";
				ret1 = sqlite3_get_table(db1, countQuery, &db1_result, &nrow1, &ncolumn1, &s1);
				recordLength = atoi(db1_result[1]);
				ret1 = sqlite3_get_table(db1, select_query1, &db1_result, &nrow1, &ncolumn1, &s1);
				for (int i = 0; i < recordLength; i++)
				{
					
					vara.push_back(db1_result[3*i+3]);
					varb.push_back(db1_result[3 * i + 4]);
					varc.push_back(db1_result[3 * i + 5]);
				}
			
				for (int i = 0; i < recordLength; i++)
				{
				
					IVera.push_back(stoi(vara[i]));
				
					IVerb.push_back(stoi(varb[i]));
		
				}
				
				compare(Temp, varc, IVera, IVerb);
				Temp.setTimeOfmovie();
				

				//Store Temp into database
				//long test = 123221562;
				ret1 = sqlite3_open("./NEW.db", &db1);
				//Temp.getNameOfmovie(),Temp.returnRoom(),Temp.getHour(),Temp.getTimeOfmovie(),Temp.seatStatus(),Temp.generatePrice()
				//std::string insertStr = "insert into movieTimeSlot values(" + std::to_string(test) + "," + std::to_string(test) + ")";
				string stest= Temp.getNameOfmovie();
				std::string insertStr = "insert  into movieTimeSlot(movieId,moviename,room, startingtime, lastingtime,seatstatus,price,totalPrice) values("+to_string(Temp.returnID())+",'" + stest + "','" + Temp.returnRoom() + "'," + to_string(Temp.getHour()) + "," + to_string(Temp.getTimeOfmovie()) + ",'" + Temp.seatStatus() + "'," + to_string(Temp.generatePrice()) +","+ to_string(0) + ")";
				char *sqliteInsert = const_cast<char*>(insertStr.c_str());//怎么把这个字母写进去？
				ret1 = sqlite3_exec(db1, sqliteInsert, 0, 0, &s1);

				if (ret1 != SQLITE_OK)
				{
					
					printf("insert error\n");
					cout << s1;
					//return 1;
				}
				printf("insert success\n");

				//movieID = Temp.returnID()
				//movieName = Temp.getNameOfmovie()
				//room = Temp.returnRoom()
				//startingTime = Temp.getHour()
				//lastingTime = Temp.getTimeOfmovie()
				//seatStatus = Temp.seatStatus()
				//Price = Temp.generatePrice()



				cout << "do you want to add new movie?" << endl;
				cout << "1.YES\t\n2.NO\t\n";
				int i;	cin >> i;
				if (i == 1)
				{
					flag1 = true;
				}
				else if (i == 2)
				{
					system("cls");
					flag1 = false;
				}
			}
		}

			break;

		case 3:
		{
			cout << "please input the movieId of the movie:" << endl;
			int a;
			cin >> a;
			// a is the index
			// Delete the movie arrangement whose index is a
			string deleteStr = "delete from movieTimeSlot where movieId =(" + to_string(a) + ")";
			char *delete_query2 = const_cast<char*>(deleteStr.c_str());
			int ret2 = sqlite3_exec(db, delete_query2, 0, 0, &s);
			if (ret2 != SQLITE_OK)
			{
				
				printf("delete error\n");
				//return 1;
			}
			printf("delete success\n");
			system("pause");
			break;
		}
		case 4:
			//Manage Statics
			cout << "All income based on distinct movies are as follows.\n";
			 ret = sqlite3_exec(db, copyquery, 0, 0, &s);
			 int nrow1, ncolumn1;
			 char ** db1_result;
			 ret = sqlite3_get_table(db, copyquery, &db1_result, &nrow1, &ncolumn1, &s);
		
			 
			
			 for (i1 = 0; i1 < (nrow1 + 1)*ncolumn1; i1 += ncolumn1)
			 {
				 for (j1 = 0; j1 < ncolumn1; j1++)
				 {
					 printf("%-15s", db1_result[i1 + j1]);
				 }
				 printf("\n");
			 }
			 system("pause");
			
			break;
		case 5:
			flag = false;
			system("cls");
			break;
		}
	}
}


void compare(movie &Temp, vector<string> room, vector<int> startingTime, vector<int> lastingTime)
{
here:
	for (int i = 0; i < room.size(); i++)
	{
		if (room[i] == Temp.returnRoom())
		{
			if (startingTime[i] <= Temp.getHour() && Temp.getHour() < (startingTime[i] + lastingTime[i]))
			{
				cout << "Occupied time, invalid plan" << endl;
				fflush(stdin);
				Temp.startTime();
				goto here;
			}
			else if (startingTime[i] == Temp.getHour())
			{
				cout << "Occupied time, invalid plan" << endl;
				fflush(stdin);
				Temp.startTime();
				goto here;
			}
		}
	}
}
//Create a new table to store each movie's income
void cus(customer &temp)
{
	bool flag = true;
	bool flag1 = true;
	int option;
	int n = 0;
	while (flag == true)
	{
		system("cls");
		cout << "What do you want to do?\n\t";
		cout << "1. surf recent movies\n\t2. buy ticket\n\t3. exit\n";
		bool flag2 = false;
		string a;
		cin >> a;
		if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '3'))
		{
			flag2 = true;
			system("cls");
		}
		while (flag2)
		{
			cout << "Invalid entry! Please input the option again" << endl;
			cout << "\t1. surf recent movies\n\t2. buy ticket\n\t3. exit\n";
			cin >> a;
			if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '3'))
			{
				flag2 = true;
			}
			if (((a.size() == 1)) && (a[0] >= '1'&&a[0] <= '3'))
			{
				flag2 = false;
			}
			system("cls");
		}
		option = atoi(a.c_str());
		switch (option)
		{
		case 1:

			system("cls");
			//Display all recent movies
			cout << "Recent movies are as follows" << endl;
			//cout << Recent movies'names
			//cout << "Recent movies are as follows" << endl;


			char *s;

			//printf("create success\n");

			char **db_result;
			int nrow, ncolumn;
			ret = sqlite3_get_table(db, select_query2, &db_result, &nrow, &ncolumn, &s);
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
					printf("%-15s  ", db_result[i1 + j1]);
				}
				printf("\n");
			}

			system("pause");
			system("cls");
			flag = false;
			break;

		case 2:
			flag1 = true;

			while (flag1 == true)
			{


				temp.buyTicket();

				n++;
				cout << "do you want to buy another ticket?" << endl;
				cout << "1.YES\t\n2.NO\t\n";
				int i;
				cin >> i;
				if (i == 1)
				{
					flag1 = true;
				}
				else if (i == 2)
				{
					system("cls");
					flag1 = false;
				}
				if (n > 4)
				{
					cout << "You have bought five tickets and you can buy more." << endl;
					system("pause");
					flag1 = false;

				}
				system("cls");
			}
			break;

		case 3:
			flag = false;
			system("cls");
			break;
		}
	}
}
