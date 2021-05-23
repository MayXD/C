# 指令编译器和选项
CC = gcc
CFLAGS = -Wall -std=gnu99
 
# 目标文件
TARGET = hex.o

# 源文件
SRCS = hex_cclt.c hex_conversion.c
OBJS = vpath %.s %.o ./
  
all: 
	gcc $(SRCS) $(CFLAGS) -o $(TARGET)
	
.PHONY:clean
clean:
	-rm $($OBJS)
