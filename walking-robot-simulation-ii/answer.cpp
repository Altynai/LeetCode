const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const string dir[4] = {"East", "North", "West", "South"};

class Robot {
private:
  int w, h;
  int x, y;
  int d;

public:
  Robot(int width, int height) {
    w = width, h = height;
    d = 0, x = 0, y = 0;
  }

  void move(int num) {
    int loop = (w * 2 + h * 2) - 4;
    if (num >= loop) {
      num %= loop;
      // handle special directions
      if (x == 0 && y == 0)
        d = 3;
      else if (x == w - 1 && y == 0)
        d = 0;
      else if (x == w - 1 && y == h - 1)
        d = 1;
      else if (x == 0 && y == h - 1)
        d = 2;
    }

    while (num--) {
      x += dx[d], y += dy[d];
      if (x < 0 || x >= w || y < 0 || y >= h) {
        x -= dx[d], y -= dy[d];
        d = (d + 1) % 4;
        x += dx[d], y += dy[d];
      }
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() { return dir[d]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
