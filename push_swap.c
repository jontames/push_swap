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

// int	*ra(int *a, int *b)
// {
	
// }

// int	*rb(int *a, int *b)
// {
	
// }

// int	*rr(int *a, int *b)
// {
	
// }

// int	*rra(int *a, int *b)
// {
	
// }

// int	*rrb(int *a, int *b)
// {
	
// }

// int	*rrr(int *a, int *b)
// {
	
// }

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

	printf("%lu\n\n", a_len);

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

	printf("\n");
	// sa(a);
	// sb(b);
	// ss(a, b);
	pb(a, b);
	pb(a, b);
	// pb(a, b);

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
	
	return 0;
}

