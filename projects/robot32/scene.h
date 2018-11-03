#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

typedef void (*SceneFunc)(void);

struct Scene {
	SceneFunc init;
	SceneFunc quit;
	SceneFunc start;

	SceneFunc handle;
	SceneFunc update;
	SceneFunc render;
};

struct Scene scene_CreateScene(SceneFunc init, SceneFunc quit, SceneFunc start,
		SceneFunc handle, SceneFunc update, SceneFunc render);

#endif /* SCENE_H_INCLUDED */

