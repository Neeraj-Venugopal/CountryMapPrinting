/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   City.h
 * Author: Neeraj
 *
 * Created on March 12, 2018, 11:13 AM
 */

#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>

#include "Coordinate.h"

using namespace std;

/**
 * City data.
 */
class City
{
public:
    
    /***** Complete this class. *****/
    
    City();

    /**
     * Overloaded input stream operator to read a city
     * from an input stream.
     * @param ins the input stream.
     * @param city the city to read.
     * @return the input stream.
     */
    friend istream& operator >>(istream& ins, City& city);

    /**
     * Overloaded output stream operator to output a city
     * to an output stream.
     * @param outs the output stream.
     * @param city the city to output.
     * @return the output stream.
     */
    friend ostream& operator <<(ostream& outs, const City& city);
    
    // Getter Functions Declaration
    Coordinate get_Coordinate_Object() const;
    string get_name() const;
    string get_state() const;

private:
    string name;
    string state;
    Coordinate coordinate;
};

#endif /* CITY_H_ */

