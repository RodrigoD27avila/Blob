;
; Simple SDL example in assembly
;

%define SDL_INIT_VIDEO 0x00000020
%define SDL_SW_SURFACE 0x00000000

%define WIDTH  640
%define HEIGHT 480
%define BPP    32

extern SDL_Init
extern SDL_Quit
extern SDL_Delay
extern SDL_SetVideoMode

section .text
global main

main:
        push    ebp
        mov     ebp, esp

        ; initialize sdl       
        push    SDL_INIT_VIDEO
        call    SDL_Init

        ; set video mode
        push    dword SDL_SW_SURFACE
        push    dword BPP
        push    dword HEIGHT
        push    dword WIDTH
        call    SDL_SetVideoMode

        ; delay 5s     
        push    5000
        call    SDL_Delay

        ; quit SDL
        call    SDL_Quit

        mov     esp, ebp
        pop     ebp

        mov     eax, 0
        ret
