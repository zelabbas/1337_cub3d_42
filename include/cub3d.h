/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelabbas <zelabbas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:25:52 by zech-chi          #+#    #+#             */
/*   Updated: 2024/06/02 15:47:27 by zelabbas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# define BUFFER_SIZE 1
# define SUCCESS 0
# define FAILED 1
# define WHITE "\e[1;37m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define RESET "\e[m"

/* cub3d struct */
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_cub
{
	char	**map;
	char	*line;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*cf;
	int		*cc;
	t_list	*head;
	int		rows;
	int		cols;
	int		pr;
	int		pc;
	int		fd;
}	t_cub;

/* get_next_line/get_next_line_utils.c */
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	shift_buff_or_clean_it(char *buff, size_t j);
int		has_the_end(char *buff, char **line);

/* get_next_line/get_next_line.c */
char	*get_next_line(int fd);

/* tools */
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *str, int fd, int endl, char *color);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_valid_name(char *name);
int		ft_open_file(char *path);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_skip_space(char *str, int *i);

/* malloc */
void	*allocate_memory_safely(size_t bytes, t_cub *cub);
void	ft_free_data(t_cub *cub);
void	ft_free_list(t_list **head);

/* parsing/parsing.c */
void	ft_parsing(int ac, char **av, t_cub *cub);
int		*ft_get_color(char *line, t_cub *cub);
int		ft_set_color(t_cub *cub, int **color, char *line, int *i);
void	ft_scan_file(t_cub *cub, char *path);
void	ft_create_map(t_cub *cub);
int		ft_scan_map(t_cub *cub);

/* parsing/scan_file.c*/
int		ft_part1_full(t_cub *cub);

/* parsing/scan_line_1&2.c*/
void	ft_scan_line(t_cub *cub, int *check);
int		ft_is_full_spaces(char *line);
int		ft_is_full_spaces_newline(char *line);
int		ft_check_content_line(char *line, int *check);
int		ft_set_coordonates_textures(char **texture, char *line, int *i);

/*linked_list*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_display_list(t_list *head);// to remove 
/*to remove*/
void	ft_display(t_cub *cub);

#endif