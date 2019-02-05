#pragma once

#include <string>
#include <vector>

class CourseDateTime
{
public:
    int day, start, end;
};

class Course
{
public:
    std::string name;
    std::vector<CourseDateTime> times;
};

