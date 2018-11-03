#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED

struct Action;

struct Scheduler {
	struct Action *head;
	struct Action *tail;
};

void scheduler_Init(struct Scheduler *sched);
void scheduler_Clear(struct Scheduler *sched);

void scheduler_RegisterAction(struct Scheduler *sched, struct Action *action);
void scheduler_RemoveAction(struct Scheduler *sched, struct Action *action);

void scheduler_Execute(struct Scheduler *sched);

#endif // SCHEDULER_H_INCLUDED
