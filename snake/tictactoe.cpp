#include <iostream>
#include "GameClasses.h"


int main()
{
    setlocale(LC_ALL, "russian");

    field fl;
    cell introductionField;
    int cellNumber;


    for (int i = 0; i < 9 ; ++i)
    {
        if (fl.checkWinner())
        {
            system("cls");
            std::cout << "Победитель: " << fl.pl.takePlayer() << std::endl;
            break;
        }
        fl.pl.showPlayer();
        std::cin >> cellNumber;

        switch (cellNumber)
        {
        case 1: introductionField = firstFILD;
            break;
        case 2: introductionField = secondFILD;
            break;
        case 3: introductionField = thirtFILD;
            break;
        case 4: introductionField = fourthFILD;
            break;
        case 5: introductionField = fifthFILD;
            break;
        case 6: introductionField = sixthFILD;
            break;
        case 7: introductionField = seventhFILD;
            break;
        case 8: introductionField = eighthFILD;
            break;
        case 9: introductionField = ninethFILD;
            break;
        case 0: goto endgame;
            break;
        default: system("cls");
            continue;
            break;
        }

        fl.motion(introductionField);
        fl.paintField();
        gotoxy(0, 0);
    }

endgame:
    if (!fl.checkWinner())
    {
        system("cls");
        std::cout << "Ничья! " << std::endl;
    }

    return 0;
}



