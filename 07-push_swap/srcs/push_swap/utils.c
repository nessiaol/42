#include "push_swap.h"

// int ft_isdigit_string(char *s)
// {
//     int i;
//     i = 0;
//     if (!s)
//         return (1);
//     if (s[0] == '-')
//         i++;
//     while (s[i])
//     {
//         if (!ft_isdigit(s[i]))
//             return (0);
//         i++;
//     }
//     return (1);
// }

int		ft_checkquotes(char *argument)
{
	int n;

	n = 0;
	while (argument[n])
	{
		if (argument[0] == '-')
        	n++;
		if (!ft_isdigit(argument[n]))
			return(1);
		n++;
	}
	return(0);
}