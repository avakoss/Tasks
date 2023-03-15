from query import request
from database import create_table, add_info, answer

create_table()
token = input("Введите API-ключ: ")
info = answer(token)
if info is None:
    secret = input("Введите секретный ключ: ")
    language = input("Выберите язык en/ru: ")
    if language != "ru" and language != "en":
        language = "ru"
    add_info(token, secret, language)
else:
    token = info[0]
    secret = info[1]
    language = info[2]
print("Если хотите выйти, напишите exit")
request(token, secret, language)
