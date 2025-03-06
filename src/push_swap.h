/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amezoe <amezoe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 21:52:43 by amezoe            #+#    #+#             */
/*   Updated: 2025/03/06 14:33:46 by amezoe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/printf/ft_printf.h"
# include "../include/libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				moves_to_top;
	int				above_medium;

	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

int			validate_format(char **av); //
int			validate_num_limit(char **num); // 
int			check_dupe(char **num); //
long long	ft_atol(const char *nptr); // 
int			ft_arg_count(char **av);
int			validate_input(char**av); //
void		error(void); //
void		free_list(t_stack *head); //
t_stack		*new_item(int value); //
int			max_of_list(t_stack **stack);
int			min_of_list(t_stack **stack);
void		rotate_a(t_stack **stack_a, int flag); //
void		rotate_b(t_stack **stack_b, int flag); // 
void		rotate_ab(t_stack **stack_a, t_stack **stack_b); //
void		rotate_ab_both(t_stack **stack_a, t_stack **stack_b, t_stack *node);
void		swap_a(t_stack **stack_a, int flag); //
void		swap_b(t_stack **stack_b, int flag); //
void		swap_ab(t_stack **stack_a, t_stack **stack_b); //
void		rev_rotate_a(t_stack **stack_a, int flag); //
void		rev_rotate_b(t_stack **stack_b, int flag); //
void		rev_rotate_ab(t_stack **stack_a, t_stack **stack_b); //
void		rev_rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *node);
void		push_a(t_stack **stack_a, t_stack **stack_b); //
void		push_b(t_stack **stack_a, t_stack **stack_b); //
t_stack		*stack_initialization(char **av); //
int			count_nodes(t_stack **stack); //
void		add_to_end(t_stack **list, t_stack *new); //
void		onto_top_b(t_stack **stack_b, t_stack *node);
void		onto_top_a(t_stack **stack_a, t_stack *node);
void		calculate_target_alignment(t_stack **stack_a, t_stack **stack_b, t_stack *node);
int			is_sorted(t_stack **stack); //
void		sort_three(t_stack **stack); //
t_stack		*find_bigger(t_stack **stack);
t_stack		*find_lower(t_stack **stack);
void		index_def(t_stack **stack); //
void		define_lowest(t_stack **stack_a, t_stack **stack_b);
void		define_highest(t_stack **stack_a, t_stack **stack_b);
void		update_a(t_stack **stack_a, t_stack **stack_b); //
void		update_b(t_stack **stack_a, t_stack **stack_b); //
void		count_move_cost(t_stack **stack_a, t_stack **stack_b);
t_stack		*less_moves_top(t_stack **stack_a); // 
void		less_moves_top_b(t_stack **stack_a, t_stack **stack_b);
void		maximum_on_top(t_stack **stack); //
void		minimum_on_top(t_stack **stack); // 
void		main_sorting(t_stack **stack_a); //
int			free_everything(char **str); //
int			main(int ac, char **av); //
void free_all(t_stack **stack_a, t_stack **stack_b);

#endif