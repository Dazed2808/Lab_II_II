#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    Time operator+(int mins) {
        Time result = *this;
        result.minutes += mins;
        result.normalize();
        return result;
    }

    Time operator-(int mins) {
        Time result = *this;
        result.minutes -= mins;
        result.normalize();
        return result;
    }

    Time operator+(double secs) {
        int total_secs = hours * 3600 + minutes * 60 + seconds + secs;
        Time result(0, 0, total_secs);
        result.normalize();
        return result;
    }

    Time operator-(double secs) {
        int total_secs = hours * 3600 + minutes * 60 + seconds - secs;
        Time result(0, 0, total_secs);
        result.normalize();
        return result;
    }

    Time operator*(double hrs) {
        int total_secs = (hours * 3600 + minutes * 60 + seconds) * hrs;
        Time result(0, 0, total_secs);
        result.normalize();
        return result;
    }

    Time operator/(double hrs) {
        int total_secs = (hours * 3600 + minutes * 60 + seconds) / hrs;
        Time result(0, 0, total_secs);
        result.normalize();
        return result;
    }

    int operator-(Time other) {
        int this_mins = hours * 60 + minutes;
        int other_mins = other.hours * 60 + other.minutes;
        return this_mins - other_mins;
    }

    double operator/(Time other) {
        int this_secs = hours * 3600 + minutes * 60 + seconds;
        int other_secs = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return (this_secs - other_secs) / 3600.0;
    }

    bool operator<(Time other) {
        int this_secs = hours * 3600 + minutes * 60 + seconds;
        int other_secs = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return this_secs < other_secs;
    }

    bool operator>(Time other) {
        int this_secs = hours * 3600 + minutes * 60 + seconds;
        int other_secs = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return this_secs > other_secs;
    }

    bool operator<=(Time other) {
        int this_secs = hours * 3600 + minutes * 60 + seconds;
        int other_secs = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return this_secs <= other_secs;
    }

    bool operator>=(Time other) {
        int this_secs = hours * 3600 + minutes * 60 + seconds;
        int other_secs = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return this_secs >= other_secs;
    }

    bool operator==(Time other) {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

// conversion of the entered time into seconds
int toSeconds() {
    return hours * 3600 + minutes * 60 + seconds;
}

int toMinutes() {
    return hours * 60 + minutes;
}

void normalize() {
    int total_secs = hours * 3600 + minutes * 60 + seconds;
    int remaining_secs = total_secs % 3600;
    hours = total_secs / 3600;
    minutes = remaining_secs / 60;
    seconds = remaining_secs % 60;
}

friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

std::ostream& operator<<(std::ostream& os, const Time& t) {
    os << t.hours << " hours, " << t.minutes << " minutes, " << t.seconds << " seconds";
    return os;
}

int main() {
    Time t(2, 30, 0);
    std::cout << t << std::endl;

    Time t2 = t + 60;
    std::cout << t2 << std::endl;

    Time t3 = t - 30;
    std::cout << t3 << std::endl;

    Time t4 = t + 45.5;
    std::cout << t4 << std::endl;

    Time t5 = t - 15.2;
    std::cout << t5 << std::endl;

    Time t6 = t * 1.5;
    std::cout << t6 << std::endl;

    Time t7 = t / 2.5;
    std::cout << t7 << std::endl;

    Time t8(1, 15, 30);
    int diff_minutes = t - t8;
    std::cout << "Time difference in minutes: " << diff_minutes << std::endl;

    double diff_hours = t / t8;
    std::cout << "Time difference in hours: " << diff_hours << std::endl;

    if (t < t2) {
        std::cout << t << " is less than " << t2 << std::endl;
    }

    if (t > t3) {
        std::cout << t << " is greater than " << t3 << std::endl;
    }

    if (t == t) {
        std::cout << t << " is equal to " << t << std::endl;
    }

    int total_secs = t.toSeconds();
    std::cout << t << " in seconds: " << total_secs << std::endl;

    int total_mins = t.toMinutes();
    std::cout << t << " in minutes: " << total_mins << std::endl;

    return 0;
}
