/* 
 * File:   Collection.h
 * Author: George Spary
 */


#include "Album.h"
#include "Track.h"
#include "Duration.h"
#include <string>
#include <vector>

using namespace std;
#ifndef COLLECTION_H
#define COLLECTION_H

class Collection {
public:
    //default empty constructor
    Collection();
    
    //adds an ablum to the collection
    void addAlbum(Album al);
    
    //gets the total amount of albums in collection
    int getAlbumCount();
    
    //print function
    void print();
private:
    //variables
    vector<Album> albums;
    int albumCount;
};

#endif /* COLLECTION_H */

