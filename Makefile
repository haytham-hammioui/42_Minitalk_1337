# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 15:33:11 by hhammiou          #+#    #+#              #
#    Updated: 2025/03/01 13:53:10 by hhammiou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

NAMEC = client
NAMES = server
NAMEC_B = client_bonus
NAMES_B = server_bonus

CYAN = "\033[1;32m"
MAGENTA = "\033[1;35m"
GOLD = "\033[1;33m"
WHITE = "\033[1;37m"
RESET = "\033[0m"

SRCS = 		mandatory/mini_printf.c			\
			mandatory/help.c				\
		
SRCSB = 	bonus/mini_printf_bonus.c		\
			bonus/help_bonus.c				\
			
SRCS1 = mandatory/server.c
SRCS2 = mandatory/client.c
SRCSB1 = bonus/server_bonus.c
SRCSB2 = bonus/client_bonus.c

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
OBJSB1 = $(SRCSB1:.c=.o)
OBJSB2 = $(SRCSB2:.c=.o)

all: $(NAME)

$(NAME): server client

server: $(OBJS1) $(OBJS) mandatory/header.h
	@$(CC) $(CFLAGS) $(OBJS1) $(OBJS) -o $(NAMES)
	@echo $(MAGENTA)"Minitalk Server"$(RESET)"                     "$(CYAN)"[Active]"$(RESET)


client: $(OBJS2) $(OBJS) mandatory/header.h
	@$(CC) $(CFLAGS) $(OBJS2) $(OBJS) -o $(NAMEC)
	@echo $(MAGENTA)"Minitalk Client"$(RESET)"                     "$(CYAN)"[Active]"$(RESET)
	@echo $(CYAN)"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"$(RESET)
	@echo $(GOLD)"To start:"$(RESET)
	@echo $(WHITE)"  ➜ Run: "$(CYAN)"./server"$(RESET)
	@echo $(WHITE)"  ➜ Then use: "$(CYAN)"./client <PID> <message>"$(RESET)
	@echo $(CYAN)"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"$(RESET)
	@echo $(WHITE)"     	            by: hhammiou42 [ESBG 💜]"$(RESET)

bonus: server_bonus client_bonus

server_bonus: $(OBJSB1) $(OBJSB) bonus/header_bonus.h
	@$(CC) $(CFLAGS) $(OBJSB1) $(OBJSB) -o $(NAMES_B)
	@echo $(MAGENTA)"Minitalk Bonus Server"$(RESET)"                     "$(CYAN)"[Active]"$(RESET)

client_bonus: $(OBJSB2) $(OBJSB) bonus/header_bonus.h
	@$(CC) $(CFLAGS) $(OBJSB2) $(OBJSB) -o $(NAMEC_B)
	@echo $(MAGENTA)"Minitalk Bonus Client"$(RESET)"                     "$(CYAN)"[Active]"$(RESET)
	@echo $(CYAN)"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"$(RESET)
	@echo $(GOLD)"To start:"$(RESET)
	@echo $(WHITE)"  ➜ Run: "$(CYAN)"./server_bonus"$(RESET)
	@echo $(WHITE)"  ➜ Then use: "$(CYAN)"./client_bonus <PID> <message>"$(RESET)
	@echo $(CYAN)"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"$(RESET)
	@echo $(WHITE)"     	                  by: hhammiou42 [ESBG 💜]"$(RESET)

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(OBJSB) $(OBJS1) $(OBJS2) $(OBJSB1) $(OBJSB2)
	@echo $(CYAN)"Object files removed"$(RESET)

fclean: clean
	@rm -f $(NAMEC) $(NAMES) $(NAMEC_B) $(NAMES_B)
	@echo $(GOLD)"Minitalk Executables Removed"$(RESET)

re: fclean all

.PHONY: clean
