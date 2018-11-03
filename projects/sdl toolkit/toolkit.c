#include "toolkit.h"

/*--Global--*/
Sint32 ToolkitInit()
{
    globalError.message = "";
    
    globalStack.items = 0;
    globalStack.stack = SDL_malloc(sizeof(Group));

    if (!globalStack.stack)
    {
        globalError.message = "Could not alloc resources.";
        return STK_FAILURE;
    }
    
    return STK_SUCCESS;
}

void RegisterWidget(void *widget)
{
    GroupAppend(globalStack.stack, widget);
    globalStack.items += 1;   
}

void GlobalHandle(SDL_Event *event)
{
    Widget *widget = NULL;
    if (event)
    {
        if (event->type == SDL_MOUSEBUTTONDOWN)
        {
            widget = GetWidgetXY(event->button.x, event->button.y);

            if (widget)
                widget->widgethandle(widget, event);
        }
    }
}

void ToolkitQuit()
{
    Group  *current = globalStack.mywidgets; 
    Widget *widget  = NULL;

    for(;;)
    {
        if (!current)
            return;
        
        widget = current->data;

        if (widget)
        {
            widget->widgetdestroy(widget->data);
            SDL_free(widget);
        }

        current = current->next;
    }
}

void *GetWidgetXY(Sint16 x, Sint16 y)
{
    Group  *current = globalStack.stack;
    Widget *widget  = NULL;

    for (;;)
    {
        if (!current)
            return NULL;
        
        widget = current->data;
            
        if (widget)
        {
            Sint16 x1 = widget->geometry->x;
            Sint16 x2 = x1 + widget->geometry->w;
            Sint16 y1 = widget->geometry->y;
            Sint16 y2 = y1 + widget->geometry->h;

            if ((x >= x1) && (x <= x2) && (y >= y1) && (y <= y2))
            {
               return widget;
            }
        }

        current = current->next;
    }
}

char *GetError()
{
    char *message = globalError.message;
    globalError.message = "";

    return message;
}

/****---Widget---****/

/*------Container------*/

void ContainerInit(Widget *widget, Group *group, Layout layout)
{
    Container *container = SDL_malloc(sizeof(Container));
    SDL_memset(container, 0, sizeof(Container));

    container->group  = group;
    container->layout = layout;
    
    widget->widget        = container;
    widget->widgetdestroy = ContainerDestroy;
    widget->widgetdraw    = ContainerDraw;
}

void ContainerDestroy(void *container)
{
    SDL_free(container);
}

/*------Button------*/

void ButtonInit(Widget *widget, const char *text, ButtonType type)
{
    ButtonData *buttondata = SDL_malloc(sizeof(ButtonData));
    SDL_memset(buttondata, 0, sizeof(ButtonData));

    buttondata->text = text;
    buttondata->type = type;

    widget->widget = buttondata;
    widget->widgetdestroy = ButtonDestroy;
    widget->widgetdraw    = ButtonDraw;
}

void ButtonDestroy(void *button)
{
    SDL_free(button);
}

/*------Label------*/

void LabelInit(Widget *widget, const char *text, LabelType type)
{
    LabelData *label = SDL_malloc(sizeof(LabelData));
    SDL_memset(label, 0, sizeof(LabelData));

    label->text = text;
    label->type = type;

    widget->widget = label;
    widget->widgetdestroy = LabelDestroy;
    widget->widgetdraw    = LabelDraw;
     
}

void LabelDestroy(void *label)
{
    SDL_free(label);
}

/*-----Slider------*/

void SliderInit(Widget *widget, Sint64 first, Sint64 last)
{
    SliderData *slider = SDL_malloc(sizeof(SliderData));
    SDL_memset(slider, 0, sizeof(SliderData));

    slider->first = first;
    slider->last  = last;

    widget->widget = slider;
    widget->widgetdestroy = SliderDestroy;
    widget->widgetdraw    = SliderDraw;
}

void SliderDestroy(void *slider)
{
    SDL_free(slider);
}

/*------Input-----*/
void InputNew(Widget *widget, SDL_bool multiline, SDL_bool mask)
{
    InputData *input = SDL_malloc(sizeof(InputData));
    SDL_memset(input, 0, sizeof(InputData));

    input->multiline = multiline;
    input->mask      = mask;

    widget->widget = input;
    widget->widgetdestroy = InputDestroy;
    widget->widgetdraw    = InputDraw;
}

void InputDestroy(void *input)
{
    SDL_free(input);
}

/*------ItemData------*/

void ItemDataInit(Widget *widget, Uint32 index, const char *text, void *data)
{
    ItemData *item = SDL_malloc(sizeof(ItemData));
    SDL_memset(item, 0, sizeof(ItemData));

    item->index = index;
    item->text  = text;
    item->data  = data;

    widget->widget = item;
    widget->widgetdestroy = ItemDataDestroy;
}

void ItemDataDestroy(void *itemdata)
{
    SDL_free(itemdata);
}

/*------Table------*/

void TableInit(Widget *widget, Uint32 columns, Uint32 rows, Group *data)
{
    TableData *table = SDL_malloc(sizeof(TableData));
    SDl_memset(table, 0, sizeof(TableData));

    table->columns = columns;
    table->rows    = rows;
    table->data    = data;

    widget->widget = table;
    widget->widgetdestroy = TableDestroy;
    widget->widgetdraw    = TableDraw;
}

void TableDestroy(void *table)
{
    SDL_free(table);
}

/*-----Dropdown------*/
void DropdownInit(Widget *widget, Group *data)
{
    DropdownData *drop = SDL_malloc(sizeof(DropdownData));
    SDL_memset(drop, 0, sizeof(DropdownData));

    drop->data = data;

    widget->widget = drop;
    widget->widgetdestroy = DropdownDestroy;
    widget->widgetdraw    = DropdownDraw;
}

void DropdownDestroy(void *dropdown)
{
    SDL_free(dropdown);
}
