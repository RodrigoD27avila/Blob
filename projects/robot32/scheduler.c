#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "scheduler.h"
#include "action.h"

void scheduler_Init(struct Scheduler *sched)
{
	sched->head  = NULL;
	sched->tail  = NULL;
}

void scheduler_Clear(struct Scheduler *sched)
{
	struct Action *curr = sched->head;

	while (curr) {
		struct Action *next = curr->next;
		curr->next   = NULL;
		curr         = next;
	}
}

void scheduler_RegisterAction(struct Scheduler *sched, struct Action *action)
{
	if (sched->head == NULL) {
		sched->head = action;
		sched->tail = action;
	} else {
		sched->tail->next = action;
		sched->tail = action;
	}

}

void scheduler_RemoveAction(struct Scheduler *sched, struct Action *action)
{
	if (sched->head == action) {
		if (sched->head == sched->tail) {
			sched->tail = NULL;
			sched->head = NULL;
		} else {
			sched->head = sched->head->next;
		}

	} else {

		if (sched->tail == action) {
			struct Action *curr = sched->head;
			while (curr->next != sched->tail) {
				curr = curr->next;
			}
			curr->next  = NULL;
			sched->tail = curr;

		} else {

			struct Action *curr = sched->head;
			struct Action *next = curr->next;
			while (next != action) {
				curr = next;
				next = next->next;
			}

			curr->next = next->next;
		}
	}
}

void scheduler_Execute(struct Scheduler *sched)
{
	struct Action *curr = sched->head;
	while (curr) {
		action_Start(curr);
		action_Callback(curr);
		curr = curr->next;
	}

}
