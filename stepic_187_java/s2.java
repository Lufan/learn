/*
На игровом поле находится робот. Позиция робота на поле описывается двумя 
целочисленным координатами: X и Y. Ось X смотрит слева направо, ось Y — снизу 
вверх. (Помните, как рисовали графики функций в школе?)

В начальный момент робот находится в некоторой позиции на поле. Также известно, 
куда робот смотрит: вверх, вниз, направо или налево. Ваша задача — привести робота 
в заданную точку игрового поля.

Робот описывается классом Robot. Вы можете пользоваться следующими его методами 
(реализация вам неизвестна):

public class Robot {

    public Direction getDirection() {
        // текущее направление взгляда
    }

    public int getX() {
        // текущая координата X
    }

    public int getY() {
        // текущая координата Y
    }

    public void turnLeft() {
        // повернуться на 90 градусов против часовой стрелки
    }

    public void turnRight() {
        // повернуться на 90 градусов по часовой стрелке
    }

    public void stepForward() {
        // шаг в направлении взгляда
        // за один шаг робот изменяет одну свою координату на единицу
    }
}
Direction, направление взгляда робота,  — это перечисление:
public enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
}
Пример

В метод передано: toX == 3, toY == 0; начальное состояние робота такое: 
robot.getX() == 0, robot.getY() == 0, robot.getDirection() == Direction.UP

Чтобы привести робота в указанную точку (3, 0), метод должен вызвать у робота 
следующие методы:

robot.turnRight();
robot.stepForward();
robot.stepForward();
robot.stepForward();
P.S. Если вам понравилось это задание, то вам может прийтись по душе игра Robocode, 
в которой надо написать алгоритм управления танком. Алгоритмы, написанные разными 
людьми, соревнуются между собой.
*/

public static void go(Robot robot, int steps)
{
    for (int i = 0; i < steps; i++) {
        robot.stepForward();
    }
}

public static void moveRobot(Robot robot, int toX, int toY) {
    int x = robot.getX();
    int y = robot.getY();
    Direction d = robot.getDirection();
    int dx = toX - x;
    int dy = toY - y;

    if (dy > 0) {                          // Если надо идти вверх
        switch (robot.getDirection()) {    // Разворачиваемся вверх
            case UP:
                break;
            case DOWN:
                robot.turnLeft();
                robot.turnLeft();
                break;
            case RIGHT:
                robot.turnLeft();
                break;
            case LEFT:
                robot.turnRight();
                break;
            default:
                break;
        }
        go(robot, dy);                     // и идем вверх (toY - y) шагов
    } else if (dy < 0){                    // Если надо идти вниз
        switch (robot.getDirection()) {    // Разворачиваемся вниз
            case UP:
                robot.turnLeft();
                robot.turnLeft();
                break;
            case DOWN:
                break;
            case RIGHT:
                robot.turnRight();
                break;
            case LEFT:
                robot.turnLeft();
                break;
            default:
                break;
        }
        go(robot, -1*dy);                  // и идем вниз (toY - y) шагов
    }                                      // прибыв в назначенное место по оси Y
    
    if (dx > 0) {                          // если надо идти направо
        switch (robot.getDirection()) {    // Разворачиваемся направо
            case UP:
                robot.turnRight();
                break;
            case DOWN:
                robot.turnLeft();
                break;
            case RIGHT:
                break;
            case LEFT:
                robot.turnLeft();
                robot.turnLeft();
                break;
            default:
                break;
        }
        go(robot, dx);                     // и идем напрво (toX - x) шагов
    } else if (dx < 0) {                   // Если требуется идти налево
        switch (robot.getDirection()) {    // Разворачиваемся налево
            case UP:
                robot.turnLeft();
                break;
            case DOWN:
                robot.turnRight();
                break;
            case RIGHT:
                robot.turnLeft();
                robot.turnLeft();
                break;
            case LEFT:
                break;
            default:
                break;
        }
        go(robot, -1*dx);                 // и идем налево (toX - x) шагов
    }
}