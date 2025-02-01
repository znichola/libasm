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

C_FLAGS = -Wall -Werror -Wextra -fsanitize=address

all: $(NAME)
	
obj/%.o : src/%.s obj
	nasm -f elf64 -o $@ $<

$(NAME): $(OBJ_FILES)
	ar rc $(NAME) $(OBJ_FILES)

clean:
	-rm -r $(NAME) obj tst 

re : clean $(NAME)

tst: $(NAME) test/main.c
	gcc $(C_FLAGS) -I. test/main.c -L. -lasm -o tst

obj:
	mkdir obj

