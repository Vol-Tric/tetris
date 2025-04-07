#pragma once //used to define that this file will be used in compilation only once
#include<vector>
#include<raylib.h>


class Grid{
    private:
    int numRows;
    int numCols;
    int cellSize;
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row , int numOfRows);
    std::vector<Color>colors;




    public:
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row , int col);
    bool IsCellEmpty(int row , int col);
    int ClearFullRows();
    int grid[20][10];

};