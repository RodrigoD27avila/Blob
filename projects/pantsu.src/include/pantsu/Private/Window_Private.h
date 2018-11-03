#ifndef PANTSU_WINDOW_PRIVATE_H
#define PANTSU_WINDOW_PRIVATE_H

#ifdef __cplusplus
namespace pantsu  {
#endif

struct DLL_LOCAL Window_Private {
	u16        width;
	u16        height;
	u16        bpp;
	u32        flags;
	bool       fullscreen;
	const char *title;
};

#ifdef __cplusplus
} // end namespace pantsu
#endif

#endif // PANTSU_WINDOW_PRIVATE_H
