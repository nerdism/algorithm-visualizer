#ifndef VSIGNAL_H
#define VSIGNAL_H

bool register_signal	(int signum, void (*handler)(int));

/**
 * signal intrrupt (CTRL + c) function handler
 */
void sigint_handler	(int signum);
    

#endif

