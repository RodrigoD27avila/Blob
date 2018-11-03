#include "static.h"

static void teste()
{
	Static s;
	return;
}

int main()
{
	Static sta;
	Static::con = Static::Const();
	teste();
}
