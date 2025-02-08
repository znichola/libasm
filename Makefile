NAME = libasm.a

SRC_FILES =                 \
			src/ft_read.s   \
			src/ft_strcmp.s \
			src/ft_strcpy.s \
			src/ft_strdup.s \
			src/ft_strlen.s \
			src/ft_write.s

OBJ_FILES =                 \
			obj/ft_read.o   \
			obj/ft_strcmp.o \
			obj/ft_strcpy.o \
			obj/ft_strdup.o \
			obj/ft_strlen.o \
			obj/ft_write.o

C_FLAGS = -Wall -Werror -Wextra # -g3 #-fsanitize=address

all: $(NAME) Makefile
	
obj/%.o : src/%.s
	@mkdir -p obj
	nasm -f elf64 -o $@ $<

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

clean:
	-rm -r obj test/main.o 

fclean : clean
	rm $(NAME) tst

re : fclean $(NAME)

test/main.o : test/main.c
	gcc $(C_FLAGS) -I. -c $< -o $@

tst: $(NAME) test/main.o
	gcc $(C_FLAGS) test/main.o -L. -lasm -o tst

t: tst
	./tst

obj:
	mkdir obj

.PHONY: all clean re t 
