def is_available(xy, pindex):
    if xy[0]<0 or xy[1]<0 or xy[0]>=cols or xy[1]>=rows:
        return False
    if maze[xy[0]][xy[1]]=='#': return False
    for i in paths[pindex]:
        if xy==i:
            return False
    return True

def move(xy, pindex):
    paths[pindex].append(xy)
    if xy==(31,39): 
        global min
        if min>len(paths[pindex]):
            min=len(paths[pindex])
            print(min-1)
        return
    
    dir=[]
    for i in range(4):
        dir.append(False)
        
    x=xy[0]
    y=xy[1]
    ways=[(x,y-1),(x+1,y),(x,y+1),(x-1,y)]
    for i in range(4):
        dir[i]=is_available(ways[i], pindex)
        
    temp=[]
    temp=paths[pindex].copy()
    first=True
    for i in range(4):
        if dir[i]:
            if first:
                first=False
                move(ways[i], pindex)
            else:
                newpindex=pindex+1
                paths.append([])
                paths[newpindex] = temp.copy()
                move(ways[i], newpindex)
                      
    
rows=50
cols=50
puzzleinput=1352
min=555
maze=[]
for i in range(rows):
    maze.append([])
    for j in range(cols):
        maze[i].append('.')
        
for y in range(rows):
    for x in range(cols):
        n=x*x + 3*x + 2*x*y + y + y*y + puzzleinput
        count=0
        while n!=0:
            if n%2==1:
                count=count+1
            n=int(n/2)
        if count%2==0:
            maze[x][y]=' '
        else:
            maze[x][y]='#'

for y in range(rows):
    for x in range(cols):
        print(maze[x][y],end='')
    print('')

paths=[]
paths.append([])
move((1,1), 0)
    


