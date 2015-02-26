#!/usr/bin/python

import sys;
import random;

def main():
	range_min = (int)(sys.argv[1]);
	range_max = (int)(sys.argv[2]);
	n_elem = (int)(sys.argv[3]);

	print ' '.join([str(a) for a in random.sample(xrange(range_min, range_max), n_elem)]);

if __name__ == "__main__":
    main()
