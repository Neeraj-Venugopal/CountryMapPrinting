/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Neeraj
 * 
 * Created on March 12, 2018, 11:12 AM
 */

#include <math.h>
#include "Node.h"

/***** Complete this class. *****/

// Constructor
Node::Node()
{
    name = "";
    state = "";
    row = 0;
    col = 0;
}
Node::Node(Coordinate coordinate)
{
    //cout << "Inside Node Constructor" << endl;
    name = "";
    state = "";
    convert_coordinate(coordinate);
}

Node::Node(City city)
{
    convert_coordinate(city.get_Coordinate_Object());
    name = city.get_name();
    state = city.get_state();
    //cout << get_row() << " " << get_col() << endl;
}

void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

int Node::get_row() const
{
    return row;
}

int Node::get_col() const
{
    return col;
}

string Node::get_name() const
{
    return name;
}
string Node::get_state() const
{
    return state;
}

bool Node::operator > (const Node& other) const
{
    //cout << " Inside Operator Overload ";   
    if(row > other.row)
        return true;
    else if(row == other.row && col > other.col)
        return true;
    else
        return false;
}