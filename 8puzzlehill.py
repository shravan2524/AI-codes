import copy

choice = int(input('Press 1 for Default board\nPress 2 for board with blank at 9th Cell\nPress 3 for Custom Board\n'))
if choice == 1:
    goal = {1:[0,0],2:[0,1],3:[0,2],4:[1,2],5:[2,2],6:[2,1],7:[2,0],8:[1,0],0:[1,1]}
elif choice == 2:
    goal = {1:[0,0],2:[0,1],3:[0,2],4:[1,0],5:[1,1],6:[1,2],7:[2,0],8:[2,1],0:[2,2]}
else:
    print("Enter Values for Goal state")
    goal = {}
    for i in range(3):
        goal_temp = input().split(' ')
        goal[int(goal_temp[0])] = [i,0]
        goal[int(goal_temp[1])] = [i,1]
        goal[int(goal_temp[2])] = [i,2]

print("Enter Values in 3*3 Puzzle")
initial = []
for i in range(3):
    temp = input().split(' ')
    temp = [int(i) for i in temp]
    initial.append(temp)

def calculate_manhattan(initial,goal):
    md = 0
    empty = []
    for i in range(3):
        for j in range(3):
            num = initial[i][j]
            if num == 0:
                empty.append([i,j])
            else:
                org_pos = goal.get(num)
                if org_pos[0] == i and org_pos[1] == j:
                    continue
                else:
                    md = md + abs(org_pos[0]-i) + abs(org_pos[1]-j)
            # print(num,abs(org_pos[0]-i) + abs(org_pos[1]-j))
    return md,empty[0]

def display(initial):
    for i in range(3):
        print(str(initial[i][0])+'\t'+str(initial[i][1])+"\t"+str(initial[i][2])+'\n')

def simulate(initial,goal,empty,moves,dist):
    temp_initial = []
    temp_dist = dist
    temp_empty = []
    main_move = ""
    # print(initial)
    # print(dist)
    # print('Start')
    for move in moves:
        # print(move)
        temp = copy.deepcopy(initial)
        if move == 'UP':
            zero = temp[empty[0]][empty[1]]
            temp[empty[0]][empty[1]] = temp[empty[0]+1][empty[1]]
            temp[empty[0]+1][empty[1]] = zero
        if move == 'DOWN':
            zero = temp[empty[0]][empty[1]]
            temp[empty[0]][empty[1]] = temp[empty[0]-1][empty[1]]
            temp[empty[0]-1][empty[1]] = zero
        if move == "RIGHT":
            zero = temp[empty[0]][empty[1]]
            temp[empty[0]][empty[1]] = temp[empty[0]][empty[1]+1]
            temp[empty[0]][empty[1]+1] = zero
        if move == "LEFT":
            zero = temp[empty[0]][empty[1]]
            temp[empty[0]][empty[1]] = temp[empty[0]][empty[1]-1]
            temp[empty[0]][empty[1]-1] = zero
        td,te = calculate_manhattan(temp,goal)
        # print(temp,td)
        if temp_dist > td:
            temp_dist = td
            temp_initial = copy.deepcopy(temp)
            temp_empty = te
            main_move = move
    if temp_dist == dist:
        return -1,-1,-1
    if main_move == 'DOWN':
        print("Move Number 0 UP")
    elif main_move == 'UP':
        print("Move Number 0 DOWN")
    elif main_move == "LEFT":
       print("Move Number 0 LEFT")
    elif main_move == "RIGHT":
        print("Move Number 0 RIGHT")
    display(temp_initial)
    print('-----------------------------------------------------------')
    return temp_initial,temp_dist,temp_empty

def solve(initial,goal):
    dist = 0
    dist, empty = calculate_manhattan(initial,goal)
    print('-----------------------------------------------------------')
    print('\n\n Initial State')
    display(initial)
    while(1):
        i = empty[0]
        j = empty[1]
        if (i==1) and (j == 1):
            initial,dist,empty = simulate(initial,goal,empty,['UP','DOWN','LEFT','RIGHT'],dist)
        elif (i==0 and j==0) or (i==0 and j==2) or (i==2 and j == 2) or (i==2 and j==0):
            if i==0:
                if j == 0:
                    initial,dist,empty = simulate(initial,goal,empty,['UP','RIGHT'],dist)
                else:
                    initial,dist,empty = simulate(initial,goal,empty,['UP','LEFT'],dist)
            else:
                if j == 2:
                    initial,dist,empty = simulate(initial,goal,empty,['DOWN','LEFT'],dist)
                else:
                    initial,dist,empty = simulate(initial,goal,empty,['DOWN','RIGHT'],dist)
        else:
            if i == 0:
                initial,dist,empty = simulate(initial,goal,empty,['UP','LEFT','RIGHT'],dist)
            elif i ==1:
                if j == 0:
                    initial,dist,empty = simulate(initial,goal,empty,['UP','DOWN','RIGHT'],dist)
                else:
                    initial,dist,empty = simulate(initial,goal,empty,['UP','DOWN','LEFT'],dist)
            else:
                initial,dist,empty = simulate(initial,goal,empty,['DOWN','LEFT','RIGHT'],dist)
        if initial == -1:
            print("No solution Possible")
            break
        if dist == 0:
            break
solve(initial,goal)