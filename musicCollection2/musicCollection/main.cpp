
/* 
 * File:   main.cpp
 * Author: George Spary
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cctype>
#include "Duration.h"
#include "Track.h"
#include "Album.h"
#include "Collection.h"

using namespace std;

int main(int argc, char** argv) {
    
    //declarations of variables
    Collection colec = Collection();
    Album al;
    Track track;
    Duration duration;
    string pfArtist = "Pink Floyd";
    Duration PFDuration = Duration();
    int token = 0;
    string albDelim = ":";
    string trackDelim = " -";
    string line_, dur, artist, title, trkName ;
    ifstream file_("albums.txt");
    
    //if the file is found, open and begin reading
    if(file_.is_open())
    {
        while(getline(file_,line_))
        {
            //splits the line depending on 1st char and token value
            //splitting either if album name or beginning duration
            
           if(isdigit(line_[0]) == 0 && token == 0){
               
               artist = line_.substr(0, line_.find(albDelim));
               line_.erase(0, line_.find(albDelim) + albDelim.length());
               title = line_;
               al = Album(artist, title);
               token++ ;    
              
              //adds the album to the collection, creating new empty 
              //album for next set of tracks 
           }else if(isdigit(line_[0]) == 0 && token != 0){
               colec.addAlbum(al);
               artist = line_.substr(0, line_.find(albDelim));
               line_.erase(0, line_.find(albDelim) + albDelim.length());
               title = line_;
               al = Album(artist, title);
              
               
               
               //adds the track to the currently being read-in album
           }else if(isdigit(line_[0]) != 0){
               dur = line_.substr(0, line_.find(trackDelim));
               duration = Duration(dur);
               line_.erase(0, line_.find(trackDelim) + trackDelim.length());
               trkName = line_;
               track = Track(trkName, duration);
               al.addTrack(track);
               
            
           }else{
               //if failure to do so, error is printed
               cout << "error";
           }
               
               
                  
        }
        file_.close();
                       
    }
    //if file doesn't exist, then prints failure clause
    else{
      cout<<"Error: File is not open"<<'\n';
    cin.get();    
    
    }
    
    
    colec.addAlbum(al);
    if(al.getArtist() == pfArtist){
        PFDuration.addDuration(al.getTotalDuration());
    }
    colec.print();
    
    cout << "Pink Floyd Duration: ";
    PFDuration.print();
  
    
    /* Album Testing
    duration d1;
    d1.new_duration(03,02,01);
    
    duration d2;
    d2.new_duration(04,55,12);
    
    
    track t1;
    t1.new_track("Test Track", d1);
    
    track t2;
    t2.new_track("Test Track #2", d2);
    track t3;
    t3.new_track("Test Track #3",d2);
    
    album a1;
    a1.new_album("Test Title", "George");
    a1.print(a1);
    a1.addtrack_album(t1);
    a1.addtrack_album(t2);
    a1.full_print(a1);
    a1.addtrack_album(t3);
    a1.full_print(a1);
    */
    
    
    /* Duration Testing:
    duration d1;
    d1.new_duration(0,0,0);
    duration d2;
    d2.new_duration(9,60,60);
    d1.print();
    std::cout << d1.getHour() << std:: endl;
    d2.print();
    duration d3;
    d3.add_duration(d1, d2);
    d3.print();
    int result;
    result = d1.compare_duration(d1, d3);
    std::cout << result << std:: endl;
    */
    
    
    /* Track Testing
    track t1;
    t1.print();
    string resultString;
    resultString = t1.getTitle();
    duration resultDuration = t1.getDuration();
    std::cout << resultString << std:: endl;
    resultDuration.print();
    */
  
    return 0;
}

