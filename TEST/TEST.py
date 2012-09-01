#!/usr/bin/python env 
# -*- coding: utf-8 -*-

import sys

if __name__ == "__main__":
	while True:
		n = raw_input()
		if int(n) == 42:
			sys.exit()
		else:
			print n