// File: CppDraw.cpp
//      
//   A Drawing Tool using C++ Classes by Muditt Khurana
//   Uses WinBGI library 
//
// "Press C-Circle,L-Line,E-Ellipse,R-Rectangle,Q-Quit"
//
// Implimentation for Draw Main Class

#include "CppDraw.h"
#include "WinBGI\winbgi.h"
#include <iostream>

void check_keys();

/// //////////////////////////////////////////////
/// 
///     DrawMain Class
///     Manages all the Draw Objects created on the Canvas
/// 
/// //////////////////////////////////////////////


CMainDraw* CMainDraw::pcmd;

CMainDraw::CMainDraw() {
    currObj = NULL;
}
 
CMainDraw::~CMainDraw() {
    for (auto t : Objs) delete t;
}

void CMainDraw::MainLoop() {
    for (;;) // Infinite loop to keep program running... only quits when user
                  // presses the q key to exit.
    {
        check_keys();
        delay(10);
    }
}

void CMainDraw::handleMouseMove(int x, int y) {
    x2 = x; y2 = y;
    if( currObj )
        currObj->handleMouseMove(x,y);
    Refresh();
}
void CMainDraw::handleLButtonDown(int x, int y) {
    x1 = x2 = x;
    y1 = y2 = y;
    if(shape=='L') currObj = new CDTDrawLine(x1, y1, x2, y2);
    else if (shape == 'C') currObj = new CDTDrawCircle(x1, y1, 0);
    else if (shape == 'R') currObj = new CDTDrawRect(x1, y1, x2, y2);
    else if (shape == 'P') currObj = new CDTDrawFH(x1, y1);
    else if (shape == 'E') currObj = new CDTDrawEllipse(x1, y1);
    Objs.push_back( currObj );
}
void CMainDraw::handleRButtonDown(int x, int y) {

}
void CMainDraw::handleLButtonUp(int x, int y) {
    x2 = x; y2 = y;
    if( currObj )
        currObj->handleLButtonUp(x,y);
    Refresh();
    currObj = NULL;
}

void CMainDraw::Refresh() {
    cleardevice();
    outtextxy(25, 725, "Press C-Circle,L-Line,E-Ellipse,R-Rectangle,Q-Quit");
    for (auto t : Objs) t->Refresh();
}


void check_keys()
{
    int command;

    if (kbhit() == true)
    {
        command = toupper(getch());
        if (char(command) == 'Q')
        {
            cout << "Exiting..." << endl;
            exit(EXIT_SUCCESS);
        }
        else CMainDraw::pcmd->shape = char(command);
    }
}
