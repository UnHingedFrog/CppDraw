#pragma once
// File: DrawTools.h
//      
//   A Drawing Tool using C++ Classes by Muditt Khurana
//   Uses WinBGI library 
//
// "Press C-Circle,L-Line,E-Ellipse,R-Rectangle,Q-Quit"
//
// Header file to Draw Classes 

using namespace std;
/// //////////////////////////////////////////////
/// 
///     DrawBase Class
/// 
/// //////////////////////////////////////////////

class CDTDrawBase {
public:
	virtual void Refresh() = 0;
	virtual void handleMouseMove(int, int) = 0;
	virtual void handleLButtonUp(int, int) = 0;
};

/// //////////////////////////////////////////////
/// 
///     DrawLine Class
/// 
/// //////////////////////////////////////////////


class CDTDrawLine : public CDTDrawBase {
	int x1, y1;
	int x2, y2;
public:
	virtual void handleMouseMove(int, int) override;
	virtual void handleLButtonUp(int, int) override;
	virtual void Refresh() override;
	CDTDrawLine(int, int, int, int);

};

/// //////////////////////////////////////////////
/// 
///     DrawCircle Class
/// 
/// //////////////////////////////////////////////

class CDTDrawCircle : public CDTDrawBase {
	int x1, y1;
	int radius;
public:
	virtual void handleMouseMove(int, int) override;
	virtual void handleLButtonUp(int, int) override;
	virtual void Refresh() override;
	CDTDrawCircle(int, int, int);

};

/// //////////////////////////////////////////////
/// 
///     DrawRectangle Class
/// 
/// //////////////////////////////////////////////


class CDTDrawRect : public CDTDrawBase {
	int x1, y1;
	int x2, y2;
public:
	virtual void handleMouseMove(int, int) override;
	virtual void handleLButtonUp(int, int) override;
	virtual void Refresh() override;
	CDTDrawRect(int, int, int, int);

};

/// //////////////////////////////////////////////
/// 
///     DrawFreeHand Class
/// 
/// //////////////////////////////////////////////

class CDTDrawFH : public CDTDrawBase {
	int x1, y1;
	int x2, y2;
public:
	virtual void handleMouseMove(int, int) override;
	virtual void handleLButtonUp(int, int) override;
	virtual void Refresh() override;
	CDTDrawFH(int, int);

};

/// //////////////////////////////////////////////
/// 
///     DrawEllipse Class
/// 
/// //////////////////////////////////////////////

class CDTDrawEllipse : public CDTDrawBase {
	int x1, y1;
	int x2, y2;
	int xradius, yradius;
	int stangle, endangle;
public:
	virtual void handleMouseMove(int, int) override;
	virtual void handleLButtonUp(int, int) override;
	virtual void Refresh() override;
	CDTDrawEllipse(int, int);

};


