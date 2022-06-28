# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdenna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 04:11:54 by mabdenna          #+#    #+#              #
#    Updated: 2022/06/25 04:11:58 by mabdenna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = minitalk.h

CSRC = client.c
CSRC_OBJ = ${CSRC:.c=.o}

SSRC = server.c
SSRC_OBJ = ${SSRC:.c=.o}

CNAME = client

SNAME = server

all: $(CNAME) $(SNAME)

$(CNAME): $(CSRC_OBJ) $(INC)
		$(CC) $(CFLAGS) $(CSRC_OBJ) -o $(CNAME)
$(SNAME): $(SSRC_OBJ) $(INC)
		$(CC) $(CFLAGS) $(SSRC_OBJ) -o $(SNAME)

clean:
	@rm -rf $(SSRC_OBJ) $(CSRC_OBJ)

fclean: clean
	@rm -rf $(CNAME) $(SNAME)

re: fclean all
