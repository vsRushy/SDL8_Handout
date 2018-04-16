#include "Application.h"
#include "Enemy_mech.h"
#include "ModuleCollision.h"

Enemy_Mech::Enemy_Mech(int x, int y) : Enemy(x, y)
{
	anim.PushBack({ 5, 72, 21, 22 });
	anim.speed = 0.2f;

	move.PushBack(, , &anim);

	animation = &anim;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_Mech::Move()
{

	if (going_up)
	{
		if (wave > 0.8f)
			going_up = false;
		else
			wave += 0.02f;
	}
	else
	{
		if (wave < -0.8f)
			going_up = true;
		else
			wave -= 0.02f;
	}

	position.y = int(float(original_y) + (25.0f * sinf(wave)));
	position.x -= 1;
}
