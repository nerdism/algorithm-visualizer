
#include <unistd.h>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <signal.h>
#include <terminal.h>

bool register_signal(int signum, void (*handler)(int)) {

    struct sigaction action = {0};

    action.sa_handler = handler;
    
    sigaction(signum, &action, NULL);
    return true;
}

void sigint_handler(int signum) {
    std::cout << "SIGINT Happend!" << std::endl;

    // turn off cursor display
    write(STDOUT_FILENO, "\x1b[?25h", 6);
    std::string out = "";
    setColor(out, FG_DEFAULT);
    exit(0);
}

