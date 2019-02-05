#pragma once

#include "course.hpp"

class Generator
{
public:
    void create_timetables(const std::vector<Course> &courses)
    {
        if (courses.size() == buffer.size())
        {
            if (evaluate(courses, buffer) == 1000)
            {
                for (auto a : buffer)
                {
                    std::cout << a << " ";
                }

                std::cout << std::endl;
                print_timetable(courses, buffer);
                std::cout << std::endl;
            }
        }
        else
        {
            for (int i = 0; i < courses[buffer.size()].times.size(); ++i)
            {
                buffer.push_back(i);
                create_timetables(courses);
                buffer.pop_back();
            }
        }
    }

    static int evaluate(const std::vector<Course> &courses, const std::vector<int> &time_ids)
    {
        if (courses.size() != time_ids.size())
        {
            throw;
        }

        bool busy[7][24];

        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < 24; ++j)
            {
                busy[i][j] = false;
            }
        }

        int score = 1000;

        for (int i = 0; i < courses.size(); ++i)
        {
            for (int t = courses[i].times[time_ids[i]].start; t < courses[i].times[time_ids[i]].end; ++t)
            {
                if (busy[courses[i].times[time_ids[i]].day][t])
                {
                    --score;
                }
                else
                {
                    busy[courses[i].times[time_ids[i]].day][t] = true;
                }
            }
        }

        return score;
    }

    static void print_timetable(const std::vector<Course> &courses, std::vector<int> &time_ids)
    {
        if (courses.size() != time_ids.size())
        {
            throw;
        }

        std::string busy[7][24];

        for (int i = 0; i < 7; ++i)
        {
            for (int j = 0; j < 24; ++j)
            {
                busy[i][j] = "______";
            }
        }

        for (int i = 0; i < courses.size(); ++i)
        {
            for (int t = courses[i].times[time_ids[i]].start; t < courses[i].times[time_ids[i]].end; ++t)
            {
                busy[courses[i].times[time_ids[i]].day][t] = courses[i].name;
            }
        }

        for (int i = 7; i <= 20; ++i)
        {
            std::cout << i << "\t";
            for (int j = 0; j <= 4; ++j)
            {
                std::cout << busy[j][i].substr(0, 6) << "\t";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<int> buffer;
};

