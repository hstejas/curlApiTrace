#!/usr/bin/env perl
use strict;
use warnings;
open my $f , ">","curlopttostr.h" or die $!;
my$begin=<<'END';
#pragma once
void printOptName(unsigned int option, long parameter)
{
    switch(option)
    {
END
open my $en, "<", "curlenum.h" or die $!;
my @out = <$en>;
print $f $begin;
foreach (@out)
{
    if(/CINIT\((.+), (.+), \d+/)
    {
        my $opt=$1; 
        my $type=$2;
        my $str = qq(...");
        $str = qq(%ld", parameter) if($type eq "LONG");
        $str = qq(%s", (char*)parameter) if($type eq "STRINGPOINT");
        print $f " "x8 ."case CURLOPT_$opt: printf(\"CURLOPT_$opt, $str); break;\n";
    }
}

my $end =<<'END';
    default:
        printf("UNKNOWN, AAAAAAAAAAARRRRGH");
        break;
    }
    printf(")\n");
}
END

print $f $end;
