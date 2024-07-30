#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

class Time
{
public:
    const int SINH = 3600;
    const int MINH = 60;

    Time(int h, int m, int s)
    {
        set_seconds(s);
        set_minutes(m);
        set_hours(h);
    }

    Time() : hours(0), minutes(0), seconds(0) {}

    void set_hours(int ihours)
    {
        hours = hours + ihours;
    }
    void set_minutes(int iminutes)
    {
        if ((minutes + iminutes) > MINH)
        {
            hours += (minutes + iminutes) / MINH;
            minutes = (minutes + iminutes) % MINH;
        }
        else if ((minutes + iminutes) < 0)
        {
            hours += (minutes + iminutes- MINH) / MINH;
            minutes = MINH + (minutes + iminutes) % MINH;
        }
        else
            minutes = iminutes;


    }
    void set_seconds(int iseconds)
    {
        if (iseconds > MINH)
        {
            minutes += iseconds / MINH;
            seconds = iseconds % MINH;
        }
        else if (iseconds < 0)
        {
            minutes += (iseconds- MINH) / MINH;
            seconds = MINH + iseconds % MINH;
        }
        else
            seconds = iseconds;
    }

    int get_hours() const
    {
        return hours;
    }
    int get_minutes() const
    {
        return minutes;
    }
    int get_seconds() const
    {
        return seconds;
    }

    void showTime() const
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void sum_Time(Time t1, Time t2)
    {
        set_seconds(t1.get_seconds() + t2.get_seconds());
        set_minutes(t1.get_minutes() + t2.get_minutes());
        set_hours(t1.get_hours() + t2.get_hours());
    }

    Time sumTime(const Time& t) const
    {
        Time sum;
        sum.set_seconds(seconds + t.get_seconds());
        sum.set_minutes(minutes + t.get_minutes());
        sum.set_hours(hours + t.get_hours());
        return sum;
    }

    Time operator+ (const Time& t) const
    {
        Time sum;
        sum.set_seconds(seconds + t.get_seconds());
        sum.set_minutes(minutes + t.get_minutes());
        sum.set_hours(hours + t.get_hours());
        return sum;
    }

    Time operator- (const Time& t) const
    {
        Time sum;
        sum.set_seconds(seconds - t.get_seconds());
        sum.set_minutes(minutes - t.get_minutes());
        sum.set_hours(hours - t.get_hours());
        return sum;
    }

    Time operator+(float hour) const {
        Time sum;
        int sec = (int)(hour * SINH) % MINH;
        int min = (int)(hour * MINH) % MINH;
        sum.set_seconds(seconds + sec);
        sum.set_minutes(minutes + min);
        sum.set_hours(hours + (int)hour);
        return sum;
    }

    friend Time operator+(float hour, const Time& time);

    bool operator<(const Time& t) const {
        if ((hours * SINH + minutes * MINH + seconds) < (t.get_hours() * SINH + t.get_minutes() * MINH + t.get_seconds()))
            return true;
        return false;
    }

    bool operator > (const Time& t) const {
        return t < *this;
    }

    bool operator<=(const Time& t) const {
        return !(*this > t);
    }

    bool operator>=(const Time& t) const {
        return !(*this < t);
    }

    bool operator==(const Time& t) const {
        return (hours * SINH + minutes * MINH + seconds) == (t.get_hours() * SINH + t.get_minutes() * MINH + t.get_seconds());
    }

    bool operator!=(const Time& t) const {
        return !(*this == t);
    }

private:
    int hours{};
    int minutes{};
    int seconds{};
};

Time operator+(float hour, const Time& time) {
    //Time sum;
    //int sec = (int)(hour * 3600) % 60;
    //int min = (int)(hour * 60) % 60;
    //sum.set_seconds(time.get_seconds() + sec);
    //sum.set_minutes(time.get_minutes() + min);
    //sum.set_hours(time.get_hours() + (int)hour);
    //return sum;
    return Time(time) + hour;
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Time time00;
    time00.showTime();

    const Time time01(4, 50, 50);
    time01.showTime();

    Time time02 = Time(3, 3862, 3972);//68:28:12
    time02.showTime();

    Time time03;
    time03.sum_Time(time01, time02);
    time03.showTime();

    Time time04 = time01.sumTime(time02);
    time04.showTime();

    Time time05 = time01+time02;
    time05.showTime();

    Time time06 = time02 - time01;
    time06.showTime(); //63:37:22

    Time time07 = time00 + 1.456f;
    time07.showTime(); //1:27:21

    Time time08 = 0.543f + time07;
    time08.showTime();//1:59:55

    cout << "time01 < time02: " << std::boolalpha << (time01 < time02) << endl;
    cout << "time01 > time02: " << std::boolalpha << (time01 > time02) << endl;
    cout << "time01 == time02: " << std::boolalpha << (time01 == time02) << endl;
    cout << "time04 == time05: " << std::boolalpha << (time04 == time05) << endl;

}