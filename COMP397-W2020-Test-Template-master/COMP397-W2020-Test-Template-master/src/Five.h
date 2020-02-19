//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Five
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __FIVE__
#define __FIVE__
#include "DisplayObject.h"

class Five : public DisplayObject
{
public:

	Five();
	~Five();

	void draw() override;
	void update() override;
	void clean() override;

};
#endif /* defined (__FIVE__) */