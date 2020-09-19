#!/usr/bin/python3
"""Count It"""
import requests


def count_words(subreddit, word_list, hot_list_titles=[], after='null'):
    """ returns a list containing the titles
    of all hot articles for a given subreddit.
    """
    base_url = 'https://www.reddit.com/r/'
    url = base_url + subreddit + "/hot.json"
    credentials = {'User-Agent': "Mozilla/5.0 (X11; CrOS x86_64 10066.0.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.105 Safari/537.36"}
    parameters = {"limit": "100", "after": after}
    response = requests.get(url,
                            headers=credentials,
                            params=parameters,
                            allow_redirects=False)
    if response.status_code != 200:
        return None

    hot_list_of_dicts = response.json().get("data").get("children")
    after = response.json().get("data").get("after")
    """""to print the after string, which acts as a "pointer"
    to the next response uncomment the following line"""
    # print(after)
    hot_list_titles.extend([reddit.get("data").get("title") for
                            reddit in hot_list_of_dicts])
    """to print the length of the hot_list_titles uncomment
    the following line"""
    # print(len(hot_list_titles))

    if after is None:
        to_print_dict = {x: 0 for x in word_list}
        for word in word_list:
            count = 0
            for title in hot_list_titles:
                split_title = title.split()
                new_split = [element.lower() for element in split_title]
                count = count + new_split.count(word.lower())
            if count != 0:
                to_print_dict[word] = to_print_dict[word] + count

        for elem in sorted(to_print_dict.items(), key=lambda x: (-x[1], x[0])):
            if elem[1] != 0:
                print("{}: {}".format(elem[0], elem[1]))
    else:
        return count_words(subreddit, word_list,
                           hot_list_titles, after)
