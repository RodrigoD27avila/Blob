#ifndef PANTSU_PRIVATE_X11_WINDOW_H
#define PANTSU_PRIVATE_X11_WINDOW_H

namespace pantsu  {
namespace Private {

struct Window_Private;

class DLL_LOCAL Window
public:
	void create();
private:
	Window_Private *priv;


} // end namespace Private
} // end namespace pantsu

#endif // PANTSU_PRIVATE_X11_WINDOW_H
