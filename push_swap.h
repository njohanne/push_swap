/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:27:29 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/26 17:49:57 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

typedef struct s_stack
{
	int		*arr;
	int		cur_size;
	int		max_size;
	int		min_num;
	int		max_num;
	int		count_step;
	int		lol;
	char	name;
}	t_stack;

void	ft_error(void);
int		ft_pars_atoi(char *str, int	*array);
int		ft_isdigit(int sh);
int		ft_array_sorted(t_stack stack);
int		ft_array_ready(t_stack stack);
int		ft_find_min(t_stack stack);
int		ft_find_max(t_stack stack);
void	ft_putstr(char *s);
void	ft_minisort(t_stack *a, t_stack *b);
void	ft_sort_tre(t_stack *a);
void	ft_full_sort(t_stack *a, t_stack *b);
void	ft_pa_pb(t_stack *str, t_stack *dst);
void	ft_ra_rb(t_stack *stack, int same);
void	ft_rr(t_stack *a, t_stack *b, int check);
void	ft_rra_rrb(t_stack *stack, int same);
void	ft_rrr(t_stack *a, t_stack *b, int check);
void	ft_sa_sb(t_stack *stack, int same);
void	ft_ss(t_stack *a, t_stack *b, int check);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *array);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dest, const char *source, size_t n);
char	**ft_parser_str(int arg, char **arv, t_stack *stack);

void	ft_parse(t_stack *a, t_stack *b);
int		ft_strcmp(const char *s1, const char *s2);

#endif