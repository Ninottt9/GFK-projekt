#pragma once
#include "Function.h"

class Config {
public:
	Config(std::vector<Function*>* function_ptr);

	double GetX_Min() const;
	double GetX_Max() const;
	double GetY_Min() const;
	double GetY_Max() const;
	double GetZ_Min() const;
	double GetZ_Max() const;
	double GetBufferZ() const;
	unsigned int GetCuts() const;
	double GetCutLen() const;
	Function* GetCurrentFun();	// do wyrzucenia
	unsigned int GetPrintOption() const;
	double GetArrowsLen() const;
	double GetNearPlane() const;
	double GetFarPlane() const;
	double GetNearest() const;
	double GetFurthest() const;
	unsigned int GetListId() const;
	double GetStartX() const;
	double GetStartY() const;
	double GetEndX() const;
	double GetEndY() const;
	double GetSwipe() const; // ?

	double& SetX_Min(double x);
	double& SetX_Max(double x);
	double& SetY_Min(double x);
	double& SetY_Max(double x);
	double& SetZ_Min(double x);
	double& SetZ_Max(double x);
	double& SetBufferZ(double x);
	unsigned int& SetCuts(unsigned int x);
	double& SetCutLen(double x);
	Function* SetCurrentFun(Function* fun); // do wyrzucenia
	unsigned int& SetPrintOption(unsigned int x);
	double& SetArrowsLen(double x);
	double& SetNearPlane(double x);
	double& SetFarPlane(double x);
	double& SetNearest(double x);
	double& SetFurthest(double x);
	unsigned int& SetListId(unsigned int x);
	double& SetStart(double x, double y);
	double& SetEnd(double x, double y);

	double GetViewRotX() const;
	double GetViewRotY() const;
	double GetViewRotZ() const;

	double& SetViewRotX(double x);
	double& SetViewRotY(double x);
	double& SetViewRotZ(double x);

	bool GetPressed() const;
	void SetPressed(bool x);
	Function* GetFunction(int id) const;
	void SetFunction(int id);
	
	bool GetControl() const;
	void SetControl(bool x);

	double GetScale() const;
	double SetScale(double x);

	void PlaneEnabled(bool x);
	bool isPlaneEnable() const;

private:
	double x_min, x_max;
	double y_min, y_max;
	double z_min, z_max;
	double bufferZ;
	unsigned int number_of_cuts;
	double lenght_of_cut;
	Function* current_function;
	unsigned int print_option;
	double length_of_arrows;

	double near_plane;
	double far_plane;
	double nearest_point;
	double furthest_point;

	double start_swipe_x;
	double start_swipe_y;
	double end_swipe_x;
	double end_swipe_y;
	unsigned int id;

	double view_rot_x;
	double view_rot_y;
	double view_rot_z;
	bool pressed;
	bool control;
	double scale;
	bool plane_enable;

	std::vector<Function*>* function_ptr;
public:
	bool closed;
};