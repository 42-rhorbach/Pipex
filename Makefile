# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rhorbach <rhorbach@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/14 12:49:02 by rhorbach      #+#    #+#                  #
#    Updated: 2023/01/25 16:12:17 by rhorbach      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADERFILES = ./libft/libft.h ./src/ft_printf.h ./src/ft_conv.h
NORMFLAGS = -Wall -Wextra -Werror $(if $(DEBUG),-g -fsanitize=address)
INCLUDES = $(addprefix -I, $(sort $(dir $(HEADERFILES))))
OBJDIR = obj
FILES = \
	./src/ft_printf.c		\
	./src/ft_conv_txt.c		\
	./src/ft_conv_num.c
OBJFILES = $(addprefix $(OBJDIR)/,$(FILES:c=o))

LIBFT = ./libft/libft.a

clear_line = \e[K
move_up = \e[A
define prettycomp
printf "$(1)$(clear_line)\n"
$(1)
printf "$(move_up)"
endef

all: $(NAME)

$(NAME): $(OBJFILES) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJFILES)

$(LIBFT):
	@$(MAKE) -C $(dir $(LIBFT))

$(OBJDIR)/%.o: %.c $(HEADERFILES)
	@mkdir -p $(dir $@)
	@$(call prettycomp,$(CC) -c $(NORMFLAGS) $(INCLUDES) $< -o $@)

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(dir $(LIBFT)) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(dir $(LIBFT)) fclean

re: fclean all

bonus:
	$(MAKE) all BONUS=1


ifdef DEBUG
test: $(NAME)
	$(CC) $(NORMFLAGS) main.c -L. -l ftprintf -o DEBUG_ft_printf
else
test:
	$(MAKE) test DEBUG=1
endif

.PHONY: all clean fcleam re test bonus
