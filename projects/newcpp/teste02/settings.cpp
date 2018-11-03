#include "settings.h"

static int screen_width;
static int screen_height;

void Settings::setWidth(int width)
{ screen_width = width; }

void  Settings::setHeight(int height)
{ screen_height = height; }

int Settings::getWidth()
{ return screen_width; }

int Settings::getHeight()
{ return screen_height; }
