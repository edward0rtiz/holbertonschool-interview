#!/usr/bin/python3
""" makechange challenge """


def makeChange(coins, total):
    """
    mkechange challenge
    """

    if total <= 0:
        return 0

    coins.sort(reverse=True)
    sum = 0
    i = 0
    counter = 0
    num_coins = len(coins)
    while sum < total and i < num_coins:
        while coins[i] <= total - sum:
            sum += coins[i]
            counter += 1
            if sum == total:
                return counter
        i += 1
    return -1
