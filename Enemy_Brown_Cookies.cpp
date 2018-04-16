#include "Application.h"
#include "Enemy_Brown_Cookies.h"
#include "ModuleCollision.h"

Enemy_BrownCookie::Enemy_BrownCookie(int x, int y) : Enemy(x, y)
{
	fly.PushBack({ 5, 72, 21, 22 });
	fly.speed = 2.5f;

	animation = &fly;

	collider = App->collision->AddCollider({ 0, 0, 24, 24 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_y = y;
}

void Enemy_BrownCookie::Move()
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

	position.y = int(float(original_y) + (95.0f * sinf(wave)));
	position.x -= 1;
}
