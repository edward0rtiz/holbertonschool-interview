# 0x06 Log Parsing :neckbeard:

> Technical interview challenges

## Tasks :heavy_check_mark:

Write a script that reads stdin line by line and computes metrics:

Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C), print these statistics from the beginning:
Total file size: File size: <total size>
where <total size> is the sum of all previous <file size> (see input format above)
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear, don’t print anything for this status code
format: <status code>: <number>
status codes should be printed in ascending order

## Results :chart_with_upwards_trend:

| Filename |
| ------ |
| [0-stats.py](https://github.com/edward0rtiz/holbertonschool-interview/blob/master/0x06-log_parsing/0-stats.py)|

## Additional info :construction:
### Resources

- Python 3.6


### Try It On Your Machine :computer:
```bash
git clone https://github.com/edward0rtiz/holbertonschool-interview
cd 0x06-log_parsing
./0-generator.py | ./0-stats.py 
```
