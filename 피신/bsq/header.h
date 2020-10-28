#ifndef __DF_HD__
#define __DF_HD__

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//tool.c
int ft_atoi(char *str);
int	ft_strlen(char *str);
char *cpy_str(char *a, char *b);

typedef struct {
	int x;
	int y;
	int max_x;
	int max_y;
	int max;
	int **map;
	char empty;
	char obst;
	char full;
} map_info;

// read_f.c
map_info set_map(int file, map_info info);
map_info file_to_struct(char *filename);
map_info set_info(char *str);
int get_x_len(int file);
char *get_info(char *file_name);

// scan_square.c
int	compare(int a, int b, int c);
void set_max(map_info *info, int i, int j);
void scan_square(map_info *info);

// print_res.c
void set_square(map_info *info);
void max_one(map_info *info);
void print_res(map_info *info);
#endif
