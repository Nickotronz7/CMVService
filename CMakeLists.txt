cmake_minimum_required(VERSION 3.17)
project(CMVService C)

set(CMAKE_C_STANDARD 99)

add_executable(CMVService server/main.c server/source/cJSON.c server/source/httpd.c server/header/cJSON.h server/header/httpd.h server/header/tools.h server/source/tools.c)