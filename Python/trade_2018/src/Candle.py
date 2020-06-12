##
## EPITECH PROJECT, 2019
## trade_2018
## File description:
## Candle
##

from datetime import datetime

class Candle(object):
    def __init__(self, array):
        self.candle = {
            "pair": array[0],
            "date": datetime.fromtimestamp(int(array[1])),
            "high": float(array[2]),
            "low": float(array[3]),
            "open": float(array[4]),
            "close": float(array[5]),
            "volume": float(array[6]),
        }
    
    def getCandle(self):
        return self.candle

