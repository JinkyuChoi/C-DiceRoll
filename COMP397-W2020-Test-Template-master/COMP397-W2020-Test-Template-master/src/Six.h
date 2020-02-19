//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for Six
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __SIX__
#define __SIX__
#include "DisplayObject.h"

class Six : public DisplayObject
{
public:

	Six();
	~Six();

	void draw() override;
	void update() override;
	void clean() override;

};
#endif /* defined (__FIVE__) */