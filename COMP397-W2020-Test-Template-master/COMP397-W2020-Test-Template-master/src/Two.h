//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Two
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __TWO__
#define __TWO__
#include "DisplayObject.h"

class Two : public DisplayObject
{
public:

	Two();
	~Two();

	void draw() override;
	void update() override;
	void clean() override;

};
#endif /* defined (__TWO__) */