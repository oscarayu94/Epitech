##
## EPITECH PROJECT, 2019
## trade_2018
## File description:
## Bot
##

import sys
from datetime import datetime
from src.Candle import *

class Bot(object):
    def __init__(self):
        self.settings = {
            "timebank": 0,
            "time_per_move": 0,
            "candle_interval": 0,
            "candles_total": 0,
            "candles_given": 0,
            "initial_stack": 0,
            "candle_format": {},
            "transaction_fee_percent": float(0),
        }
        self.candleList = []
        # self.candle = {
        #     "timebank": 0,
        #     "date": datetime(2000, 1, 1, 0, 0, 0, 0000),
        #     "charts": {}
        # }

    def run(self):
        for line in sys.stdin:
            arrayLine = line.split(" ")
            if arrayLine[0] == "settings":
                if arrayLine[1] != "" and arrayLine[2] != "":
                    self.setSettings(arrayLine[1], arrayLine[2])
                # print(self.settings)
            if arrayLine[0] == "update" and arrayLine[1] == "game":
                self.parseGame(arrayLine)
            if arrayLine[0] == "action":
                print("pass")

    def setSettings(self, setting, val):
        if setting == "timebank":
            self.settings["timebank"] = int(val)
        if setting == "time_per_move":
            self.settings["time_per_move"] = int(val)
        if setting == "candle_interval":
            self.settings["candle_interval"] = int(val)
        if setting == "candles_total":
            self.settings["candles_total"] = int(val)
        if setting == "candles_given":
            self.settings["candles_given"] = int(val)
        if setting == "initial_stack":
            self.settings["initial_stack"] = int(val)
        if setting == "transaction_fee_percent":
            self.settings["transaction_fee_percent"] = float(val)
        if setting == "candle_format":
            self.settings["candle_format"] = val.split(",")

    def parseGame(self, arrayLine):
        if arrayLine[2] == "next_candles":
            self.next(arrayLine[3])
        if arrayLine[2] == "stacks":
            self.stacks(arrayLine[3])

    def next(self, string):
        candleSection = string.split(";")
        for sec in candleSection:
            can = Candle(sec.split(","))
            self.candleList.append(can)
            # print(self.candleList)
            for candlel in self.candleList:
                print(candlel.getCandle())

    def stacks(self, string):
        stacks = string.split(",")
        for stack in stacks:
            currency, num = stack.split(":")
