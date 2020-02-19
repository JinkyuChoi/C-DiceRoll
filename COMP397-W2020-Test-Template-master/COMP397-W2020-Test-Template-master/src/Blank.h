//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Blank
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __BLANK__
#define __BLANK__
#include "DisplayObject.h"

class Blank : public DisplayObject
{
public:

	Blank();
	~Blank();

	void draw() override;
	void update() override;
	void clean() override;

};
#endif /* defined (__BLANK__) */