from dadata import Dadata


def request(token, secret, language):
    """
    Finds the coordinates of the address requested by the user
    :param token: API-key
    :param secret: secret key
    :param language: language answer
    :return: None
    """
    while True:
        answers = []
        req = input("Введите адрес: ")
        if req == "exit":
            break
        data = Dadata(token, secret)
        result = data.suggest(name="address", query=req, count=20, language=language)
        if not result:
            print("Ничего не найдено")
            continue
        for i, res in enumerate(result, start=1):
            answers.append(res['value'])
            print(f"№ {i}: {res['value']}")

        addr = input("Введите номер подходящего адреса: ")
        if addr == "exit":
            break
        print(f"Вы выбрали номер {addr}")
        try:
            if int(addr) - 1 >= 0:
                addr = int(addr) - 1
                a = data.clean("address", answers[addr])
            else:
                raise ValueError
        except (IndexError, ValueError):
            print("Неверный номер")
        else:
            print(f"Адрес: {a['result']}")
            print(f"Координаты адреса: широта {a['geo_lat']}, долгота {a['geo_lon']}")


