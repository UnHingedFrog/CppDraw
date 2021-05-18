#pragma once
// File: CppDraw.h
//      
//   A Drawing Tool using C++ Classes by Muditt Khurana
//   Uses WinBGI library 
//
// "Press C-Circle,L-Line,E-Ellipse,R-Rectangle,Q-Quit"
//
// Header file to CMainDraw Class 


#include <vector>
#include "DrawTools.h"
using namespace std;

/// //////////////////////////////////////////////
/// 
///     DrawMain Class
///     Manages all the Draw Objects created on the Canvas
/// 
/// //////////////////////////////////////////////


class CMainDraw {

	vector<CDTDrawBase *> Objs;
	CDTDrawBase* currObj;
	
	int x1, y1;
	int x2, y2;
public:
	char shape;
	void handleMouseMove(int, int);
	void handleLButtonDown(int, int);
	void handleRButtonDown(int, int);
	void handleLButtonUp(int, int);
	void MainLoop();
	void Refresh();
	CMainDraw();
	~CMainDraw();
	static CMainDraw* pcmd;
};

