
#include "push_swap.h"
/*ordina le sequenze da 3 a 7 numeri
in particolare questa funzione determina quanti valori 
sono più grandi del valore medio e di consegenza quelli più piccoli*/
static int	lolo(int *a, int n, int m, int *x)
{
	while (x[1] - x[0] != 1 && x[1] - x[0] != 0)
	{
		if (x[1] - x[0] != 1)			//se la differenza tra i num. minori e i maggiori è diversa da 1  o 0 
			m = m + (x[1] - x[0]);		//adatta il midpoint per dividere la stack in due parti uguali o quasi
		x[0] = 0;
		x[1] = 0;
		x[2] = 0;
		while (x[2] < n)			//scorre la stack
		{
			if (a[x[2]] < m)		//riconta i numeri minori del midpoint
				x[0]++;
			else
				x[1]++;				//e i maggiori
			x[2]++;
		}
	}
	return (m);
}
/*determina se ci mette meno mosse per muovere il numero
 * più piccolo nello stack b
 * , quindi che il numero più piccolo sia l'ultimo numero in b*/

static void	lole(int *a, int *b, int *n, int i)
{
	if (i < (n[1] - n[0]) / 2)
	{
		while (i != 0)
		{
			r(a, b, "ra", n);
			ft_putendl("ra");
			i--;
		}
	}
	else
	{
		while (i != (n[1] - n[0]))
		{
			rr(a, b, "rra", n);
			ft_putendl("rra");
			i++;
		}
		i = 0;
	}
}
/*pusha tutti i valori ordinati da b ad a*/

static void	fstep(int *a, int *b, int *n)
{
	pa(a, b, "pa", n);
	ft_putendl("pa");
}
/*identifica i valori principali per determinare quante posizioni distano 
 * i numeri da enrambe le estremità, quindi si calcola il punto medio */

int	mid(int *a, int n)
{
	int		m;
	int		x[3];

	m = 0;
	x[0] = 0;
	x[1] = 0;
	x[2] = 0;
	while (x[2] < n)
	{
		m = m + a[x[2]];	//m è la somma dei numeri della stack
		x[2]++;
	}
	m = m / x[2];			//divide il totale per la quantita' di numeri della stack per ottenere la media
	x[2] = 0;
	while (x[2] < n)
	{
		if (a[x[2]] < m)	//scorre la stack e conta i numeri minori del midpoint, mettendo il totale in x[0]
			x[0]++;
		else
			x[1]++;			//conta i maggiori del midpoint
		x[2]++;
	}
	m = lolo(a, n, m, x);	//trova il midpoint (numero che divide la stack a meta' circa)
	return (m);
}

/*identifica il valore medio, quindi se un particolare index è minore 
 * del valore medio quest'ultimo viene pushato in b*/
void	ft_upto_six(int *a, int *b, int *n)
{
	int		i;
	int		m;

	if (!checka(a, n[1]))
	{
		m = mid(a, n[1]);
		i = 0;
		while (i < n[1] - n[0])		//scorre la stack
		{
			if (a[0] < m)			//se il n. è minore del midpoint lo pusha in b
			{
				pa(a, b, "pb", n);
				ft_putendl("pb");
				i = 0;
			}
			if (a[i] < m)			//se è maggiore del midpoint ruota nel senso piu' conveniente
				lole(a, b, n, i);
			i++;
		}
		ft_upto_three(a, b, n);		//ordina stack a
		ft_upto_three_b(a, b, n);	//ordian stack b
		while (n[0] != 0)
			fstep(a, b, n);			//pusha tutti i numeri di b in a
	}
}
