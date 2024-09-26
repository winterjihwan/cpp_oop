struct Coor {
  double x, y;
};

class Shape {
protected:
  Coor coor;
  int z;
  Shape(double x_coor, double y_coor, int z)
      : coor{.x = x_coor, .y = y_coor}, z{z} {};

public:
  virtual ~Shape() = default;
  virtual void draw() = 0;

  void set_coor(double x_coor, double y_coor);

  void set_z(int z);

  int get_z(Shape *shape);
  Coor get_coor(Shape *shape);
};
