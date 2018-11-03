#ifndef GROUP_H_INCLUDED
#define GROUP_H_INCLUDED 

#include <SDL/SDL.h>

typedef struct _Group
{
    void *next;
    void *data;

} Group;

typedef void (*IndexDestroyFunc)(void *data);

void  GroupAppend(Group *group, void *data);
void *GroupRemoveIndex(Group *group, Uint32 index);
void  GroupDestroyIndex(Group *group, Uint32 index, IndexDestroyFunc destroy);

#endif /*GROUP_H_INCLUDED*/

