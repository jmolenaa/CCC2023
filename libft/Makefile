NAME = libft.a
SRC_FILES_LIBFT =	is/ft_isalpha.c is/ft_isdigit.c is/ft_isalnum.c is/ft_isascii.c is/ft_isprint.c\
					str/ft_strlen.c str/ft_strchr.c str/ft_strrchr.c str/ft_strncmp.c str/ft_strnstr.c str/ft_atoi.c\
					chnstr/ft_strlcpy.c chnstr/ft_strlcat.c chnstr/ft_toupper.c chnstr/ft_tolower.c chnstr/ft_striteri.c\
					mem/ft_bzero.c mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c mem/ft_memchr.c mem/ft_memcmp.c\
					crtstr/ft_calloc.c crtstr/ft_strdup.c crtstr/ft_substr.c crtstr/ft_strjoin.c crtstr/ft_strtrim.c crtstr/ft_split.c crtstr/ft_itoa.c crtstr/ft_strmapi.c\
					fd/ft_putchar_fd.c fd/ft_putstr_fd.c fd/ft_putendl_fd.c fd/ft_putnbr_fd.c\
					lst/ft_lstnew_bonus.c lst/ft_lstadd_front_bonus.c lst/ft_lstsize_bonus.c lst/ft_lstlast_bonus.c lst/ft_lstadd_back_bonus.c lst/ft_lstdelone_bonus.c lst/ft_lstclear_bonus.c lst/ft_lstiter_bonus.c lst/ft_lstmap_bonus.c
SRC_FILES_GNL =		get_next_line.c get_next_line_utils.c
SRC_FILES_PRINTF =	char_conversion.c decimal_conversion.c flag_functions.c flag_validate.c ft_printf.c helper_functions.c\
					hexa_conversion.c percent_conversion.c pointer_conversion.c string_conversion.c unsigned_conversion.c validation.c
SRC_FILES_OTHER =	ft_exit_with_error.c ft_print_binary.c
OBJFILES = $(SRC_FILES_LIBFT:%.c=obj/libft/%.o) $(SRC_FILES_GNL:%.c=obj/get_next_line/%.o) $(SRC_FILES_PRINTF:%.c=obj/printf/%.o) $(SRC_FILES_OTHER:%.c=obj/other/%.o)
OBJDIR = obj
DIRECTORIES = obj obj/libft obj/libft/is obj/libft/str obj/libft/chnstr/ obj/libft/mem obj/libft/crtstr/ obj/libft/fd obj/libft/lst obj/get_next_line obj/printf obj/other
CC = cc
LIGHTGREEN=\033[1;92m
EXIT=\033[0m
DIM=\033[2m
YELLOW=\033[1;33m
CFLAGS = -Wall -Wextra -Werror
ifdef DEBUG
CFLAGS += -g -fsanitize=address
endif

all: $(NAME)

$(NAME): $(OBJFILES)
	@ar -csr $@ $^

obj/%.o: src/%.c $(OBJDIR)
	@$(CC) -iquote includes -c $(CFLAGS) -o $@ $<

$(OBJDIR):
	@echo "\n ${LIGHTGREEN}|C|o|m|p|i|l|i|n|g|  |l|i|b|f|t|${EXIT}\n";
	@mkdir $(DIRECTORIES)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\n $(YELLOW) |D|e|l|e|t|i|n|g|  |l|i|b|f|t|$(EXIT)\n";
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all

debug: fclean
	$(MAKE) DEBUG=1 all

.PHONY: all fclean clean re
