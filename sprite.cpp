#include "sprite.h"

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

void sprite::down(){
    erase();
    y++;
    print();
}

void sprite::up(){
    erase();
    y--;
    print();
}

void sprite::left(){
    erase();
    if(!x) x = 50;
    else x--;
    print();
    Sleep(100);
    printscore();
}

void sprite::printscore(){
    score++;
    setxy(0, 0);
    std::cout<<"Score: " <<score;
}


void sprite::setxy(int x, int y){
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(console, coord);
}

void sprite::erase(){
    setxy(x,y);
    if (type) std::cout<<" ";
    else std::cout<<"_";
}

void sprite::print(){
    setxy(x,y);
    if (type) std::cout<<"O";
    else std::cout<<"|";
}

void sprite::drawground(){
    for (int i = 0; i < 50; i++){
        setxy(i,10);
        std::cout<<"_";
    }
}

void sprite::debug(){
    setxy(8, 9);
    std::cout<<y;
}