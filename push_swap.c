/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtames <jtames@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:06 by jtames            #+#    #+#             */
/*   Updated: 2024/12/30 20:31:35 by jtames           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void	sa(char a[])
{
	char	temp;

	if (!a)
		return;
	temp = a[0];
	a[0] = a[1];
	a[1] = temp;
}

void	sb(char b[])
{
	char	temp;

	if (!b)
		return ;
	temp = b[0];
	b[0] = b[1];
	b[1] = temp;
}

void	ss(char a[], char b[])
{
	sa(a);
	sb(b);	
}

void	pa(char a[], char b[])
{
	int	i;
	
	if (!b)
		return;
	i = strlen(a) - 1;
	while (i >= 0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (b[i] != '\0')
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = '\0';
}

void	pb(char a[], char b[])
{
	int	i;
	
	if (!a)
		return;
	i = strlen(b) - 1;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (a[i] != '\0')
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = '\0';
}

void	ra(char a[])
{
	int		i;
	char	c;

	i = 0;
	c = a[0];
	while (a[i] != '\0')
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i - 1] = c;
}

void	rb(char b[])
{
	int		i;
	char	c;

	i = 0;
	c = b[0];
	while (b[i] != '\0')
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i - 1] = c;
}

void	rr(char a[], char b[])
{
	ra(a);
	rb(b);
}

void	rra(char a[])
{
	int		i;
	char	c;

	i = strlen(a) - 1;
	c = a[i];
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = c;
}

void	rrb(char b[])
{
	int		i;
	char	c;

	i = strlen(b) - 1;
	c = b[i];
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[i] = c;
}

void	rrr(char a[], char b[])
{
	rra(a);
	rrb(b);
}

void	wr(char a[], char b[], size_t a_len)
{
	size_t	i;

	i = 0;
	while (i < a_len)
	{
		if (a[i])
			printf("%c ", a[i]);
		else
			printf("  ");
		if (b[i])
			printf("%c\n", b[i]);
		else
			printf(" \n");
		i++;
	}
	printf("_ _\na b\n");
}

void	ins_slct(char a[], char b[], size_t a_len)
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
		pa(a, b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "pb", 2) == 0)
	{	
		pb(a, b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "ra", 2) == 0)
	{	
		ra(a);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rb", 2) == 0)
	{	
		rb(b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rra", 3) == 0)
	{	
		rra(a);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rrb", 3) == 0)
	{	
		rrb(b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rrr", 3) == 0)
	{	
		rrr(a, b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "rr", 2) == 0)
	{	
		rr(a, b);
		wr(a, b, a_len);
	}
	else if (strncmp(input, "exit", 4) == 0)
		return;
	else
		ins_slct(a, b, a_len);
	i++;
	ins_slct(a, b, a_len);
}

/* void	algorithm(char a[], char b[])
{
	if (a[1] > a[0])
		sa(a);
	else if (b[1] > b[0])
		sb(b);
	else if (a[0] > )
} */

int main(int argc, char const *argv[])
{
	char	a[argc];
	char	b[argc];
	size_t	i;
	int	j;
	size_t	a_len;

	a_len = argc - 1;
	memset(a, 0, argc);
	memset(b, 0, argc);
	i = 0;
	j = 1;
	if (argc > 1)
	{
		while(i < a_len)
		{
			a[i] = argv[j][0];
			i++;
			j++;
		}
	}
	printf("Init a and b:\n");
	i = 0;
	while (i < a_len)
	{
		if (a[i])
			printf("%c ", a[i]);
		else
			printf("  ");
		if (b[i])
			printf("%c\n", b[i]);
		else
			printf(" \n");
		i++;
	}
	printf("_ _\na b\n");
	ins_slct(a, b, a_len);

	return 0;
}

