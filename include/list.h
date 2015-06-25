/*
** list.h for list in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Tue May  5 13:49:15 2015 Dan Ayasch
** Last update Sun Jun  7 15:54:07 2015 Dan Ayasch
*/

#ifndef LIST_H_
# define LIST_H_

# define LEN 4096

char		*g_prompt;

typedef struct	s_point
{
  char		**env;
  int		point;
}		t_point;

typedef struct	s_param_env
{
  int		y_pwd;
  int		y_old_pwd;
}		t_param_env;

typedef struct	s_chaine
{
  int		i;
  char		*str;
  struct s_chaine	*prev;
  struct s_chaine	*next;
}		t_chaine;

typedef struct	s_var
{
  int		x;
  int		j;
  int		a;
}		t_var;

typedef struct	s_redir
{
  int		(*ftn)(char **s1, char **s2, char **env, int point);
  char		*str;
}		t_redir;

typedef struct	s_tab
{
  int		(*fct)(char **env, char **s);
  char		*str;
}		t_tab;

typedef struct	s_list
{
  char		*command;
  char		**option;
  char		*operand;
  int		token;
}		t_list;

int		slash(char **env, char **save);
int		my_access(char *str);
int		my_do(char *tub, char **env, char **save);
char		**read_path(char **env);
int		exec_rm(char **env);
char		**exec_redir(char **env, char **clear2);
int		creat_file(char **tab3);
int		check_redir(char **s1, char **s2, char *redir, t_point *point);
char		*my_strcat(char *str);
char		*env_name(char *env);
char		*my_strcomp(char *str1, char *str2, int c);
int		checker(char **save, char **env);
char		**my_str_to_wordtab(char *str, char str2);
char		*get_next_line(const int fd);
t_list		*parseur(char *str, t_list *list);
void		my_putstr(char *str);
int		my_exec(char **env, char *str, char **save);
char		*my_strcpy(char *src);
char		*cpy_str(char *str, char *str2);
char		*cpy_str2(char *str, char *str2);
char		*path(char **env);
char		*my_getenv(char **envp, char *str);
char		*my_prompt(char **envp);
int		my_putnbr(int nb);
int		my_strncmp(char *s1, char *s2);
int		my_strcmp2(char *s1, char *s2);
void		my_putchar(char c);
int		my_strlen(char *str);
int		my_strcmp(char *s1, char *s2);
int		my_env(char **env, char **s);
int		my_cd(char **env, char **s);
int		my_setenv(char **env, char **s);
int		my_unsetenv(char **env, char **s);
int		my_exit(char **env, char **s);
int		my_echo(char **env, char **s);
int		my_comma(char **s1, char **s2, char **env, int point);
int		d_arrow_left(char **s1, char **s2, char **env, int point);
int		redirect(char **command, char **file, char **env, int point);
int		redirection_gauche(char **command, char **file,
				   char **env, int point);
int		separator_and(char **s1, char **s2, char **env, int point);
int		separator_or(char **s1, char **s2, char **env, int point);
int		separator_pipe(char **s1, char **s2, char **env, int point);
int		pipe_fork(char **s1, char **s2, char **env, char **path);
int		s_arrow_right(char **s1, char **s2, char **env, int point);
int		s_arrow_left(char **s1, char **s2, char **env, int point);
int		d_arrow_right(char **s1, char **s2, char **env, int point);
int		tri(char **env, t_list *list);
int		check_list(char **env, t_list *list);
int		history(t_chaine **chaine, char *str);
int		my_put_in_list(t_chaine **root, char *str, int i);
int		modif(char **env, t_param_env *param);
int		modif_cd(char **env, t_param_env *param, char **s);
int		modif_oldpwd(char **env, t_param_env *param);
int		modif_cd_norm(char **env, t_param_env *param, char *s);
int		recup_pwd(char **env, t_param_env *param);
int		recur(char **env, char *prompt, t_list *list);
char		*my_strcpy_pwd(char *env);
char		*my_getenv_pwd(char **env, char *str);
int		check_built(char **s1);
char		*epur_str(char *str);
int		check_slash(char **tab, char **env);
char		**check_path(char **env);
int		call_no_env(char **save, char **env, t_list *list, int i);
int		no_command(t_list *list, char **env);
int		call_multi_redir(t_list *list, int i, char **env);
int		call_redir(t_list *list, int i, char **env);
int		call_notoken(char **env, t_list *list, int i);
int		check_access(char **s1, char **path);
char		**check_path(char **env);
int		check_slash(char **tab, char **env);
int		echo_$(char **s, char **env);
int		call_checker(char **s1, char **path, char **env, char **s2);
int		alias(t_list **list);
void		my_puterr(char *str);
char		**cd_minus(char **env, t_param_env param, char **s, int a);
int		built_alias(char **env, char **save);
int		create_file(char *str);
char		*erase_tab(char *str);
int		multi_sep(t_list *list, char **env);
int		other_pipe(t_list *list, char **env,
			   char **path, int i);
int		exec_path(char **env, char **option, char **path);
int		multi_pipe(t_list *list, char **env);
int		re_fork(t_list *list, int i, char **env, char **path);
int		wait_exec_red(int pid, int statue, int fd);
int		wai_father(int pid, int p[2], int status);
int		process_son(int p[2]);

#endif /* !LIST_H_ */
