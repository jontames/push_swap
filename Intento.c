/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intento.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <jtames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:06 by jtames            #+#    #+#             */
/*   Updated: 2025/01/17 18:09:16 by jtames           ###   ########.fr       */
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

void	pa(int a[], int b[], int a_size[], int b_size[])
{
	int	i;
	
	i = a_size[0] - 1;
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < b_size[0])
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = 0;
	a_size[0]++;
	b_size[0]--;
}

void	pb(int a[], int b[], int a_size[], int b_size[])
{
	int	i;
	
	i = b_size[0] - 1;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < a_size[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = 0;
	a_size[0]--;
	b_size[0]++;
}

void	ra(int a[], int a_size[])
{
	int		i;
	int		temp;

	i = 0;
	temp = a[0];
	while (i < a_size[0])
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = temp;
}

void	rb(int b[], int b_size[])
{
	int		i;
	int		temp;

	i = 0;
	temp = b[0];
	while (i < b_size[0])
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = temp;
}

void	rr(int a[], int b[], int a_size[], int b_size[])
{
	ra(a, &a_size[0]);
	rb(b, &b_size[0]);
}

void	rra(int a[], int a_size[])
{
	int		i;
	int		temp;

	i = a_size[0] - 1;
	temp = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = temp;
}

void	rrb(int b[], int b_size[])
{
	int		i;
	int		temp;

	i = b_size[0] - 1;
	temp = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = temp;
}

void	rrr(int a[], int b[], int a_size[], int b_size[])
{
	rra(a, &a_size[0]);
	rrb(b, &b_size[0]);
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

void	algorithm(int a[], int b[], int a_size[], int b_size[], int a_len)
{
	if ((a_size[0] > 1 && check_min(a, a[a_size[0] - 1], a_size[0])) && (b_size[0] > 1 && check_max(b, b[b_size[0] - 1], b_size[0])))
	{
		rrr(a, b, &a_size[0], &b_size[0]);
		printf("rrr\n");
	}
	else if ((a_size[0] > 1 && check_max(a, a[0], a_size[0])) && (b_size[0] > 1 && check_min(b, b[0], b_size[0])))
	{
		rr(a, b, &a_size[0], &b_size[0]);
		printf("rr\n");
	}
	else if (a_size[0] > 1 && check_min(a, a[a_size[0] - 1], a_size[0]))
	{
		rra(a, &a_size[0]);
		printf("rra\n");
	}
	else if ((a_size[0] > 1 && b_size[0] > 1) && (a[1] < a[0] && b[1] > b[0]))
	{	
		ss(a, b);
		printf("ss\n");
	}
	else if (a_size[0] > 1 && a[1] < a[0])
	{
		sa(a);
		printf("sa\n");
	}
	else if ((a_size[0] > 1 && check_max(a, a[0], a_size[0])) || (a_size[0] > 1 && a[0] > a[a_size[0] - 1]))
	{
		ra(a, &a_size[0]);
		printf("ra\n");
	}
	else if (b_size[0] > 1 && check_max(b, b[b_size[0] - 1], b_size[0]))
	{
		rrb(b, &b_size[0]);
		printf("rrb\n");
	}
	else if (b_size[0] > 1 && check_min(b, b[0], b_size[0]))
	{
		rb(b, &b_size[0]);
		printf("rb\n");
	}
	else if (b_size[0] > 1 && b[1] > b[0])
	{
		sb(b);
		printf("sb\n");
	}	
	else if (b_size[0] > 0 && check_order(a, '+', a_size[0])/*  && b[0] < a[0] */)
	{
		pa(a, b, &a_size[0], &b_size[0]);
		printf("pa\n");
	}
	else if (a_size[0] > 0 && a[0] < a[1] /* && a[0] > b[0] */)
	{
		pb(a, b, &a_size[0], &b_size[0]);
		printf("pb\n");
	}
	else 
		return ;
	
	if (check_order(a, '+', a_len))
		return ;
	else
		algorithm(a, b, &a_size[0], &b_size[0], a_len);
}

int main(int argc, char const *argv[])
{
	int		a[argc - 1];
	int		b[argc - 1];
	int		i;
	int		j;
	int		a_len;
	int		a_size[1];
	int		b_size[1];

	a_len = argc - 1;
	a_size[0] = argc - 1;
	b_size[0] = 0;
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
	algorithm(a, b, &a_size[0], &b_size[0], a_len);
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

