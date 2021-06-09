
#include "source/push_swap.h"
/*passi la sequenza da ordinare in push swap 
 * che la smista nell algoritmo più adatto*/
static void	push_swap(int *a, int *b, int *n)
{
	if (n[1] > 6)
		ft_oversix(a, b, n);
	else if (n[1] > 3 && n[1] < 7)
		ft_upto_six(a, b, n);
	else
		ft_upto_three(a, b, n);
}

/* intcheck converte gli argomenti dei numeri 
 * delimitati da spazi in un array di interi*/

static void	intcheck(int ac, char **av, int *n)
{
	int		x[3];				//[0] qtà temporanea numeri, [1] qtà totale numeri, [2], [3]
	int		i[3];				//in posizione 1, 2, 3 non so cosa ci sia 
	int		a[n[1]];			//stack a
	int		b[n[1]];			//stack b

	i[0] = 1;					//counter di argv
	i[1] = 0;					//
	x[1] = 0;					//counter per quantita' di numeri da ordinare
	while (i[0] < ac)
	{
		x[0] = ft_wordcount(av[i[0]], ' ');		//in x[0] c'e' la quantita' di numeri nell'argomento 
		x[1] += x[0];							//aggiorna argomento dopo argomento
		if (x[0] > 1)							//se nell'argomento c'e' piu' di un numero
		{
			x[2] = x[1] - x[0];					//mette in x[2] 
			add_erpl2(av[i[0]], a, x);			//fa split e atoi dei numeri 
		}
		else if (x[0] != 0)						//se nell'argv c'è un solo numero
		{
			x[2] = i[0];						//mette il numero in x[2]
			erpl1(a, x, av);					//fa atoi del numero
		}
		i[0]++;
	}
	push_swap(a, b, n);
}

int	main(int ac, char **av)
{
	int		i;
	int		num[2];		//[1] qta' numeri totali [0] qta' numeri in singolo argomento [2]counter stack si usa piu avanti

	if (ac > 1)
	{
		i = 1;			//counter degli argomenti
		num[1] = 0;
		while (i < ac)
		{
			num[0] = ft_wordcount(av[i], ' ');			//conta se ci sono piu' numeri in un argomento
			if (num[0] == 0 && !ft_strequ(av[i], ""))	//da errore se l'argomento e' nullo o se la stringa e' vuota
			{
				ft_putendl("Error");
				exit(0);
			}
			num[1] += num[0];			//in num[1] mette il numero degli argomenti (divisi anche dentro il singolo argv) aggiornandolo
			i++;
		}
		if (num[1] == 0)			//se gli argomenti sono 0 esce dal programma
			exit(0);
		num[0] = 0;					//azzera il counter temporaneo
		intcheck(ac, av, num);		//a intecheck passa argc, argv e il numero delle cifre da ordinare (num)
	}
}
