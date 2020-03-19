#include "stdafx.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "HardWheel.h"

int HardWheel::getCompRange() {
	return compRange;
}
void HardWheel::setCompRange(int c) {
	compRange = c;
}
int HardWheel::spinComp() {
	return (rand() % compRange) + 1;
}