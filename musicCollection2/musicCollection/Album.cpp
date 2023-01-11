/* 
 * File:   Album.cpp
 * Author: George Spary
 */

#include "Album.h"
#include "Track.h"
#include "Duration.h"
#include <string>
#include <vector>
using namespace std;

//default empty album constructor
Album:: Album(){
    
}

//inputted album constructor
Album:: Album(string art1, string t1){
    title = t1;
    artist = art1;
   
}


//adds a track to an album
void Album:: addTrack(Track track1){
    Track t1 = track1;
    tracks.push_back(t1);
    trackCount++;
    totalDuration.addDuration(t1.getDuration());
    }
    
    
    
//print method for albums
void Album:: print(){
    cout << artist << " - "<< title << "\n";
    
    for (auto ths = tracks.begin(); ths != tracks.end(); ths++){
        
        Track t3 = *ths;
        t3.print();
    }
    
    
    }

//accessor methods

//Returns album title
string Album:: getTitle(){
       return title;
    }

//returns the album artist
string Album:: getArtist(){
    return artist;
    }

//returns the total duration for an album
Duration Album:: getTotalDuration(){
    return totalDuration;
    }

//returns total tracks in an album
int Album:: getTrackCount(){
    return trackCount;
    }

