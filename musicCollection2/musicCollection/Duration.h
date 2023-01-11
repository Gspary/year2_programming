

/* 
 * File:   Duration.h
 * Author: George Spary
 */

#ifndef DURATION_H
#define DURATION_H
#include <string>

using namespace std;

class Duration {
public:
    //default constructor
    Duration();
    
    //integer duration input
    Duration(int h1, int m1, int s1);
    
    //string duration input
    Duration(string str);
    
    //print function
    void print();
    
    //adds 2 durations together, validating results
    void addDuration(Duration d1, Duration d2);
    
    //adds a single duration to the main duration
    void addDuration(Duration d1);
    
    //compares 2 durations together, returning a result
    int compareDuration(Duration d1, Duration d2);
    
    //accessor methods
    int getHour();
    int getMinute();
    int getSecond();
private:
//variables
int hours;
int minutes;
int seconds;
};

#endif /* DURATION_H */

