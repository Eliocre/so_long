
NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lXext -lX11

SRC_DIR = src/
MLBX_DIR = $(SRC_DIR)minilibx-linux/
LIBFT_DIR = $(SRC_DIR)libft/
SO_LONG_DIR = $(SRC_DIR)so_long/

SRCS = oui.c utils.c img_manager.c sprite_manager.c error_manager.c \

HEADERS = ./include/so_long.h ./libft/include/libft.h ./libft/include/printf.h \
		./libft/include/get_next_line_bonus.h \

OBJS = $(addprefix $(SO_LONG_DIR), $(SRCS:.c=.o))

.SILENT : 

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(Red)Compilation de libft ...${NC}" 
	$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "$(Red)Compilation de minilibx ...${NC}" 
	$(MAKE) --no-print-directory -C $(MLBX_DIR)
	@echo -n "$(Red)Compilation de so_long ...${NC}"
	$(CC) $^ $(XFLAGS) $(CFLAGS) $(LIBFT_DIR)libft.a $(MLBX_DIR)libmlx.a -o $(NAME) && sleep 0.1
	@echo "$(Green)\r-----Compilation finie-----${NC}" 

%.o : %.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	cd  $(MLBX_DIR) && $(MAKE) --no-print-directory clean
	cd $(LIBFT_DIR) && $(MAKE) --no-print-directory clean
	rm -rf $(OBJS)

fclean :
	cd $(MLBX_DIR) && $(MAKE) --no-print-directory clean
	cd $(LIBFT_DIR) && $(MAKE) --no-print-directory fclean
	rm -rf $(OBJS) $(NAME)

re : fclean all

.PHONY : all clean fclean re

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
