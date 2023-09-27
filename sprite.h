#ifndef SPRITE_H
#define SPRITE_H

#include <iostream> 
#include <time.h>
#include <windows.h>

class sprite {
private:
    bool type;
    COORD coord;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    void erase();

public:
    int x,y;
    int score;
    sprite(bool dino);
    bool isjumping;
    void up();
    void down();
    void left();
    void printscore();
    void setxy(int x, int y);
    void print();
    void debug();
    void drawground();
};

#endif