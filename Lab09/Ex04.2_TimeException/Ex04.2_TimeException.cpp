
#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

class Time
{
public:

    class ExTime
    {
    public:
        ExTime() : message("Указано недопустимое время") { }
        void printMessage() const { cout << message << endl; }
    private:
        string message;
    };

    Time(int h, int m, int s)
    {
        if (s < 0 || m < 0 || h < 0)
            throw ExTime();
        set_seconds(s);
        set_minutes(m);
        set_hours(h);
    }

    Time() : hours(0), minutes(0), seconds(0) {}

    void set_hours(int ihours)
    {
        if (ihours < 0)
            throw ExTime();
        hours = hours + ihours;
    }
    void set_minutes(int iminutes)
    {
        if (iminutes < 0)
            throw ExTime();
        if ((minutes + iminutes) > 60)
        {
            hours += (minutes + iminutes) / 60;
            minutes = (minutes + iminutes) % 60;
        }
        else
            minutes = iminutes;
    }
    void set_seconds(int iseconds)
    {
        if (iseconds < 0)
            throw ExTime();
        if (iseconds > 60)
        {
            minutes += iseconds / 60;
            seconds = iseconds % 60;
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
        cout.precision(2);
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    //void sumTime(Time& time)
    //{
    //    set_seconds(seconds+time.get_seconds());
    //    set_minutes(time.get_minutes());
    //    set_hours(time.get_hours());
    //}

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

private:
    int hours{};
    int minutes{};
    int seconds{};
};



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

    try
    {
        Time time001(-5,0,0);
        time001.showTime();
    }
    catch (Time::ExTime& error)
    {
        cout << "ОШИБКА: ";
        error.printMessage();
        return 1; // завершение программы при ошибке
    }
}