NAME = libft.a

CC = cc
FLAGS = -Werror -Wextra -Wall 

# SRCS
LIBFT_SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c \
			ft_striteri.c ft_strmapi.c ft_strtrim.c ft_split.c \
			ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c 

PRINTF_SRCS = ft_check.c ft_printf.c ft_putnbr_base.c tools.c 

GNL_SRCS = get_next_line.c get_next_line_utils.c

# DIR
SRC_DIR = src/
INCL_DIR = include/
OBJS_DIR = .obj/
LIBFT_DIR = $(SRC_DIR)libft/
PRINTF_DIR = $(SRC_DIR)printf/
GNL_DIR = $(SRC_DIR)get_next_line/

# OBJS
LIBFT_OBJS = $(OBJS_DIR)libft/
PRINTF_OBJS = $(OBJS_DIR)printf/
GNL_OBJS = $(OBJS_DIR)get_next_line/

HEADER = $(addprefix $(INCL_DIR), libft.h get_next_line.h ft_printf.h)
LIBFT = $(addprefix $(LIBFT_OBJS), $(LIBFT_SRCS:.c=.o))
PRINTF = $(addprefix $(PRINTF_OBJS), $(PRINTF_SRCS:.c=.o))
GNL = $(addprefix $(GNL_OBJS), $(GNL_SRCS:.c=.o))

.SILENT:

all:
	@echo -n "$(Red)Compilation en cours .${NC}" 
	@mkdir -p $(OBJS_DIR) $(LIBFT_OBJS) $(PRINTF_OBJS) $(GNL_OBJS) && sleep 0.2
	@echo -n "$(Purple)\rCompilation en cours ..${NC}" 
	@$(MAKE) $(NAME) && sleep 0.1
	@echo -n "$(Blue)\rCompilation en cours ...${NC}" && sleep 0.5
	@echo "$(Green)\r------Compilation finie !-------${NC}"

$(NAME): $(LIBFT) $(PRINTF) $(GNL)
	ar -rc $@ $^

$(LIBFT_OBJS)%.o: $(LIBFT_DIR)%.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(PRINTF_OBJS)%.o: $(PRINTF_DIR)%.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

$(GNL_OBJS)%.o: $(GNL_DIR)%.c $(HEADER) Makefile
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo -n "$(Red).o en cours de suppression ...${NC}"
	@rm -rf $(OBJS_DIR) && sleep 0.2
	@echo "$(Green)\r---------.o supprime !----------${NC}"

fclean: clean
	@echo -n "$(Red).a en cours de suppression...${NC}"
	rm -f $(NAME) && sleep 0.2
	@echo "$(Green)\r---------.a supprime !----------${NC}"

re: fclean all

.PHONY: all clean fclean re

# COLORS =======================================================================

# Reset
NC=\033[0m

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Bold
BBlack=\033[1;30m
BRed=\033[1;31m
BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPurple=\033[1;35m
BCyan=\033[1;36m
BWhite=\033[1;37m

# Underline
UBlack=\033[4;30m
URed=\033[4;31m
UGreen=\033[4;32m
UYellow=\033[4;33m
UBlue=\033[4;34m
UPurple=\033[4;35m
UCyan=\033[4;36m
UWhite=\033[4;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

# High Intensity
IBlack=\033[0;90m
IRed=\033[0;91m
IGreen=\033[0;92m
IYellow=\033[0;93m
IBlue=\033[0;94m
IPurple=\033[0;95m
ICyan=\033[0;96m
IWhite=\033[0;97m

# Bold High Intensity
BIBlack=\033[1;90m
BIRed=\033[1;91m
BIGreen=\033[1;92m
BIYellow=\033[1;93m
BIBlue=\033[1;94m
BIPurple=\033[1;95m
BICyan=\033[1;96m
BIWhite=\033[1;97m

# High Intensity backgrounds
On_IBlack=\033[0;100m
On_IRed=\033[0;101m
On_IGreen=\033[0;102m
On_IYellow=\033[0;103m
On_IBlue=\033[0;104m
On_IPurple=\033[0;105m
On_ICyan=\033[0;106m
On_IWhite=\033[0;107m
