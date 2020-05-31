#!/usr/bin/env python3

import sys

codes = {}
status_codes = [200, 301, 400, 401, 403, 404, 405, 500]
count = 0
size = 0

try:
    for ln in sys.stdin:
        if count == 10:
            print("File size: {}".format(size))
            for key in codes:
                print("{}: {}".format(key, status_codes[key]))
            count = 1
        else:
            count += 1
        line = ln.split()

        try:
            size = size + int(line[-1])
            print(line)
        except (ValueError, IndexError):
            pass
        try:
            if line[-1] in status_codes:
                if codes.get(line[-2], -1) == -1:
                    codes[line[-2]] = 1
                else:
                    codes[line[-2]] += 1
        except IndexError:
            pass

    print("File size: {}".format(size))
    for key in codes:
        print("{}: {}".format(key, status_codes[key]))

except KeyboardInterrupt:
    print("File size: {}".format(size))
    for key in codes:
        print("{}: {}".format(key, status_codes[key]))
    raise

