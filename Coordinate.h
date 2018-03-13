/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordinate.h
 * Author: Neeraj
 *
 * Created on March 12, 2018, 11:14 AM
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <iostream>
#include <string>
using namespace std;

/**
 * A geographic coordinate.
 */
class Coordinate
{
public:

    //Constructor 
    Coordinate();   
    

    /**
     * Overloaded input stream extraction operator
     * to read a coordinate from an input stream.
     * @param ins the input stream.
     * @param coordinate the coordinate to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, Coordinate& coordinate);

    // Constants for this app's input data.
    static const double MAX_LATITUDE;
    static const double MIN_LONGITUDE;
    
    // Return Latitude 
    double get_latitude() const;
    
    // Return Longitude
    double get_longitude() const;
    
    // Setter Function Declarations
    void set_latitude(double lat);    
    void set_longitude(double lon);

private:
    double latitude;
    double longitude;
};

#endif /* COORDINATE_H_ */
