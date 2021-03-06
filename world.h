#ifndef world_h
#define world_h
#include <stdbool.h>
#include <stdio.h>
#include "ant.h"

#define WORLD_WIDTH 20
#define ESCAPE_DIST 10
#define MAX_STEP 400

#define FACING_COUNT 4

enum Facing {
	north=0, east=1, south=2, west=3,
};
typedef enum Facing Facing;

struct World {
	bool hasFood[WORLD_WIDTH][WORLD_WIDTH];
	int x, y;
	Facing facing;
};
typedef struct World World;

unsigned int WorldRun(World, Ant *, FILE *f);
void WorldPrint(World *w, Ant *a, FILE *f);

/*
 * When successful, returns the number of cells that contain food.
 *
 * Returns a negative value on failure. Example causes of failure:
 * 1: the given world was not initialized correctly
 * 2: the number of food items in the given world cannot be represented by an integer
 */
int WorldCountFood(World w);

#endif
