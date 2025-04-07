#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game{
    private:
    Grid grid;
    bool IsBlockOutside();
    bool BlockFits();
    void RotateBlock();
    void LockBlock();
    void Reset();
    void MoveBlockLeft();
    void MoveBlockRight();
    void UpdateScore(int linesCleared , int moveDownPoints);
    std::vector<Block> GetAllBlocks();
    std::vector<Block> blocks;
    Block GetRandomBlock();
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;


    public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;
    
};