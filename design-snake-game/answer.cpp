#define NIL -1
#define x first
#define y second
#define Point pair<int, int>
#define MP(a, b) make_pair((a), (b))

class SnakeGame {
public:
    deque<Point> snake;
    vector<vector<bool>> occupied;
    vector<pair<int, int>> food;
    int index;
    int height;
    int width;

    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        occupied = vector<vector<bool>>(height, vector<bool>(width, false));
        snake.clear();
        this->food = food;
        index = 0;

        occupied[0][0] = true;
        snake.push_front(MP(0, 0));
    }

    void decodeDirection(string direction, int& x, int &y) {
        if (direction == "U")
            x = -1, y = 0;
        else if (direction == "L")
            x = 0, y = -1;
        else if (direction == "R")
            x = 0, y = 1;
        else
            x = 1, y = 0;
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int dx = 0, dy = 0;
        decodeDirection(direction, dx, dy);
        Point& head = snake.front();
        int nx = head.x + dx, ny = head.y + dy;
        if (nx < 0 || nx >= height || ny < 0 || ny >= width)
            return -1;
        if (index < food.size() && nx == food[index].x && ny == food[index].y) {
            index++;
        } else {
            Point& tail = snake.back();
            snake.pop_back();
            occupied[tail.x][tail.y] = false;
        }
        if (occupied[nx][ny])
            return -1;
        snake.push_front(MP(nx, ny));
        occupied[nx][ny] = true;
        return index;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */