#include <Windows.h>
#include <cstdlib>
#include <ctime>

#include "amxxmodule.h"

cell AMX_NATIVE_CALL hehe_random_num(AMX *amx, cell *params);
cell AMX_NATIVE_CALL hehe_random_float(AMX *amx, cell *params);

AMX_NATIVE_INFO g_AmxNativeInfo[] =
{
	{ "hehe_random_num", hehe_random_num },
	{ "hehe_random_float", hehe_random_float },
	{NULL, NULL}
};

void OnAmxxAttach()
{
	MF_AddNatives(g_AmxNativeInfo);
}

cell AMX_NATIVE_CALL hehe_random_num(AMX *amx, cell *params)
{
	static bool seed = false;

	if (!seed)
		srand((unsigned)time(NULL));
	seed = true;
	return (rand() % (params[2] - params[1] + 1) + params[1]);
}

cell AMX_NATIVE_CALL hehe_random_float(AMX *amx, cell *params)
{
	static bool seed = false;

	if (!seed)
		srand((unsigned)time(NULL));
	seed = true;
	float low = amx_ctof(params[1]);
	float up = amx_ctof(params[2]);
	return amx_ftoc(low + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (up - low))));
}
