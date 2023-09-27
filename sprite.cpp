#include "sprite.h"

// Constructor for sprite
sprite::sprite(bool dino){
    type = dino;
    if (type){
        x = 3;
        y = 10;
        print();
        isjumping = false;
    }
    else{
        x = 50;
        y = 10;
        score = 0;
    }
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 0;
    cursor.bVisible = false;
    SetConsoleCursorInfo(console, & cursor);
}

// Move sprite down
void sprite::down(){
    erase();
    y++;
    print();
}

// Move sprite up
void sprite::up(){
    erase();
    y--;
    print();
}

// Move sprite left
void sprite::left(){
    erase();
    if(!x) x = 50;
    else x--;
    print();
    Sleep(100);
    printscore();
}

// Print the current score
void sprite::printscore(){
    score++;
    setxy(0, 0);
    std::cout<<"Score: " <<score;
}

// Set the console cursor position
void sprite::setxy(int x, int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

// Erase the sprite
void sprite::erase(){
    setxy(x,y);
    if (type) std::cout<<" ";
    else std::cout<<"_";
}

// Print the sprite
void sprite::print(){
    setxy(x,y);
    if (type) std::cout<<"O";
    else std::cout<<"|";
}

// Draw the ground
void sprite::drawground(){
    for (int i = 0; i < 50; i++){
        setxy(i,10);
        std::cout<<"_";
    }
}

// Debugging function (unused)
void sprite::debug(){
    setxy(8, 9);
    std::cout<<y;
}

