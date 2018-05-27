#!/usr/bin/env perl
use strict;
use warnings;
open my $f , ">","curlopttostr.h" or die $!;
my @out = `gcc -E curlenum.h`;
my$begin=<<'END';
#pragma once
void printOptName(unsigned int option, long parameter)
{
    switch(option)
    {
END
print $f $begin;
foreach (@out)
{
    if(/(CURLOPT_.*) = (\d+)/)
    {
        my $opt=$1; 
        my $type=$2;
        my $str=qw(...");
        $str = qq(%ld", parameter) if($type == 0);
        $str = qq(%s", (char*)parameter) if($type == 10000 && $opt=~/(?!DATA)/);
        print $f " "x8 ."case $opt: printf(\"$opt, $str); break;\n";
    }
}

my $end =<<'END';
    default:
        printf("UNKNOWN, AAAAAAAAAAARRRRGH");
        break;
    }
    printf("\n");
}
END

print $f $end;
