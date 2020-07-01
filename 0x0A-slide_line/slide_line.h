#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

void move_right(int *line, size_t size);
void move_left(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);


#endif /* SLIDE_LINE_H */
