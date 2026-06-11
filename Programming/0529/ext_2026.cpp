#include<iostream>
using namespace std;

class Date2026 {
    private: 
        int d, m;
        int first_weekday = 4; // 2026-01-01 is Thursday
        int weekday;
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

        void genWeekday() {
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
            this->weekday = ((delta % 7) + this->first_weekday) % 7;
        }
    
    public: 
        Date2026() {
            d = 1;
            m = 1;
            genWeekday();
        }
        
        Date2026(int mm, int dd) {
            if (mm < 1 || mm > 12 || dd < 1 || dd > 31) {
                m = -1;
                d = -1;
                throw "a date not in 2026";
            } else if (mm == 2 && dd > 28) {
                m = -1;
                d = -1;
                throw "a date not in 2026";
            } else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) {
                m = -1;
                d = -1;
                throw "a date not in 2026";
            }
            m = mm;
            d = dd;
            genWeekday();
        }

        void print() {
            if (m == -1 || d == -1) {
                cout << "a date not in 2026" << endl;
                return;
            }
            cout << getWeekdayStr() << ", " << getMonthStr() << " " << d << ", 2026";
        }

        void plusday(int days) {
            // move date forward by days
            if (m == -1 || d == -1) {
                throw "a date not in 2026";
            }
            
            while(days > 0) {
                int days_in_month;
                switch (m) {
                    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                        days_in_month = 31;
                        break;
                    case 4: case 6: case 9: case 11:
                        days_in_month = 30;
                        break;
                    case 2:
                        days_in_month = 28;
                        break;
                }
                if (d + days <= days_in_month) {
                    d += days;
                    days = 0;
                } else {
                    days -= (days_in_month - d + 1);
                    d = 1;
                    m++;
                    if (m > 12) {
                        m = 1;
                    }
                }
            }
            genWeekday();
        }
};

int main() {
    /*Input:
3
1 1 20
1 1 31
2 1 0

Output:
20 days after Thursday, January 1, 2026 is Wednesday, January 21, 2026.
31 days after Thursday, January 1, 2026 is Sunday, February 1, 2026.
0 days after Sunday, February 1, 2026 is Sunday, February 1, 2026.*/
    
    int n;
    cin >> n;
    while(n--) {
        int m, d, days;
        cin >> m >> d >> days;
        try {
            Date2026 date(m, d);
            cout << days << " days after ";
            date.print();
            cout << " is ";
            date.plusday(days);
            date.print();
            cout << "." << endl;
        } catch (const char* msg) {
            cout << msg << endl;
            return -1;
        }
    }
    return 0;
}