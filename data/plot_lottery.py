import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os

def main():
    data = pd.read_csv('lottery.csv')
    plt.plot(list(range(0, 100)), data['10'].tolist(), label = '10 tickets')
    plt.plot(list(range(0, 100)), data['20'].tolist(), label = '20 tickets')
    plt.plot(list(range(0, 100)), data['30'].tolist(), label = '30 tickets')
    plt.xlabel('Time')
    plt.ylabel('Ticks')
    plt.legend()
    plt.show()

main()