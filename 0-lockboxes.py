#!/bin/python3

def search_box(boxes, locked_box, n_box):
    if len(n_box) > 0:
        for box_key in n_box:
            if (box_key < len(boxes)) and (box_key not in n_box):
                #if (locked_box not in box_key) and (box_key < len(n_box)):
                locked_box.inser(-1, box_key)
                search_again = search_box(boxes, locked_box, boxes[box_key])
                locked_box = search_again
        return locked_box
    else:
        return locked_box


def canUnlockAll(boxes):
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





""""boxes = [[1], [2], [3], [4], []]

print(canUnlockAll(boxes))
print(type(boxes))
print(len(boxes))
print('---->LB:', search_box(boxes, [0], boxes[0]))"""""