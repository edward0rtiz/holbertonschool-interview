#!/usr/bin/python3
"""Challenge UTF-8"""


def validUTF8(data):
    """
    method that determines if a given data
    set represents a valid UTF-8 encoding
    Args:
        data: data will be represented by a list
              of integers
    Return: True if data is a valid UTF-8 encoding,
            else return False
    """

    n_bytes = 0

    mask1 = 1 << 7
    #print("-------M2", mask1)
    mask2 = 1 << 6
    #print("-------M2", mask2)

    for i in data:
        mask = 1 << 7
        if n_bytes == 0:
            while mask & i:
                n_bytes += 1
                mask = mask >> 1
                #print("-------M3", mask)
            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (i & mask1 and not (i & mask2)):
                return False
        n_bytes -= 1
    #print("-------NB", n_bytes)
    return n_bytes == 0