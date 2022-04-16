/**
 *File: hw07.cc
 *Author: Mila Gmerek
 *Date: 4/10/2022
 *Brief: Class that represents an appointment.
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

class Appointment
{
public:
    string title;
    string date;
    int year;
    int month;
    int day;
    int time;
    int duration;

    void setTitle(string newTitle); // setter/mutator functions
    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);
    void setTime(int newTime);
    void setDuration(int newDuration);
    void setDate(int newYear, int newMonth, int newDay);

    string getTitle(); // getter/accessor functions
    int getYear();
    int getMonth();
    int getDay();
    int getTime(); // military time
    int getDuration();
    string getDate();
    string getStandardTime();

    Appointment();               // deafault constructor
    Appointment(string appData); // puts all appointment data in one string

    string militaryToStandard(int time);
    int standardToMilitary(string time);
    friend bool operator==(const Appointment &first, const Appointment &second);
};

int main()
{
    Appointment a;
    string newTitle;
    int newYear;
    int newMonth;
    int newDay;
    int newTime;

    cout << "Enter appointment title" << endl;
    getline(cin >> ws, newTitle);
    a.setTitle(newTitle);

    cout << "Enter year of appointment (enter in format 00)" << endl;
    cin >> newYear;
    a.setYear(newYear);

    cout << "Enter month of appointment (enter in format 00)" << endl;
    cin >> newMonth;
    a.setMonth(newMonth);

    cout << "Enter day of appointment (enter in format 00)" << endl;
    cin >> newDay;
    a.setDay(newDay);

    cout << "Enter appointment time" << endl;
    cin >> newTime;
    a.setTime(newTime);

    string appData;
    Appointment();

    cout << a.title << " on " << a.getDate() << " at " << a.militaryToStandard(newTime) << endl; // this is just to test the output when user enters military time
    return 0;
}

Appointment::Appointment() // default constructor that sets all variables to their default value
{
    title = "N/A";
    date = 111;
    time = 0;
    duration = 1;
}

void Appointment::setTitle(string newTitle) // when user enters an appointment title, it will be set
{
    if (newTitle != "N/A")
    {
        title = newTitle;
    }
}

void Appointment::setYear(int newYear) // when user enters a year, it will be set
{
    if (newYear != 1)
    {
        year = newYear;
    }
}

void Appointment::setMonth(int newMonth) // when user enters a month, it will be set
{
    if (newMonth != 1)
    {
        month = newMonth;
    }
}

void Appointment::setDay(int newDay) // when user enters a day, it will be set
{
    if (newDay != 1)
    {
        day = newDay;
    }
}

void Appointment::setTime(int newTime) // when user enters a time, it will be set
{
    if (newTime != 0)
    {
        time = newTime;
    }
}

void Appointment::setDuration(int newDuration) // when user enters a duration, it will be set
{
    if (newDuration != 1)
    {
        duration = newDuration;
    }
}

void Appointment::setDate(int newYear, int newMonth, int newDay) // sets the entire date of the appointment
{
    to_string(newYear);
    to_string(newMonth);
    to_string(newDay);
    date = newYear + newMonth + newDay;
}

string Appointment::getTitle() // returns the title
{
    return title;
}

int Appointment::getYear() // returns the year
{
    return year;
}

int Appointment::getMonth() // returns the month
{
    return month;
}

int Appointment::getDay() // returns the day
{
    return day;
}

int Appointment::getTime() // returns the time
{
    return time;
}

int Appointment::getDuration() // returns the duration
{
    return duration;
}

string Appointment::getDate() // gets the date for the appointment
{
    getMonth();
    getDay();
    getYear();
    string m = to_string(month);
    string d = to_string(day);
    string y = to_string(year);
    date = m + d + y;
    date.insert(2, "/");
    date.insert(5, "/");
    return date;
}

string Appointment::militaryToStandard(int time) // converts standard time to military time
{
    string standardTime;
    if (time > 1200)
    {
        time -= 1200;
    }
    if (time < 1200)
    {
        standardTime = time;
    }
    standardTime = to_string(time);
    if (standardTime.length() == 4)
    {
        standardTime.insert(2, ":");
    }
    if (standardTime.length() == 3)
    {
        standardTime.insert(1, ":");
    }
    return standardTime;
}

int Appointment::standardToMilitary(string time) // converts standard time to military time
{
    int militaryTime;
    militaryTime = atoi(time.c_str());
    if (militaryTime < 1200)
    {
        militaryTime += 1200;
    }
    return militaryTime;
}

Appointment::Appointment(string appData) // appointment string
{
    string y = to_string(year);
    string m = to_string(month);
    string d = to_string(day);
    string t = to_string(time);
    string dur = to_string(duration);
    appData = title + y + m + d + t + dur;
    int length = title.length();
    appData.insert(length, "|");
    appData.insert(length, " ");
    int location1 = appData.find("|");
    appData.insert(location1 + 1, " ");
    appData.insert(location1 + 4, " ");
    appData.insert(location1 + 4, " |");
    appData.insert(location1 + 9, " | ");
    appData.insert(location1 + 14, " | ");
    appData.insert(location1 + 20, " | ");
}

bool operator==(const Appointment &first, const Appointment &second) // if two appointment titles are the same, function will return true
{
    string title1;
    string title2;
    if (title1 == title2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
