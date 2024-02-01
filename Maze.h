#pragma once
#include <string>

class Maze {
public:
	Maze(std::string path);
    bool solvable();
    bool findStart(std::string maze[], int& sr, int& sc);
    bool findEnd(std::string maze[], int& er, int& ec);
private:
	std::string* maze_;
	int lines_;
};

class Coord
{
public:
    Coord(int r, int c) : m_r(r), m_c(c) {}
    int r() const { return m_r; }
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

int getLines(std::string path);