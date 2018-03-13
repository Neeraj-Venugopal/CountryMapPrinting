/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Coordinate.cpp
 * Author: Neeraj
 * 
 * Created on March 12, 2018, 11:14 AM
 */

#include "Coordinate.h"
using namespace std;

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;


// Constructor
Coordinate::Coordinate()
{
    
}

// Getter Function Definition
double Coordinate::get_latitude() const
{
    return latitude;
}

double Coordinate::get_longitude() const
{
    return longitude;
}

// Setter Function Definition 
void Coordinate::set_latitude(double lat)
{
    latitude = lat;
}

void Coordinate::set_longitude(double lon)
{
    longitude = lon;
}

// Input Stream operator Overloading
istream& operator >>(istream& ins, Coordinate& coordinate)
{
    string line = "";
    
    ins >> coordinate.latitude;
    getline(ins, line, ',');
    ins >> coordinate.longitude;
        
    //cout << coordinate.latitude << " Printing " << coordinate.longitude << endl;
    //cout << "Inside Operator Overload" << endl;
    
    return ins;
}