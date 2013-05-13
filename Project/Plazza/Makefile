##
## Makefile for Plazza V2 in /home/guiho_f//Projet/Plazza/plazza/Project/Plazza
## 
## Made by florian guiho
## Login   <guiho_f@epitech.net>
## 
## Started on  Mon May 13 22:04:04 2013 florian guiho
## Last update Mon May 13 22:11:40 2013 florian guiho
##

NAME		=	plazza

INC_DIR		= ./inc/

INC		= $(wildcard $(INC_DIR)*.hpp)

INC_UNIX_DIR	= ./inc/Unix/

INC_UNIX	= $(wildcard $(INC_UNIX_DIR)*.hpp)

SRC_DIR		= ./src/

SRC		= $(wildcard $(SRC_DIR)*.cpp)

SRC_UNIX_DIR	= ./src/Unix/

SRC_UNIX	= $(wildcard $(SRC_UNIX_DIR)*.cpp)

OBJ_DIR		= ./obj/

OBJ		= 	$(SRC:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)

OBJ_UNIX_DIR	= ./obj/Unix/

OBJ_UNIX	= 	$(SRC_UNIX:$(SRC_UNIX_DIR)%.cpp=$(OBJ_UNIX_DIR)%.o)

CC=		g++

RM=		rm -f

FLAGS		= -I./inc/ -I./inc/Unix/

CDFLAG		+= -W -Wall -Wextra

$(NAME):	$(OBJ) $(OBJ_UNIX)
	$(CC) $(OBJ) $(OBJ_UNIX) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.cpp $(INC) $(INC_UNIX_DIR)
	$(CC) -c -o $@ $< $(FLAGS) $(CDFLAG) 

$(OBJ_UNIX_DIR)%.o:	$(SRC_UNIX_DIR)%.cpp $(INC) $(INC_UNIX_DIR)
	$(CC) -c -o $@ $< $(FLAGS) $(CDFLAG)


all:	$(NAME)

clean:
	@$(RM) $(OBJ) $(OBJ_UNIX)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean \
	all