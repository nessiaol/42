#include <stdio.h>
#include "push_swap.h"
/*sta funzione determina lo stack landscape, il minimo e il massimo*/

static void	minmax(int *i, int *a, int *min, int *max)
{
	while (i[1] < i[0])		//scorre la stack a
	{
		if (a[i[1]] < min[0])		//se il n. corrente in a è minore del primo numero in stack a
			min[0] = a[i[1]];		//cambia il minore col corrente.
		if (a[i[1]] > max[0])		//se il n. corrente è maggiore del primo numero in stack a
		{
			max[2] = max[1];		//vedi sotto
			max[1] = max[0];		//il max vecchio va in posizione 2
			max[0] = a[i[1]];		//cambia il maggiore col corrente.
		}
		if (a[i[1]] < max[0] && a[i[1]] > max[1])	//se il corrente è minore del max e maggiore del vecchio max
		{
			max[2] = max[1];			//il corrente va in pos. 1 e quello ancora minore va in pos. 2
			max[1] = a[i[1]];
		}
		if (a[i[1]] < max[1] && a[i[1]] > max[2])	//se il corrente è minore del vecchio max e maggiore del vecchio vecchio max
			max[2] = a[i[1]];						//lo sostituisce.
		i[1]++;
	}				//alla fine abbiamo in max i 3 numeri piu' alti in pos. 0 / 1 / 2
	// printf("min: %d max %d, secondo max %d, terzo max %d\n", min[0], max[0], max[1], max[2]);
}

/*Determina se richiede più mosse 
 * per l'indice ra o rra in cima allo stack*/
static void	ra_or_rra1(int *a, int *b, int *n, int *i)
{
	if (i[0] < (n[1] - n[0]) / 2)
	{
		while (i[0] > 0)
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
			i[0]--;
		}
	}
	else
	{
		while (i[0] < (n[1] - n[0]))
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
			i[0]++;
		}
	}
	pb_asort(a, b, n);
}

/* divide lo stack in sezioni a 
 * seconda della grandezza per ottimizzare il tutto*/
static void	findx(int *min, int *max, int *x, int *i)
{
	x[0] = max[0] - min[0];
	if (i[1] <= 100)
		x[1] = 5;
	else if (i[1] <= 200)
		x[1] = 6;
	else if (i[1] <= 300)
		x[1] = 7;
	else if (i[1] <= 400)
		x[1] = 8;
	else
		x[1] = 11;
	x[0] = x[0] / x[1];		//determina quanti numeri vanno in ogni sezione
	min[1] = min[0];
}
/*determina  i numeri della posizione dell index 
 * è dall index dei valori 'tagliati'*/

static void	to_ra_or_rra(int *i, int *a, int *b, int *n)
{
	int		loop;

	loop = 0;
	while (loop != 1)
	{
		i[0] = 0;
		while (a[i[0]] > i[2] && i[0] < (n[1] - n[0]))
			i[0]++;
		if (i[0] == (n[1] - n[0]) || n[0] == n[1] - 3)
			loop = 1;
		else
			ra_or_rra1(a, b, n, i);
	}
}

/*muove il numero relativamente piu piccolo 
 * in cima allo stck a lo pushi in b */
void	ft_oversix(int *a, int *b, int *n)
{
	int		i[3];
	int		x[2];
	int		min[2];
	int		max[3];

	if (!checka(a, n[1]))		//se non sono ordinati
	{
		min[0] = a[0];			//mette in min[0] il primo num. di a
		max[0] = -2147483648;	//mette in max[0] il max int
		i[1] = 0;
		i[0] = n[1];
		minmax(i, a, min, max);	//trova minimo e massimi
		findx(min, max, x, i);	//divide la stack in gruppi di numeri a seconda della grandezza della stack
		while (min[1] <= min[0] + (x[0] * x[1])) 
		{
			i[0] = 0;
			i[1] = (n[1] - n[0]) - 1;
			min[1] = min[1] + x[0];
			ex(min, max, i);
			to_ra_or_rra(i, a, b, n);
			if (n[0] == n[1] - 3)
				min[1] = max[0] + x[0];
		}
		passb(a, b, n);
	}
}
