#include <iostream>
#include <cstdlib>
#include "Calendar.cpp"
#include "CalendarMonth.cpp"
using namespace std;

void Question1()
{
    CalendarMonth calendarMonth(2009, 1);
    // Check Question 1(a).
    cout << "Year: " << calendarMonth.getYear() << endl;
    cout << "Month: " << calendarMonth.getMonth() << endl;
    // Check Question 1(b).
    cout << "Number of Days: " << calendarMonth.getNumberOfDays() << endl;
}

void Question2()
{
    static string monthName[12] =
    {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    CalendarMonth calendarMonth(2009, 1);

    cout << "Year: " << calendarMonth.getYear() << endl;
    cout << "Month: " << calendarMonth.getMonth() << endl;
    cout << "Number of Days: " << calendarMonth.getNumberOfDays() << endl;

    // Check Question 2(a).
    int newYearDay = 1;
    calendarMonth.putEntry("New Year Day", newYearDay);

    // Check Question 2(b).
    cout << "Entry at " << monthName[calendarMonth.getMonth() - 1] << " " << newYearDay
         << " is " << calendarMonth.getEntry(newYearDay) << endl;
}

void Question3()
{
    CalendarMonth calendarMonth(2009, 1);
    calendarMonth.putEntry("New Year Day", 1);
    calendarMonth.putEntry("Chinese New Year", 26);
    calendarMonth.display(4);  // firstDayOfMonth is Thursday
}

void Question4()
{
    Calendar calendar(2009); //Calendar(int year)
    calendar.putEntry("New Year Day", 1, 1); //putEntry(string text, int month, int day)
    calendar.putEntry("Chinese New Year 1", 1, 26);
    calendar.putEntry("Chinese New Year 2", 1, 27);
    calendar.putEntry("Thaipusam", 2, 8);
    calendar.putEntry("Valentine\'s Day", 2, 14);
    calendar.putEntry("Prophet Muhammad\'s Birthday", 3, 9);
    calendar.putEntry("Good Friday", 4, 10);
    calendar.putEntry("Labour Day", 5, 1);
    calendar.putEntry("Vesak Day", 5, 9);
    calendar.putEntry("King's Birthday", 6, 6);
    calendar.putEntry("Malaysia\'s National Day", 8, 31);
    calendar.putEntry("Deepavali", 10, 17);
    calendar.putEntry("Christmas", 12, 25);
    calendar.display(4); // THURSDAY, display(int firstDayOfYear)
}

int main()
{
    system("title Calendar");

    //Question1();
    //Question2();
    //Question3();
    //Question4();

    system("pause");
    return 0;
}
