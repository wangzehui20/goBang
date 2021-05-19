# goBang(五子棋)

This goBang code is implemented by c++ displaying in cmd or powershell with three mode: 

**1.player vs player**

**2.player vs computer**

**3.computer**

If chessboard is not aligned during display in cmd, you need to set it compatible with older console.

## Usage

### 1.Rebuild solution 

New folder in directory, for example: build. `cd build` in cmd or powershell,  then `cmake ..`

### 2.Play

**key: W A S D** represents up, left, down, right.

**key: Space** represents dropping chess pieces. 

## Reference

This code based on [gobang-Cpp](https://github.com/DavinciEvans/gobang-Cpp), but original code has some shortages. For example, if chess status is block4, next step will win. Otherwise, next step can not win directly and drop other positions which may be algorithm or chess status weights problems(chess status weights may influence our performance.). 

Also, you can learn more about **local search algorithm**, **miniMax search algorithm** and **α-β pruning algorithm** in [五子棋ai](https://blog.csdn.net/livingsu/article/details/104544562?spm=1001.2014.3001.5501) and its code [Gobang-ai](https://github.com/livingsu/Gobang-ai).



