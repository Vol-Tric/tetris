#include "grid.h"
#include<iostream>
#include"colors.h"


Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize(){
    for(int rows = 0 ; rows < numRows ; ++rows){
        for(int cols = 0 ; cols < numCols ; ++cols){
            grid[rows][cols] = 0;
        }
    }
}

void Grid::Print(){
    for(int rows = 0 ; rows < numRows ; ++rows){
        for(int cols = 0 ; cols < numCols ; ++cols){
            std::cout << grid[rows][cols] << "  ";
        }
        std::cout<< std::endl;
    }
}




void Grid::Draw(){
    for(int rows = 0 ; rows < numRows ; ++rows){
        for(int cols = 0 ; cols < numCols ; ++cols){
            int cellValue = grid[rows][cols];
            DrawRectangle(cols*cellSize + 11 , rows*cellSize + 11 , cellSize - 1 , cellSize - 1 , colors[cellValue]); //(x , y , w , h , color)
        }
    }
}

bool Grid::IsCellOutside(int row, int col){
    if(row >= 0 && row < numRows && col >= 0 && col < numCols){
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int col){
    if(grid[row][col] == 0){
        return true;
    }
    return false;
}

int Grid::ClearFullRows(){
    int completed = 0;
    for(int row = numRows - 1 ; row >= 0 ; --row){

        if(IsRowFull(row)){
            ClearRow(row);
            completed++;
        }

        else if(completed > 0){
            MoveRowDown(row , completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row){
    for(int col = 0 ; col < numCols ; ++col){
        if(grid[row][col] == 0){
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row){
    for(int col = 0 ; col < numCols ; ++col){
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int numOfRows){

    for(int col = 0 ; col < numCols ; ++col){
        grid[row + numOfRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}
