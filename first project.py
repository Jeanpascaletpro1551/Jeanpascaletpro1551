""" first of all we must enter the year """
M = input("enter the corresponding year : ")
M = int(M)
""" we must subtract 1900 to this year  """
n = M - 1900
""" now we must take the rest of the division of n by 19 """
a = n % 19
""" we will do some operation until"""
paque = (a * 7) + 1
b = paque // 19
calcul1 = (11 * a) - b + 4
c = calcul1 % 29
d = n // 4
calcul2 = n - c + d + 31
e = calcul2 % 7
p = 25 - c - e
""" the day of the paque is in function of p 
if p <=0 this day is in March else it's in April"""
if p < 0:
    p1 = 31 + p
    print("this year the day of the paque is ", p1, "March")
elif p == 0:
    print("this year the day of paque is the 31 March ")
elif p == 1:
    print("this year the day of paque is the first April")
else:
    print("this year the day of paque is", p, "April")