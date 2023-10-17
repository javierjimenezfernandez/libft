# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: javjimen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 12:30:20 by javjimen          #+#    #+#              #
#    Updated: 2023/10/18 00:43:14 by javjimen         ###   ########.fr        #
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

PART_2		= ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c

SRCS 		= $(PART_1) $(PART_2)

BONUS_SRCS	= ft_lstnew_bonus.c \
			  ft_lstadd_front_bonus.c \
			  ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c \
			  ft_lstadd_back_bonus.c \
			  ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c \
			  ft_lstiter_bonus.c \
			  ft_lstmap_bonus.c

# Building directory
BUILD_DIR	= build

# List of object files
OBJS 		= $(SRCS:%.c=$(BUILD_DIR)/%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=$(BUILD_DIR)/%.o)

# List of dependent files
DEPS 		= $(OBJS:.o=.d)
BONUS_DEPS	= $(BONUS_OBJS:.o=.d)

# List of header files
#INCLUDE 	= libft.h

# Compilation flags
CC			= cc
RM			= rm -rf
AR			= ar
DIR_DUP		= mkdir -p $(@D)

CFLAGS 		+= -Wall -Wextra -Werror
CPPFLAGS	+= -MMD -MP -I.
ARFLAGS		= -r -c -s

SANITIZE	= -fsanitize=address

# Rule name protection
.PHONY:		all clean fclean re bonus

# Make rules
all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)/%.o: %.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS) $(BONUS_DEPS)

sanitize:	$(OBJS)
			$(CC) $(OBJS) $(SANITIZE) -o $(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS)

fclean: 	clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(NAME) $(BONUS_OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(BONUS_OBJS)

so:
			$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS_SRCS)
			gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

#.SILENT:

