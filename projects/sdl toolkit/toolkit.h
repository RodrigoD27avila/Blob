#ifndef TOOLKIT_H_INCLUDED
#define TOOLKIT_H_INCLUDED

#include <SDL/SDL.h>

#include "group.h"

/*---Constants---*/
#define STK_SUCCESS  0
#define STK_FAILURE -1

/*--Global--*/
typedef struct _ToolkitStack
{
    SDL_Surface *mainsurface;

    Uint32 items;
    Group *stack;

    Group *mywidgets;

} ToolkitStack;

typedef struct _ToolkitError
{
    char *message;
    
} ToolkitError;

extern ToolkitStack globalStack;
extern ToolkitError globalError;

Sint32 ToolkitInit();
void RegisterWidget(void *widget);
void GlobalHandle(SDL_Event *event);
void ToolkitQuit();
void *GetWidgetXY(Sint16 x, Sint16 y);

char *GetError();

/*------Widget------*/

typedef void (*WidgetDestroyFunc)(void *widget);
typedef void (*WidgetHandleFunc)(void *widget, SDL_Event *event);
typedef void (*WidgetDrawFunc)(void *widget);

typedef struct _Widget
{
    WidgetDestroyFunc widgetdestroy;
    WidgetHandleFunc  widgethandle;
    WidgetDrawFunc    widgetdraw;
        
    void *widget;
    void *data;
    SDL_Surface *surface;
    SDL_Rect    *geometry;

    void *parent;

} Widget;

/*------Container------*/

typedef enum _Layout
{
    LA_RELATIVE,
    LA_HBOX,
    LA_VBOX,
    LA_GRID,
    
} Layout;

typedef struct _Container
{
    Group  *group;
    Layout  layout;

} Container;

void ContainerInit(Widget *widget, Group *group, Layout layout);
void ContainerDestroy(void *container);
void ContainerDraw(void *container);

/*------Button------*/

typedef enum _ButtonType
{
    BT_NORMAL,
    BT_RADIO,
    BT_CHECK,    

} ButtonType;

typedef struct _ButtonData
{
    const char *text;
    ButtonType  type;

} ButtonData;

void ButtonInit(Widget* widget, const char *text, ButtonType type);
void ButtonDestroy(void *button);
void ButtonDraw(void *button);

/*------Label------*/

typedef enum _LabelType
{
    LB_NORMAL,
    LB_HYPERLINK,

} LabelType;

typedef struct _LabelData
{
    const char *text;
    LabelType   type;

} LabelData;

void LabelInit(Widget *widget, const char *text, LabelType type);
void LabelDestroy(void *label);
void LabelDraw(void *label);

/*------Slider------*/

typedef const char *(*SliderFormatTextFunc)(Sint64 currentvalue);

typedef struct _SliderData
{
    Sint64 currentvalue;
    Sint64 first;
    Sint64 last;

    SliderFormatTextFunc format;

} SliderData;

void SliderInit(Widget *widget, Sint64 first, Sint64 last);
void SliderDestroy(void *slider);
void SliderDraw(void *slider);

/*------Input------*/

typedef struct _InputData
{
    SDL_bool multiline;
    SDL_bool mask;

} InputData;

void InputNew(Widget *widget, SDL_bool multiline, SDL_bool mask);
void InputDestroy(void *input);
void InputDraw(void *input);

/*------ItemData------*/

typedef struct _ItemData
{
    Uint32 index;
    const char *text;
    
    void *data;

} ItemData;

void ItemDataInit(Widget *widget, Uint32 index, const char *text, void *data);
void ItemDataDestroy(void *itemdata);

/*------Table------*/

typedef struct _TableData
{
    Uint32 columns;
    Uint32 rows;
    
    Group *data;
    
} TableData;

void TableInit(Widget *widget, Uint32 columns, Uint32 rows, Group *data);
void TableDestroy(void *table);
void TableDraw(void *table);

/*------Dropdown------*/

typedef struct _DropdownData
{
    Group *data;

} DropdownData;

void DropdownInit(Widget *widget, Group *data);
void DropdownDestroy(void *dropdown);
void DropdownDraw(void *dropdown);

#endif /*TOOLKIT_H_INCLUDED*/
