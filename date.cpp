//Name: Kyle Scales
//Implelentation for date object

#include <iostream>
#include <string>
#include <iomanip>
#include "date.h"

using namespace std;

//Name:  Date
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to 01/01/0001
//Description:  This is the default constructor which will be called automatically when 
//an object is declared.  It will initialize the state of the class
//
//*************************************************************************************
Date::Date()
{
	myMonth = 01;
	myDay = 01;
	myYear = 0001;
	
	cout << "Default constructor has been called" << endl << *this << endl;
}

//*************************************************************************************
//Name:  Date
//Precondition: The state of the object has not been initialized
//Postcondition: The state has been initialized to mm/dd/yyyy, and a message is
//displayed if it is a leap year.
//Description:  This is the explicit value constructor that inititalizes the state
//of the class to the arguments passed.
//
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
	int leapYear = 0;

	if (y % 4 == 0 && y % 100 != 0) //checks if y is a leap year
		leapYear = 1;
	if (y > 0)
	{
		if (m == 2)
		{
			if (leapYear == 1)
			{
				if (d > 0 && d <= 29)
				{
					myMonth = m;
					myDay = d;
					myYear = y;

					cout << "Explicit value constructor has been called" << endl
						<< *this << endl << "This is a leap year" << endl << endl;
				}
				else
				{
					cout << "Explicit value constructor has been called" << endl 
						<< "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
				}
			}
			else
			{
				if (d > 0 && d <= 28)
				{
					myMonth = m;
					myDay = d;
					myYear = y;

					cout << "Explicit value constructor has been called" << endl 
						<< *this << endl << endl;
				}
				else
				{
					cout << "Explicit value constructor has been called" << endl 
						<< "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
				}
			}
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			if (d > 0 && d <= 30)
			{
				myMonth = m;
				myDay = d;
				myYear = y;

				cout << "Explicit value constructor has been called" << endl 
						<< *this << endl << endl;
				if (leapYear == 1)
					cout << "This is a leap year" << endl << endl;
			}
			else
			{
				cout << "Explicit value constructor has been called" << endl 
					<< "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
			}
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d > 0 && d <= 31)
			{
				myMonth = m;
				myDay = d;
				myYear = y;

				cout << "Explicit value constructor has been called" << endl 
						<< *this << endl << endl;
				if (leapYear == 1)
					cout << "This is a leap year" << endl << endl;
			}
			else
			{
				cout << "Explicit value constructor has been called" << endl 
					<< "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
			}
		}
		else
			cout << "Explicit value constructor has been called" << endl << 
			"Month = " << setfill('0') << setw(2) << m << " is incorrect" << endl << endl;
	}
	else
	{
		cout << "Explicit value constructor has been called" << endl;

		if (m > 12)
		{
			cout << "Month = " << setfill('0') << setw(2) << m << " is incorrect" << endl <<
				"Day = " << d << " is incorrect" << endl;
		}

		cout << "Year = " << setfill('0') << setw(4) << y << " is incorrect" << endl << endl;
	}
}

//*************************************************************************************
//Name:  Display
//Precondition: The state of the object has been initialized
//Postcondition: The date object is output to the screen
//Description:  This is an accessor that outputs the date object to the screen.
//
//*************************************************************************************
void Date::display()
{
	cout << *this << endl << endl;
}
	
//*************************************************************************************
//Name:  getMonth
//Precondition: The month field of the object has been initialized
//Postcondition: The month field of the object is output to the screen
//Description:  This is an accessor that outputs the month of the date object to 
//the screen
//
//*************************************************************************************	
int Date::getMonth()
{
	return myMonth;
}

//*************************************************************************************
//Name:  getDay
//Precondition: The day field of the object has been initialized
//Postcondition: The day field of the object is output to the screen
//Description:  This is an accessor that outputs the day of the date object to 
//the screen
//
//*************************************************************************************
int Date::getDay()
{
	return myDay;
}

//*************************************************************************************
//Name:  getYear
//Precondition: The year field of the object has been initialized
//Postcondition: The year field of the object is output to the screen
//Description:  This is an accessor that outputs the year of the date object to 
//the screen
//
//*************************************************************************************
int Date::getYear()
{
	return myYear;
}

//*************************************************************************************
//Name: setMonth
//Precondition: The object has been declared
//Postcondition: The objects month is set to m
//Description:  This is a mutator that changes the month field of the date object to
//the value passed as the argument.
//
//*************************************************************************************
void Date::setMonth(unsigned m)
{
	if (m > 0 && m <= 12)
		myMonth = m;
	else
		cout << "Month = " << setfill('0') << setw(2) << m << " is incorrect" << endl << endl;
}

//*************************************************************************************
//Name:  setDay
//Precondition: The object has been declared
//Postcondition: The objects day is set to d
//Description:  This is a mutator that changes the day field of the date object to
//the value passed as the argument.
//
//*************************************************************************************
void Date::setDay(unsigned d)
{
	if (myMonth == 2)
	{
		int leapYear = 0;
		
		if (myYear % 4 == 0 && myYear % 100 != 0) //checks if y is a leap year
			leapYear = 1;

		if (leapYear == 1)
		{
			if (d > 0 && d <= 29)
				myDay = d;
			else
				cout << "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
		}
		else
		{
			if (d > 0 && d <= 28)
				myDay = d;
			else
				cout << "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
		}
	}
	else if (myMonth == 4 || myMonth == 6 || myMonth == 9 || myMonth == 11)
	{
			if (d > 0 && d <= 30)
				myDay = d;
			else
				cout << "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
	}
	else if (myMonth == 1 || myMonth == 3 || myMonth == 5 || myMonth == 7 || 
		myMonth == 8 || myMonth == 10 || myMonth == 12)
	{
			if (d > 0 && d <= 31)
				myDay = d;
			else
				cout << "Day = " << setfill('0') << setw(2) << d << " is incorrect" << endl << endl;
	}	
}

//*************************************************************************************
//Name:  setYear
//Precondition: The object has been declared
//Postcondition: The objects year is set to y
//Description:  This is a mutator that changes the year field of the date object to
//the value passed as the argument.
//
//*************************************************************************************
void Date::setYear(unsigned y)
{
	if (y > 0)
		myYear = y;
	else
		cout << "Year = " << setfill('0') << setw(4) << y << " is incorrect" << endl << endl;
}

//*************************************************************************************
//Name:  operator<<
//Description:  This overloads the << operator to work properly with the date class.
//
//*************************************************************************************
ostream & operator<<(ostream & out, const Date & dateObj)
{
	cout << setfill('0') << setw(2) << dateObj.myMonth << "/" << dateObj.myDay << "/";
	cout << setfill('0') << setw(4) << dateObj.myYear;
	return out;

}

