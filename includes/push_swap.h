/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkenji-u <tkenji-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:36:41 by thiagouemur       #+#    #+#             */
/*   Updated: 2025/10/22 09:54:02 by tkenji-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	int				index;
	struct s_list	*next;
}					t_list;

/* Validations */
void	error_exit(void);
int		input(int argc, char **argv, t_list **a);
int		input_number(const char *str);
int		fill_stack_args(char **args, t_list **a);

/* Operations */
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

/* list memory */
int		lst_size(t_list *list);
void	lst_add_back(t_list **a, t_list *new_node);
void	cleanup(t_list **a, t_list **b);
void	free_split(char **args);
void	free_stack(t_list **stack);

/* sorted */
void	sorted(t_list **a, t_list **b, int size);
void	sorted_2(t_list **a);
void	sorted_3(t_list **a);
void	sorted_4_5(t_list **a, t_list **b, int size);
void	sorted_big(t_list **a, t_list **b, int chunk_size);
void	sorted_pa(t_list **a, t_list **b);

/* aux sorted big*/
void	set_index(t_list **a);
int		index_max(t_list **a);
int		max_pos(t_list **b, int max_index, int size);
int		min_pos(t_list **a, int min, int size);

/* aux */
int		n_min(t_list **a);
int		n_max(t_list **a);

/* libft */
long	ft_atol(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isdigit(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif