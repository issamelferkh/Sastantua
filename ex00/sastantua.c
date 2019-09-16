/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 04:15:43 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/01/13 22:47:23 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		get_etage_x(int etage)
{
	int c;

	c = 2 * ((etage + 3) + (etage % 2) + (etage / 2) + 1);
	if (etage == 0)
		return (7);
	return (get_etage_x(etage - 1) + c);
}

int		get_port_x(int etage)
{
	if ((etage + 1) % 2)
		return (etage + 1);
	else
		return (etage);
}

void	print_port(int *xy, int *ij, int port_x)
{
	if (port_x > 4 && ij[0] == (xy[0] - port_x + (port_x / 2))
		&& ij[1] == ((xy[1] + port_x) / 2) - 2)
		ft_putchar('$');
	else
		ft_putchar('|');
}

void	print_etage(int *xy, int deca, int port_x)
{
	int ij[2];
	int half;

	ij[0] = 0;
	half = (xy[1] - port_x) / 2;
	while (ij[0] < xy[0])
	{
		ij[1] = 0;
		while (ij[1] < xy[1] + deca)
		{
			if (ij[1] < deca - ij[0] + xy[0] - 1)
				ft_putchar(' ');
			else if (ij[1] < deca - ij[0] + xy[0])
				ft_putchar('/');
			else if ((port_x && ij[0] >= xy[0] - port_x)
				&& (ij[1] > half - 1 && ij[1] < half + port_x))
				print_port(xy, ij, port_x);
			else if (ij[1] < deca + xy[1] - xy[0] + ij[0])
				ft_putchar('*');
			ij[1]++;
		}
		ft_putchar('\\');
		ft_putchar('\n');
		ij[0]++;
	}
}

void	sastantua(int size)
{
	int xy[2];
	int deca;
	int port_x;
	int i;

	i = 0;
	port_x = 0;
	while (0 < size)
	{
		while (i < size)
		{
			xy[0] = 3 + i;
			xy[1] = get_etage_x(i);
			deca = (get_etage_x(size - 1) - xy[1]) / 2;
			if (i == size - 1)
				port_x = get_port_x(i);
			print_etage(xy, deca, port_x);
			i++;
		}
	}
}
