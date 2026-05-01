/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalzubi <oalzubi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 16:47:53 by oalzubi           #+#    #+#             */
/*   Updated: 2026/05/01 21:34:20 by oalzubi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	down_check(int per[4][4], int req[16])
{
	int	row_counter;
	int	clo_counter;
	int	max;
	int	count;

	row_counter = 3;
	while (row_counter >= 0)
	{
		col_counter = 0;
		max = 0;
		count = 0;
		while (col_counter < 4)
		{
			if (per[col_counter][row_counter] > max)
			{
				max = per[col_counter][row_counter];
				count++;
			}
			col_counter++;
		}
		if (count != req[row_counter])
			return (0);
		row_counter++;
	}
	return (1);
}

int	up_check(int per[4][4], int req[16])
{
	int	i;
	int	j;
	int	max;
	int	count;

	i = 0;
	while (i < 4)
	{
		j = 0;
		max = 0;
		count = 0;
		while (j < 4)
		{
			if (per[j][i] > max)
			{
				max = per[j][i];
				count++;
			}
			j++;
		}
		if (count != req[i])
			return (0);
		i++;
	}
	return (1);
}

int	col_check(int per[4][4])
{
	int	frq[4];
	int		i;
	int		j;
	
	i = 0;
	while (i < 4)
	{
		j = 0;
		frq[0] = 0;
		frq[1] = 0;
		frq[2] = 0;
		frq[3] = 0;
		while (j < 4)
		{
			if (frq[per[j][i] - 1] > 0)
				return (0);
			frq[per[j][i] - 1]++;
			j++;
		}
		i++;
	}
	return (1);
}


int	main(void)
{
	int per[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 1, 2, 3}};
	int req[16] = {4,3,2,1,1,2,2,2,4,3,2,1,1,2,2,2};
	printf(" %d", col_check(per));
	printf(" %d", up_down_check(per, req));
}
