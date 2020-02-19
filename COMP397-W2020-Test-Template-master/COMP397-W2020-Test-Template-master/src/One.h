//Jinkyu Choi 301024988
//2020-02-18
//Visual Die for One
//Referenced from Tom Tsiliopoulos


#pragma once
#ifndef __ONE__
#define __ONE__
#include "DisplayObject.h"

class One : public DisplayObject
{
public:

	One();
	~One();
	
	void draw() override;
	void update() override;
	void clean() override;
	
};
#endif /* defined (__ONE__) */
