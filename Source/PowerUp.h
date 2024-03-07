#ifndef POWERUP_H
#define POWERUP_H
#include <vector>
#include <string>
#include "Object.h"
using namespace std;

class PowerUp : public Object {
public:
	PowerUp();
	void Update(int i);
	void ChangePosition();
private:
	Texture t_1,t_2,t_3,t_4,t_5,t_6;
};

#endif

