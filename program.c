// Multiplicative Order Finder

#include <stdio.h>

int find_greatest_common_divisor(int a, int b)
{
    return b ? find_greatest_common_divisor(b, a % b) : a;
}

int exponentiate_modularly(int base, int index, int modulus)
{
    if (base == 0) return 0;
    if (index == 0) return 1;

    if (base > modulus) base %= modulus;
    if (index == 1) return base;
    
    int residue = 1;
            
    while (index)
    {
        if (index & 1) residue = (residue * base) % modulus;
        
        base = (base * base) % modulus;
        index >>= 1;
    }
    
    return residue;    
}

int find_multiplicative_order(int modulus, int base)
{
    if (find_greatest_common_divisor(modulus, base) != 1) return -1;
    
    for (int order = 1; order < modulus; order++)
        if (exponentiate_modularly(base, order, modulus) == 1) return order;
}

int main()
{
    int input, status, buffer;
    
    for (;;)
    {
        printf("Enter an integer modulus: ");
    
        status = scanf("%d", & input);
        	
    	while (status != 1)
    	{
            while ((buffer = getchar()) != EOF && buffer != '\n');
            
            printf("Invalid input.");
            printf("\n\n");
            printf("Enter an integer modulus: ");
            
            status = scanf("%d", & input);
    	}
    	
    	int modulus = input;
    	
    	printf("Enter an integer base: ");
    	
    	status = scanf("%d", & input);
        	
    	while (status != 1)
    	{
            while ((buffer = getchar()) != EOF && buffer != '\n');
            
            printf("Invalid input.");
            printf("\n\n");
            printf("Enter an integer base: ");
            
            status = scanf("%d", & input);
    	}
    	
    	int base = input;
        
        int multiplicative_order = find_multiplicative_order(modulus, base);
        
        if (multiplicative_order == -1)
            printf("\nThe base is not coprime to the modulus.");
        else
            printf("\nThe multiplicative order of %d modulo %d is %d.", base, modulus, multiplicative_order);
        
        printf("\n\n");
    }
    
    return 0;
}
