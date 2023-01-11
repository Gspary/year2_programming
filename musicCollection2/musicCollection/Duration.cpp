

/* 
 * File:   Duration.cpp
 * Author: George Spary
 * 
 */

#include "Duration.h"
#include <iostream>
#include <string>
using namespace std;

//default empty constructor
Duration::Duration() {
    hours = 0;
    minutes = 0;
    seconds = 0;
    

}

// integer duration constructor
Duration::Duration(int h1, int m1, int s1) {
    if(h1 < 0 || m1 < 0 || s1 < 0 ){
        cout << "Invalid Duration, Hours must be positive";
       
    }else{
    
    hours = h1;
    minutes = m1;
    seconds = s1;
    }
}
// string duration constructor
Duration::Duration(string str) {
    string strDelim = ":";  
    int h1 = stoi (str.substr(0, str.find(strDelim)));
    str.erase(0, str.find(strDelim) + strDelim.length());
    
    int m1 = stoi (str.substr(0, str.find(strDelim)));
    str.erase(0, str.find(strDelim) + strDelim.length());
    int s1 = stoi(str);  
    if(h1 < 0 || m1 < 0 || s1 < 0 ){
        cout << "Invalid Duration, must have positive values";
       
    }else{
    
    hours = h1;
    minutes = m1;
    seconds = s1;
    
        
    }
    
}
//adds 2 durations together, validating the results
void Duration:: addDuration(Duration d1, Duration d2){
    //variable set-up
    int extmins = 0;
    int exthours = 0;
    int h1,m1,s1;
    h1 = d1.getHour() + d2.getHour();
    m1 = d1.getMinute() + d2.getMinute();
    s1 = d1.getSecond() + d2.getSecond();
    
    
   while(s1 >= 60){
       extmins++;
       s1 = s1 - 60; 
             
   }    
    seconds = s1;
    m1 = m1 + extmins;
    
    while(m1 >= 60){
       exthours++;
       m1 = m1 - 60; 
    }
    
    minutes = m1;
    hours = h1 + exthours;
}

//adds a single duration to the main duration, validating results
void Duration:: addDuration(Duration d1){
    //variable set-up
    int extmins = 0;
    int exthours = 0;
    int h2,m2,s2;
    h2 = hours + d1.getHour();
    m2 = minutes + d1.getMinute();
    s2 = seconds + d1.getSecond();
    
    
    //validation
   while(s2 >= 60){
       extmins++;
       s2 = s2 - 60; 
             
   }    
    seconds = s2;
    m2 = m2 + extmins;
    
    while(m2 >= 60){
       exthours++;
       m2 = m2 - 60; 
    }
    
    minutes = m2;
    hours = h2 + exthours;
    
    
    
}



//compares 2 durations together, returning integer result
int Duration:: compareDuration( Duration dur1, Duration dur2){
    
    int tim1 = 0;
    int tim2 = 0;
    
    tim1 = (dur1.getHour()*3600) + (dur1.getMinute() * 60) + (dur1.getSecond());
    tim2 = (dur2.getHour()*3600) + (dur2.getMinute() * 60) + (dur2.getSecond());
    
    
    //returns compared result
    if(tim1 > tim2){
        return 1;
    }
    else if(tim1 = tim2){
        return 0;
    }
    else if(tim2 > tim1){
        return -1;
    }
}


//the print function, to 2sf for each segment
void Duration::print(){
    printf("%02i:%02i:%02i", hours, minutes, seconds );
    
}

//accessor methods

//returns the hours for duration
int Duration::getHour(){
    return hours;
}

//returns the minutes for duration
int Duration::getMinute(){
    return minutes;
}

//returns the seconds for duration
int Duration::getSecond(){
    return seconds;
}