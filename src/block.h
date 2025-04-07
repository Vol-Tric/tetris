#pragma once
#include<vector>
#include<unordered_map>
#include"position.h"
#include"colors.h"

class Block{
    private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int colOffset;
    std::vector<Color>colors;

    public:
    Block();
    void Draw(int offsetX , int offsetY);
    void Move(int rows, int cols);
    std::vector<Position> GetCellPosition();
    void Rotate();
    void UndoRotate();
    int id;
    std::unordered_map<int , std::vector<Position>>cells;


};