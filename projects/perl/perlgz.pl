#!/usr/bin/perl

use strict ;
use warnings ;
use Compress::Zlib ;

#use stdin if no files supplied
@ARGV = '-' unless @ARGV ;

foreach my $file (@ARGV) {
	my $buffer ;
	my $gz = gzopen($file, 'rb')
			or die "Cannot open $file: $gzerrno\n" ;
	print $buffer while $gz->gzread($buffer) > 0 ;
	die "Error reading from $file: $gzerrno" . ($gzerrno+0) . "\n"
		if $gzerrno != Z_STREAM_END ;
		$gz->gzclose() ;
}
