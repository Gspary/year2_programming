

/* 
 * File:   Track.cpp
 * Author: George Spary
 * 
 */

#include "Track.h"
#include <string>
#include <iostream>
#include "duration.h"

//default track constructor
Track:: Track(){
}

//input track constructor
Track::Track(string t1, Duration dur) {
    title = t1;
    duration = dur;
        
}

//prints the track
void Track::print(){
    duration.print();
    cout <<" - " << title << "\n";
}

//accessor methods

 //returns the track title
string Track::getTrackTitle() {
    return title;
}

 //returns the track duration
Duration Track::getDuration(){
    return duration;
}
