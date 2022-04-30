#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define uint unsigned int

int main( int argc, const char *argv[])
{
    uint maxnum = argc < 2 ? 250000
                           : atoi( argv[1]);

    uint *primes = malloc( sizeof( uint) * (10 + lrint( 1.15 * maxnum / log( maxnum))) );
    uint n_primes = 0;
    primes[ n_primes++ ] = 3;
    uint n_primes2 = 0;
    uint last_prime2 = primes[ n_primes2++ ] * 2;
    int tests = 0;

    for( uint num = 3; num <= maxnum; num += 2 )
    {
        uint i = 0;
        for( ; i < n_primes2; ++i )
        {
            if( num % primes[i] == 0 )
                goto LABEL;
        }
        primes[ n_primes++ ] = num;
LABEL:
        if( num > last_prime2 )
            last_prime2 = primes[ n_primes2++ ] * 2;

        tests -= i;
        if( tests < 0 )
        {
            tests = 50000000;
            printf( "p%u = %u\r", n_primes + 1, primes[ n_primes - 1 ]);
        }
    }

    printf( "p%u = %u\n", n_primes + 1, primes[ n_primes - 1 ]);

    //for( uint i = 0; i < n_primes; ++i )
    //    printf(", %u", primes[i]);
    //printf("\n");

    free( primes);
    return 0;
}

/*
int main1()
{
    int n_primes = 1;

    for( int n = 3; n < 250000; n += 2)
    {
        for( int p = 2; p <= n/2; p++)
        {
            if( n % p == 0 )
                goto aaa;
        }
        ++n_primes;
        aaa:;
    }

    printf("%d\n", n_primes);
    return 0;
}
*/
