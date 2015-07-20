#include <iostream>

using namespace std;

#define check_leap(year) ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
#define debug(n) cout << n << endl

int get_days(int month, bool leap){
    if (month == 2){
        if (leap) return 29;
        return 28;
    } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return 31;
    } else {
        return 30;
    }
}


int days[] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

#define days_prior_to_month(n) days[n-2]
int num_days_between(int month1, int day1, int month2, int day2, bool leap){
    if (month2 > month1)
        return ((days_prior_to_month(month2) - days_prior_to_month(month1+1)) + get_days(month1, leap) - day1 + 1 + day2) + ((leap &&  month1 <= 2 && 2 <= month2) ? 1 : 0);
    else if (month2 == month1)
        return day2;
    return -1;
}

int main(int argc, char * argv[]){
    int year, month, day, year2, month2, day2;
    cout << "Year: "; cin >> year;
    cout << "Month: "; cin >> month;
    cout << "Day: "; cin >> day;
    cout << "Year 2: "; cin >> year2;
    cout << "Month 2: "; cin >> month2;
    cout << "Day 2: "; cin >> day2;

    int total = 0;
    if (year2 != year){
        int leapyears = 0;
        total += num_days_between(month, day, 12, 31, check_leap(year));
        debug(total);
        total += num_days_between(1, 1, month2, day2, check_leap(year2));
        debug(total);
        int originalyear = year;
        year++;
        year = year + year % 4;
        while (year <= year2-1){
            leapyears += check_leap(year) ? 1 : 0;
            year += 4;
        }

        total += leapyears * 366;
        debug(total);
        total += max(year2 - originalyear - leapyears - 1, 0) * 365;
        debug(total);

    } else {
        total = num_days_between(month, day, month2, day2, check_leap(year));
    }
        cout << "Total Number of Days In Between: " << total << endl;
    system("PAUSE");
    return 0;
}
