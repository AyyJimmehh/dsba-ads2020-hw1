import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv("C:/Users/Steve George Parakal/Desktop/AlgorithmCSV.csv")

fig = plt.figure()
ax = plt.axes()
ax.plot('Digit', ' GSA', data=df, label="GSA", color='blue');
ax.plot('Digit', ' Ktsba', data=df, label="Karatsuba", color='red')
ax.plot('Digit', ' DC ', data=df, label="Divide & Conquer", color='green')
plt.title("Algorithm Analysis")
plt.xlabel("Digits")
plt.ylabel("Seconds")
plt.legend()
plt.show()
