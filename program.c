// Multiplicative Order Finder

#include <stdio.h>

typedef unsigned long long integer;

integer find_greatest_common_divisor(integer a, integer b)
{
    return b ? find_greatest_common_divisor(b, a % b) : a;
}

integer exponentiate_modularly(integer base, integer index, integer modulus)
{
    if (base == 0) return 0;
    if (index == 0) return 1;
    if (modulus == 1) return 0;
    
    base %= modulus;
    
    integer modular_power = 1;
    
    while (index)
    {
        if (index & 1) modular_power = (modular_power * base) % modulus;
        
        base = (base * base) % modulus;
        index >>= 1;
    }
    
    return modular_power;
}

integer find_multiplicative_order(integer modulus, integer base)
{
    if (find_greatest_common_divisor(modulus, base) != 1) return -1;
    
    for (int order = 1; order < modulus; order++)
        if (exponentiate_modularly(base, order, modulus) == 1) return order;
}

integer main()
{
    integer input, status, buffer;
    
    for (;;)
    {
        printf("Enter an integer modulus: ");
        
        status = scanf("%llu", & input);
        	
        while (status != 1)
        {
            while ((buffer = getchar()) != EOF && buffer != '\n');
            
            printf("Invalid input.");
            printf("\n\n");
            printf("Enter an integer modulus: ");
            
            status = scanf("%llu", & input);
        }
        
        integer modulus = input;
        
        printf("Enter an integer base: ");
        
        status = scanf("%llu", & input);
        	
        while (status != 1)
        {
            while ((buffer = getchar()) != EOF && buffer != '\n');
            
            printf("Invalid input.");
            printf("\n\n");
            printf("Enter an integer base: ");
            
            status = scanf("%llu", & input);
        }
        
        integer base = input;
        
        integer multiplicative_order = find_multiplicative_order(modulus, base);
        
        if (multiplicative_order == -1)
            printf("\nThe base is not coprime to the modulus.");
        else
            printf("\nThe multiplicative order of %llu modulo %llu is %llu.", base, modulus, multiplicative_order);
            
        printf("\n\n");
    }
    
    return 0;
}
