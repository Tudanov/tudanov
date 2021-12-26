// MazeGame.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <conio.h>
#include "time.h"
#include "windows.h"
#include "CrtLib.h"

using namespace std;
using namespace crt;

const int LX = 75;
const int LY = 20;

const char player = (char)1;
// 0 - пустое пространство
// 1 - стена 
// 2 - выход
// 3 - игрок
// 4 - монета

int maze[LY][LX] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
    {1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1},
    {1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,2},
    {1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,0,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,4,0,0,0,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0,0,0,0,4,0,0,0,0,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1},
    {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,1,4,0,1,1,0,0,0,4,0,1,1,1,1,1,1,1,1,0,4,0,0,0,0,0,0,0,4,1,0,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,4,0,0,1},
    {1,1,1,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,4,1,0,1,0,1,1,1,0,1},
    {1,1,1,4,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,4,1,0,1,1,1,1,1,0,0,0,0,0,0,0,4,0,4,1,1,1,0,1,1,1,0,1,0,0,0,0,0,4,0,0,0,0,0,4,1,1,0,1,0,1,0,1,1,1,0,2},
    {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,4,0,0,0,0,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,0,1,4,1,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,4,1,1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,1},
    {1,1,1,0,1,1,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,4,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,1,0,0,0,4,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,4,0,0,0,0,0,0,0,4,0,1,1,1,1,1,1,1},
    {1,1,1,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,4,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// глобальные переменные
int hx, hy; // позиция игрока в лабиринте
int score = 0; // счет игры

int endLevel = 0; // 0 - игра продолжается, 1 - выигрыш, 2 - закончилось время
int timeLimit = 540; // лимит игры в секундах
int gameTime; // оставшееся время

clock_t tstart;

// Функция обновления счета
void UpdateScore(int score)
{
    GotoXY(35, 30);
    setlocale(LC_ALL, "Russian");
    cout << "СЧЕТ: " << score;
    setlocale(LC_ALL, "English");
}

// функция обновления оставшегося времени
void UpdateClock(clock_t t)
{
    gameTime = timeLimit - (t - tstart) / CLOCKS_PER_SEC;
    setlocale(LC_ALL, "Russian");
    GotoXY(49, 30);
    if (gameTime < 0)
    {
        endLevel = 2;
    }
    else
    {
        SetTextColor(7);
        cout << "Осталось: ";
        if (gameTime > 15)
            SetTextColor(10);
        else
            SetTextColor(12);
        cout << gameTime;
        SetTextColor(7);
        cout << " секунд ";
    }
    setlocale(LC_ALL, "English");
}

void PrintMaze(int maze[LY][LX], int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            switch (maze[i][j])
            {
            case 0:
                cout << ' ';
                break;
            case 1:
                cout << (char)178;
                break;
            case 2:
                cout << (char)176;
                break;
            case 3:
                cout << player;
                break;
            case 4:
                cout << '$';
                break;
            default:
                cout << '?';
            }
        }
        cout << endl;
    }
}

void FindFirstPlayerPosition(int maze[LY][LX], int sizeX, int sizeY)
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            if (maze[i][j] == 3)
            {
                hx = j;
                hy = i;
                return;
            }
        }
    }
    hx = hy = 0;
}

void HidePlayer()
{
    GotoXY(hx, hy);
    cout << ' ';
    maze[hy][hx] = 0;
}

void ShowPlayer()
{
    GotoXY(hx, hy);
    cout << player;
    maze[hy][hx] = 3;
}

void GoUp()
{
    if (hy > 0)
    {
        switch (maze[hy - 1][hx])
        {
        case 0:
            HidePlayer();
            hy--;
            ShowPlayer();
            break;
        case 2:
            HidePlayer();
            hy--;
            ShowPlayer();
            UpdateScore(score += 500);
            endLevel = 1;
            break;
        case 4:
            HidePlayer();
            hy--;
            ShowPlayer();
            UpdateScore(score += 100);
            break;
        }
    }

}

void GoDown()
{
    if (hy < LY - 1)
    {
        switch (maze[hy + 1][hx])
        {
        case 0:
            HidePlayer();
            hy++;
            ShowPlayer();
            break;
        case 2:
            HidePlayer();
            hy++;
            ShowPlayer();
            UpdateScore(score += 500);
            endLevel = 1;
            break;
        case 4:
            HidePlayer();
            hy++;
            ShowPlayer();
            UpdateScore(score += 100);
            break;
        }
    }
}

void GoRight()
{
    if (hx < LX - 1)
    {
        switch (maze[hy][hx + 1])
        {
        case 0:
            HidePlayer();
            hx++;
            ShowPlayer();
            break;
        case 2:
            HidePlayer();
            hx++;
            ShowPlayer();
            UpdateScore(score += 500);
            endLevel = 1;
            break;
        case 4:
            HidePlayer();
            hx++;
            ShowPlayer();
            UpdateScore(score += 100);
            break;
        }
    }
}

void GoLeft()
{
    if (hx > 0)
    {
        switch (maze[hy][hx - 1])
        {
        case 0:
            HidePlayer();
            hx--;
            ShowPlayer();
            break;
        case 2:
            HidePlayer();
            hx--;
            ShowPlayer();
            UpdateScore(score += 500);
            endLevel = 1;
            break;
        case 4:
            HidePlayer();
            hx--;
            ShowPlayer();
            UpdateScore(score += 100);
            break;
        }
    }
}

void ShowEndGameMessage(int endLevel)
{
    setlocale(LC_ALL, "Russian");
    GotoXY(30, 15);
    if (endLevel == 1)
    {
        cout << "   АМИГО ТЫ ВЫЙГРАЛ   "; 
    }
    else
    {
        cout << "  К СОЖАЛЕНИЮ АМИГО, ТЫ ПРОИГРАЛ   ";
    }
    GotoXY(32, 16);
    cout << " НАЖМИТЕ КЛАВИШУ <ENTER> ";
    while (_getch() != 13);
    system("cls");
}

void Control()
{
    tstart = clock();
    UpdateScore(score);
    unsigned char x;
    while (!endLevel)
    {
        UpdateClock(clock());
        if (_kbhit())
        {
            x = _getch();
            if (x == 27) return;
            if (x == 0xe0)
                switch (_getch())
                {
                case 72:
                    //cout << "Up" << endl;
                    GoUp();
                    break;
                case 80:
                    //cout << "Down" << endl;
                    GoDown();
                    break;
                case 75:
                    //cout << "Left" << endl;
                    GoLeft();
                    break;
                case 77:
                    //cout << "Right" << endl;
                    GoRight();
                    break;
                }
        }
        Sleep(100);
    }
    ShowEndGameMessage(endLevel);
}


int main()
{
    system("mode con cols=80 lines=31");
    system("cls");
    PrintMaze(maze, LX, LY);
    FindFirstPlayerPosition(maze, LX, LY);
    ShowCursor(false);
    Control();
    ShowCursor(true);
}

