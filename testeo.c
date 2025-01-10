/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testeo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <jtames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:06 by jtames            #+#    #+#             */
/*   Updated: 2025/01/10 18:37:57 by jtames           ###   ########.fr       */
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

void	wr(int a[], int b[], size_t a_len)
{
	size_t	i;

	i = 0;
	while (i < a_len)
	{
		printf("%d ", a[i]);
		printf("%d\n", b[i]);
		i++;
	}
	printf("_ _\na b\n");
}

void	ins_slct(int a[], int b[], size_t a_len, int a_size[], int b_size[])
{
	char		input[5];
	static int	i = 1;

	scanf("%s", input);
	printf("Comando %d:\n", i);
	if (strncmp(input, "sa", 2) == 0)
	{	
		sa(a);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "sb", 2) == 0)
	{	
		sb(b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "ss", 2) == 0)
	{	
		ss(a, b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "pa", 2) == 0)
	{	
		pa(a, b, &a_size[0], &b_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "pb", 2) == 0)
	{	
		pb(a, b, &a_size[0], &b_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "ra", 2) == 0)
	{	
		ra(a, &a_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rb", 2) == 0)
	{	
		rb(b, &b_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rra", 3) == 0)
	{	
		rra(a, &a_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rrb", 3) == 0)
	{	
		rrb(b, &b_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rrr", 3) == 0)
	{	
		rrr(a, b, &a_size[0], &b_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rr", 2) == 0)
	{	
		rr(a, b, &a_size[0], &b_size[0]);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "exit", 4) == 0)
		return;
	else
		ins_slct(a, b, a_len, &a_size[0], &b_size[0]);
	i++;
	ins_slct(a, b, a_len, &a_size[0], &b_size[0]);
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
	printf("Init a and b:\n");
	i = 0;
	while (i < a_len)
	{
		printf("%d ", a[i]);
		printf("%d\n", b[i]);
		i++;
	}
	printf("_ _\na b\n");
	ins_slct(a, b, a_len, &a_size[0], &b_size[0]);

	return 0;
}

