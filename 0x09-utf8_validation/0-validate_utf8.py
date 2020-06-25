#!/usr/bin/python3
"""Challenge UTF-8"""


def validUTF8(data):
    """
    Bit manipulation leetcode.com implementation
    method that determines if a given data
    set represents a valid UTF-8 encoding
    Args:
        data: data will be represented by a list
              of integers
    Return: True if data is a valid UTF-8 encoding,
            else return False
    """

    n_bytes = 0

    m1 = 1 << 7
    m2 = 1 << 6

    for i in data:
        m = 1 << 7
        if n_bytes == 0:
            while m & i:
                n_bytes += 1
                m = m >> 1
            if n_bytes == 0:
                continue
            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (i & m1 and not (i & m2)):
                return False
        n_bytes -= 1
    return n_bytes == 0
