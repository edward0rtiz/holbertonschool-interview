#!/usr/bin/python3
"""Script to get stats from a request"""

import sys

codes = {}
status_codes = ['200', '301', '400', '401', '403', '404', '405', '500']
count = 0
size = 0

try:
    for ln in sys.stdin:
        if count == 10:
            print("File size: {}".format(size))
            for key in sorted(codes):
                print("{}: {}".format(key, codes[key]))
            count = 1
        else:
            count += 1

        ln = ln.split()

        try:
            size = size + int(ln[-1])
        except (IndexError, ValueError):
            pass

        try:
            if ln[-2] in status_codes:
                if codes.get(ln[-2], -1) == -1:
                    codes[ln[-2]] = 1
                else:
                    codes[ln[-2]] += 1
        except IndexError:
            pass

    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))

except KeyboardInterrupt:
    print("File size: {}".format(size))
    for key in sorted(codes):
        print("{}: {}".format(key, codes[key]))
    raise
