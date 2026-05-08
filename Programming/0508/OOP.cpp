#include <iostream>
using namespace std;

class Date2026 {
    private:
        int y = 2026;
        int m;
        int d;
        int weekday, delta;
        string getMonthStr() {
            switch (this->m) {
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
            this->weekday = ((this->delta % 7) + 4) % 7;
        }

        void getDeltaDay() {
            int delta = 0;
            for (int i = 1; i < this->m; i++) {
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
            delta += this->d - 1;
            this->delta = delta;
        }
    public:
        Date2026() {
            m = 1;
            d = 1;
            getDeltaDay();
            getWeekday();
        }
        Date2026(int mm, int dd) {
            if (mm < 1 || mm > 12 || dd < 1 || dd > 31) {
                throw "Invalid date";
                return;
            }
            m = mm;
            d = dd;
            getDeltaDay();
            getWeekday();
        }
        void print() {
            cout << getWeekdayStr() << ", " << getMonthStr() << " " << d << ", 2026";
        }
};

int main(int argc, char * argv[]) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int month, day;
        cin >> month;
        cin >> day;
        Date2026 date = Date2026(month, day);
        date.print();
        cout << endl;
    }
}