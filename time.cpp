#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second) {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    Time(int duration) {
        hour = duration / 3600;
        minute = (duration % 3600) / 60;
        second = duration % 60;

        if (hour > 24) {hour = hour - 24;}
    }

    void setHour(int h) { hour = h; }
    void setMinute(int m) { minute = m; }
    void setSecond(int s) { second = s;}

    int getHour() { return hour;}
    int getMinute() { return minute;}
    int getSecond() { return second;}

    int getDuration() {
        return hour * 3600 + minute * 60 + second;
    }

    Time add(Time other) {
        int total = getDuration() + other.getDuration();
        return Time(total);
    }

    int subtract(Time other) {
        int diff = getDuration() - other.getDuration();
        return (diff < 0) ? 86400 + diff : diff;
        
    }

    int equals(Time other) {
        return (hour == other.getHour() && minute == other.getMinute() && second == other.getSecond()) ? 1 : 0;
    }

    string toString() {
        return to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
    }
};

int main() {
    Time time1(2, 2, 2);
    Time time2(1, 1, 1);

    cout << "To string : " << time1.toString();
}