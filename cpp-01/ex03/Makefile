NAME = ex03

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98


OBJDIR = obj


SRCS = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp


OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))


all: $(NAME)


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)


$(OBJDIR)/%.o: %.cpp  $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


$(OBJDIR):
	mkdir -p $(OBJDIR)


clean:
	rm -rf $(OBJDIR)


fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
