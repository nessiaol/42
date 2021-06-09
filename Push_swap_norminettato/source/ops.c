#include "push_swap.h"
/*contiene tutte le funzini e regole usate per alterare lordine della sequenza*/
void	s(int *a, int *b, char *str, int *n)
{
	int		tmp;

	if ((ft_strequ(str, "sa") || ft_strequ(str, "ss")) && n[1] - n[0] > 1)
	{
		tmp = a[0];
		a[0] = a[1];
		a[1] = tmp;
	}
	if ((ft_strequ(str, "sb") || ft_strequ(str, "ss")) && n[0] > 1)
	{
		tmp = b[0];
		b[0] = b[1];
		b[1] = tmp;
	}
}

int	pb(int *a, int *b, int *n)
{
	int		i;
	int		j;

	i = n[0];
	j = 0;
	while (i >= 0)
	{
		b[i + 1] = b[i];
		i--;
	}
	b[0] = a[0];
	while (j < n[1] - n[0])
	{
		a[j] = a[j + 1];
		j++;
	}
	n[0]++;
	return (n[0]);
}

int	pa(int *a, int *b, char *str, int *n)
{
	int		i;
	int		j;

	if (ft_strequ(str, "pa") && n[0] != 0)
	{
		i = n[1] - n[0];
		j = 0;
		while (i >= 0)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[0] = b[0];
		while (j < n[0] - 1)
		{
			b[j] = b[j + 1];
			j++;
		}
		n[0]--;
	}
	if (ft_strequ(str, "pb") && n[1] - n[0] != 0)
		n[0] = pb(a, b, n);
	return (n[0]);
}

void	rr(int *a, int *b, char *str, int *n)
{
	int		i;
	int		tmp;

	if ((ft_strequ(str, "rra") || ft_strequ(str, "rrr")) && n[1] - n[0] != 0)
	{
		i = n[1] - n[0] - 1;
		tmp = a[i];
		while (i > 0)
		{
			a[i] = a[i - 1];
			i--;
		}
		a[0] = tmp;
	}
	if ((ft_strequ(str, "rrb") || ft_strequ(str, "rrr")) && n[0] != 0)
	{
		i = n[0] - 1;
		tmp = b[i];
		while (i > 0)
		{
			b[i] = b[i - 1];
			i--;
		}
		b[0] = tmp;
	}
}

void	r(int *a, int *b, char *str, int *n)
{
	int		i;
	int		tmp;

	if ((ft_strequ(str, "ra") || ft_strequ(str, "rr")) && n[1] - n[0] != 0)
	{
		i = 0;
		tmp = a[i];
		while (i < n[1] - n[0] - 1)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[i] = tmp;
	}
	if ((ft_strequ(str, "rb") || ft_strequ(str, "rr")) && n[0] != 0)
	{
		i = 0;
		tmp = b[i];
		while (i < n[0] - 1)
		{
			b[i] = b[i + 1];
			i++;
		}
		b[i] = tmp;
	}
}
