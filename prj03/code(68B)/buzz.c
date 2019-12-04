
#define __buzz_c

#include    "includeAll.h"

void Buzz(void)
{
	//config reuse pin P3_4 to output
	bBuzz = 1;
	#buzzC1
	buzzLastTimer = D_buzzLastTime;
	//buzzConvertAdTimer = D_buzzConvertAdTime;
}
