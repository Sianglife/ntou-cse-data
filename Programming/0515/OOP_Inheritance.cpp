#include <iostream>
using namespace std;

class Date {
    protected:
        int year;
        int first_weekday;
        
        int month;
        int day;
        int weekday, day_delta;
        string getMonthStr() {
            switch (this->month) {
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

        string getWeekdayStr() {
            switch (this->weekday) {
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

        void getWeekday() {
            this->weekday = ((this->day_delta % 7) + this->first_weekday) % 7;
        }

        void getDeltaDay() {
            int delta = 0;
            for (int i = 1; i < this->month; i++) {
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
            delta += this->day - 1;
            this->day_delta = delta;
        }
    public:
        Date(int mm, int dd) {
            if (mm < 1 || mm > 12 || dd < 1 || dd > 31) {
                throw "Invalid date";
                return;
            }
            month = mm;
            day = dd;
        }
        void print() {
            // cout << weekday << endl;
            cout << getWeekdayStr() << ", " << getMonthStr() << " " << day << ", " << year;
        }
};

class Date2026 : public Date {
    public:
        Date2026(int mm, int dd) : Date(mm, dd) {
            this->year = 2026;
            this->first_weekday = 4;
            this->getDeltaDay();
            this->getWeekday();
        }
};

class Date2027 : public Date {
    public:
        Date2027(int mm, int dd) : Date(mm, dd) {
            this->year = 2027;
            this->first_weekday = 5;
            this->getDeltaDay();
            this->getWeekday();
        }
};

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
            date.print();
        } else if (year == 2027) {
            Date2027 date = Date2027(month, day);
            date.print();
        }
        cout << endl;
    }
}