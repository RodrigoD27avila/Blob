#include <memory>
#include <SDL.h>

namespace SDL {
auto CreateWindow(const char *title, int x, int y, int w, int h, Uint32 flags) {
		return std::shared_ptr<SDL_Window>(SDL_CreateWindow(title,
			x, y, w, h, flags), [=](SDL_Window *window) {
				SDL_DestroyWindow(window);
		});
	}

auto CreateRenderer(SDL_Window *window, int index, Uint32 flags) {
		return std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(window,
			index, flags), [=](SDL_Renderer *renderer) {
				SDL_DestroyRenderer(renderer);
		});
	}

auto CreateTexture(SDL_Renderer *renderer, Uint32 format,
		int access, int w, int h) {
		return std::shared_ptr<SDL_Texture>(SDL_CreateTexture(renderer,
			format, access, w, h), [=](SDL_Texture *texture) {
				SDL_DestroyTexture(texture);
		});
	}
	
}
	

