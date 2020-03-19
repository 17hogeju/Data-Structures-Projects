#include "stdafx.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Wheel.h"


Wheel::Wheel() {//Only one constructor necessary, since wheel is always made as “wheel w; ”
}

void Wheel::setMaxVal(int newMax) { //sets maximum value
	maxVal = newMax;
}

int Wheel::getMaxVal() { //gets Maximum value
	return maxVal;
}

void Wheel::setMinVal(int newMin) { //sets Minimum value (should never be used)
	minVal = newMin;
}

int Wheel::getMinVal() { //gets Minimum value
	return minVal;
}

void Wheel::changeRange(int change) { //minVal is always 1, so we just updated the value of max.
	maxVal = change;
}

int Wheel::spin() {
	return (rand() % maxVal) + 1;
}