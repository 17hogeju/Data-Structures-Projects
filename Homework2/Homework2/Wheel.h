#pragma once
class Wheel {
public:
	Wheel(); //Only one constructor necessary, since wheel is always made as “wheel w; ”
	void setMaxVal(int newMax);
	int getMaxVal();
	void setMinVal(int newMin);
	int getMinVal();

	void changeRange(int change);
	//minVal is always 1, so just modify maxVal based on change
	int spin();
	//random from 1 to maxVal
private:
	int maxVal;
	int minVal;
};