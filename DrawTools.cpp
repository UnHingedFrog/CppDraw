// File: DrawTools.cpp
//      
//   A Drawing Tool using C++ Classes by Muditt Khurana
//   Uses WinBGI library 
//
// "Press C-Circle,L-Line,E-Ellipse,R-Rectangle,Q-Quit"
//
// Implimentation for Drawing Tools Objects

#include "DrawTools.h"
#include "WinBGI\winbgi.h"
#include <math.h>

/// //////////////////////////////////////////////
/// 
///     DrawLine Class
/// 
/// //////////////////////////////////////////////

CDTDrawLine::CDTDrawLine(int a1, int b1, int a2, int b2) {
	x1 = a1; y1 = b1;
	x2 = a2; y2 = b2;
}
void CDTDrawLine::handleMouseMove(int x, int y) {
	x2 = x; y2 = y;
}

void CDTDrawLine::handleLButtonUp(int x, int y) {
	x2 = x; y2 = y;
}

void CDTDrawLine::Refresh() {
	line(x1, y1, x2, y2);
}

/// //////////////////////////////////////////////
/// 
///     DrawCircle Class
/// 
/// //////////////////////////////////////////////


CDTDrawCircle::CDTDrawCircle(int a1, int b1, int r) {
	x1 = a1; y1 = b1;
	radius = r;
}
void CDTDrawCircle::handleMouseMove(int x, int y) {
	radius = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));	
}

void CDTDrawCircle::handleLButtonUp(int x, int y) {
	radius = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}

void CDTDrawCircle::Refresh() {
	circle(x1, y1, radius);
}

/// //////////////////////////////////////////////
/// 
///     DrawRectangle Class
/// 
/// //////////////////////////////////////////////


CDTDrawRect::CDTDrawRect(int a1, int b1, int a2, int b2) {
	x1 = a1; y1 = b1;
	x2 = a2; y2 = b2;
}
void CDTDrawRect::handleMouseMove(int x, int y) {
	x2 = x; y2 = y;
}

void CDTDrawRect::handleLButtonUp(int x, int y) {
	x2 = x; y2 = y;
}

void CDTDrawRect::Refresh() {
	line(x1, y1, x2, y1);
	line(x1, y2, x2, y2);
	line(x1, y1, x1, y2);
	line(x2, y1, x2, y2);
}

/// //////////////////////////////////////////////
/// 
///     DrawFreeHand Class
/// 
/// //////////////////////////////////////////////

CDTDrawFH::CDTDrawFH(int a1, int b1) {
	x1 = a1; y1 = b1;
}
void CDTDrawFH::handleMouseMove(int x, int y) {
	x2 = x; y2 = y;
}

void CDTDrawFH::handleLButtonUp(int x, int y) {
	x2 = x; y2 = y;
}
void CDTDrawFH::Refresh() {
	putpixel(x2,y2,15);
}

/// //////////////////////////////////////////////
/// 
///     DrawEllipse Class
/// 
/// //////////////////////////////////////////////

CDTDrawEllipse::CDTDrawEllipse(int a1, int b1) {
	x1 = a1; y1 = b1;
}
void CDTDrawEllipse::handleMouseMove(int x, int y) {
	x2 = x; y2 = y;
	xradius = abs(x - x1);
	yradius = abs(y - y1);
}

void CDTDrawEllipse::handleLButtonUp(int x, int y) {
	x2 = x; y2 = y;
	xradius = abs(x - x1);
	yradius = abs(y - y1);
}
void CDTDrawEllipse::Refresh() {
	ellipse(x1, y1, 0, 360, xradius, yradius);
}

/// //////////////////////////////////////////////
/// 
///     End of DrawTools
/// 
/// //////////////////////////////////////////////
