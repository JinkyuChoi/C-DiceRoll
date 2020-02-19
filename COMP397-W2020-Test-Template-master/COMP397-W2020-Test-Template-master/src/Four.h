//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Four
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __FOUR__
#define __FOUR__
#include "DisplayObject.h"

class Four : public DisplayObject
{
public:

	Four();
	~Four();

	void draw() override;
	void update() override;
	void clean() override;

};
#endif /* defined (__FOUR__) */