#include "libftprintf.h"


int     main()
{
    int sxoriginale;
    int sxmio;
    //int dxmio;
    //int dxoriginale;
    int i = 0;


    //char str[10]= "test12";

    sxoriginale = printf("|%-*.*d|", 4, 3, -12);
    printf("\n");
    sxmio =    ft_printf("|%-*.*d|", 4, 3, -12);

    printf("\nsx originale: %d \nsx mio : %d\n", sxoriginale, sxmio);
    printf("\n");

    // sxoriginale = printf("this %d number", 0);
    // printf("\n");
    // sxmio =    ft_printf("this %d number", 0);
    // // printf("\n");
    // // sxoriginale = printf("%-010.5s", "test");
    // // printf("\n");
    // // sxmio =    ft_printf("%-010.5s", "test");
 
    // printf("\nsx originale: %d \nsx mio : %d\n", sxoriginale, sxmio);
    // printf("\n");
    // dxoriginale = printf("dx: prova [%15.5s] test2 %c %020.5%  %% \n", "test", 'a');
    // dxmio =    ft_printf("dx: prova [%15.5s] test2 %c %020.5%  %% \n", "test", 'a');
    
    // printf("\nsx originale: %d \nsx mio : %d\n", sxoriginale, sxmio);
    // printf("\n");

    // sxoriginale = printf("sx: prova [%-20.8d] test2 %c\n", 123456, 'k');
    // sxmio =    ft_printf("sx: prova [%-20.8d] test2 %c\n", 123456, 'k');

    // printf("\nsx originale: %d \nsx mio : %d\n", sxoriginale, sxmio);
    // printf("\n");

    // sxoriginale = printf("sx: prova [%-20.*d] test2 %c\n", -1000, 123456, 'k');
    // sxmio =    ft_printf("sx: prova [%-20.*d] test2 %c\n", -1000, 123456, 'k');
 
    // printf("\nsx originale: %d \nsx mio : %d\n", sxoriginale, sxmio);

    // dxoriginale = printf("dx: prova [%010.5u] test2 %c\n", 111, 'a');
    // dxmio =    ft_printf("dx: prova [%010.5d] test2 %c\n", 111, 'a');

    // printf("\nsx originale: %d \nsx mio : %d\n", sxoriginale, sxmio);
    // printf("\ndx originale: %d \ndx mio : %d\n", dxoriginale, dxmio);

    // int val0;
    // int val1;
    // printf("\n");
    // //val0 = printf("%% *.5i 42 == |%2u|\n", 4147483648);
    // //val1 = ft_printf("%% *.5i 42 == |%2u|\n", 4147483648);
    // val0 = printf("%% *.5i 42 == |%040.5X|\n", 42);
    // val1 = ft_printf("%% *.5i 42 == |%040.5X|\n", 42);
    // val0 = printf("%% *.5i 42 == |%040.5x|\n", -42);
    // val1 = ft_printf("%% *.5i 42 == |%040.5x|\n", -42);
    // printf("Return : (%d //", val0);
    // printf(" %d)\n", val1); 
    return (0); 
}