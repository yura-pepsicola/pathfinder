#include "../libmx/inc/libmx.h"
#include <limits.h>

int main(int argc, char *argv[]);

typedef struct node_s {
    char *name;
    int price;
} node_t;

typedef struct bridge_s {
    node_t *next;
    int price;
    node_t *prev;
} bridge_t;

//error check
void mx_sys_error(const char* str);
void mx_check_cmd_args(int argc);
void mx_check_no_file(int fd, char* file_name);
void mx_check_empty_file(char *file_name);
bool mx_isdigit(int c);
bool mx_isnumber(char *line);
int mx_atoi(char *str);
void mx_check_first_line(char *line);
bool mx_isletter(int c);
void mx_check_lines(char **lines);
bool mx_check_duplicates(bridge_t *bridges, int bridge_count);
void mx_check_bridge_len(char **lines);
bool mx_check_limits(bridge_t *bridges, int bridge_count);

//parsing
int mx_count_bridges(char **array);
void mx_bridges_init(bridge_t *bridges, int bridge_count);
int mx_add_node(node_t *nodes, char *node, int node_count);
void mx_nodes_init(node_t *nodes, int node_count);
void mx_file_parse(node_t *nodes, char **array, int node_count, bridge_t *bridges, int bridge_count);

//pathfinder
void mx_pathfinder(node_t *nodes, int node_count, bridge_t *bridges, int bridge_count);

//list
t_list *mx_list_copy(t_list *list);
void mx_list_clear(t_list **list);

//output
void mx_paths_output(t_list *path);
void mx_rec_print(node_t *nodes, bridge_t *bridges, t_list *prev_path, node_t *last, int sum, int bridge_count);
