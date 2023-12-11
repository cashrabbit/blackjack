#!/bin/sh
g++ -c runBlackjack.cpp
g++ -c gameDef.cpp
g++ -c welcomeDef.cpp
g++ -c gameRun.cpp
g++ -c runFiveCard.cpp
g++ -c poker.cpp
g++ runBlackjack.o gameDef.o welcomeDef.o gameRun.o runFiveCard.o poker.o -o playgame
./playgame

#Runs blackjack and then bets 50
