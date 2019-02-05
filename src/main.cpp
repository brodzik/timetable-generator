#include <iostream>

#include "generator.hpp"

void input_data(std::vector<Course> &courses)
{
    int n;
    std::cin >> n;

    while (n--)
    {
        std::string name;
        int k;
        std::cin >> name >> k;

        std::vector<CourseDateTime> times;

        while (k--)
        {
            int day, start, end;
            std::cin >> day >> start >> end;

            times.push_back(CourseDateTime {day, start, end});
        }

        courses.push_back(Course {name, times});
    }
}

int main()
{
    std::vector<Course> courses;
    input_data(courses);

    Generator gen;
    gen.create_timetables(courses);

    return 0;
}
