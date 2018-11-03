#include <iostream>
using namespace std;
namespace video {
template <class Handle, class Update, class Render>
	void loop(Handle h, Update u, Render r)
{ h(); u(); r(); }

template <class Action>
	void main_loop(Action act, int fps)
{
	while (true) {
		cout << fps << endl;
		act();
	}	
}

} // ensd namespace video


int main()
{
	video::main_loop (
	[](void) {video::loop(
		[](void) {cout << "handle" << '\n';},
		[](void) {cout << "update" << '\n';},
		[](void) {cout << "render" << '\n';}
	);}, 60);

}
