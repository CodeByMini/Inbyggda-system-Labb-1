#ifndef SERIAL_H_
#define SERIAL_H_

#define MAX_COMMAND_SIZE 20

void uart_init();

void uart_putstr(char *);
void uart_echo();
void uart_get_command(char *command);

#endif