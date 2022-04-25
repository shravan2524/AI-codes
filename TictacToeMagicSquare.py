from tkinter import dialog


def TicTacToe():
  board = [1, 2, 3, 4, 5, 6, 7, 8, 9]
  end = False
  MagicSquare = [4, 9, 2,
                 3, 5, 7, 
                8, 1, 6]
  # MagicSquare is a square which has the sum of rows, column and dialogs equal to 15

  # Printing my tic tac toe board
  def PrintBoard():
    print()
    print('', board[0], "|", board[1], "|", board[2])
    print("---|---|---")
    print('', board[3], "|", board[4], "|", board[5])
    print("---|---|---")
    print('', board[6], "|", board[7], "|", board[8])
    print()


# Taking input from the user
  def GetNumber():
    while True:
      number = input()
      try:
        number  = int(number)
        if number in range(1, 10):
          return number
        else:
          print("\nNumber not on board")
      except ValueError:
        print("\nThat's not a number. Try again")
        continue

    # Its check the cell is occupied or not
  def Turn(player):
    placing_index = GetNumber() - 1
    if board[placing_index] == "X" or board[placing_index] == "O":
      print("\nBox already occupied. Try another one")
      Turn(player)
    else:
      board[placing_index] = player

# Checks whether then player is wining or not
  def CheckWin(player):
    count = 0
    for x in range(9):
      for y in range(9):
        for z in range(9):
          if x != y and y != z and z != x:
            if board[x] == player and board[y] == player and board[z] == player:
              if MagicSquare[x] + MagicSquare[y] + MagicSquare[z] == 15:
                print("Player", player ,"wins!\n")
                return True

    for a in range(9):
      if board[a] == "X" or board[a] == "O":
        count += 1
      if count == 9:
        print("The game ends in a Tie\n")
        return True

  while not end:
    PrintBoard()
    end = CheckWin("O")
    if end == True:
      break
    print("Choose a box player X")
    Turn("X")

    PrintBoard()
    end = CheckWin("X")
    if end == True:
      break
    print("Choose a box player O")
    Turn("O")


TicTacToe()
