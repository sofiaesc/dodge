#ifndef POINTBALL_H
#define POINTBALL_H
#include "Object.h"

class PointBall : public Object {
public:
	PointBall();
	void Update();
	void ChangeState(int i);
	int CheckPoints();
	void ChangeColor();
	void ChangePosition();
private:
	int point_count = 0;
	bool buff = false;
};

#endif

