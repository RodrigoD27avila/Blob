#!/usr/bin/perl

use strict ;
use warnings ;

my @arrdata = (0xA, 0x9, 0x3, 1, 0xa, 0xf, 0xf, 0x2, 0x5, 0xb, 0x6, 0x3, 0x6, 0x1, 0x1, 0x1) ;
print scalar(@arrdata) ;
my @arrdef = (0) ;
my $i = 0 ;
my $j = 1 ;

while (1) {
	
	if ($arrdata[$i] > $arrdata[$j]) {
		1
	}

}


