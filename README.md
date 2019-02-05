# Timetable generator
Brute-force course planner

## Compiling
Use CMake to generate a Makefile to compile or use an alternative project file system.
```
> mkdir build
> cd build
> cmake ..
> make
```

## Running
Manual input:
```
> ./timetable-generator

number_of_courses

course_name number_of_date_times
day start end
...
day start end

course_name number_of_date_times
day start end
...
day start end

...
```
Using input/output streams to directly read/write from/to files:
```
> ./timetable-generator < input.txt > output.txt
```

## Sample input
```
6
ANA2-cwi 4
0 8 9
0 9 10
2 10 11
2 11 12
ANA2-wyk 1
1 8 10
BD-lab 5
2 10 12
2 14 16
4 8 10
4 10 12
4 12 14
BD-wyk 1
3 16 18
FO-cwi 6
3 12 14
3 16 18
3 18 20
4 8 10
4 10 12
4 12 14
FO-wyk 1
2 12 14
```

## Sample output
```
0 0 0 0 0 0
7	______	______	______	______	______
8	ANA2-c	ANA2-w	______	______	______
9	______	ANA2-w	______	______	______
10	______	______	BD-lab	______	______
11	______	______	BD-lab	______	______
12	______	______	FO-wyk	FO-cwi	______
13	______	______	FO-wyk	FO-cwi	______
14	______	______	______	______	______
15	______	______	______	______	______
16	______	______	______	BD-wyk	______
17	______	______	______	BD-wyk	______
18	______	______	______	______	______
19	______	______	______	______	______
20	______	______	______	______	______

0 0 0 0 2 0
7	______	______	______	______	______
8	ANA2-c	ANA2-w	______	______	______
9	______	ANA2-w	______	______	______
10	______	______	BD-lab	______	______
11	______	______	BD-lab	______	______
12	______	______	FO-wyk	______	______
13	______	______	FO-wyk	______	______
14	______	______	______	______	______
15	______	______	______	______	______
16	______	______	______	BD-wyk	______
17	______	______	______	BD-wyk	______
18	______	______	______	FO-cwi	______
19	______	______	______	FO-cwi	______
20	______	______	______	______	______

...
```
