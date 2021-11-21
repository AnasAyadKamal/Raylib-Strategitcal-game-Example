cc p.c -g -std=c99 -c -I /opt/raylib/src -o p.o
cc p.o -s -Wall -std=c99 -I/opt/raylib/src -L/opt/raylib/release/libs/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
