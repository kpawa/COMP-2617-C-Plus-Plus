// Assignment 6: TurtleGraphics.cpp
// Prints coordinates plotted by "turtle" movement
// Author: Kully Pawa
// Date: March 15, 2017

#include "TurtleGraphics.h"
#include <iostream>
using namespace std;

// ctor to clear the floor i.e. inititialize all rows and col to zero (false)
TurtleGraphics::TurtleGraphics() :
	row(STARTING_ROW),
	column(STARTING_COL),
	pen(STARTING_PEN_POSITION),
	direction(STARTING_DIRECTION)

{
	for (auto &row : m_Floor) {
		for (auto &column : row) {
			column = 0;
		}
	}
}

//		NORTH
//			|^|
// WEST <= commands[position] => EAST
//			|v|
//			SOUTH


// reads in all the commands and passes to displayFloor
void TurtleGraphics::processTurtleMoves(const array< int, ARRAY_SIZE> & commands)
{
	int position = 0; // current index of command array
	int count = 0;

	while (static_cast<Cmds>(commands[position]) != Cmds::END_OF_DATA && position < ARRAY_SIZE) {
		//cout << "commands[" << position << "]: " << commands[position] << endl;
		switch (static_cast<Cmds> (commands[position])) {
		case Cmds::PEN_UP:
			pen = false;
			break;
		case Cmds::PEN_DWN:
			pen = true;
			break;
		case Cmds::TURN_RIGHT:
			switch (direction) {
			case Directions::NORTH:
				direction = Directions::EAST;
				break;
			case Directions::EAST:
				direction = Directions::SOUTH;
				break;
			case Directions::SOUTH:
				direction = Directions::WEST;
				break;
			case Directions::WEST:
				direction = Directions::NORTH;
				break;
			default:
				cerr << "ENCOUNTERED A PROBLEM TURNING RIGHT";
				direction = Directions::NORTH; // Set current direction to NORTH for now
				return;
			}
			break;
		case Cmds::TURN_LEFT:
			switch (direction) {
			case Directions::NORTH:
				direction = Directions::WEST;
				break;
			case Directions::EAST:
				direction = Directions::NORTH;
				break;
			case Directions::SOUTH:
				direction = Directions::EAST;
				break;
			case Directions::WEST:
				direction = Directions::SOUTH;
				break;
			default:
				cerr << "ENCOUNTERED A PROBLEM TURNING LEFT";
				direction = Directions::NORTH; // Set direction to NORTH for now
				return;
			}
			break;
		case Cmds::MOVE:  // advance to next position in the commands
			++position;
			if (commands[position] < 1) {
				break;
			}
			switch (direction) {
			case Directions::EAST:
				for (count = 1; count <= commands[position]; ++column, ++count) {
					if (column >= NCOLS)
					{
						column = NCOLS;   // reached the max number of columns = 70
						break;
					}
					if (pen) {
						m_Floor[row][column] = true;
					}
				}
				break;
			case Directions::SOUTH:
				for (count = 1; count <= commands[position]; ++row, ++count) {
					if (row >= NROWS) {
						row = NROWS; // reached the max rows = 22
						break;
					}
					if (pen)
					{
						m_Floor[row][column] = true;
					}
				}
				break;
			case Directions::WEST:
				for (count = 1; count <= commands[position]; --column, ++count) {
					{
						if (column <= 0) { break; } // reached column 0
					}
					if (pen)
					{
						m_Floor[row][column] = true;
					}
				}
				break;
			case Directions::NORTH:
				for (count = 1; count <= commands[position]; --row, ++count) {
					if (row <= 0) { break; } // reached row 0
					if (pen) {
						m_Floor[row][column] = true;
					}
				}
				break;
			default: // I have no idea how you could even get here!
				cerr << "\n\nPROBLEM WITH INNER SWITCH STATEMENT AT ROW: "
					<< static_cast<unsigned int>(row) << "\n\n";
				return;
			}
			break;
		case Cmds::DISPLAY:
			displayFloor();
			break;
		default:
			cerr << "\n\nPROBLEM WITH OUTTER SWITCH STATEMENT AT COMMAND[" << position << "]: "
				<< commands[position] << "\n\n";
			return;
		} // outter switch statment ends
		++position;  // advance to next command
	}   //  while loop ends
}

// displays canvas floor on the screen
void TurtleGraphics::displayFloor() const
{
	for (auto const & row : m_Floor) {
		for (auto const & column : row) {
			if (column == 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << std::endl;
	}
}