#include "sprite.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

void start(sprite& UI);
int play();
void jump(sprite &dino, sprite &cactus);

int main(){
    system("cls");
    sprite UI(0);
    int highscore = 0;

    while(true){
        start(UI);
        if (highscore){
            UI.setxy(0,0);
            std::cout<< "HIGHSCORE: " <<highscore;
        }
         
        char op = getch();
        
        if (op == '1'){
            int score = play();
            if (score > highscore){
                highscore = score;
            }   
        }
        else if (op == '2') break;
    }
    system("cls");
    return 0;
}


void start(sprite& UI){
    	system("cls");
		UI.setxy(10,2); std::cout<<" -------------------------- ";
		UI.setxy(10,3); std::cout<<" |   DINO RUN (C++ game)  | ";
        UI.setxy(10,4); std::cout<<" |    by Michael McPhee   | ";
		UI.setxy(10,5); std::cout<<" -------------------------- ";
		UI.setxy(10,6); std::cout<<"1. Start Game"; 
		UI.setxy(10,7); std::cout<<"2. Quit";
		UI.setxy(10,8); std::cout<<"Select option: ";
}

int play() {
    system("cls");
    sprite dino(1);
    sprite cactus(0);
    cactus.drawground();
    while (true) {
        cactus.left();
        if (kbhit() && !dino.isjumping) {
            if (getch() == ' ') jump(dino, cactus);
            else if (getch() == 'q') return cactus.score;
        }

        if (dino.y == 10 && cactus.x == 3) {
            system("cls");
            std::cout << "Game Over. Press any key to continue." << std::endl;
            getch();
            return cactus.score;
        }
    }
}

void jump(sprite &dino, sprite &cactus){
    dino.isjumping = true;
    for (int i = 0; i < 2; i++) { 
        dino.up();
        cactus.left();
    }
    for (int i = 0; i < 3; i++) cactus.left();
    dino.down();
    cactus.left();
    dino.down();
    dino.isjumping = false;
    while (kbhit()) getch();
}