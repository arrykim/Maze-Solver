#include "Maze.h"
#include <iostream>
#include <string>
#include <queue>
#include <fstream>

using namespace std;

int main()
{
    Maze a("Text.txt");
    if (a.solvable())
        cerr << "Yes!" << endl;
    else
        cerr << "No!" << endl;
}