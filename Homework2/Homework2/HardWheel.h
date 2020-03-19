#pragma once
#include "Wheel.h"

class HardWheel : public Wheel{
public:
	int getCompRange();
	void setCompRange(int c);
	int spinComp();

private:
	int compRange;
};