#pragma once

#ifndef _GAME_CLASSES_H_
#define _GAME_CLASSES_H_

#include <iostream>
#include <windows.h>

enum cell
{
    firstFILD = 1,
    secondFILD = 2,
    thirtFILD = 3,
    fourthFILD = 4,
    fifthFILD = 5,
    sixthFILD = 6,
    seventhFILD = 7,
    eighthFILD = 8,
    ninethFILD = 9
};

class player
{
protected:
    char player1 = 'X';
    char player2 = '0';
    bool whoPlays = true;
public:
    char getPlayer();
    char takePlayer();
    void showPlayer();
};

class field
{
public:
    field();
    void motion(cell el);
    void paintField();
    bool checkWinner();
    player pl;
private:
    char fieldChar[3][3];
};

void gotoxy(short a, short b);

#endif // !1





