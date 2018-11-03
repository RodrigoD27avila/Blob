#!/usr/bin/perl
# perlgzcomp.pl
# Rodrigo D'avila

use strict ;
use warnings ;
use Compress::Zlib;

my $comp = compress("rodrigo" x 1000);

#print "$comp";

print length($comp);
