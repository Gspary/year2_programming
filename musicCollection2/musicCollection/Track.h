
/* 
 * File:   Track.h
 * Author: George Spary
 *
 */

#ifndef TRACK_H
#define TRACK_H
#include "Duration.h"
#include <string>
#include <iostream>

using namespace std;

class Track {
public:
    //default track constructor
    Track();
    
    //input track constructor
    Track(string t1, Duration dur);
    
    //returns the track title
    string getTrackTitle();
    
    //returns the track duration
    Duration getDuration();
    
    //prints the track
    void print();
private:
    //variables
    string title;
    Duration duration;
};

#endif /* TRACK_H */

