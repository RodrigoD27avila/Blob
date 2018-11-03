#include "group.h"

void GroupAppend(Group *group, void *data)
{
    if (!group->data)
        group->data = data;
    
    else
    {
        Group *current  = group->next; 
        for (;;)
        {
            if (!current)
            {
                Group *newgroup = SDL_malloc(sizeof(Group));
                SDL_memset(newgroup, 0, sizeof(Group));

                newgroup->data = data;
                current->next = newgroup;
                break;
            }

            current = current->next;
        }
    }
}

void *GroupRemove(Group *group, Uint32 index)
{
    int i = 0;
    Group *current = group;
    for (;;)
    {
        if (!current)
            return NULL;

        if (i == index)
        {
            void *data = current->data;
            current->data = NULL;

            return data;
        }
        current = current->next; 
    }
     
}

void GroupDestroyIndex(Group *group, Uint32 index, IndexDestroyFunc destroy)
{
    void *data = GroupRemoveIndex(group, index);
    destroy(data);
}
