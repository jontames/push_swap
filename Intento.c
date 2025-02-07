/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intento.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <jtames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:06 by jtames            #+#    #+#             */
/*   Updated: 2025/02/07 20:51:19 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void	sa(int a[])
{
	int	temp;

	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	sb(int b[])
{
	int	temp;

	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
}

void	ss(int a[], int b[])
{
	sa(a);
	sb(b);
}

void	pa(int a[], int b[], int stck_size[])
{
	int	i;
	
	i = stck_size[0] - 1;
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < stck_size[1])
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = 0;
	stck_size[0]++;
	stck_size[1]--;
}

void	pb(int a[], int b[], int stck_size[])
{
	int	i;
	
	i = stck_size[1] - 1;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < stck_size[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = 0;
	stck_size[0]--;
	stck_size[1]++;
}

void	ra(int a[], int stck_size[])
{
	int		i;
	int		temp;

	i = 0;
	temp = a[0];
	while (i < stck_size[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = temp;
}

void	rb(int b[], int stck_size[])
{
	int		i;
	int		temp;

	i = 0;
	temp = b[0];
	while (i < stck_size[1])
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = temp;
}

void	rr(int a[], int b[], int stck_size[])
{
	ra(a, &stck_size[0]);
	rb(b, &stck_size[1]);
}

void	rra(int a[], int stck_size[])
{
	int		i;
	int		temp;

	i = stck_size[0] - 1;
	temp = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = temp;
}

void	rrb(int b[], int stck_size[])
{
	int		i;
	int		temp;

	i = stck_size[1] - 1;
	temp = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = temp;
}

void	rrr(int a[], int b[], int stck_size[])
{
	rra(a, &stck_size[0]);
	rrb(b, &stck_size[1]);
}

int	check_order(int stack[], char way, int size)
{
	int i;

	i = 0;
	if (way == '+')
	{
		while (i < (size - 1))
		{
			if (stack[i] > stack[i + 1])
				return 0;
			i++;	
		}
		return 1;
	}
	else if (way == '-')
	{
		while (i < (size - 1))
		{
			if (stack[i] < stack[i + 1])
				return 0;
			i++;	
		}
		return 1;
	}
	else
		return 0;
}

int	check_min(int stack[], int n, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		if (n > stack[i])
			return 0;
		i++;
	}
	return 1;
}

int	check_max(int stack[], int n, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		if (n < stack[i])
			return 0;
		i++;
	}
	return 1;
}

int	find_min(int stack[], int size)
{
	int		i;
	int		min_pos;

	i = 0;
	min_pos = 0;
	while (i < size)
	{
		if (stack[i] < stack[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

int	find_max(int stack[], int size)
{
	int		i;
	int		max_pos;

	i = 0;
	max_pos = 0;
	while (i < size)
	{
		if (stack[i] > stack[max_pos])
			max_pos = i;
		i++;
	}
	return (max_pos);
}

int	count_dorgz(int stack[], int size)
{
	int		i;
	int		max_pos;
	int		dorgz;
	int		min_pos;

	min_pos = find_min(stack, size);
	max_pos = find_max(stack, size);
	dorgz = 0;
	i = min_pos + 1;
	while (stack[i] != stack[max_pos])
	{
		if (i == 0)
		{
			if (stack[i] < stack[size - 1])
				dorgz++;
		}
		if (stack[i] < stack[i - 1])
			dorgz++;
		i++;
		if (i >= size)
			i = 0;
	}
	i++;
	while (stack[i] != stack[min_pos])
	{
		dorgz++;
		i++;
		if (i >= size)
			i = 0;
	}
	return (dorgz);
}

void	move_dorgz(int a[], int b[], int stck_size[])
{
	int		dorgz;
	int		min_nbr;
	// int		max_nbr;
	
	dorgz = count_dorgz(a, stck_size[0]);
	min_nbr = a[find_min(a, stck_size[0])];
	while (dorgz > 0)
	{
		if (a[0] != min_nbr && a[0] < a[stck_size[0] - 1])
		{
			pb(a, b, stck_size);
			printf("pb\n");
			dorgz--;
		}
		else
		{
			ra(a, stck_size);
			printf("ra\n");
		}
	}
}

void	calc_move_near_top(int a[], int b[], int stck_size[])
{
	int		i;
	int		diff;
	int		pos;
	int		nbr;
	
	i = 0;
	diff = 2147483647;
	pos = 0;
	while (i < (stck_size[0]))
	{
		if (a[i] > b[0])
		{
			if ((a[i] - b[0]) < diff)
			{
				diff = a[i] - b[0];
				pos = i;
			}
		}
		i++;
	}
	nbr = a[pos];
	if ((stck_size[0] - 1) - pos < pos)
	{
		while (a[0] != nbr)
		{
			rra(a, stck_size);
			printf("rra\n");
		}
	}
	else
	{
		while (a[0] != nbr)
		{
			ra(a, stck_size);
			printf("ra\n");
		}
	}
}

int	calc_near_top(int a[], int b, int stck_size[])
{
	int		i;
	int		diff;
	int		pos;
	
	i = 0;
	diff = 2147483647;
	pos = 0;
	while (i < (stck_size[0]))
	{
		if (a[i] > b)
		{
			if ((a[i] - b) < diff)
			{
				diff = a[i] - b;
				pos = i;
			}
		}
		i++;
	}
	return (pos);
}

int	calc_best2move(int a[], int b[], int stck_size[])
{
	int		pos_first;
	int		pos_last;
	int		mv_first;
	int		mv_last;

	pos_first = calc_near_top(a, b[0], stck_size);
	if ((stck_size[0] - 1) - pos_first < pos_first)
		mv_first = (stck_size[0] - 1) - pos_first;
	else
		mv_first = pos_first;
	pos_last = calc_near_top(a, b[stck_size[1] - 1], stck_size);
	if ((stck_size[0] - 1) - pos_last < pos_last)
		mv_last = (stck_size[0] - 1) - pos_last;
	else
		mv_last = pos_last;
	if (mv_last < mv_first)
		return (1);
	else
		return (0);
}

void	mv_best(int a[], int b[], int stck_size[])
{
	int		pos;
	int		nbr;
	
	pos = 0;
	if (calc_best2move(a, b, stck_size) == 0)
	{
		pos = calc_near_top(a, b[0], stck_size);
		nbr = a[pos];
		if ((stck_size[0] - 1) - pos < pos)
		{
			while (a[0] != nbr)
			{
				rra(a, stck_size);
				printf("rra\n");
			}
		}
		else
		{
			while (a[0] != nbr)
			{
				ra(a, stck_size);
				printf("ra\n");
			}
		}
	}
	else if (calc_best2move(a, b, stck_size) == 1)
	{
		rrb(b, stck_size);
		printf("rrb\n");
		pos = calc_near_top(a, b[0], stck_size);
		nbr = a[pos];
		if ((stck_size[0] - 1) - pos < pos)
		{
			while (a[0] != nbr)
			{
				rra(a, stck_size);
				printf("rra\n");
			}
		}
		else
		{
			while (a[0] != nbr)
			{
				ra(a, stck_size);
				printf("ra\n");
			}
		}
	}
}

/* void	push_messy(int a[], int b[], int stck_size[])
{
	int		i;
	int		min_pos;
	int		max_pos;

	i = 0;
	min_pos = 0;
	max_pos = 0;
	while (i < stck_size[0])
	{
		if (check_min(a, a[i], stck_size[0]))
			min_pos = i;
		else if (check_max(a, a[i], stck_size[0]))
			max_pos = i;
		i++;
	}
	
	while (!check_order(a, '+', stck_size[0]))
	{
		
	}
} */

void	algorithm(int a[], int b[], int stck_size[], int a_len)
{
	static int	instruction_nbr = 1;

	printf("%d: ", instruction_nbr);
	
	if ((stck_size[0] > 1 && check_min(a, a[stck_size[0] - 1], stck_size[0])) && (stck_size[1] > 1 && check_max(b, b[stck_size[1] - 1], stck_size[1])))
	{
		rrr(a, b, stck_size);
		printf("rrr\n");
	}
	else if ((stck_size[0] > 1 && check_max(a, a[0], stck_size[0])) && (stck_size[1] > 1 && check_min(b, b[0], stck_size[1])))
	{
		rr(a, b, stck_size);
		printf("rr\n");
	}
	else if (stck_size[0] > 1 && check_min(a, a[stck_size[0] - 1], stck_size[0]))
	{
		rra(a, stck_size);
		printf("rra\n");
	}
	else if ((stck_size[0] > 1 && stck_size[1] > 1) && (a[1] < a[0] && b[1] > b[0]))
	{	
		ss(a, b);
		printf("ss\n");
	}
	else if ((stck_size[0] > 1 && check_max(a, a[0], stck_size[0])) || (stck_size[0] > 1 && a[0] > a[stck_size[0] - 1]))
	{
		ra(a, stck_size);
		printf("ra\n");
	}
	else if (stck_size[0] > 1 && a[1] < a[0])
	{
		sa(a);
		printf("sa\n");
	}
	else if (stck_size[1] > 1 && check_max(b, b[stck_size[1] - 1], stck_size[1]))
	{
		rrb(b, stck_size);
		printf("rrb\n");
	}
	else if (stck_size[1] > 1 && check_min(b, b[0], stck_size[1]))
	{
		rb(b, stck_size);
		printf("rb\n");
	}
	else if (stck_size[1] > 1 && b[1] > b[0])
	{
		sb(b);
		printf("sb\n");
	}	
	else if (stck_size[1] > 0 && check_order(a, '+', stck_size[0])/*  && b[0] < a[0] */)
	{
		pa(a, b, stck_size);
		printf("pa\n");
	}
	else if (stck_size[0] > 0 && a[0] < a[1] /* && a[0] > b[0] */)
	{
		pb(a, b, stck_size);
		printf("pb\n");
	}
	else 
		return ;

	instruction_nbr++;
	
	if (check_order(a, '+', a_len))
		return ;
	else
		algorithm(a, b, stck_size, a_len);
}

int main(int argc, char const *argv[])
{
	int		a[argc - 1];
	int		b[argc - 1];
	int		i;
	int		j;
	int		a_len;
	int		stck_size[2];
	int		nbr;
	int		pos;

	a_len = argc - 1;
	stck_size[0] = argc - 1;
	stck_size[1] = 0;
	i = 0;
	while (i < a_len)
	{
		a[i] = 0;
		b[i++] = 0;
	}
	i = 0;
	j = 1;
	if (argc > 1)
	{
		while(i < a_len)
		{
			a[i] = atoi(argv[j]);
			i++;
			j++;
		}
	}
	// printf("MAX: %d\n", find_max(a, stck_size[0]));
	// printf("MIN: %d\n", find_min(a, stck_size[0]));
	// printf("DORGZ: %d\n", count_dorgz(a, stck_size[0]));
	// printf("\n");
	
	// move_dorgz(a, b, stck_size);
	// while (stck_size[1] > 0)
	// {
	// 	calc_move_near_top(a, b, stck_size);
	// 	pa(a, b, stck_size);
	// 	printf("pa\n");
	// }
	// nbr = a[find_min(a, stck_size[0])];
	// pos = find_min(a, stck_size[0]);
	// if ((stck_size[0] - 1) - pos < pos)
	// {
	// 	while (a[0] != nbr)
	// 	{
	// 		rra(a, stck_size);
	// 		printf("rra\n");
	// 	}
	// }
	// else
	// {
	// 	while (a[0] != nbr)
	// 	{
	// 		ra(a, stck_size);
	// 		printf("ra\n");
	// 	}
	// }

	move_dorgz(a, b, stck_size);
	while (stck_size[1] > 0)
	{
		mv_best(a, b, stck_size);
		pa(a, b, stck_size);
		printf("pa\n");
	}
	nbr = a[find_min(a, stck_size[0])];
	pos = find_min(a, stck_size[0]);
	if ((stck_size[0] - 1) - pos < pos)
	{
		while (a[0] != nbr)
		{
			rra(a, stck_size);
			printf("rra\n");
		}
	}
	else
	{
		while (a[0] != nbr)
		{
			ra(a, stck_size);
			printf("ra\n");
		}
	}
	
	// algorithm(a, b, stck_size, a_len);
	i = 0;
	while (i < a_len)
	{
		printf("%d ", a[i]);
		printf("%d\n", b[i]);
		i++;
	}
	printf("_ _\na b\n");
	return 0;
}

