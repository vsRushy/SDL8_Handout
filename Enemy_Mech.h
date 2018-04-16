#ifndef __ENEMY_MECH_H__
#define __ENEMY_MECH_H__

#include "Enemy.h"

class Enemy_Mech : public Enemy
{
private:
	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	Animation anim;
	Path move;

public:

	Enemy_Mech(int x, int y);

	void Move();
};

#endif // __ENEMY_MECH_H__