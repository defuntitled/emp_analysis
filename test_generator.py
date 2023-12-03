import random
import string

def generate_random_ascii_strings(m, n, filename):
    # Создаем строку из всех печатаемых ASCII символов
    printable_ascii = [chr(i) for i in range(32, 127)]
    
    # Открываем файл для записи
    with open(filename, 'w') as file:
        file.write(f'{n} {m} {m}\n')
        # Генерируем m строк
        for _ in range(m):
            random_string = ''.join(random.choice(string.ascii_letters) for _ in range(n))
            file.write(random_string + '\n')  # Добавляем перевод строки после каждой сгенерированной строки

# Пример: сгенерировать 5 строк по 10 случайных символов и записать в файл 'output.txt'
params = [(10,20),(20,40),(500,500),(1000, 1000),(100,100000),(200,200000)]
for i in range(1,7):
    generate_random_ascii_strings(params[i-1][1], params[i-1][0], f'tests/input{i}.txt')
