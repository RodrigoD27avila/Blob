#include <stdio.h>

void foo(a,b,c)
int a; float b; double c;
{ }

struct pt_regs {
        long restart_r0;        /* R0 checkpoint for syscall restart */
        long syscall_nr;        /* Only used in system calls */
        union {
                struct {
                        unsigned long usr;
                        unsigned long preds;
                };
                long long int predsusr;
        };
        union {
                struct {
                        unsigned long m0;
                        unsigned long m1;
                };
                long long int m1m0;
        };
};

int main()
{
	struct pt_regs regs;
	regs.usr = 10;
	printf("%lu\n", regs.usr);
	return 0;
}
