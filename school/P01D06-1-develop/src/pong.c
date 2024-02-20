// I WANT TO PLAY WITH YOU
//         YOUR FRIEND, AI

#include <stdio.h>

int playGame();
int isWin(int);
void drawScore(int, int);
void drawField(int, int, int, int);
int playerCanMove(int, int);
int playerInput(int, int);
int ballDir(int, int, int, int, int);

int main(void) {
  int gameCode = playGame();

  printf("PLAYER %d HAS WON!\nThanks for playing :)\n", gameCode);

  return 0;
}

int playGame() {
  int r1y = 12, r2y = 12;
  int bx = 39, by = 12, dir = 1;
  int s1 = 0, s2 = 0;

  while (s1 < 21 && s2 < 21) {
    if (isWin(bx) == 1) {
      printf("\n\nPLAYER 1 HAS WON!\n");
      s1++;
      r1y = r2y = by = 12;
      bx = 39;
      dir = 1;
    } else if (isWin(bx) == -1) {
      printf("\n\nPLAYER 2 HAS WON!\n");
      s2++;
      r1y = r2y = by = 12;
      bx = 39;
      dir = 1;
    }
    drawScore(s1, s2);
    drawField(r1y, r2y, bx, by);
    r1y = playerInput(1, r1y);
    r2y = playerInput(2, r2y);
    dir = ballDir(r1y, r2y, bx, by, dir);

    switch (dir) {
    case 1:
      bx--;
      by--;
      break;
    case 2:
      bx++;
      by--;
      break;
    case 3:
      bx--;
      by++;
      break;
    case 4:
      bx++;
      by++;
      break;
    }
}

  return s1 > s2 ? 1 : 2;
}

int isWin(int x) {
  if (x == 79)
    return 1;
  else if (x == 0)
    return -1;
  return 0;
}

void drawScore(int s1, int s2) {
  printf("\n*************************\nSCORE: %d - "
         "%d\n*************************\n",
         s1, s2);
}

void drawField(int r1y, int r2y, int bx, int by) {
  printf("----------------"
         "----------------"
         "----------------"
         "----------------"
         "----------------"
         "--\n");
  for (int y = 0; y < 25; y++) {
    for (int x = -1; x <= 80; x++) {
      if (x == -1 || x == 80) {
        printf("|");
      } else if (x == 0) {
        if (y + 1 == r1y || y == r1y || y - 1 == r1y)
          printf("#");
        else
          printf(" ");
      } else if (x == 79) {
        if (y + 1 == r2y || y == r2y || y - 1 == r2y)
          printf("#");
        else
          printf(" ");
      } else if (x == bx && y == by)
        printf("@");
      else
        printf(" ");
    }
    printf("\n");
  }
  printf("----------------"
         "----------------"
         "----------------"
         "----------------"
         "----------------"
         "--\n");
}

int playerCanMove(int dir, int ry) {
  if ((dir == 1 && ry == 1) || (dir == -1 && ry == 23))
    return 0;
  return 1;
}

int playerInput(int turn, int ry) {
  char dir;
  while (1) {
    if (turn == 1) {
      printf("PLAYER 1: Choose up or down (a/z): ");
      dir = getchar();
      while (getchar() != '\n')
        ;

      if (dir == 65 || dir == 97) {
        if (playerCanMove(1, ry))
          return --ry;
        else {
          printf("You cannot go upper!\n");
          continue;
        }
      }

      else if (dir == 90 || dir == 122) {
        if (playerCanMove(-1, ry))
          return ++ry;
        else {
          printf("You cannot go lower!\n");
          continue;
        }
      }

      else if (dir == 32) {
        printf("Skipping\n");
        return ry;
      }

      else {
        printf("Invalid input!\n\n");
        continue;
      }
    }

    if (turn == 2) {
      printf("PLAYER 2: Choose up or down (k/m): ");
      dir = getchar();
      while (getchar() != '\n')
        ;

      if (dir == 75 || dir == 107) {
        if (playerCanMove(1, ry))
          return --ry;
        else {
          printf("You cannot go upper!\n");
          continue;
        }
      }

      else if (dir == 77 || dir == 109) {
        if (playerCanMove(-1, ry))
          return ++ry;
        else {
          printf("You cannot go lower!\n");
          continue;
        }
      }

      else if (dir == 32) {
        printf("Skipping\n");
        return ry;
      }

      else {
        printf("Invalid input!\n\n");
        continue;
      }
    }
  }
}

int ballDir(int r1y, int r2y, int bx, int by, int dir) {
  if (by == 0 && dir == 1)
    return 3;
  else if (by == 0 && dir == 2)
    return 4;
  else if (by == 24 && dir == 4)
    return 2;
  else if (by == 24 && dir == 3)
    return 1;
  else if ((bx == 1) && (dir == 3) &&
           (by == r1y || by == r1y + 1 || by == r1y - 1))
    return 4;
  else if ((bx == 1) && (dir == 1) &&
           (by == r1y || by == r1y + 1 || by == r1y - 1))
    return 2;
  else if ((bx == 78) && (dir == 4) &&
           (by == r2y || by == r2y + 1 || by == r2y - 1))
    return 3;
  else if ((bx == 78) && (dir == 2) &&
           (by == r2y || by == r2y + 1 || by == r2y - 1))
    return 1;
  return dir;
}
