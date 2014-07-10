
#include <iostream>
#include "ctime"

using namespace std;

// setting up some public variables
int year, month, day;


// some methods :)

// calculating years old
int findYearsOld(int yearBorn, int monthBorn) {
    
    int yearsOld;
    
    
    if (month < monthBorn)
        yearsOld = year - yearBorn - 1;
    else
        yearsOld = year - yearBorn;
    
    
    return yearsOld;
    
}



// calculating months old
int findMonthsOld (int monthBorn, int dayBorn) {
    
    int monthsOld;
    
    // months
    if (day >= dayBorn)
        monthsOld = abs(monthBorn - month);
    else
        monthsOld = abs(monthBorn - month) - 1;
    
    
    return monthsOld;
    
}




// calculating days old
int findDaysOld (int dayBorn) {
    
    int daysOld;
    
    // days
    daysOld = abs(day - dayBorn);

    return daysOld;
    
}

// this time I will try to declare the method here, and fill it with code after main
int daysOfMonth(int year, int month);







// main method goes right here baby
int main(int argc, const char * argv[])
{
    

    // just some variables
    int birthYear;
    int birthMonth;
    int birthDay;
    int monthDays;
    int monthsLeft, daysLeft;
    
    
    // here starts the fun
    // first lets get current timing and getting days in month
    time_t now = time(0);
    
    tm time = *localtime(&now);
    
    year = time.tm_year + 1900;
    month = time.tm_mon + 1;
    day = time.tm_mday;
    monthDays = daysOfMonth(year, month);
    
    
    // the fun is here
    cout << "okay lets check whats inside now: " << now << "\n";

    cout << " which year you wear born?\n";
    
    cin >> birthYear;
    
    cout << "Which month?\n";
    
    cin >> birthMonth;
    
    cout << "Which day?\n";
    
    cin  >> birthDay;
    

     cout << "You Are: " << findYearsOld(birthYear, birthMonth) << " years old. \n";
     cout << "And " <<  findMonthsOld(birthMonth, birthMonth) << " months old, and " << findDaysOld(birthDay) << " days old. \n";
    
    // calculating how much months or days left for your birthday:
    
    if (month < birthMonth)
        monthsLeft = abs(month - birthMonth) - 1;
    else
        monthsLeft = (12 - month) + birthMonth - 1;
        
    
    if ( day > birthDay)
        daysLeft = (monthDays - day) + birthDay;
    else
        daysLeft = birthDay - day;
    
    cout << "you are " << daysLeft << " days " << monthsLeft << " months away from " << findYearsOld(birthYear, birthMonth) + 1 << ".\n";
    cout << "And by the way there are " <<  monthDays << " days in this month :).\n";

    return 0;
}




// filling the daysOfMonth method with code:
int daysOfMonth(int year, int month) {
    
    int days;
    
    
    // calculating: if 30 days:
    if (month == 4 || month == 6 || month == 9 || month == 11)
        days = 30;
    
    
    
    else if (month == 2) {
        
        // calculating if month = 2: checking if leap year, if so month 2 has 29 otherwise it has 28
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        
        if (isLeapYear)
            days = 28;
        else
            days = 29;
    } else
        // if none of the previous, days = 31:
        days = 31;
    
    
    // that was a piece of cake huh?
    // now lets return the result
    return days;
    
}





















// i just want to add some space for my coding
