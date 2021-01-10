########################################################################
####################### Makefile Template ##############################
# target:dependency
# <tab> command
########################################################################
main: main.o
	g++ -c main.cpp -I/Development/RPG/3rdparty/SFML-2.5.1/include -L/Development/RPG/3rdparty/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system



# Compiler settings - Can be customized.
# CC = g++
# CXXFLAGS = -std=c++11 -Wall
# LDFLAGS = 

# # Makefile settings - Can be customized.
# APPNAME = Game1
# EXT = .cpp
# SRCDIR = /Development/RPG
# OBJDIR = obj

# BIN := bin
# SRC := src
# # INCLUDE := include
# INCLUDE := /Development/RPG/3rdparty/SFML-2.5.1/include

# LIBRARIES := -lsfml-graphics -lsfml-window -lsfml-system

