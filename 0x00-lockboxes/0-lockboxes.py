#!/bin/python3

"""
Problem: You have n number of locked boxes in front of you.
         Each box is numbered sequentially from 0 to n - 1
         and each box may contain keys to the other boxes.
Task: Write a method that determines if all the boxes can be opened.
"""


def search_box(boxes, unlocked_box, n_box):
    """
    Recursive function to iterate over the boxes and open if the n_box
    is the same as the key_box
    """
    if len(n_box) > 0:
        for box_key in n_box:
            if (box_key < len(boxes)) and (box_key not in unlocked_box):
                unlocked_box.insert(-1, box_key)
                search_again = search_box(boxes, unlocked_box, boxes[box_key])
                unlocked_box = search_again
        return unlocked_box
    else:
        return unlocked_box


def canUnlockAll(boxes):
    """
    Function that checks with boolean value if the list type and
    length to invoke recursive function was True or not (False)
    """
    if type(boxes) is not list:
        return False
    elif (len(boxes)) == 0:
        return False
    for k_box in boxes:
        if type(k_box) is not list:
            return False
    boxes_checked = search_box(boxes, [0], boxes[0])
    if len(boxes_checked) == len(boxes):
        return True
    else:
        return False
