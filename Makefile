# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iomayr <iomayr@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 10:27:37 by iomayr            #+#    #+#              #
#    Updated: 2022/02/07 11:50:34 by iomayr           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
PRINTF = ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = ft_utiles.c
OBJ = ${SRC:%.c=%.o}
SRCB = ft_utiles_bonus.c
OBJB = ${SRCB:%.c=%.o}

NAME = minitalk.a
NAMEB = minitalk_bonus.a

all : ${NAME} server client 

bonus: ${NAMEB} server_bonus client_bonus

${NAME}: minitalk.h ${OBJ}
	make -C ft_printf
	ar -rc ${NAME} ${OBJ}

${NAMEB}: minitalk_bonus.h ${OBJB}
	make -C ft_printf
	ar -rc ${NAMEB} ${OBJB}

client: ft_client.c
	${CC} ${CFLAGS} ft_client.c -o client ${PRINTF} ${NAME}

server: ft_server.c
	${CC} ${CFLAGS} ft_server.c -o server ${PRINTF} ${NAME}

client_bonus:ft_client_bonus.c 
	${CC} ${CFLAGS} ft_client_bonus.c -o client_bonus ${PRINTF} ${NAMEB}
	
server_bonus:ft_server_bonus.c
	${CC} ${CFLAGS} ft_server_bonus.c -o server_bonus ${PRINTF} ${NAMEB}

clean:
	make fclean -C ft_printf
	
fclean:clean
	rm -f ${NAME} ${OBJ}
	rm -f ${NAMEB} ${OBJB}
	rm server_bonus client_bonus server client
re: fclean all