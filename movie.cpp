#include"movie.h"

movie::movie()
{
	//cout << "construction called";
	string nameOfmovie = "0";
	int ID = 0;
	int priceParameter = 0;

	int publicTimeMonth = 0;
	int publicTimeDay = 0;
	int publicTimeHour = 0;
	int publicTimeMinute = 0;

	int positionOfmovie = 0;
	int lastingOfmovie = 0;
}

movie::~movie()
{

}

void movie::setNameOfmovie()
{
	cout << "Please enter movie name:" << endl;
	char s[40];
	cin >> s;
	this->nameOfmovie = s;
	cout << "the movie name your enter is:" << nameOfmovie << endl;
}

string movie::getNameOfmovie()
{
	return nameOfmovie;
}

void movie::inputID()
{
	cout << "Please intput the ID of movie" << endl;
	string a;
	bool flag = false;
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
		cout << "Invalid entry! Please input the movie ID again" << endl;
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
	ID = atoi(a.c_str());
}

void movie::getID()
{
	cout << ID << endl;
}

int movie::returnID()
{
	return ID;
}

int movie::getHour()
{
	return startTimeHour;
}

void movie::inputPriceParameter()
{
	string a;
	cout << "please enter the price factor:" << endl;
	bool flag = false;
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
		cout << "Invalid entry! Please input the price factor again" << endl;
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
	priceParameter = atoi(a.c_str());
}

void movie::locationOfmovie()
{
	cout << "please enter the location of movie:" << endl;
	string a;
	bool flag = false;
	cin >> a;
	if ((a.size() != 1)|| !(a[0] >= '1'&&a[0] <= '8'))
	{
		flag = true;
	}
	while (flag)
	{
		cout << "Invalid entry! Please input the location of movie again" << endl;
		cin >> a;
		if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '8'))
		{
			flag = true;
		}
		if (((a.size() == 1)) && (a[0] >= '1'&&a[0] <= '8'))
		{
			flag = false;
		}
		system("cls");
	}
	positionOfmovie = atoi(a.c_str());
}

void movie::startTime()
{
	cout << "please enter the start time of movie:" << endl;
	cout << "Hour:";
	string a;
	int flag = false;
	cin >> a;
	if (!((a.size() == 1) || (a.size() == 2)))
	{
		flag = true;
	}
	if (a.size() == 1)
	{
		if (!(a[0] >= '1'&&a[0] <= '9'))
		{
			flag = true;
		}
	}
	if (a.size() == 2)
	{
		if (a[0] == '1')
		{
			if (!(a[1] >= '0'&&a[1] <= '9'))
			{
				flag = true;
			}
		}
		if (a[0] == '2')
		{
			if (!(a[1] >= '0'&&a[1] <= '4'))
			{
				flag = true;
			}
		}
	}
	while (flag)
	{
		cout << "Invalid entry! Please input the staring time of movie again" << endl;
		cin >> a;
		if ((a.size() == 1) || (a.size() == 2))
		{
			if (a.size() == 1)
			{
				if (a[0] >= '1'&&a[0] <= '9')
				{
					flag = false;
				}
			}
			if (a.size() == 2)
			{
				if (a[0] == '1')
				{
					if (a[1] >= '0'&&a[1] <= '9')
					{
						flag = false;
					}
				}
				if (a[0] == '2')
				{
					if (a[1] >= '0'&&a[1] <= '3')
					{
						flag = false;
					}
				}
			}
		}
		else
		{
			flag = true;
		}
		system("cls");
	}
	startTimeHour = atoi(a.c_str());
}

void movie::showTime()
{
	cout << startTimeHour << endl;
}

void movie::getLocation()
{
	if (positionOfmovie == 1)
		cout << "smallroom 1" << endl;
	if (positionOfmovie == 2)
		cout << "smallroom 2" << endl;
	if (positionOfmovie == 3)
		cout << "smallroom 3" << endl;
	if (positionOfmovie == 4)
		cout << "smallroom 4" << endl;
	if (positionOfmovie == 5)
		cout << "smallroom 5" << endl;
	if (positionOfmovie == 6)
		cout << "bigroom 1" << endl;
	if (positionOfmovie == 7)
		cout << "bigroom 2" << endl;
	if (positionOfmovie == 8)
		cout << "bigroom 3" << endl;
}

string movie::returnRoom()
{
	string s;
	if (positionOfmovie == 1)
	{
		s = "smallroom 1";
		return s;
	}
	if (positionOfmovie == 2)
	{
		s = "smallroom 2";
		return s;
	}
	if (positionOfmovie == 3)
	{
		s = "smallroom 3";
		return s;
	}
	if (positionOfmovie == 4)
	{
		s = "smallroom 4";
		return s;
	}
	if (positionOfmovie == 5)
	{
		s = "smallroom 5";
		return s;
	}
	if (positionOfmovie == 6)
	{
		s = "bigroom 1";
		return s;
	}
	if (positionOfmovie == 7)
	{
		s = "bigroom 2";
		return s;
	}
	if (positionOfmovie == 8)
	{
		s = "bigroom 3";
		return s;
	}
}

string movie::seatStatus()
{
	string s;
	if (positionOfmovie == 1)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
	if (positionOfmovie == 2)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
	if (positionOfmovie == 3)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
	if (positionOfmovie == 4)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
	if (positionOfmovie == 5)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
	if (positionOfmovie == 6)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
	if (positionOfmovie == 7)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
	if (positionOfmovie == 8)
	{
		s = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		return s;
	}
}

float movie::generatePrice()
{
	float R, T, price;
	if (positionOfmovie == 1 || positionOfmovie == 2 || positionOfmovie == 3 || positionOfmovie == 4 || positionOfmovie == 5)
	{
		R = 1.2;
	}
	else
	{
		R = 1;
	}
	if (startTimeHour >= 12 && startTimeHour <= 24)
	{
		T = 1.2;
	}
	else
	{
		T = 1;
	}
	price = R * T*priceParameter;
	return price;
}

int movie::getLocation2()
{
	return positionOfmovie;
}

void movie::setTimeOfmovie()
{
	string a;
	bool flag = false;
	cout << "plesae enter the lasting time of movie:" << endl;
	cin >> a;
	if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '9'))
	{
		flag = true;
	}
	while (flag)
	{
		cout << "Invalid entry! Please input the lasting time of movie again" << endl;
		cin >> a;
		if ((a.size() != 1) || !(a[0] >= '1'&&a[0] <= '9'))
		{
			flag = true;
		}
		if (((a.size() == 1)) && (a[0] >= '1'&&a[0] <= '9'))
		{
			flag = false;
		}
		system("cls");
	}
	lastingOfmovie = atoi(a.c_str());
}

int movie::getTimeOfmovie()
{
	return lastingOfmovie;
}
