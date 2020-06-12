#ifndef LIST_H_
#define LIST_H_

char	**decide_instructions(char **tabx, char **env);
void	use_cd(char **tabx, char **envi);
void	use_pwd(char **tabx);
char	**use_setenv(char **tabx, char **envi);
char	**use_unsetenv(char **tabx, char **envi);
void	use_env(char **envi);
char	**my_str_to_word_array(char *str, char separator);
char	**my_str_to_wordtab(char *str);
int	my_strcmp(char *s1, char *s2);
void	my_print_tab(char **tab);
void	my_putchar(char c);
char	*my_str_concatenate(char *str,char *scr);
char	*my_str_concatenate_equal(char *str,char *scr);
char	*my_strdup(char *str);
int	my_strlen(char *str);
char	**my_tabcpy(char **src);
char	*my_strcpy(char *dest, char *src);
int	my_putstr(char const *str);

#endif
