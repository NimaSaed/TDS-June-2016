
#include "CalendarMonth.cpp"
#include <string>
using namespace std;

class Calendar
{
    public:
        Calendar(int year);
        ~Calendar();

        void display(int firstDayOfYear);
        void putEntry(string text, int month, int day);

        int getYear();
        string getEntry(int month, int day);

    private:
        int year;
        CalendarMonth* calendarMonths[12];
};

Calendar::Calendar(int year):year(year)
{
    // TODO: Write your code here
    // Begin Question
    for (int i = 0; i < 12; ++i)
        calendarMonths[i] = new CalendarMonth(year, i + 1);
	// End Question
}

Calendar::~Calendar()
{
    // TODO: Write your code here
    // Begin Question
    for (int i = 0; i < 12; ++i)
    {
        delete calendarMonths[i]; // delete the memory content
        calendarMonths[i] = NULL; //pointers point to nothing
    }
	// End Question
}

void Calendar::display(int firstDayOfYear)
{
    // TODO: Write your code here
    // Begin Question
    // (i) Display all the months
    if(firstDayOfYear>=1 && firstDayOfYear<=7){
        int firstDayOfMonth = firstDayOfYear;

        for (int i = 0; i < 12; ++i)
        {
            // display the month
            calendarMonths[i]->display(firstDayOfMonth);

            // calculate the first day for next month
            // eg. 4 + 31 = 35, 35%7 = 0 tab, Thu = 4 = four tabs
            firstDayOfMonth = (firstDayOfMonth + calendarMonths[i]->getNumberOfDays()) % 7;
        }
    }
	// End Question
}

void Calendar::putEntry(string text, int month, int day)
{
    // TODO: Write your code here
    // Begin Question
    if (month < 1 || month > 12)
        return;
    else if (day < 1 || day>calendarMonths[month-1]->getNumberOfDays())
        return;
    else
        calendarMonths[month - 1]->putEntry(text, day);
	// End Question
}

string Calendar::getEntry(int month, int day)
{
    // TODO: Write your code here
    // Begin Question
    if (month < 1 || month > 12)
        return "";
    else if (day < 1 || day>calendarMonths[month-1]->getNumberOfDays())
        return "";
    else
        return calendarMonths[month - 1]->getEntry(day);
	// End Question
}

int Calendar::getYear()
{
    // TODO: Write your code here
    // Begin Question
    return year;
	// End Question
}

