from decimal import Decimal
import math

words = ["Первый груз", "Второй груз", "оба груза"]
bowl = ["Правая чаша", "Левая чаша", "Метод двойного взвешивания"]

n = 3 # Количество измерений
k = n * (n - 1) # Коэф.
q = 6 # Окргуление в расётах (до N-го знака после запятой)
r = 3 # Округление при выводе данных на экран (до N-го знака после запятой)
s_base = Decimal('0.01') # Погрешность весов (минимально возможный грузик. Здесь 10 мг)

m = [[[Decimal('13.80'), Decimal('13.81'), Decimal('13.79')], 
    [Decimal('13.80'), Decimal('13.79'), Decimal('13.80')], 
    [Decimal('13.80'), Decimal('13.80'), Decimal('13.795')]], 
    [[Decimal('23.83'), Decimal('23.82'), Decimal('23.82')], 
    [Decimal('23.81'), Decimal('23.81'), Decimal('23.81')], 
    [Decimal('23.82'), Decimal('23.815'), Decimal('23.815')]],
    [[Decimal('37.63'), Decimal('37.63'), Decimal('37.62')], 
    [Decimal('37.59'), Decimal('37.60'), Decimal('37.60')], 
    [Decimal('37.61'), Decimal('37.615'), Decimal('37.61')]]]
#  Таблица (матрица) состоит из "3 столбов" и "9 строк"
#  1-й столбец - левая чаша весов, 2-й - правая, 3-й метод двойного взвешивания
#  На каждый объект (1-й, 2-й, 1-й + 2-й) выделено по 3 строки соответственно

for i in range(n):
    print(words[i].upper())
    print("=====================")
    for j in range(n):
        print('---------------------')
        print(bowl[j])
        m_mid = round(Decimal(str(sum(m[i][j])/n)), q)
        print(f"m{i+1} сред. = {round(Decimal(str(m_mid)), r)}")
        sm_mid = round(Decimal(str(math.sqrt(Decimal(str(1 / k)) * Decimal(str(Decimal(str((Decimal(str(m_mid - m[i][j][0])) ** 2))) + Decimal(str(Decimal(str(m_mid - m[i][j][1])) ** 2)) + Decimal(str(Decimal(str(m_mid - m[i][j][2])) ** 2))))))), q)
        print(f"Sm{i+1} сред. = {str(round(Decimal(str(sm_mid)), r+q))[:-r]}")
        sm = round(Decimal(str(math.sqrt(Decimal(str(s_base ** 2)) + Decimal(str(sm_mid ** 2))))), q)
        print(f"Sm{i+1} = {str(round(Decimal(str(sm)), r+q))[:-r]}")
        print(f"Итоговое измерение: {str(round(Decimal(str(m_mid)), r+q))[:-r]} +- {str(round(Decimal(str(sm)), r+q))[:-r]}")
        print('---------------------')
    print("=====================")
    for _ in range(2): print()

# "S" в выводе означает "сигма" (обозначение для погрешности)