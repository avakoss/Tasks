import sqlite3


def create_table():
    """
    Create a table if it doesn't exist yet
    :return: None
    """
    connection = sqlite3.connect("settings.db")
    cursor = connection.cursor()
    cursor.execute("CREATE TABLE IF NOT EXISTS setting(token TEXT, key TEXT, language TEXT)")
    connection.commit()


def add_info(token, key, language):
    """
    Create a table if it doesn't exist yet and adds user information
    :param token: api-key
    :param key: secret key
    :param language: response language
    :return: None
    """
    connection = sqlite3.connect("settings.db")
    cursor = connection.cursor()
    info = (token, key, language)
    cursor.execute("INSERT INTO setting VALUES (?, ?, ?)", info)
    connection.commit()


def answer(token):
    """
    :param token: API-key
    :return: user data
    """
    connection = sqlite3.connect("settings.db")
    cursor = connection.cursor()
    cursor.execute("SELECT * FROM setting WHERE token = (?)", (token, ))
    ans = cursor.fetchone()
    connection.commit()
    return ans


def delete():
    """
    Delete table
    :return: None
    """
    connection = sqlite3.connect("settings.db")
    cursor = connection.cursor()
    cursor.execute("DROP TABLE IF EXISTS setting")
    connection.commit()
