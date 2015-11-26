#!/usr/bin/python2

import vcf
from island_counter_ext import IslandCounter

filename = './chr22head.vcf.gz'
reader = vcf.Reader(open(filename, 'r'))

c = IslandCounter()

c.read(reader)

print(c.maximum_stretch(20000000))
