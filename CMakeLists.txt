cmake_minimum_required(VERSION 3.8)
project(liblab)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES
		liblab.c
		strutils.c
		number.c
		liblab.h linked_list.c linked_list.h lexer.c lexer.h algo.c algo.h strutils.h
		bits.c bits.h tree.c tree.h matrix.c matrix.h number.h)
add_library(liblab ${SOURCE_FILES})