import math
from decimal import Decimal


# ПРЕДУПРЕЖДЕНИЕ: В коде (не выводе на экран) коэффициенты "a" и "b" для расчёта имеют обратные обозначения


n = 10 # кол-во измеерений
q = 3 # Окргуление в расётах (до N-го знака после запятой)
t = 1_000_000 # Степень для подсчёта погрешности удельного сопротивления
s = Decimal('0.126') # Посчитаная площадь сечения проволоки
l = Decimal('502.41') # Посчитаная длина одного витка проволоки
ro = Decimal('0.001056') # Посчитаное удельное сопротивление

x_list = [10 + i*4 for i in range(n)]
y_list = [
    Decimal('44.40'), 
    Decimal('61.42'), 
    Decimal('78.18'), 
    Decimal('95.05'), 
    Decimal('112.28'), 
    Decimal('128.68'), 
    Decimal('145.54'), 
    Decimal('162.53'), 
    Decimal('179.30'), 
    Decimal('196.03')
] # Список замеренных измерений

x = Decimal(str(sum(x_list) / n)) # <x>
y = Decimal(str(sum(y_list) / n)) # <y>
xy = Decimal(str(sum([x_list[i] * y_list[i] for i in range(n)]) / n)) # <xy>
sqr_x = Decimal(str(sum([i ** 2 for i in x_list]) / n)) # <x^2>
sqr_y = Decimal(str(sum([i ** 2 for i in y_list]) / n)) # <y^2>

print(f"<x> = {x}")
print(f"<y> = {y}")
print(f"<xy> = {xy}")
print(f"<x^2> = {sqr_x}")
print(f"<y^2> = {sqr_y}")


a = Decimal(str(round((xy - (x * y)) / (sqr_x - (x ** 2)), q)))
print(f"b = {a}")

b = Decimal(str(round((y - a * x), q)))
print(f"a = {b}")

s_a = Decimal(str(round( Decimal(str(1/math.sqrt(n))) * Decimal(str(math.sqrt( Decimal(str( (sqr_y - (y ** 2)) / (sqr_x - (x ** 2)) - (a ** 2))) ))), q)))
print(f"Sb = {s_a}")

s_b = Decimal(str(round(( s_a * Decimal(str(math.sqrt(sqr_x - (x ** 2)))) ), q)))
print(f"Sa = {s_b}")

# Проверка изменения сопротивления между измерениями (не нужно для лабораторки. проверка на "аномалии", которых быть не должно)
print("============")
for i in range(9):
    print(f"{y_list[i+1]} - {y_list[i]} = {y_list[i+1] - y_list[i]}")
glist = []
for i in range(9):
    glist.append(y_list[i+1] - y_list[i])
print(sum(glist) / 9)
print("============")

s_ro = round(Decimal(str(math.sqrt(Decimal(str(Decimal(str(Decimal(str((s / l))) ** 2)) * Decimal(str(s_a ** 2)) + Decimal(str(Decimal(str((Decimal(str(a * s)) / Decimal(str(l ** 2))))) ** 2)) * Decimal(str(3.14 ** 2))))))) * t, q) #
print(f"Sro = {s_ro} * 10^(-{t//10})")
perc = round(Decimal(str((s_ro / t)/ ro)) * 100, q)
print(f"Percantage = {perc}%")
print(f"Answer: {round(ro * 1_000, 4)} +- {round(ro * 10 * perc, 4)}")