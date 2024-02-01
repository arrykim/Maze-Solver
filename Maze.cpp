#include "Maze.h"
#include <string>
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int getLines(string path)
{
    ifstream inputFile;
    inputFile.open(path);
    string temp;
    int lineCount = 0;
    if (inputFile.is_open()) {
        while (getline(inputFile, temp))
        {
            lineCount++;
        }
        inputFile.close();
    }
    else {
        return -1;
    }
    return lineCount;
}


bool getContent(string path, string maze[])
{
    ifstream inputFile;
    inputFile.open(path);
    string temp;
    int linecount = 0;
    if (inputFile.is_open()) {
        while (getline(inputFile, temp))
        {
            maze[linecount] = temp;
            linecount++;
        }
        inputFile.close();
    }
    else {
        return false;
    }
	return true;
}

//Maze

Maze::Maze(string path)
{
    lines_ = getLines(path);
    maze_ = new string[lines_];
    getContent(path, maze_);
}

bool Maze::findStart(string maze[], int& sr, int& sc)
{
    for (int i = 0; i < lines_; i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            if (maze[i][j] == '@')
            {
                sr = i;
                sc = j;
                return true;
            }
        }
    }
    return false;
}

bool Maze::findEnd(string maze[], int& er, int& ec)
{
    for (int i = 0; i < lines_; i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            if (maze[i][j] == '!')
            {
                er = i;
                ec = j;
                return true;
            }
        }
    }
    return false;
}

bool Maze::solvable()
{
    queue<Coord> cQ;
    int sr, sc, er, ec;
    findStart(maze_, sr, sc);
    findEnd(maze_, er, ec);
    maze_[sr][sc] = '$';
    Coord a(sr, sc);

    cQ.push(a);


    while (!cQ.empty())
    {
        Coord a = cQ.front();
        
        cQ.pop();
        
        if (a.r() == er && a.c() == ec)
        {
            return true;
        }
        if (a.r() - 1 >= 0 && (maze_[a.r() - 1][a.c()] == '.' || maze_[a.r() - 1][a.c()] == '!'))
        {
            Coord north(a.r() - 1, a.c());
            cQ.push(north);
            maze_[a.r() - 1][a.c()] = '$';
        }
     
        if (a.c() - 1 >= 0 && (maze_[a.r()][a.c() - 1] == '.' || maze_[a.r()][a.c() - 1] == '!'))
        {
            Coord west(a.r(), a.c() - 1);
            cQ.push(west);
            maze_[a.r()][a.c() - 1] = '$';
        }
       
        if (a.r() + 1 < lines_ && (maze_[a.r() + 1][a.c()] == '.' || maze_[a.r() + 1][a.c()] == '!'))
        {
            Coord south(a.r() + 1, a.c());
            cQ.push(south);
            maze_[a.r() + 1][a.c()] = '$';
        }
        
        if (a.c() + 1 < maze_[a.r()].size() && (maze_[a.r()][a.c() + 1] == '.' || maze_[a.r()][a.c() + 1] == '!'))
        {
            Coord east(a.r(), a.c() + 1);
            cQ.push(east);
            maze_[a.r()][a.c() + 1] = '$';
        }
    }

    return false;
}