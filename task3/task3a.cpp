#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum field
{
    open_square,
    tree
};

class Board
{
    std::vector<field> fields;

    const int width;
    int height;

    public:
        void saveLine( const std::string& line )
        {
            for( const char& c : line  )
            {
                fields.push_back( c == '#' ? tree : open_square );
            }
                
            height++;
        }

        Board( int line_size ) : width(line_size) 
        { 
            height = 0;
            fields = std::vector<field>();
        }

        int treesEncountered( int rowDiff )
        {
            int trees(0);
            int last_column(0);
            for( int i(1); i < height; i++ )
            {
                last_column = (last_column + rowDiff) % width;
                trees += fields[ i * width + last_column ];
            }
            return trees;
        }
};

Board get_entries()
{
    std::ifstream fromFile("task3.txt");

    std::string fileLine;
    getline(fromFile, fileLine);

    Board fields( fileLine.length() );
    fields.saveLine( fileLine );

    while(getline(fromFile, fileLine))
    { 
        fields.saveLine( fileLine );
    };

    return fields;
}

int main()
{
    printf("%d \n", get_entries().treesEncountered(3));
}