/*
** EPITECH PROJECT, 2018
** dk
** File description:
** dk
*/

typedef struct	space
{
	char		*name;
	struct space	*next;
}space_t;

typedef struct  list
{
	char		*name;
	int		fd;
	int		truee;
	int		number;
	int		have_passed;
	int		you_are;
	struct list	*prev;
	struct space	*separ;
	struct list	*left;
	struct list	*right;
	struct list	*next;
}list_t;

void	history_command(list_t *b, space_t *a, char **env);
int	send_to_tree_semicolon(char **str, list_t *begin, list_t *a, int i);
int	first_instruct(char *str, char *mem);
list_t  *tree_semicolon(list_t *prev, list_t *a, char **str,
			char *semicolon);
void	free_tree(list_t *a);
space_t	*get_pieces_space(char **str);
int	place_dir_name_space(space_t **list, space_t *a, char *dir_name);
void	print_space(space_t *a);
char	*delete_lateral_space(char *name);
char	**characters(void);
void	free_space(space_t *a);
void	tree(list_t **begin, list_t *a);
char	**execute_instruction(char **env, char **pwd, char *real_pwd,
			list_t *a);
char	**pipe_options(char **env, char **pwd, list_t *a, char *real_pwd);
int	pipe_stuff(char **env, char **pwd, list_t *a, char *real_pwd);
list_t	*tree_start(list_t *a, char *list);
void	initialize_number(list_t *a);
void	initialize_char(list_t *list, char **character);
void	initialize_some_var(list_t *list);
char	*initialize_mem(void);
void	print_it(list_t *a);
int	create_separ(list_t *a);
int	create_execve_file(char c);
void	execvee(list_t *b, space_t *a, char **env);
void	print_space(space_t *a);
char	*get_name(list_t *a, char *sign);
int	is_there_output(list_t *a, char *sign);
int	get_env(char **env, space_t *a, list_t *b);
void	exiting(list_t *b, space_t *a);
int	arguments_after(space_t *a);
int	get_cd(char **env, list_t *a, char **pwd, char *pwd_mem);
void	comands(char **pwd, char *pwdmem, space_t *a, char **env);
void	loop_cd(char **env, list_t *a, char **pwd, char *pwd_mem);
char	**path_ls(char **path, char *str);
void	geta_pwd(list_t *b, space_t *a);
void	execvee(list_t *b, space_t *a, char **env);
int	execute(list_t *b, space_t *a, char **env);
char	**options(char **env, char **pwd, list_t *a, char *real_pwd);
char	**set_env(list_t *b, space_t *a, char **env);
char	**unsetenva(list_t *b, space_t *a, char **env);
int	change_fd_not_create(list_t *a, char *name);
int	change_fd(list_t *a, int i);
int	double_input_redirection(list_t *a);
char	**loop_pipe(char **env, char **pwd, list_t *a, char *real_pwd);
char	**comands_options(char **env, char **pwd, list_t *a,
			char *real_pwd);
int	ls_loop(list_t *b, space_t *a, char **env);
char	**path_ls(char **path, char *str);
void	print_list(list_t *a);
void	free_list(list_t *a);
list_t	*get_pieces(char **str);
char	**put_comands(char *path, space_t *a);
