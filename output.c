#include "output.h"

#ifdef _WIN32
#include <windows.h>
#include <termios.h>
#include <sys/ioctl.h>

size_t output_console_width(){
	struct winsize size;
	ioctl(STDIN_FILEINFO, TIOCGWINSZ, (char*) &size);
	return size.ws_col;
}

size_t output_console_height(){
	struct winsize size;
	ioctl(STDIN_FILEINFO, TIOCGWINSZ, (char*) &size);
	return size.ws_row;
}
#else
#include <sys/ioctl.h>

size_t output_console_width(){
	struct winsize size;
	ioctl(0, TIOCGWINSZ, (void*) &size);
	return size.ws_col;
}

size_t output_console_height(){
	struct winsize size;
	ioctl(0, TIOCGWINSZ, (char*) &size);
	return size.ws_row;
}
#endif