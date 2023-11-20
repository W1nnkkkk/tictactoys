#include "GameClasses.h"


    char player::getPlayer()
    {
        if (whoPlays)
        {
            whoPlays = false;
            return player1;
        }
        else
        {
            whoPlays = true;
            return player2;
        }
    };
    char player::takePlayer()
    {
        if (whoPlays)
        {
            return player1;
        }
        else
        {
            return player2;
        }
    }
    void player::showPlayer()
    {
        if (whoPlays)
        {
            std::cout << "Ход игрока: " << player1 << " ввод: ";
        }
        else
        {
            std::cout << "Ход игрока: " << player2 << " ввод: ";
        }
    }


    field::field()
    {
        for (size_t i = 0; i < 3; ++i)
        {
            for (size_t j = 0; j < 3; ++j) {
                fieldChar[i][j] = '/';
            }
        }
    }
    void field::motion(cell el)
    {
        switch (el)
        {
        case firstFILD:
            if (fieldChar[2][0] != '0' && fieldChar[2][0] != 'X') { fieldChar[2][0] = pl.getPlayer(); }
            break;
        case secondFILD:
            if (fieldChar[2][1] != '0' && fieldChar[2][1] != 'X') { fieldChar[2][1] = pl.getPlayer(); }
            break;
        case thirtFILD:
            if (fieldChar[2][2] != '0' && fieldChar[2][2] != 'X') { fieldChar[2][2] = pl.getPlayer(); }
            break;
        case fourthFILD:
            if (fieldChar[1][0] != '0' && fieldChar[1][0] != 'X') { fieldChar[1][0] = pl.getPlayer(); }
            break;
        case fifthFILD:
            if (fieldChar[1][1] != '0' && fieldChar[1][1] != 'X') { fieldChar[1][1] = pl.getPlayer(); }
            break;
        case sixthFILD:
            if (fieldChar[1][2] != '0' && fieldChar[1][2] != 'X') { fieldChar[1][2] = pl.getPlayer(); }
            break;
        case seventhFILD:
            if (fieldChar[0][0] != '0' && fieldChar[0][0] != 'X') { fieldChar[0][0] = pl.getPlayer(); }
            break;
        case eighthFILD:
            if (fieldChar[0][1] != '0' && fieldChar[0][1] != 'X') { fieldChar[0][1] = pl.getPlayer(); }
            break;
        case ninethFILD:
            if (fieldChar[0][2] != '0' && fieldChar[0][2] != 'X') { fieldChar[0][2] = pl.getPlayer(); }
            break;
        default:
            break;
        };

    }
    void field::paintField()
    {
        for (size_t i = 0; i < 3; ++i)
        {
            for (size_t j = 0; j < 3; ++j) {
                std::cout << fieldChar[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
    bool field::checkWinner()
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (fieldChar[i][0] == pl.takePlayer() && (fieldChar[i][1] == pl.takePlayer()) && (fieldChar[i][2] == pl.takePlayer())) {
                return true;
            };
            if (fieldChar[0][i] == pl.takePlayer() && (fieldChar[1][i] == pl.takePlayer()) && (fieldChar[2][i] == pl.takePlayer()))
            {
                return true;
            }
            if (fieldChar[0][0] == pl.takePlayer() && (fieldChar[1][1] == pl.takePlayer()) && (fieldChar[2][2] == pl.takePlayer()))
            {
                return true;
            }
            if (fieldChar[2][0] == pl.takePlayer() && (fieldChar[1][1] == pl.takePlayer()) && (fieldChar[0][2] == pl.takePlayer()))
            {
                return true;
            }
        }
        return false;
    }

void gotoxy(short a, short b) //Custom gotoxy() function
{
    COORD coordinates; //Data type of co-ordinates
    coordinates.X = a; //Assign value to X- Co-ordinate
    coordinates.Y = b; //Assign value to Y Co-ordinate

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}