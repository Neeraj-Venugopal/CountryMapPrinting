/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   City.cpp
 * Author: Neeraj
 * 
 * Created on March 12, 2018, 11:13 AM
 */

#include "City.h"



/***** Complete this class. *****/
// Constructor 
City::City()
{
    name = "";
    state = "";    
}

// Getter Function Definition

Coordinate City::get_Coordinate_Object() const
{
    return coordinate;
}

string City::get_name() const
{
    return name;    
}

string City::get_state() const
{
    return state;
}
// Operator Overloading for input Stream
istream& operator >>(istream& ins, City& city)
{
    string line = "";
    double lon;
    double lat;
    string str = "";
   
    getline(ins, line, ',' );
    for(int i = 0; i < line.length(); i++ )
    {
        if ( isalpha(line[i]))
        {
            str += line[i];
        }
    }
    
    city.name = str;
    getline(ins, city.state, ',');
    ins >> lat;
    getline(ins, line, ',');
    ins >> lon;
    
    city.coordinate.set_latitude(lat);
    city.coordinate.set_longitude(lon);
    
   // cout << city.name << " " << city.state << " " << lat << " " << lon << endl;
   
    return ins;
}