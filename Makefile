NAME = lem-in

FUNC = main ants rooms links parse dijkstra aux

C_LOC = src/
C_NAM = $(addsuffix .c, $(FUNC))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FUNC))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

LIB_LOC = ftprintf/
LIB_NAM = libftprintf.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

H_LOC = -I inc/ -I ftprintf/inc -I ftprintf/libft/inc
HEADERS = inc/*.h

all: $(NAME)

$(NAME): $(O_SRC) $(LIB_SRC)
	@/bin/echo -n "無駄"
	@gcc -Wall -Werror -Wextra $^ -o $(NAME)
	@/bin/echo -n "ァァ！」"
	@echo "\nそして、時は動き出す。"

$(O_LOC)%.o: $(C_LOC)%.c $(HEADERS)
	@/bin/echo -n "無駄"
	@gcc -Wall -Werror -Wextra $(H_LOC) -o $@ -c $<
	@/bin/echo -n "無駄"

$(LIB_SRC): force
	@make -C $(LIB_LOC)
	@echo
	@/bin/echo -n "「無駄だ！無駄"

force:
	@true

clean:
	@echo "ザ・ワールド！"
	@/bin/rm -f $(O_SRC)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_LOC)
	@echo "時よ止まれ！"

re: fclean all

.PHONY: all clean fclean re
