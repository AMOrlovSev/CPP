#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class Time
{
public:
    Time(int hours, int minutes, int seconds)
    {
        set_seconds(seconds);
        set_minutes(minutes);
        set_hours(hours);
    }
    Time()
    {
    }

    void set_hours(int ihours)
    {
        hours = hours+ihours;
    }
    void set_minutes(int iminutes)
    {
        if ((minutes + iminutes) > 60)
        {
            hours += (minutes + iminutes) / 60;
            minutes = (minutes +iminutes) % 60;
        }
        else
            minutes = iminutes;
    }
    void set_seconds(int iseconds)
    {
        if (iseconds > 60)
        {
            minutes += iseconds / 60;
            seconds = iseconds % 60;
        }
        else
            seconds = iseconds;
    }

    int get_hours()
    {
        return hours;
    }
    int get_minutes()
    {
        return minutes;
    }
    int get_seconds()
    {
        return seconds;
    }

    void const ShowTime()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    void sumTime(Time& time)
    {
        set_seconds(seconds+time.get_seconds());
        set_minutes(time.get_minutes());
        set_hours(time.get_hours());
    }

private:
    int hours{};
    int minutes{};
    int seconds{};
};



int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Time time00 = Time();
    time00.ShowTime();

    Time time01 = Time(4,50,50);
    time01.ShowTime();

    Time time02 = Time(3, 3862, 3972);//68:28:12
    time02.ShowTime();

    time02.sumTime(time01);
    time02.ShowTime();

    Time time03;
    time03.set_seconds(time02.get_seconds());
    time03.set_minutes(time02.get_minutes());
    time03.set_hours(time02.get_hours());
    time03.ShowTime();
}