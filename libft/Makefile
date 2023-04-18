# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rhorbach <rhorbach@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 12:49:02 by rhorbach      #+#    #+#                  #
#    Updated: 2022/11/01 16:32:15 by rhorbach      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADERFILES = libft.h
NORMFLAGS = -Wall -Wextra -Werror $(if $(DEBUG),-g -fsanitize=address)
OBJDIR = obj
CFILES =						\
	ft_atoi.c					\
	ft_bzero.c					\
	ft_calloc.c					\
	ft_isalnum.c				\
	ft_isalpha.c				\
	ft_isascii.c				\
	ft_isdigit.c				\
	ft_isprint.c				\
	ft_itoa.c					\
	ft_memchr.c					\
	ft_memcmp.c					\
	ft_memcpy.c					\
	ft_memmove.c				\
	ft_memset.c					\
	ft_putchar_fd.c				\
	ft_putendl_fd.c				\
	ft_putnbr_fd.c				\
	ft_putstr_fd.c				\
	ft_split.c					\
	ft_strchr.c					\
	ft_strdup.c					\
	ft_striteri.c				\
	ft_strjoin.c				\
	ft_strlcat.c				\
	ft_strlcpy.c				\
	ft_strlen.c					\
	ft_strmapi.c				\
	ft_strncmp.c				\
	ft_strnstr.c				\
	ft_strrchr.c				\
	ft_strtrim.c				\
	ft_substr.c					\
	ft_tolower.c				\
	ft_toupper.c

# BONUSFILES =					\
# 	ft_lstnew.c					\
# 	ft_lstsize.c				\
# 	ft_lstadd_front.c			\
# 	ft_lstlast.c				\
# 	ft_lstadd_back.c			\
#	ft_lstdelone.c				\
#	ft_lstclear.c

BONUSFILES =						\
	ft_lstnew_bonus.c				\
	ft_lstsize_bonus.c				\
	ft_lstadd_front_bonus.c			\
	ft_lstlast_bonus.c				\
	ft_lstadd_back_bonus.c			\
	ft_lstdelone_bonus.c			\
	ft_lstclear_bonus.c				\
	ft_lstiter_bonus.c				\
	ft_lstmap_bonus.c

ifdef BONUS
CFILES += $(BONUSFILES)
endif

OBJFILES = $(addprefix $(OBJDIR)/,$(CFILES:c=o))

all: $(NAME)

$(NAME): $(OBJFILES)
	ar -rcs libft.a $(OBJFILES)

obj/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	$(CC) -c $(NORMFLAGS) -o $@ $<

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	$(MAKE) all BONUS=1


ifdef DEBUG
test: $(NAME)
	gcc $(NORMFLAGS) main.c -L. -lft -o test_libft
else
test:
	$(MAKE) test DEBUG=1
endif

.PHONY: all clean fcleam re test bonus
