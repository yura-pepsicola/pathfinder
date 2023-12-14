#include "pathfinder.h"

int main(int argc, char *argv[]) {
    mx_check_cmd_args(argc);
    char *file_name = argv[1];
    int fd = open(file_name, O_RDONLY);
    mx_check_no_file(fd, file_name);
    mx_check_empty_file(file_name);
    char *str = mx_file_to_str(file_name);
    close(fd);
    char **array = mx_strsplit(str, '\n');
    mx_check_first_line(array[0]);
    mx_check_lines(array);
    mx_check_duplicates(array);
    int node_count = mx_atoi(array[0]); 
    node_t nodes[node_count];
    int bridge_count = mx_count_bridges(array);
    bridge_t bridges[bridge_count];
    mx_file_parse(nodes, array, node_count, bridges, bridge_count);
    mx_del_strarr(&array);
    mx_pathfinder(nodes, node_count, bridges, bridge_count);
    for(int i = 0; i < node_count; i++) {
        mx_strdel(&(nodes[i].name));
    }
    mx_strdel(&str);
    return 0;
}
