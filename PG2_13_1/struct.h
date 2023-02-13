#pragma once

typedef struct Vector2
{
	float x;
	float y;
};

//rand�͈͗pVector2
typedef struct IntVector2
{
	int x;
	int y;
};

typedef struct Object
{
	Vector2 pos;
	Vector2 speed;
	float radius;
	int isAlive;
};