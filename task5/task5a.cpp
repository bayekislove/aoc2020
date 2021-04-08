#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define ROWS 7
#define COLS 3

int calculate_index( std::string seat_in_str )
{
    int left = 0;
    int right = 127;
    for( int i = 0; i < ROWS; i++ )
    {
        if( seat_in_str[i] == 'B' )
        {
            left = ( ( right - left ) >> 1 ) + 1 + left;
        } else {
            right = ( ( right - left ) >> 1 ) + left;
        }
    }
    int row = left;
    left = 0;
    right = 7;
    for( int i = 0; i < COLS; i++ )
    {
        if( seat_in_str[i + ROWS] == 'R' )
        {
            left = ( ( right - left ) >> 1 ) + 1 + left;
        } else {
            right = ( ( right - left ) >> 1 ) + left;
        }
    }
    return row * 8 + left;
}

int main()
{
    using namespace std;
    ifstream fromFile("task5.txt");

    string fileLine;

    int temp_max = 0;
    while(getline(fromFile, fileLine))
    { 
        temp_max = max( calculate_index(fileLine), temp_max );
    }

    cout << temp_max << endl;
}