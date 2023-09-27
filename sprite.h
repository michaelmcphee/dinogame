#ifndef SPRITE_H
#define SPRITE_H

#include <iostream> 
#include <time.h>
#include <windows.h>

class sprite {
public:
    int x,y;
    int score;
    bool type;
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    sprite(bool dino);
    bool isjumping;
    void up();
    void down();
    void left();
    void printscore();
    void setxy(int x, int y);
    void print();
    void erase();
    void debug();
    void drawground();
};

#endif