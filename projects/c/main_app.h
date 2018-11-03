#ifndef MAIN_APP_H
#define MAIN_APP_H

#ifdef WINDOWS
typedef int app_int;
#else
typedef unsigned int  app_int;
#endif

typedef struct _main_app main_app;
struct _main_app
{
	app_int a;
	app_int b;
	app_int c;
};

#endif //MAIN_APP_H

