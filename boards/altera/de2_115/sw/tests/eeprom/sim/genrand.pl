#!/usr/bin/perl

for ($j = 0; $j<512; $j++)
{
	print "\t";
	for ($i = 0; $i < 8; $i++)
	{
		printf "0x%02X, ", int(rand(256));
	}
	print "\n";
}
