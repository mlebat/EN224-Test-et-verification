#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "assert.h"
#include "pgcd.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE( "Simple PGCD", "[pgcd]" ) {
    REQUIRE( PGCD(200,5) == 5 );
    REQUIRE( PGCD(17,759) == 1 );
    REQUIRE( PGCD(54321,54321) == 54321 );
}

TEST_CASE( "PGCD with exception", "[pgcd]" ) {
	REQUIRE( PGCD(200,0) == 200 );
	REQUIRE( PGCD(0,759) == 759 );
	REQUIRE( PGCD(0,0) == 0 );
}
