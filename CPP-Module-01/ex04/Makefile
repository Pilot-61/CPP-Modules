NAME = replace
SRCS = main.cpp StoreData.cpp
HEADERS = StoreData.hpp
OBJS = $(SRCS:.cpp=.o)
C = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(CFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(C) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re