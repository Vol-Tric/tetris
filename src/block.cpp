#include"block.h"

Block::Block(){
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    colOffset = 0;
}

void Block::Draw(int offsetX , int offsetY){
    std::vector<Position> tiles = GetCellPosition();
    for(Position item : tiles){
        DrawRectangle(item.col * cellSize + offsetX , item.row * cellSize + offsetY , cellSize - 1 , cellSize - 1 , colors[id]);
    }
}

void Block::Move(int rows , int cols){
    rowOffset += rows;
    colOffset += cols;
}

std::vector<Position> Block::GetCellPosition(){
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> newTiles;
    
    for(Position item : tiles){
        Position newPos = Position(item.row + rowOffset , item.col + colOffset);
        newTiles.push_back(newPos);
    }
    return newTiles;
}

void Block::Rotate(){
    rotationState++;
    if(rotationState == (int)cells.size()){
        rotationState = 0;
    }
}

void Block::UndoRotate(){
    rotationState--;
    if(rotationState == -1){
        rotationState = (int)cells.size();
    }
}
