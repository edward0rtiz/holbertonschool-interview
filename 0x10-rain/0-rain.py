#!/usr/bin/python3
"""Trapping rain water"""


def water(arr, n):
    max_size = 0

    for i in range(1, n - 1):
        left = arr[i]
        for j in range(i):
            left = max(left, arr[j])
            right = arr[i]
        for j in range(i + 1, n):
            right = max(right, arr[j])

        max_size = max_size + (min(left, right) - arr[i])

    return max_size


def rain(walls):
    water_saved = water(walls, len(walls))
    return water_saved
