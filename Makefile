PS = push_swap
CHECKER = checker
CTR = counter
SORT = sort_list
RULES_TESTER = rules_tester

BONUS = bonus/push_swap_bonus.c bonus/push_swap_translator_bonus.c \
		bonus/push_swap_rules_bonus.c bonus/push_swap_rules2_bonus.c

UTILS = push_swap_list_index.c push_swap_list_utils.c\
		push_swap_parsing.c push_swap_viewer.c sort_list.c

RULES = push_swap_rules.c push_swap_rules2.c \

TURKISH = push_swap_algo.c \
		push_swap_turkish.c push_swap_turkish_find_target.c \
		push_swap_turkish_calc_moves.c \
		push_swap_turkish_info.c push_swap_turkish_exec_moves.c\

SRCS =  $(UTILS:%=utils/%) $(TURKISH:%=algo/%)

LIBFT_MAKE = make --no-print-directory -C libft
LIBFT = libft.a
CC = cc -Wall -Wextra -Werror

all: $(LIBFT) $(PS) $(CTR) $(SORT) $(CHECKER) $(RULES_TESTER)

clean:
	@echo "Deleting..."
	@$(LIBFT_MAKE) clean
	@echo "rm *.o"

fclean: clean
	@$(LIBFT_MAKE) fclean
	rm -rf $(PS) $(LIBFT) $(CTR) $(CHECKER) $(SORT)

re: fclean all

bonus: fclean all $(CHECKER)

$(CTR): pgm/push_swap_instructions_ctr.c $(SRCS) $(LIBFT)
	$(CC) -o $(CTR) pgm/push_swap_instructions_ctr.c $(SRCS) $(RULES:%=utils/%) $(LIBFT)

$(CHECKER): $(BONUS) $(SRCS) $(LIBFT)
	$(CC) -o $(CHECKER) $(BONUS) $(SRCS) $(LIBFT)

$(SORT): pgm/$(SORT)_tester.c $(SRCS) $(LIBFT)
	$(CC) -o $(SORT) pgm/$(SORT)_tester.c $(SRCS) $(RULES:%=utils/%) $(LIBFT) -I../

$(LIBFT):
	@$(LIBFT_MAKE) all
	@cp libft/$(LIBFT) .

$(PS): $(PS).c $(SRCS) $(LIBFT)
	$(CC) -o $(PS) $(PS).c $(SRCS) $(RULES:%=utils/%) $(LIBFT)

$(RULES_TESTER): pgm/push_swap_rules_tester.c $(SRCS) $(LIBFT)
	$(CC) -o $(RULES_TESTER) pgm/push_swap_rules_tester.c $(SRCS) $(RULES:%=utils/%) $(LIBFT)

#.PHONY POUR LES RULES
.PHONY: clean fclean re all bonus
