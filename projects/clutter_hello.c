#include <clutter/clutter.h>

int main(int argc, char **argv)
{
	clutter_init(&argc, &argv);
	
	ClutterColor stage_color = {0, 0, 0, 255};
	ClutterActor *stage = clutter_stage_get_default();
	clutter_actor_set_size(stage, 512, 512);
	clutter_stage_set_color(CLUTTER_STAGE(stage), &stage_color);
	clutter_actor_show(stage);

	clutter_main();

	return 0;	
}
