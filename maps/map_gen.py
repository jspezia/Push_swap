#!/usr/bin/python

import sys;
import random;

print ' '.join([str(a) for a in random.sample(xrange(sys.argv[1], sys.argv[2]), sys.argv[3])]);
