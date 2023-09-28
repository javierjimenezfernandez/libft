# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 12:30:20 by javjimen          #+#    #+#              #
#    Updated: 2023/09/28 15:46:25 by javjimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project and the executable after build
NAME 		= libft.a

# List of source files
PART_1		= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_strlen.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c

PART_2		= 

SRCS 		= $(PART_1) $(PART_2)

# Building directory
BUILD_DIR	= build

# List of object files
OBJS 		= $(SRCS:%.c=$(BUILD_DIR)/%.o)

# LList of dependent files
DEPS 		= $(OBJS:.o=.d)

# List of header files
INCLUDE 	= libft.h

# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror
CPPFLAGS	+= -MMD -MP -I
ARFLAGS		= -r -c -s

SANITIZE	= -fsanitize=address


# Make rules
all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDE) -c -o $@ $<

-include $(DEPS)

sanitize:	$(OBJS)
			$(CC) $(OBJS) $(SANITIZE) -o $(NAME) 

clean:
			$(RM) $(OBJS) $(DEPS)

fclean: 	clean
			$(RM) $(NAME)

re:			 fclean all

.PHONY:		 all clean fclean re

#.SILENT:

