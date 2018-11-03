#include <irrlicht.h>
using namespace irr;
using namespace core;
using namespace video;


int main()
{
	IrrlichtDevice *device = createDevice(EDT_OPENGL,
		dimension2d<u32>(640, 480), 16,
		false, false, 0);

	if (!device) {
		return 1;
	}

	device->drop();
	return 0;
}
