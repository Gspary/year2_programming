/* 
 * File:   Album.h
 * Author: George Spary
 */

#ifndef ALBUM_H
#define ALBUM_H
#include "Track.h"
#include "Duration.h"
#include <string>
#include <vector>
using namespace std;

class Album {
public:
    //default empty constructor
    Album();
    
    //inputted album constructor
    Album(string art1, string t1);
    
    //adds a track to an album
    void addTrack(Track track1);
    
    //print function
    void print();
    
    //accessor methods
    
    //returns the title
    string getTitle();
    
    //returns artist
    string getArtist();
 
    //returns totalDuration
    Duration getTotalDuration();
    
    //returns total track Count
    int getTrackCount();
   
    
private:
    //variables
    string title;
    string artist;
    vector<Track> tracks;
    int trackCount = 0;
    Duration totalDuration = Duration();
    
};

#endif /* ALBUM_H */

