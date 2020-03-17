
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
#include "terminal.h"

// terminal original configuration
struct termios term_orig;
struct Screen screen;

// get terminal size
void getWindowSize(uint16_t *rows, uint16_t *cols) {
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws); 
    *cols = ws.ws_col;
    *rows = ws.ws_row; 
}

// set cursor position
void setCursor(std::string &s, int x, int y) {
    char buf[30]; 
    int a = sprintf(buf, "\x1b[%d;%df", y, x);
    buf[a] = '\0';
    s += buf;
}


// set character color
// search for ansi escape code for different color codes
void setColor(std::string &s, int color) {
    char buf[30]; 
    int a = sprintf(buf, "\x1b[%dm", color);
    buf[a] = '\0';
    s += buf;
}

/* disable terminal raw mode */
void disableTerminalRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term_orig);

    write(STDOUT_FILENO, "\x1b[?25h", 6);
}

void enableTerminalRawMode() {
    struct termios raw;

    /*
	this function will execute after
	programs exit due to any situation
    */
    atexit(disableTerminalRawMode); 

    /*
    if (tcgetattr(STDIN_FILENO, &E.orig_termios) == -1) 
	die("tcgetattr");
    */
    tcgetattr(STDIN_FILENO, &term_orig);

    raw = term_orig;
    
    /*
    When BRKINT is turned on, a break condition will cause a SIGINT signal to be sent to the program, like pressing Ctrl-C.
    INPCK enables parity checking, which doesn’t seem to apply to modern terminal emulators.
    ISTRIP causes the 8th bit of each input byte to be stripped, meaning it will set it to 0. This is probably already turned off.
    */

    // raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);

    /*
    // disable ctrl-m as new line
    // disable ctrl-s and ctrl-q
    raw.c_iflag &= ~(ICRNL| IXON);
    */

    /*
    // diable post processing of '\n' in to '\r\n'
    raw.c_oflag &= ~(OPOST);

    // set character size to 8 bit
    raw.c_cflag |= (CS8);

    */

    /*
    // how many bytes should read
    // before executing read function
    raw.c_cc[VMIN] = 0;

    // how much time should we waite
    // before executing read function
    raw.c_cc[VTIME] = 1;
    */

    // disable echo and canonical mode
    raw.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);

    /*
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
	die("tcsetattr");
    */
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

