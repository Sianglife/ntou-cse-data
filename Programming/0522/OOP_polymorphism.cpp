#include <iostream>
using namespace std;

class Date {
    protected:        
        int month, day, weekday;

    public:       
        virtual int getFirstDayWeek() = 0;
        int getDate() {
            return this->day;
        }

        int getMonth() {
            return this->month;
        }

        int getWeekday() {
            return this->weekday;
        }

        Date(int mm, int dd) {
            if (mm < 1 || mm > 12 || dd < 1 || dd > 31) {
                throw "Invalid date";
                return;
            }
            month = mm;
            day = dd;
        }
};

class Date2026 : public Date {
    private:
        int year = 2026;
    public:
        int getFirstDayWeek() {
            return 4;
        }

        Date2026(int mm, int dd) : Date(mm, dd) {}
};

class Date2027 : public Date {
    private:
        int year = 2027;
    public:
        int getFirstDayWeek() {
            return 5;
        }

        Date2027(int mm, int dd) : Date(mm, dd) {}
};

 
string getMonthStr(int month) {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "";
    }
}

string getWeekdayStr(int weekday) {
    switch (weekday) {
        case 0: return "Sunday";
        case 1: return "Monday";
        case 2: return "Tuesday";
        case 3: return "Wednesday";
        case 4: return "Thursday";
        case 5: return "Friday";
        case 6: return "Saturday";
        default: return "";
    }
}

string calculateDays(Date &date, int year) {
    int delta = 0;
    for (int i = 1; i < date.getMonth(); i++) {
        switch (i) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                delta += 31;
                break;
            case 4: case 6: case 9: case 11:
                delta += 30;
                break;
            case 2:
                delta += 28;
                break;
        }
    }
    delta += date.getDate() - 1;
    int weekday = ((delta % 7) + date.getFirstDayWeek()) % 7;
    return getWeekdayStr(weekday);
}

void printDate(Date &date, int year) {
    if (year == 2026) {
        cout << calculateDays(date, 2026) << ", " << getMonthStr(date.getMonth()) << " " << date.getDate() << ", " << 2026;
    } else if (year == 2027) {
        cout << calculateDays(date, 2027) << ", " << getMonthStr(date.getMonth()) << " " << date.getDate() << ", " << 2027;
    }
}

int main(int argc, char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int month, day, year;
        cin >> month;
        cin >> day;
        cin >> year;
        if (year == 2026) {
            Date2026 date = Date2026(month, day);
            printDate(date, 2026);
        } else if (year == 2027) {
            Date2027 date = Date2027(month, day);
            printDate(date, 2027);
        }
        cout << endl;
    }
}