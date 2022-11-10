/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 09:43:22 by minseok2          #+#    #+#             */
/*   Updated: 2022/08/09 17:10:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FREE_WITHOUT_LINE 0
# define FREE_WITH_LINE 1
# define JUST_COPY 0
# define COPY_AND_ADD_NUL 1

typedef struct s_list
{
	int				fd;
	char			buf[BUFFER_SIZE];
	int				buf_len;
	int				printed_buf_len;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*str_join_from_remain(t_list *node, int *total_len);
char	*make_line(t_list **list, t_list *node, char *line, int *total_len);
char	*str_join(t_list *node, char *line, int *total_len);
char	*add_nul(t_list **list, t_list *node, char *line, int total_len);
t_list	*set_current_node(t_list **list, int fd);
char	*allocate_memory(t_list *node, int buf_start_index, int total_len);
void	str_copy(char *joined_line, char *line, int total_len, int option);
char	*free_all(t_list **list, t_list *node, char *line, int option);

#endif
