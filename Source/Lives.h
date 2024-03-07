#ifndef LIVES_H
#define LIVES_H
#include "Object.h"

class Lives : public Object {
public:
	Lives(int x, int y);
	void Update();
	void ChangeStatus(int i);
private:
	Color real_color;
	int l_status;
};

#endif

