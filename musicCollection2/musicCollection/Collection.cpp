/* 
 * File:   Collection.cpp
 * Author: George Spary
 */

#include "Collection.h"
#include "Album.h"
#include "Track.h"
#include "Duration.h"
#include <string>
#include <vector>

using namespace std;

//default empty collection constructor
Collection::Collection() {
}

//adds an album to the collection
void Collection::addAlbum(Album alb) {
    Album a1 = alb;
    albums.push_back(a1);
    albumCount++;
    
}

//prints the collection out
void Collection:: print(){
     for (auto ths = albums.begin(); ths != albums.end(); ths++ ){
         Album a2 = *ths;
         a2.print();
        
     }
    
}

//returns the total Album Count
int Collection::getAlbumCount() {
    return albumCount;
}

