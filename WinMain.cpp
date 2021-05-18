// File: WinMain.cpp
// for Using WinBGI Graphics
//     
//   A Drawing Tool using C++ Classes by Muditt Khurana
//   Uses WinBGI library 
//
// "Press C-Circle,L-Line,E-Ellipse,R-Rectangle,Q-Quit"
//
//  Windows Main class for Initalizing and Setting up CMainDraw Class


#include "WinBGI\winbgi.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>                     // Provides exit
#include <ctype.h>                      // Provides toupper
#include "CppDraw.h"

using namespace std;
// Functions for Mouse Handler
void handle_mouse_move(int x, int y);
void handle_lbutton_down(int x, int y);
void handle_rbutton_down(int x, int y);
void handle_lbutton_up(int x, int y);

int APIENTRY WinMain
( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
        cout << "CppDraw by Muditt Khurana" << endl;
        cout << "Press 'Q' to quit" << endl;

        initwindow(1024, 768, "Cpp Drawing Tool");
        registermousehandler(WM_MOUSEMOVE, handle_mouse_move);
        registermousehandler(WM_LBUTTONDOWN, handle_lbutton_down);
        registermousehandler(WM_RBUTTONDOWN, handle_rbutton_down);
        registermousehandler(WM_LBUTTONUP, handle_lbutton_up);
        CMainDraw::pcmd = new CMainDraw();
        CMainDraw::pcmd->MainLoop();
        delete CMainDraw::pcmd;
}


// Funcions for Mouse Handler
void handle_mouse_move(int x, int y) {
    CMainDraw::pcmd->handleMouseMove(x, y);
}
void handle_lbutton_down(int x, int y) {
    CMainDraw::pcmd->handleLButtonDown(x, y);
}
void handle_rbutton_down(int x, int y) {
    CMainDraw::pcmd->handleRButtonDown(x, y);
}
void handle_lbutton_up(int x, int y) {
    CMainDraw::pcmd->handleLButtonUp(x, y);
}


